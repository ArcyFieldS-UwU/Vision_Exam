//
// Created by arcyfields on 2026/4/14.
//

#ifndef ROBOT_DETECTOR_IMAGE_UTILS_HPP
#define ROBOT_DETECTOR_IMAGE_UTILS_HPP

#include <opencv2/opencv.hpp>

namespace robot_common {
    inline int rect_sum(const cv::Mat & img_sum, const cv::Rect & rect) {
        int x0 = rect.x + rect.width, y0 = rect.y + rect.height;
        return img_sum.at<int>(rect.y, rect.x) + img_sum.at<int>(y0, x0)
             - img_sum.at<int>(y0, rect.x) - img_sum.at<int>(rect.y, x0);
    }

    bool is_have_gray(const cv::Mat & img, const cv::Rect & rect);
}

#endif //ROBOT_DETECTOR_IMAGE_UTILS_HPP
