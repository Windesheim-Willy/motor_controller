#include <ros.h>
#include "MotorController.hpp"

MotorController::MotorController(ros::NodeHandle nodehandle) :
  handle(nodehandle),
  subscriber("/cmd_vel", &MotorController::callback, this)
{
  throttle = 0;
  direction = 0;

  handle.subscribe(subscriber);
  Serial1.begin(19200, SERIAL_8E1);
}

void MotorController::loop()
{
  // Datagram always start with 0x6A
  data[0]=0x6A;

  // Variables that define the position of the joystick
  data[1]=throttle;
  data[2]=direction;

  // Driv mode
  data[3]=0;
  // Drive mode: 0x0c=fastest
  data[4]=0x0c;
  // Checksum
  data[5]=0xff-(data[0]+data[1]+data[2]+data[3]+data[4]);

  for(unsigned char i=0;i<6;i++)
  {
     // Writing the data to the motorcontroller
    Serial1.write(data[i]);
  }
}

void MotorController::callback(const geometry_msgs::Twist& twistMsg)
{
  throttle = twistMsg.linear.x * 100;
  direction = twistMsg.angular.z * 100;

  this->limit(throttle);
  this->limit(direction);
}

void MotorController::limit(int &variable)
{
  if (variable > 100) {
    variable = 100;
  }

  if (variable < -100){
    variable = 100;
  }
}
