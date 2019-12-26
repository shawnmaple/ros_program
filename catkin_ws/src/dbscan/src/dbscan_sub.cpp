#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
#include <fstream>   
#include <sensor_msgs/LaserScan.h>
#define PI 3.1415926

std::ofstream myfile("/home/shawn/record/laser.txt", std::ios::out);

void laserCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
{
    std::vector<float> ranges = msg->ranges;
    for(int i = 0; i < ranges.size(); i++)
    {
		std::cout << ranges[i] << " ";
        myfile << ranges[i] << " ";
    }
    myfile << std::endl;
}



int main(int argc, char *argv[])
{	
	if(!myfile)
    {
        std::cout<<"open file failure"<<std::endl;
    }
	ros::init(argc, argv, "dbscan");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("/scan", 1000, laserCallback);
	ros::spin();
	myfile.close();
	return 0;
}

