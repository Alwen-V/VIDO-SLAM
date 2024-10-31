#include <System.h>
#include<iostream>
#include<algorithm>
#include<fstream>
#include<chrono>
#include<unistd.h>
#include<memory>
#include<opencv2/core/core.hpp>
#include<opencv2/optflow.hpp>
#include "utils.h"
#include "ImuTypes.h"


int main(int argc, char **argv){
   
   cv::Mat image_trajectory = cv::Mat::zeros(800, 600, CV_8UC3);
   std::vector<std::string> images_names;
   std::vector<double> vTimestampsImage;
   std::map<int,std::vector<VIDO_SLAM::IMU::Point>>vImuMeas;
   std::vector<int> nImages;
   std::vector<int> nImu;
   VIDO_SLAM::System vido_system_vo;
   VIDO_SLAM::System::eSensor sensor_type = VIDO_SLAM::System::RGBD;
   // VIDO_SLAM::System vido_system_vio;
   vido_system_vo.Init("/home/alwen/slam_source_code/VIDO-SLAM/src/config/kitti_config.yaml", sensor_type);
    return 0;
}