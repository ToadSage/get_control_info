#include "ros/ros.h"
#include "std_msgs/String.h"
#include <boost/regex.hpp>
#include <iostream>


/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
void controlCallback(const std_msgs::String::ConstPtr& msg)
{
	const boost::regex e("(?<=BMAIN)(.*?)(?=EMAIN)");
	boost::smatch match;		
	if (boost::regex_search(std::string (msg->data.c_str()), match, e))
	{
		std::cout << "I heard: " << match[1].str() << std::endl;
	}
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "get_control_info");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("serial_generic", 1000, controlCallback);

  ros::spin();

  return 0;
}
