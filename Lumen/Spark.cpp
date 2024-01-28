// Spark.cpp
#include <Arduino.h>
// #include "Arduino.h”
#include "Spark.h"

Spark::Spark(uint32_t _color, float position){
  Spark(_color, position, 0, 0, true);
}
Spark::Spark(uint32_t _color, float position, float velocity, float accel){
  Spark(_color, position, velocity, accel, true);
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

void Spark::resetPos(){
  pos = highBound;
}

void Spark::setBounds(float low, float high){
  lowBound = low;
  highBound = high;
}

float Spark::getLowBound(){
  return lowBound;
}

float Spark::getHighBound(){
  return highBound;
}

uint32_t Spark::getColor(){
  return color;
}

void Spark::setPos(float newVal){
  pos = newVal;
}

float Spark::getPos(){
  return pos;
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