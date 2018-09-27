// c++ version by ftdlyc

/*
% Copyright 2012. All rights reserved.
% Author: Andreas Geiger
%         Institute of Measurement and Control Systems (MRT)
%         Karlsruhe Institute of Technology (KIT), Germany

% This is free software; you can redistribute it and/or modify it under the
% terms of the GNU General Public License as published by the Free Software
% Foundation; either version 3 of the License, or any later version.

% This software is distributed in the hope that it will be useful, but WITHOUT ANY
% WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
% PARTICULAR PURPOSE. See the GNU General Public License for more details.

% You should have received a copy of the GNU General Public License along with
% this software; if not, write to the Free Software Foundation, Inc., 51 Franklin
% Street, Fifth Floor, Boston, MA 02110-1301, USA
*/

#include "plot_corners.h"
#include <opencv2/opencv.hpp>
#include "find_corners.h"

namespace cbdetect {

void plot_corners(const cv::Mat &img, const Corner &corners) {
  cv::Mat img_show;
  cv::cvtColor(img, img_show, CV_GRAY2BGR);
  for (int i = 0; i < corners.p.size(); ++i) {
    cv::line(img_show, corners.p[i], corners.p[i] + 20 * corners.v1[i], cv::Scalar(255, 0, 0), 2);
    cv::line(img_show, corners.p[i], corners.p[i] + 20 * corners.v2[i], cv::Scalar(0, 255, 0), 2);
    cv::circle(img_show, corners.p[i], 3, cv::Scalar(0, 0, 255), -1);
    cv::putText(img_show, std::to_string(i), cv::Point2i(corners.p[i].x + 3, corners.p[i].y + 3),
                cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 255), 1);
  }
  cv::imshow("corners_img", img_show);
}

}