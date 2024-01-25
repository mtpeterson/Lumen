#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(151, 6);  // Creates a strand of 5 NeoPixels on Pin 6
int light = 7;
int bright = 8;
//151 neopixels (150 after cutting)

// int PXL1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int delayVal = 0;
int lightSetting;
uint32_t graySky = strip.Color(5, 8, 11);
int numPixels = 150;
int numLightSettings = 6;
uint32_t coolGreen = strip.Color(65, 206, 93);
uint32_t white = strip.Color(255, 255, 255);
int brightSetting;
int numBrightSettings = 10;

//const int numReadings = 200;

// int readings[numReadings];  // the readings from the analog input
// int readIndex = 0;          // the index of the current reading
// int total = 0;              // the running total
// int average = 0;            // the average

void setup() {
  Serial.begin(9600);
  pinMode(light, INPUT);
  strip.begin();
  strip.clear();
  lightSetting = 0;
  pinMode(bright, INPUT_PULLUP);
  brightSetting = numBrightSettings;
  // brightness = 255;
  // for (int thisReading = 0; thisReading < numReadings; thisReading++) {
  //   readings[thisReading] = 0;
}



void loop() {
  // // subtract the last reading:
  // total = total - readings[readIndex];
  // // read from the sensor:
  // readings[readIndex] = analogRead(potent);
  // // add the reading to the total:
  // total = total + readings[readIndex];
  // // advance to the next position in the array:
  // readIndex = readIndex + 1;

  // // if we're at the end of the array...
  // if (readIndex >= numReadings) {
  //   // ...wrap around to the beginning:
  //   readIndex = 0;
  // }

  // // calculate the average:
  // average = total / numReadings;
  // // send it to the computer as ASCII digits
  // Serial.println(analogRead(potent));
  // //delay(1);  // delay in between reads for stability

  // brightness = map(analogRead(analogRead(average)), 0, 1023, 0, 255);

  // if(brightness >= 240){
  //   strip.setBrightness(240);
  // } else if (brightness >= 217){
  //   strip.setBrightness(217);
  // } else if (brightness >= 194){
  //   strip.setBrightness(194);
  // } else if (brightness >= 171){
  //   strip.setBrightness(171);
  // } else if (brightness >= 148){
  //   strip.setBrightness(148);
  // } else if (brightness >= 115){
  //   strip.setBrightness(115);
  // } else if (brightness >= 102){
  //   strip.setBrightness(102);
  // } else if (brightness >= 79){
  //   strip.setBrightness(79);
  // } else if (brightness >= 56){
  //   strip.setBrightness(56);
  // } else if (brightness >= 33){
  //   strip.setBrightness(33);
  // } else if (brightness >= 10){
  //   strip.setBrightness(10);
  // } else {
  //   strip.setBrightness(10);
  // }
  int brightPressed = digitalRead(bright);
  // Serial.println(brightPressed);
  if (brightPressed == LOW) {
    brightSetting -= 1;
    if (brightSetting < 1) {
      brightSetting = numBrightSettings;
    }
    strip.setBrightness((brightSetting * 255 / numBrightSettings) + 5);
    // Serial.println((brightSetting * 255 / numBrightSettings) + 5);
    delay(200);
  }

  int lightPressed = digitalRead(light);
  if (lightPressed == 1) {
    lightSetting += 1;
    strip.clear();
    // strip.setBrightness(255);
    delay(200);
  }
  if (lightSetting > numLightSettings) {
    lightSetting = 0;
  }
  if (lightSetting == 1) {
    strip.fill(white, 0, numPixels);
    strip.show();
  } else if (lightSetting == 2) {
    strip.fill(graySky, 0, numPixels);
    strip.show();
  } else if (lightSetting == 3) {
    strip.fill(graySky, 0, numPixels);
    lightning(strip.Color(231, 221, 18), 1);
  }
  // else if (lightSetting == 3) {
  //   strip.fill(coolGreen, 0, numPixels);
  //   strip.show();
  // }
  else if (lightSetting == 4) {
    strips_loop();
  } else if (lightSetting == 5) {
    strips_loop1();
  }
  // else if (lightSetting == 6) {
  //   strip.clear();
  //   strips_loop2();
  // }
  else if (lightSetting == 6) {
    rainbow(10);
  } else {
    strip.clear();
    strip.show();
  }
}
//////////////////////////////////////
void rainbow(int wait) {

  ////////////
  static int n = 0;
  //static int timesRun = 0;
  for (int i = 0; i < strip.numPixels(); i++) {
    int pixelHue = n + (i * 65536 / strip.numPixels());
    strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
  }
  strip.show();
  delay(wait);
  n += 256;
  if (n >= 65536) {
    n = 0;
  }
  Serial.println(digitalRead(bright));
}
/////////////////////////////////////

