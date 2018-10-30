#include <ros.h>

#include "MotorController.hpp"

MotorController::MotorController(ros::NodeHandle &handle)
{
  this->handle = &handle;
  this->subscriber = handle.subscribe(
    "/cmd_vel",
    1000,
    boost::bind(&MotorController::callback, this)
  );

  throttle = 0;
  direction = 0;
}
