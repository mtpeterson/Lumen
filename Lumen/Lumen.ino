#include <Adafruit_NeoPixel.h>
#include "Spark.h"
Adafruit_NeoPixel strip = Adafruit_NeoPixel(151, 6);  // Creates a strand of 151 NeoPixels on Pin 6
int light = 7;  // The pin to change the mode
int bright = 8; // The pin to change the brightness

const int numSparks = 20;
Spark *sparkArray[numSparks];

uint32_t teal = strip.Color(0, 255, 140);

void setup() {
  rainDropSetup(30, 75, 105, 151 )

}

void loop() {
  // put your main code here, to run repeatedly:
  rainDropFall();
  strip.show();
}

void showSparks(){
  for(int i=0; i<numSparks; i++){
    strip.setPixelColor(sparkArray[i]->getPos(), sparkArray[i]->getColor());
  }
}

///////////// RAINSTORM /////////////
// I want to have a setting that looks like a rainstorm
// The goal is to use the Sparks as raindrops falling down either side

// This function is used to set up the raindrops
void rainDropSetup(int leftTop, int leftBottom, int rightTop, int rightBottom){
  float fallVel = 1;
  float fallAcl = 0.1;

  // Drops on the left side have even indexes
  for(int i=0; i<numSparks; i+=2){
    sparkArray[i] = new Spark(teal, leftTop, -fallVel, -fallAcl);
    sparkArray[i]->setBounds(leftTop, leftBottom);
  }

  // Drops on the right side have odd indexes
  for(int i=1; i<numSparks; i+=2){
    sparkArray[i] = new Spark(teal, rightTop, fallVel, fallAcl);
    sparkArray[i]->setBounds(rightTop, rightBottom);
  }
}

// bool velSet = false;

// This function is used to move the raindrops
void rainDropFall(){
  // Using the highBound to represent the top corner whether on the right or left
  for(int i=0; i<numSparks; i+=2){
    if(sparkArray[i]->getPos() < sparkArray[i]->getLowBound() || sparkArray[i]->getPos() > sparkArray[i]->getHighBound()){
      sparkArray[i]->resetPos();
    }
    // if(!velSet){
    //   sparkArray[i]->setVel(vel);
    //   sparkArray[i]->setAcl(acl);
    // }
    sparkArray[i]->update();
  }
  for(int i=1; i<numSparks; i+=2){
    if(sparkArray[i]->getPos() < sparkArray[i]->getLowBound() || sparkArray[i]->getPos() > sparkArray[i]->getHighBound()){
      sparkArray[i]->resetPos();
    }
    // if(!velSet){
    //   sparkArray[i]->setVel(vel);
    //   sparkArray[i]->setAcl(acl);
    // }
    sparkArray[i]->update();
  }
  // if(!velSet){
  //   velSet = true;
  // }
}