#include <ros.h>
#include "MotorController.hpp"

MotorController::MotorController(ros::NodeHandle *nodehandle) :
  handle(nodehandle),
  subscriber("/cmd_vel", 1000, &MotorController::callback, this)
{
  throttle = 0;
  direction = 0;

  handle->initNode();
  handle->subscribe(subscriber);
}

void MotorController::loop()
{
  
}

void MotorController::callback(const geometry_msgs::Twist& twistMsg)
{
  throttle = twistMsg.linear.x * 100;
  direction = twistMsg.angular.z * 100;
}
