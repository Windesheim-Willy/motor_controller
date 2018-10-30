#include <ros.h>
#include "MotorController.hpp"
#include "EmergencyButton.hpp"

#define EMERGENCY_BUTTON_PIN 7

ros::NodeHandle n;

MotorController *motorController;
EmergencyButton *emergencyButton;

int main(void)
{
  n.initNode();
  
  motorController = new MotorController(n);
  EmergencyButton = new EmergencyButton(n, EMERGENCY_BUTTON_PIN);

  while (true) {

    motorController->loop();
    emergencyButton->loop();

    n.spinOnce();
  }

}
