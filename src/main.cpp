#include <arduino.h>
#include <ros.h>
#include "MotorController.hpp"
#include "EmergencyButton.hpp"

// The led plus is connected with the A8 port
#define EMERGENCY_BUTTON_PIN 8

MotorController *motorController;
EmergencyButton *emergencyButton;

int main(void)
{
  // ros::init();
  ros::NodeHandle n;

  motorController = new MotorController(&n);
  emergencyButton = new EmergencyButton(&n, EMERGENCY_BUTTON_PIN);

  while (true) {

    motorController->loop();
    emergencyButton->loop();

    delay(20);
    n.spinOnce();
  }

}
