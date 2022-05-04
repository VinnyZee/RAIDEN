#include "Freenove_WS2812_Lib_for_ESP32.h"

#define LEDS_COUNT  13
#define LEDS_PIN1  2
#define LEDS_PIN2  13
#define LEDS_PIN3  15
#define CHANNEL   0

//Freenove_ESP32_WS2812 strip1 = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN1, CHANNEL);
Freenove_ESP32_WS2812 strip2 = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN2, CHANNEL);
//Freenove_ESP32_WS2812 strip3 = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN3, CHANNEL);
void setup() {
  strip2.begin();
}

void loop() {
  for (int j = 0; j < 255; j += 2) {
    for (int i = 0; i < LEDS_COUNT; i++) {
      strip2.setLedColorData(i, strip2.Wheel((i * 256 / LEDS_COUNT + j) & 255));
    }
    strip2.show();
    delay(2);
  }  
}
