//
// Created by arcyfields on 2026/4/14.
//

#ifndef ROBOT_DETECTOR_KALMAN_TRACKER_HPP
#define ROBOT_DETECTOR_KALMAN_TRACKER_HPP

#include <vector>
#include <opencv2/opencv.hpp>

namespace robot_common {
    struct Armor {
        int id;
        cv::KalmanFilter kf;
        cv::Point pos;
        cv::Point vel;
        cv::Point acc;
        double dt;
        int lost_count;

        Armor(int _id, const cv::Point & initial_pos, double _dt = 0.5);

        void predict(double _dt = 0.5);
        void correct(const cv::Point & measurement_pos);
    };

    class Tracker {
    private:
        std::vector<Armor> _armors;
        int _armors_cnt;
        double _max_match_dist;
        int _max_lost_count;
        double dt;

        inline void armor_matching(const std::vector<cv::Point> & positions,
                                   std::vector<std::pair<int, int>> & matches,
                                   std::vector<int> & unmatched_pos,
                                   std::vector<int> & unmatched_arm);

        inline void create_track(const cv::Point & pos);
        inline void auto_remove();
    public:
        Tracker(double _dt = 0.5);
        ~Tracker();

        void update(const std::vector<cv::Point> & positions, double _dt = 0.5);
        std::vector<Armor> get_data() const;
        inline void set_dt(double _dt);
    };
}

#endif //ROBOT_DETECTOR_KALMAN_TRACKER_HPP
