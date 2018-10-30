#ifndef INC_WILLY_MOTORCONTROL_H
#define INC_WILLY_MOTORCONTROL_H

#include <ros.h>
#include <geometry_msgs/Twist.h>

class MotorController {

public:
  MotorController(ros::NodeHandle &handle);

  void callback(const geometry_msgs::Twist& twistMsg);
  void loop();

private:

  ros::NodeHandle *handle;
  ros::Subscriber;

  int throttle, direction;
};

#endif
