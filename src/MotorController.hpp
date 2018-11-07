#ifndef INC_WILLY_MOTORCONTROL_H
#define INC_WILLY_MOTORCONTROL_H

#include <ros.h>
#include <geometry_msgs/Twist.h>

class MotorController {

public:
  MotorController(ros::NodeHandle nodehandle);

  void callback(const geometry_msgs::Twist& twistMsg);
  void loop();

  void limit(int &variable);
private:
  ros::NodeHandle handle;
  ros::Subscriber<geometry_msgs::Twist> subscriber;

  char data[5];
  int throttle, direction;
};

#endif
