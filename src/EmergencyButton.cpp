#include "EmergencyButton.hpp"

EmergencyButton::EmergencyButton(ros::NodeHandle &handle, int emergencyPin)
{
  this->emergencyPin = emergencyPin;
}
