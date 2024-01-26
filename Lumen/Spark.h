// Spark.h
#ifndef Spark_h
#define Spark_h
#include "Arduino.h"

class Spark {
  public:
    Spark(uint32_t _color, int position, bool isVis, float velocity, float accel);
    void update();

  private:
    uint32_t color;
    int pos;
    bool isVisible;

    float vel;
    float acl;
};




#endif