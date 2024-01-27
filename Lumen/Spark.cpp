// Spark.cpp
#include <Arduino.h>
// #include "Arduino.h”
#include "Spark.h"

Spark::Spark(uint32_t _color, float position){
  Spark(_color, position, 0, 0, false);
}
Spark::Spark(uint32_t _color, float position, float velocity, float accel){
  Spark(_color, position, velocity, accel, false);
}
Spark::Spark(uint32_t _color, float position, float velocity, float accel, bool isVis){
  color = _color;
  pos = position;
  vel = velocity;
  acl = accel;
  isVisible = isVis;
}

void Spark::update(){
  pos += vel;
  vel += acl;
}

void Spark::setBounds(float low, float high){
  lowBound = b1;
  highBound = b2;
}

float Spark::getBound1(){
  return bound1;
}

float Spark::getBound2(){
  return bound2;
}

void Spark::setVel(float newVal){
  vel = newVal;
}

float Spark::getVel(){
  return vel;
}

void Spark::setAcl(float newVal){
  acl = newVal;
}

float Spark::getAcl(){
  return acl;
}

void Spark::setVis(bool newVal){
  isVisible = newVal;
}

float Spark::getVis(){
  return isVisible;
}