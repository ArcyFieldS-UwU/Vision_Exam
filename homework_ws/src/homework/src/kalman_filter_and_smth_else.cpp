//
// Created by arcyfields on 2026/4/11.
//

#include "kalman_filter_and_smth_else.h"

const int STATE_SIZE = 6;
const int MEASUREMENT_SIZE = 2;
const int CONTROL_SIZE = 0;

const float Q_POS = 1e-5f;
const float Q_VEL = 1e-4f;
const float Q_ACC = 1e-3f;
const float R_POS = 1e-2f;

/* Armor Realization */

Armor::Armor(int _id, const cv::Point & initial_pos, double _dt)
    : id(_id), pos(initial_pos), vel(cv::Point(0, 0)), acc(cv::Point(0, 0)), dt(_dt), lost_count(0) {
    kf = cv::KalmanFilter(STATE_SIZE, MEASUREMENT_SIZE, CONTROL_SIZE, CV_32F);

    // Initial state vector.
    cv::Mat state(STATE_SIZE, 1, CV_32F);
    state.at<float>(0) = initial_pos.x;
    state.at<float>(1) = initial_pos.y;
    state.at<float>(2) = 0;
    state.at<float>(3) = 0;
    state.at<float>(4) = 0;
    state.at<float>(5) = 0;
    kf.statePost = state;

    // Initial err cov matrix ( involving vel & acc ).
    cv::setIdentity(kf.errorCovPost, cv::Scalar(100));
    kf.errorCovPost.at<float>(2,2) = 500;
    kf.errorCovPost.at<float>(3,3) = 500;
    kf.errorCovPost.at<float>(4,4) = 1000;
    kf.errorCovPost.at<float>(5,5) = 1000;

    // Transition matrix A.
    cv::setIdentity(kf.transitionMatrix, cv::Scalar(1));
    kf.transitionMatrix.at<float>(0, 2) = dt;
    kf.transitionMatrix.at<float>(0, 4) = 0.5 * dt * dt;
    kf.transitionMatrix.at<float>(1, 3) = dt;
    kf.transitionMatrix.at<float>(1, 5) = 0.5 * dt * dt;
    kf.transitionMatrix.at<float>(2, 4) = dt;
    kf.transitionMatrix.at<float>(3, 5) = dt;

    // Measurement matrix H.
    kf.measurementMatrix = cv::Mat::zeros(MEASUREMENT_SIZE, STATE_SIZE, CV_32F);
    kf.measurementMatrix.at<float>(0, 0) = 1.0f;
    kf.measurementMatrix.at<float>(1, 1) = 1.0f;

    // Process noise cov matrix Q.
    cv::setIdentity(kf.processNoiseCov, cv::Scalar(0));
    kf.processNoiseCov.at<float>(0, 0) = Q_POS;
    kf.processNoiseCov.at<float>(1, 1) = Q_POS;
    kf.processNoiseCov.at<float>(2, 2) = Q_VEL;
    kf.processNoiseCov.at<float>(3, 3) = Q_VEL;
    kf.processNoiseCov.at<float>(4, 4) = Q_ACC;
    kf.processNoiseCov.at<float>(5, 5) = Q_ACC;

    // Measurement noise cov matrix R.
    cv::setIdentity(kf.measurementNoiseCov, cv::Scalar(R_POS));
}

void Armor::predict(double _dt) {
    dt = _dt;
    kf.transitionMatrix.at<float>(0, 2) = dt;
    kf.transitionMatrix.at<float>(0, 4) = 0.5f * dt * dt;
    kf.transitionMatrix.at<float>(1, 3) = dt;
    kf.transitionMatrix.at<float>(1, 5) = 0.5f * dt * dt;
    kf.transitionMatrix.at<float>(2, 4) = dt;
    kf.transitionMatrix.at<float>(3, 5) = dt;

    cv::Mat prediction = kf.predict();
    pos.x = static_cast<int>(prediction.at<float>(0));
    pos.y = static_cast<int>(prediction.at<float>(1));
    vel.x = static_cast<int>(prediction.at<float>(2));
    vel.y = static_cast<int>(prediction.at<float>(3));
    acc.x = static_cast<int>(prediction.at<float>(4));
    acc.y = static_cast<int>(prediction.at<float>(5));
}

