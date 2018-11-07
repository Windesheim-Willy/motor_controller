#include <arduino.h>
#include <ros.h>
#include "MotorController.hpp"
#include "EmergencyButton.hpp"

// The led plus is connected with the A8 port
#define EMERGENCY_BUTTON_PIN 8

ros::NodeHandle handle;

MotorController *motorController;
EmergencyButton *emergencyButton;

int main(void)
{
  handle.initNode();

  motorController = new MotorController(handle);
  emergencyButton = new EmergencyButton(handle, EMERGENCY_BUTTON_PIN);

  // Loop until the end of time
  while (true) {
    motorController->loop();
    emergencyButton->loop();

    // Just sleep for a bit
    delay(20);

    handle.spinOnce();
  }
}
