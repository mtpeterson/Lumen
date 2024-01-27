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
    void setBounds(float b1, float b2);

    float lowBound();
    float highBound();
    void setVel(float newVal);
    float getVel();
    void setAcl(float newVal);
    float getAcl();
    void setVis(bool newVal);
    float getVis();

  private:
    uint32_t color;
    float pos;
    
    bool isVisible;
    float vel;
    float acl;
    float bound1;
    float bound2;
};

#endif