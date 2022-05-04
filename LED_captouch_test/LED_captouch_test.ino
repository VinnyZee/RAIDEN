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

// Pin numbers for the Capacitive Gesture Pad.
#define CPAD1 18 //swipe up
#define CPAD2 19 //tap
#define CPAD3 21 //swipe down
#define CPAD4 22 //swipe back
#define CPAD5 23 //swipe forward

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(NUMPIXELS, LED_PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3(NUMPIXELS, LED_PIN3, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 100 // Time (in milliseconds) to pause between pixels

void setup() {
  Serial.begin(115200);
  pinMode(CPAD1, INPUT);
  pinMode(CPAD2, INPUT);
  pinMode(CPAD3, INPUT);
  pinMode(CPAD4, INPUT);
  pinMode(CPAD5, INPUT);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels2.begin();
  pixels3.begin();
  pixels.clear(); // Set all pixel colors to 'off'
  pixels2.clear();
  pixels3.clear();  
}

  int G1 = 0;
  int R1 = 0;
  int BLUE1 = 0;
  int G2 = 0;
  int R2 = 0;
  int B2 = 0;
  int G3 = 0;
  int R3 = 0;
  int B3 = 0;
  int brightness = 0;
  int s = 0;

void loop() {
  if (digitalRead(CPAD1)) {
    Serial.println("swipe up");
    if (brightness < 0) {
      brightness = brightness + .01;
    }
  }
  if (digitalRead(CPAD2)) {
    Serial.println("tap");
    s = (s + 1) % 2;
  }
  if (digitalRead(CPAD3)) {
    Serial.println("swipe down");
    if (brightness > 0) {
      brightness = brightness - .01;
    }
  }
  if (digitalRead(CPAD4)) {
    Serial.println("swipe left");
    if (s == 0) {
      G1 = (G1 - 5) % 255;
      G2 = (G2 - 5) % 255;
      G3 = (G3 - 5) % 255;
    } else if (s == 1) {
      R1 = (R1 - 5) % 255;
      R2 = (R2 - 5) % 255;
      R3 = (R3 - 5) % 255;
    } else {
      BLUE1 = (BLUE1 - 5) % 255;
      B2 = (B2 - 5) % 255;
      B3 = (B3 - 5) % 255;
    }
  }
  if (digitalRead(CPAD5)) {
    Serial.println("swipe right");
    if (s == 0) {
      G1 = (G1 + 5) % 255;
      G2 = (G2 + 5) % 255;
      G3 = (G3 + 5) % 255;
    } else if (s == 1) {
      R1 = (R1 + 5) % 255;
      R2 = (R2 + 5) % 255;
      R3 = (R3 + 5) % 255;
    } else {
      BLUE1 = (BLUE1 + 5) % 255;
      B2 = (B2 + 5) % 255;
      B3 = (B3 + 5) % 255;
    }
  }
    for (int i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(G1, R1, BLUE1));
      pixels2.setPixelColor(i, pixels2.Color(G2, R2, B2));
      pixels3.setPixelColor(i, pixels3.Color(G3, R3, B3));
    }

    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(5);
    pixels2.show();
    delay(5);
    pixels3.show();

    delay(DELAYVAL); // Pause before next pass through loop
}