class Strip {
public:
  uint8_t effect;
  uint8_t effects;
  uint16_t effStep;
  unsigned long effStart;
  Adafruit_NeoPixel strip;
  Strip(uint16_t leds, uint8_t pin, uint8_t toteffects, uint16_t striptype)
    : strip(leds, pin, striptype) {
    effect = -1;
    effects = toteffects;
    Reset();
  }
  void Reset() {
    effStep = 0;
    effect = (effect + 1) % effects;
    effStart = millis();
  }
};

struct Loop {
  uint8_t currentChild;
  uint8_t childs;
  bool timeBased;
  uint16_t cycles;
  uint16_t currentTime;
  Loop(uint8_t totchilds, bool timebased, uint16_t tottime) {
    currentTime = 0;
    currentChild = 0;
    childs = totchilds;
    timeBased = timebased;
    cycles = tottime;
  }
};

Strip strip_0(151, 6, 151, NEO_GRB + NEO_KHZ800);
struct Loop strip0loop0(1, false, 1);

void strips_loop() {
  if (strip0_loop0() & 0x01)
    strip_0.strip.show();
}

uint8_t strip0_loop0() {
  uint8_t ret = 0x00;
  switch (strip0loop0.currentChild) {
    case 0:
      ret = strip0_loop0_eff0();
      break;
  }
  if (ret & 0x02) {
    ret &= 0xfd;
    if (strip0loop0.currentChild + 1 >= strip0loop0.childs) {
      strip0loop0.currentChild = 0;
      if (++strip0loop0.currentTime >= strip0loop0.cycles) {
        strip0loop0.currentTime = 0;
        ret |= 0x02;
      }
    } else {
      strip0loop0.currentChild++;
    }
  };
  return ret;
}

uint8_t strip0_loop0_eff0() {
  // Strip ID: 0 - Effect: Rainbow - LEDS: 151
  // Steps: 60 - Delay: 20
  // Colors: 3 (157.30.255, 0.9.255, 20.255.0)
  // Options: rainbowlen=60, toLeft=true,
  if (millis() - strip_0.effStart < 20 * (strip_0.effStep)) return 0x00;
  float factor1, factor2;
  uint16_t ind;
  for (uint16_t j = 0; j < 151; j++) {
    ind = strip_0.effStep + j * 1;
    switch ((int)((ind % 60) / 20)) {
      case 0:
        factor1 = 1.0 - ((float)(ind % 60 - 0 * 20) / 20);
        factor2 = (float)((int)(ind - 0) % 60) / 20;
        strip_0.strip.setPixelColor(j, 157 * factor1 + 0 * factor2, 30 * factor1 + 9 * factor2, 255 * factor1 + 255 * factor2);
        break;
      case 1:
        factor1 = 1.0 - ((float)(ind % 60 - 1 * 20) / 20);
        factor2 = (float)((int)(ind - 20) % 60) / 20;
        strip_0.strip.setPixelColor(j, 0 * factor1 + 20 * factor2, 9 * factor1 + 255 * factor2, 255 * factor1 + 0 * factor2);
        break;
      case 2:
        factor1 = 1.0 - ((float)(ind % 60 - 2 * 20) / 20);
        factor2 = (float)((int)(ind - 40) % 60) / 20;
        strip_0.strip.setPixelColor(j, 20 * factor1 + 157 * factor2, 255 * factor1 + 30 * factor2, 0 * factor1 + 255 * factor2);
        break;
    }
  }
  if (strip_0.effStep >= 60) {
    strip_0.Reset();
    return 0x03;
  } else strip_0.effStep++;
  return 0x01;
}
/////////////////////////////////////////////////////////

void lightning(uint32_t aColor, int waitTime) {
  static int index = 0;
  static unsigned long startTime = millis();

  strip.setPixelColor(index, aColor);
  strip.show();

  if (millis() - startTime >= waitTime) {
    strip.setPixelColor(index, 5, 8, 11);
    index++;
    startTime = millis();

    // if (index >= strip.numPixels()) {
    //   index = 0;
    // }
    if (index >= numPixels) {
      index = 0;
    }
  }
}
/////////////////////////////////////////
///////////////////////////////////////
void strips_loop1() {
  if (strip0_loop1() & 0x01)
    strip_0.strip.show();
}

uint8_t strip0_loop1() {
  uint8_t ret = 0x00;
  switch (strip0loop0.currentChild) {
    case 0:
      ret = strip0_loop0_eff1();
      break;
  }
  if (ret & 0x02) {
    ret &= 0xfd;
    if (strip0loop0.currentChild + 1 >= strip0loop0.childs) {
      strip0loop0.currentChild = 0;
      if (++strip0loop0.currentTime >= strip0loop0.cycles) {
        strip0loop0.currentTime = 0;
        ret |= 0x02;
      }
    } else {
      strip0loop0.currentChild++;
    }
  };
  return ret;
}

