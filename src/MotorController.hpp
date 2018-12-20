#ifndef INC_WILLY_MOTORCONTROL_H
#define INC_WILLY_MOTORCONTROL_H

#include <geometry_msgs/Twist.h>

class MotorController {

public:
  MotorController();

  void process(const geometry_msgs::Twist *twistMsg);
  void loop();

protected:
  void limit(int volatile &variable);

private:
  char data[5];
  int volatile throttle, direction;
};

#endif