void Armor::correct(const cv::Point & measurement_pos) {
    cv::Mat z(MEASUREMENT_SIZE, 1, CV_32F);
    z.at<float>(0) = (float)measurement_pos.x;
    z.at<float>(1) = (float)measurement_pos.y;
    cv::Mat estimation = kf.correct(z);
    pos.x = static_cast<int>(estimation.at<float>(0));
    pos.y = static_cast<int>(estimation.at<float>(1));
    vel.x = static_cast<int>(estimation.at<float>(2));
    vel.y = static_cast<int>(estimation.at<float>(3));
    acc.x = static_cast<int>(estimation.at<float>(4));
    acc.y = static_cast<int>(estimation.at<float>(5));
}

/* Tracker Realization */

Tracker::Tracker(double _dt)
    : _armors_cnt(0), _max_match_dist(32.0), _max_lost_count(5), dt(_dt)
{
    _armors.clear();
}

Tracker::~Tracker() {
    _armors_cnt = 0;
    _max_match_dist = 0.0;
    _max_lost_count = 0;
    dt = 0.0;
    _armors.clear();
}

void Tracker::armor_matching(const std::vector<cv::Point> & positions,
                             std::vector<std::pair<int, int> > & matches,
                             std::vector<int> & unmatched_pos,
                             std::vector<int> & unmatched_arm)
{
    matches.clear();
    int n_pos = positions.size();
    int n_arm = _armors.size();

    std::vector<bool> is_pos_matched(n_pos, false), is_arm_matched(n_arm, false);

    for (int i = 0; i < n_pos; i ++) {
        double best_dis = _max_match_dist;
        int best_idx = -1;
        for (int j = 0; j < n_arm; j ++) {
            if (is_arm_matched[j]) {
                continue;
            }
            double dis = get_euclid_distance(positions[i], _armors[j].pos);
            if (dis < best_dis) {
                best_dis = dis;
                best_idx = j;
            }
        }
        if (best_idx != -1) {
            matches.emplace_back(i, best_idx);
            is_pos_matched[i] = true;
            is_arm_matched[best_idx] = true;
        }
    }

    for (int i = 0; i < n_pos; i ++) {
        if (!is_pos_matched[i]) {
            unmatched_pos.emplace_back(i);
        }
    }
    for (int i = 0; i < n_arm; i ++) {
        if (!is_arm_matched[i]) {
            unmatched_arm.emplace_back(i);
        }
    }
}

void Tracker::create_track(const cv::Point & pos) {
    _armors.emplace_back(_armors_cnt ++, pos, dt);
}

void Tracker::auto_remove() {
    _armors.erase(
        std::remove_if(_armors.begin(), _armors.end(),
            [this](const Armor & armor) { return armor.lost_count > _max_lost_count; }),
        _armors.end()
    );
}

void Tracker::update(const std::vector<cv::Point> & positions, double _dt) {
    dt = _dt;
    for (auto & armor : _armors) {
        armor.predict(dt);
    }

    std::vector<std::pair<int, int>> matches;
    std::vector<int> unmatched_pos, unmatched_arm;
    armor_matching(positions, matches, unmatched_pos, unmatched_arm);
    for (auto & match : matches) {
        int idx_pos = match.first;
        int idx_arm = match.second;
        _armors[idx_arm].correct(positions[idx_pos]);
        _armors[idx_arm].lost_count = 0;
    }

    for (int i : unmatched_arm) {
        _armors[i].lost_count ++;
    }
    for (int i : unmatched_pos) {
        create_track(positions[i]);
    }

    auto_remove();
}

std::vector<Armor> Tracker::get_data() const {
    return _armors;
}

void Tracker::set_dt(double _dt) {
    dt = _dt;
}