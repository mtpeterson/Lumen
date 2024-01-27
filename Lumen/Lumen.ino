#include <Adafruit_NeoPixel.h>
#include "Spark.h"
Adafruit_NeoPixel strip = Adafruit_NeoPixel(151, 6);  // Creates a strand of 151 NeoPixels on Pin 6
int light = 7;  // The pin to change the mode
int bright = 8; // The pin to change the brightness

const int numSparks = 20;
Spark *sparkArray[numSparks];

uint32_t teal = strip.Color(0, 255, 140);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

///////////// RAINSTORM /////////////
// I want to have a setting that looks like a rainstorm
// The goal is to use the Sparks as raindrops falling down either side

// This function is used to set up the raindrops
void rainDropSetup(int leftTop, int rightTop, int leftBottom, int rightBottom){
  float fallVel = 1;
  float fallAcl = 0.1;

  // Drops on the left side
  for(int i=0; i<numSparks; i+=2){
    sparkArray[i] = new Spark(teal, leftTop, -fallVel, -fallAcl);
    sparkArray[i]->setBounds(leftTop, leftBottom);
  }

  // Drops on the right side
  for(int i=1; i<numSparks; i+=2){
    sparkArray[i] = new Spark(teal, rightTop, fallVel, fallAcl);
    sparkArray[i]->setBounds(rightTop, rightBottom);
  }
}

// This function is used to move the raindrops
void rainDropFall(int vel, int acl){
  for(int i=0; i<numSparks; i+=2){
    if(sparkArray[i]->getBound1;
  }
  for(int i=1; i<numSparks; i+=2){
    // sparkArray[i] = new Spark(teal, rightTop);
  }
}