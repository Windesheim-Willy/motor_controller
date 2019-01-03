#ifndef _ROS_human_detection_Person_h
#define _ROS_human_detection_Person_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace human_detection
{

  class Person : public ros::Msg
  {
    public:
      typedef uint32_t _id_type;
      _id_type id;
      typedef uint32_t _accuracy_type;
      _accuracy_type accuracy;
      typedef uint32_t _distance_type;
      _distance_type distance;

    Person():
      id(0),
      accuracy(0),
      distance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->accuracy >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->accuracy >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->accuracy >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->accuracy >> (8 * 3)) & 0xFF;
      offset += sizeof(this->accuracy);
      *(outbuffer + offset + 0) = (this->distance >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->distance >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->distance >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->distance >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->id =  ((uint32_t) (*(inbuffer + offset)));
      this->id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->id);
      this->accuracy =  ((uint32_t) (*(inbuffer + offset)));
      this->accuracy |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->accuracy |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->accuracy |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->accuracy);
      this->distance =  ((uint32_t) (*(inbuffer + offset)));
      this->distance |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->distance |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->distance |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->distance);
     return offset;
    }

    const char * getType(){ return "human_detection/Person"; };
    const char * getMD5(){ return "9a68de34062aaa96a4591368635d3f26"; };

  };

}
#endif