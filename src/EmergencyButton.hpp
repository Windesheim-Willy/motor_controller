#ifndef INC_WILLY_EMERGENCYBUTTON_H
#define INC_WILLY_EMERGENCYBUTTON_H

#include <ros.h>

class EmergencyButton {

public:
  EmergencyButton(ros::NodeHandle &handle, int pin);

  void loop();
private:

    ros::NodeHandle *handle;
    int emergencyPin;
};

#endif
