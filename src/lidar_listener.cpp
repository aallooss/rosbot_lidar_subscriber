#include <vector>
#include <iostream>
#include "ros/ros.h"
#include <sensor_msgs/LaserScan.h>

//https://gist.github.com/jdumont0201/88648818622ac5b6ebe11e355e8e8390 poggers

void scanCallback(const sensor_msgs::LaserScan::ConstPtr& msg){
  
    // //std::cout << sizeof(msg->ranges)/sizeof(msg->ranges[0]);
    // std::cout << "Minimum range " << minRange(msg) << "     ";
    // std::cout << "Maximum range " << maxRange(msg) << std::endl;

        float max = 0.2;
        float min = 12.0;

        //set maximum range of LIDAR
        for (int i = 0; i < 720; i++)
        {
            if ((msg->ranges[i] > max) && (msg->ranges[i] >= 0.2) && (msg->ranges[i] <= 12.0))
            {
                max = msg->ranges[i];
            }
        }
        //set minimum range of LIDAR
        for (int i = 0; i < 720; i++)
        {
            if ((msg->ranges[i] < min) && (msg->ranges[i] >= 0.2) && (msg->ranges[i] <= 12.0))
            {
                min = msg->ranges[i];
            }
        }
        
    std::cout << "Minimum range " << min << "     ";
    std::cout << "Maximum range " << max << "     \n";
}
int main(int argc, char** argv) {
    ros::init(argc, argv, "topic_subscriber");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("scan", 1000, scanCallback);
    ros::spin();
    return 0;
}