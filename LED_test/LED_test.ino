#include <FastLED.h>

#define NUM_LEDS 13
#define LED_PIN1 2
#define LED_PIN2 13
#define LED_PIN3 15
#define LED_BRIGHTNESS 50

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN1, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(LED_BRIGHTNESS);
  FastLED.clear();
}

void loop() {
  //leds[0] = CRGB::Red;
  //leds[1] = CRGB::Green;
//  leds[2] = CRGB::Blue;
//  leds[3] = CRGB::Red;
//  leds[4] = CRGB::Green;
//  leds[5] = CRGB::Blue;
//  leds[6] = CRGB::Red;
//  leds[7] = CRGB::Green;
//  leds[8] = CRGB::Blue;
//  leds[9] = CRGB::Red;
//  leds[10] = CRGB::Green;
//  leds[11] = CRGB::Blue;
//  leds[12] = CRGB::Red;
  FastLED.clear();
  delay(50);
}
