#include "EmergencyButton.hpp"

EmergencyButton::EmergencyButton(ros::NodeHandle nodehandle, int pin) :
  handle(handle),
  publisher("/emergency", &buttonState)
{
  this->emergencyPin = emergencyPin;
  handle.advertise(this->publisher);
}

void EmergencyButton::loop()
{
  int analogValue = analogRead(this->emergencyPin);

  // 1024 / 5 * 3 = 614,4
  if (analogValue > 500) {
    buttonState.data = true;
  } else {
    buttonState.data = false;
  }

  publisher.publish(&buttonState);
}
