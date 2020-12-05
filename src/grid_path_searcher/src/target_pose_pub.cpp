#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>


using namespace std;

int main(int argc, char** argv) {
    ros::init(argc, argv, "target_pose_pub");
    ros::NodeHandle n;

    ros::Publisher pub1 = n.advertise<geometry_msgs::PoseStamped>("/goal", 1000);

    ros::Rate rate(1);
    int i = 0;
    while(ros::ok() && i < 3)
    {

    i++;
    geometry_msgs::PoseStamped goal_msg;

    goal_msg.pose.position.x = -3.09591;
    goal_msg.pose.position.y = 4.46233;
    goal_msg.pose.position.z = 2.5;
    goal_msg.header.stamp = ros::Time::now();
    goal_msg.header.frame_id = std::string("world");
    pub1.publish(goal_msg);
    rate.sleep();
	}
    return 0;
}
