// Spark.h
#ifndef Spark_h
#define Spark_h
#include "Arduino.h"

class Spark {
  public:
    Spark(uint32_t _color, float position);
    Spark(uint32_t _color, float position, float velocity, float accel);
    Spark(uint32_t _color, float position, float velocity, float accel, bool isVis);
    void update();
    void resetPos();
    void setBounds(float low, float high);

    uint32_t color;
    float pos;
    
    bool isVisible;
    float vel;
    float acl;
    float lowBound;
    float highBound;
    // float getLowBound();
    // float getHighBound();
    // uint32_t getColor();
    // void setPos(float newVal);
    // float getPos();
    // void setVel(float newVal);
    // float getVel();
    // void setAcl(float newVal);
    // float getAcl();
    // void setVis(bool newVal);
    // float getVis();

  private:
    
};

#endif