uint8_t strip0_loop0_eff1() {
  // Strip ID: 0 - Effect: Rainbow - LEDS: 151
  // Steps: 60 - Delay: 20
  // Colors: 3 (255.0.247, 0.255.246, 14.0.255)
  // Options: rainbowlen=60, toLeft=true,
  if (millis() - strip_0.effStart < 20 * (strip_0.effStep)) return 0x00;
  float factor1, factor2;
  uint16_t ind;
  for (uint16_t j = 0; j < 151; j++) {
    ind = strip_0.effStep + j * 1;
    switch ((int)((ind % 60) / 20)) {
      case 0:
        factor1 = 1.0 - ((float)(ind % 60 - 0 * 20) / 20);
        factor2 = (float)((int)(ind - 0) % 60) / 20;
        strip_0.strip.setPixelColor(j, 255 * factor1 + 0 * factor2, 0 * factor1 + 255 * factor2, 247 * factor1 + 246 * factor2);
        break;
      case 1:
        factor1 = 1.0 - ((float)(ind % 60 - 1 * 20) / 20);
        factor2 = (float)((int)(ind - 20) % 60) / 20;
        strip_0.strip.setPixelColor(j, 0 * factor1 + 14 * factor2, 255 * factor1 + 0 * factor2, 246 * factor1 + 255 * factor2);
        break;
      case 2:
        factor1 = 1.0 - ((float)(ind % 60 - 2 * 20) / 20);
        factor2 = (float)((int)(ind - 40) % 60) / 20;
        strip_0.strip.setPixelColor(j, 14 * factor1 + 255 * factor2, 0 * factor1 + 0 * factor2, 255 * factor1 + 247 * factor2);
        break;
    }
  }
  if (strip_0.effStep >= 60) {
    strip_0.Reset();
    return 0x03;
  } else strip_0.effStep++;
  return 0x01;
}
////////////////////////////
void strips_loop2() {
  if (strip0_loop2() & 0x01)
    strip_0.strip.show();
}

uint8_t strip0_loop2() {
  uint8_t ret = 0x00;
  switch (strip0loop0.currentChild) {
    case 0:
      ret = strip0_loop0_eff2();
      break;
  }
  if (ret & 0x02) {
    ret &= 0xfd;
    if (strip0loop0.currentChild + 1 >= strip0loop0.childs) {
      strip0loop0.currentChild = 0;
      if (++strip0loop0.currentTime >= strip0loop0.cycles) {
        strip0loop0.currentTime = 0;
        ret |= 0x02;
      }
    } else {
      strip0loop0.currentChild++;
    }
  };
  return ret;
}

uint8_t strip0_loop0_eff2() {
  // Strip ID: 0 - Effect: Rainbow - LEDS: 150
  // Steps: 60 - Delay: 20
  // Colors: 3 (255.0.0, 0.255.0, 0.0.255)
  // Options: rainbowlen=60, toLeft=true,
  if (millis() - strip_0.effStart < 20 * (strip_0.effStep)) return 0x00;
  float factor1, factor2;
  uint16_t ind;
  for (uint16_t j = 0; j < 150; j++) {
    ind = strip_0.effStep + j * 1;
    switch ((int)((ind % 60) / 20)) {
      case 0:
        factor1 = 1.0 - ((float)(ind % 60 - 0 * 20) / 20);
        factor2 = (float)((int)(ind - 0) % 60) / 20;
        strip_0.strip.setPixelColor(j, 255 * factor1 + 0 * factor2, 0 * factor1 + 255 * factor2, 0 * factor1 + 0 * factor2);
        break;
      case 1:
        factor1 = 1.0 - ((float)(ind % 60 - 1 * 20) / 20);
        factor2 = (float)((int)(ind - 20) % 60) / 20;
        strip_0.strip.setPixelColor(j, 0 * factor1 + 0 * factor2, 255 * factor1 + 0 * factor2, 0 * factor1 + 255 * factor2);
        break;
      case 2:
        factor1 = 1.0 - ((float)(ind % 60 - 2 * 20) / 20);
        factor2 = (float)((int)(ind - 40) % 60) / 20;
        strip_0.strip.setPixelColor(j, 0 * factor1 + 255 * factor2, 0 * factor1 + 0 * factor2, 255 * factor1 + 0 * factor2);
        break;
    }
  }
  if (strip_0.effStep >= 60) {
    strip_0.Reset();
    return 0x03;
  } else strip_0.effStep++;
  return 0x01;
}
