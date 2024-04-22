#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>
#include <cmath>

ros::Publisher pub;
turtlesim::Pose current_pose;

void poseCallback(const turtlesim::Pose::ConstPtr& msg) {
    current_pose = *msg;
}

inline geometry_msgs::Twist getMessage(double x, double y, double z) {
    geometry_msgs::Twist msg;
    msg.linear.x = x;
    msg.linear.y = y;
    msg.angular.z = z;
    return msg;
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "turtle_control");
    ros::NodeHandle nh;
    pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
    ros::Subscriber sub = nh.subscribe("/turtle1/pose", 1000, poseCallback);
    
    const float PI = 3.14159, dt = 0.01;
    ros::Rate loopRate(100);

    double kp_distance = 0.45; 
    double kp_theta = 1.4;
    double y_goal;

    while (ros::ok()) {
        std::cout << "Nhap toa do duong thang y : ";
        std::cin >> y_goal;

        while (true) {
            ros::spinOnce();
            loopRate.sleep();

            double err_distance = y_goal - current_pose.y - 1.0; 
            double dalpha = std::atan2(0, err_distance) - current_pose.theta;
            dalpha = std::fmod(dalpha + PI, 2 * PI) - PI;

            geometry_msgs::Twist msg = getMessage(kp_distance * std::abs(err_distance), 0.0, kp_theta * dalpha);
            pub.publish(msg);

            if (std::abs(err_distance) < 0.1) {
                break;
            }
        }
    }

    return 0;
}
