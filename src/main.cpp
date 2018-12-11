#include <arduino.h>
#include <ros.h>
#include "MotorController.hpp"
#include "EmergencyButton.hpp"

// The led plus is connected with the A8 port
#define EMERGENCY_BUTTON_PIN 8

ros::NodeHandle nh;

MotorController *motorController;
EmergencyButton *emergencyButton;

void messageCb(const geometry_msgs::Twist& twistMsg)
{
  motorController->process(&twistMsg);
}

ros::Subscriber<geometry_msgs::Twist> sub("/cmd_vel", &messageCb);

int main(void)
{
  nh.initNode();
  nh.subscribe(sub);

  motorController = new MotorController();
  emergencyButton = new EmergencyButton(nh, EMERGENCY_BUTTON_PIN);

  // Loop until the end of time
  while (true) {
    motorController->loop();
    emergencyButton->loop();

    // Just sleep for a bit
    delay(20);

    nh.spinOnce();
  }
}
