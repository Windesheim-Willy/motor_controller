#ifndef INC_WILLY_EMERGENCYBUTTON_H
#define INC_WILLY_EMERGENCYBUTTON_H

#include <ros.h>
#include <std_msgs/Bool.h>

class EmergencyButton {

public:
  EmergencyButton(ros::NodeHandle* handle, int pin);

  void loop();
private:
    ros::NodeHandle *handle;
    ros::Publisher publisher;

    int emergencyPin;

    std_msgs::Bool buttonState;
};

#endif
