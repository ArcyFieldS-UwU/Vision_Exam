//
// Created by arcyfields on 2026/4/14.
//

#include "robot_common/image_utils.hpp"

namespace robot_common {
    bool is_have_gray(const cv::Mat & img, const cv::Rect & rect) {
        cv::Mat ROI = img(rect);
        cv::Mat mask;
        cv::inRange(ROI, cv::Scalar(140, 140, 140), cv::Scalar(150, 150, 150), mask);
        return cv::countNonZero(mask) > 0;
    }
}