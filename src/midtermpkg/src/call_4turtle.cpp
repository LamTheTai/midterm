#include <ros/ros.h>
#include <turtlesim/Spawn.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "turtle_spawner");
    ros::NodeHandle nh;

    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");

    // Tạo ra 4 con rùa ở các vị trí khác nhau
    turtlesim::Spawn srv;
    srv.request.x = 2.0;
    srv.request.y = 2.0;
    srv.request.theta = 0.0;
    client.call(srv);

    srv.request.x = 5.0;
    srv.request.y = 5.0;
    srv.request.theta = 0.0;
    client.call(srv);

    srv.request.x = 8.0;
    srv.request.y = 8.0;
    srv.request.theta = 0.0;
    client.call(srv);

    srv.request.x = 11.0;
    srv.request.y = 11.0;
    srv.request.theta = 0.0;
    client.call(srv);

    return 0;
}
