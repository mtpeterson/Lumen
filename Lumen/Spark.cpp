// Spark.cpp
#include <Arduino.h>
// #include "Arduino.h”
#include "Spark.h"

Spark::Spark(uint32_t _color, int position = 0, bool isVis = false, float velocity = 0, float accel = 0){
  color = _color;
  pos = position;
  isVisible = isVis;
  vel = velocity;
  acl = accel;
}

void Spark::update(){
  pos += vel;
  vel += acl;
}