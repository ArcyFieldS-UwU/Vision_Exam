//
// Created by arcyfields on 2026/4/14.
//

#ifndef ROBOT_DETECTOR_GEOMETRY_UTILS_HPP
#define ROBOT_DETECTOR_GEOMETRY_UTILS_HPP

#include <opencv2/opencv.hpp>
#include "kalman_tracker.hpp"

namespace robot_common {
    inline double get_euclidean_distance(cv::Point p1, cv::Point p2) {
        return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    }

    inline int cross_product(const cv::Point p1, const cv::Point p2) {
        return p1.x * p2.y - p1.y * p2.x;
    }
    bool is_intersectant(const cv::Point p11, const cv::Point p12, const cv::Point p21, const cv::Point p22);

    cv::Point get_pre_point(cv::Point pos, cv::Point vel, cv::Point acc, double dt, const cv::Point EMITTER_POS);
    void get_pre_contours(const Armor & armor,
                          double dt,
                          const cv::Point EMITTER_POS,
                          std::vector<std::pair<cv::Point, cv::Point> > & friends_pre_contours);
    cv::Point get_pre_ene(const Armor & armor, const cv::Point EMITTER_POS, double dt);
}

#endif //ROBOT_DETECTOR_GEOMETRY_UTILS_HPP
