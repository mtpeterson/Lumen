// Spark.h
#ifndef Spark_h
#define Spark_h
#include "Arduino.h"

class Spark {
  public:
    Spark(uint32_t _color);
    Spark(uint32_t _color, int position);
    Spark(uint32_t _color, int position, float velocity);
    Spark(uint32_t c_olor, int position, float velocity, float accel);
    void exampleFunction();

  private:
    int pos;
    uint32_t color;

    float vel;
    float acl;
};




#endif