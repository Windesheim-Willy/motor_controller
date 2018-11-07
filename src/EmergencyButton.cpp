#include "EmergencyButton.hpp"

EmergencyButton::EmergencyButton(ros::NodeHandle *handle, int pin) :
  handle(handle),
  publisher("/emergency", &buttonState)
{
  this->emergencyPin = emergencyPin;
  handle->advertise(this->publisher);
}

void EmergencyButton::loop()
{
  int analogValue = analogRead(this->emergencyPin);

  if (analogValue > 500) {
    buttonState.data = true;
  } else {
    buttonState.data = false;
  }

  publisher.publish(&buttonState);
}
