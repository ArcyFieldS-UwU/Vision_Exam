//
// Created by arcyfields on 2026/4/14.
//

#include "robot_common/geometry_utils.hpp"

namespace robot_common {
    bool is_intersectant(const cv::Point p11, const cv::Point p12, const cv::Point p21, const cv::Point p22) {
        if (std::max(p11.x, p12.x) < std::min(p21.x, p22.x) ||
            std::max(p11.y, p12.y) < std::min(p21.y, p22.y) ||
            std::max(p21.x, p22.x) < std::min(p11.x, p12.x) ||
            std::max(p21.y, p22.y) < std::min(p11.y, p12.y))
        {
            return false;
        }

        cv::Point v1 = cv::Point(p12.x - p11.x, p12.y - p11.y);
        cv::Point v2 = cv::Point(p22.x - p21.x, p22.y - p21.y);

        int u1 = cross_product(cv::Point(p11.x - p21.x, p11.y - p21.y), v2);
        int u2 = cross_product(cv::Point(p12.x - p21.x, p12.y - p21.y), v2);
        int u3 = cross_product(cv::Point(p21.x - p11.x, p21.y - p11.y), v1);
        int u4 = cross_product(cv::Point(p22.x - p11.x, p22.y - p11.y), v1);

        return ((u1 * u2 <= 0) && (u3 * u4 <= 0));
    }

    cv::Point get_pre_point(cv::Point pos, cv::Point vel, cv::Point acc, double dt, const cv::Point EMITTER_POS) {
        const double BULLER_SPPED = 600.0;
        const double BUFF = 0.6;

        double effective_t = dt * BUFF;
        double dis = get_euclidean_distance(pos, EMITTER_POS) + effective_t * BULLER_SPPED;
        double t0 = dis / BULLER_SPPED;

        for (int i = 0; i < 10; i ++) {
            cv::Point pre = pos + vel * t0 + 0.5 * acc * t0 * t0;
            dis = get_euclidean_distance(pre, EMITTER_POS) + effective_t * BULLER_SPPED;
            t0 = dis / BULLER_SPPED;
        }
        return pos + vel * t0 + 0.5 * acc * t0 * t0;
    }
    void get_pre_contours(const Armor & armor,
                          double dt,
                          const cv::Point EMITTER_POS,
                          std::vector<std::pair<cv::Point, cv::Point> > & friends_pre_contours)
    {
        cv::Point pos = armor.pos, vel = armor.vel, acc = armor.acc;

        // LB
        pos.y += 16;
        pos.x -= 32;
        cv::Point p1 = get_pre_point(pos, vel, acc, dt, EMITTER_POS);

        // RB
        pos.x += 64;
        cv::Point p2 = get_pre_point(pos, vel, acc, dt, EMITTER_POS);

        // LT
        pos.y -= 32;
        pos.x -= 64;
        cv::Point p3 = get_pre_point(pos, vel, acc, dt, EMITTER_POS);

        // RT
        pos.x += 64;
        cv::Point p4 = get_pre_point(pos, vel, acc, dt, EMITTER_POS);

        friends_pre_contours.emplace_back(p1, p2); // Bottom
        friends_pre_contours.emplace_back(p3, p4); // Top
    }
    cv::Point get_pre_ene(const Armor & armor, const cv::Point EMITTER_POS, double dt) {
        cv::Point pos = armor.pos, vel = armor.vel, acc = armor.acc;

        // Choose the Bottom as the shooting point.
        pos.y += 16;
        cv::Point p = get_pre_point(pos, vel, acc, dt, EMITTER_POS);

        return p;
    }
}