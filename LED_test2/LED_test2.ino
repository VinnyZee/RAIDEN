#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN        2
#define NUMPIXELS  5

Adafruit_NeoPixel pixels(7, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  
#endif

  Serial.begin(115200);
  pixels.begin();
  //pixels.setPixelColor(2, pixels.Color(0, 255, 0));
  pixels.show();
}

int numIter = 0;

void loop() {
//  pixels.clear();
//
//  for(int i=0; i< NUMPIXELS; i++) {
//    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
//    pixels.show();
//    delay(DELAYVAL);
//  }
//  //numIter += 1;
//  delay(DELAYVAL);
//  Serial.print(numIter);
}
