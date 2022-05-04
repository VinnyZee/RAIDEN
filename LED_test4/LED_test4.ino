// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define LED_PIN1        2 // middle
#define LED_PIN2        13 //back
#define LED_PIN3        15 //front

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 13 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(NUMPIXELS, LED_PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3(NUMPIXELS, LED_PIN3, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels2.begin();
  pixels3.begin();
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'
  pixels2.clear();
  pixels3.clear();

//   The first NeoPixel in a strand is #0, second is 1, all the way up
//   to the count of pixels minus one.
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

//    pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
//    Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(15, 34, 87));
    pixels2.setPixelColor(i, pixels2.Color(90, 78, 0));
    pixels3.setPixelColor(i, pixels3.Color(50, 0, 100));

    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(5);
    pixels2.show();
    delay(5);
    pixels3.show();

    delay(DELAYVAL); // Pause before next pass through loop
  }
}
