#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Bool.h>

ros::NodeHandle nh;
std_msgs::Bool emergency;

int analogValue;
int volatile irun, iturn;
unsigned char data[255];

void messageCb(const geometry_msgs::Twist& twistMsg)
{
  irun = twistMsg.linear.x * 100;
  iturn = twistMsg.angular.z * 100;
}

ros::Subscriber<geometry_msgs::Twist> sub("/cmd_vel", &messageCb);
ros::Publisher pub("emergency", &emergency);
 
void setup()
{ 
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(pub);
  
  Serial1.begin(19200, SERIAL_8E1);  
}
    
void loop()
{
    int drive = irun;                                                       //Set value from ros to motorcontroller
    int turn = iturn;                                                       //Set value from ros to motorcontroller

    if(drive > 100) {
      drive = 100;
    }
    
    if(drive < -100) {
      drive = -100;
    }
  
    if(turn > 100) {
      turn = 100;
    }
    if(turn < -100) {
      turn = -100;
    }

    data[0]=0x6A;                                              //-Datagram always start with 0x6A
    data[1]=drive;                                             //-Drive +-100
    data[2]=turn;                                              //-Turn +-100
    data[3]=0;                                                 //-Driv mode
    data[4]=0x0c;                                              //-Drive mode: 0x0c=fastest
    data[5]=0xff-(data[0]+data[1]+data[2]+data[3]+data[4]);    //-Checksum

    for(unsigned char i=0;i<6;i++)
    {
      Serial1.write(data[i]);                                  // Writing the data to the motorcontroller
    }
    
    analogValue = analogRead(A8);

    if (analogValue > 500) {
      emergency.data = true;
    } else {
      emergency.data = false;
    }

    pub.publish(&emergency);
          
    nh.spinOnce();

    delay(20);
  
}

