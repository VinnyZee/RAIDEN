#include <Adafruit_PCT2075.h>  // Temperature sennsor library
#include <Wire.h>  // Arduino I2C library
#include <WiFi.h>  // ESP32 WiFi library

// I2C pins
#define I2C_SDA 15
#define I2C_SCL 16

// LED pins
#define LED_R 11
#define LED_G 12
#define LED_B 10

// ALS pin
#define ALS_PIN 9

// Setup for RGB smooth color switching
int redangle = 0;
int greenangle = 120;
int blueangle = 240;

// Setup for ALS and temp sensor
double als_intensity_max = 1.0;
double cur = 1.0;

// Declare an instance of the temp sensor
Adafruit_PCT2075 PCT2075;

// Define WiFi access point name and password
const char *ssid = "Vincent_Zheng"; // REMOVE "String(esp_random()).c_str()" and put your name in the format "First_Last"
const char *password = "123456789"; // CHOOSE A UNIQUE PASSWORD


// The setup routine runs once when you press reset or the board is reset automatically:
void setup() {
  PCT2075 = Adafruit_PCT2075();
  // Begin serial communication over UART->USB at 115200 baud rate (Hz)
  Serial.begin(115200);

  // Initialize I2C interface for temp sensor
  Wire.begin(I2C_SDA, I2C_SCL);

  // Check the temp sensor is present and responding to I2C messages
  if (!PCT2075.begin(PCT2075_I2CADDR_DEFAULT, &Wire)) {
    Serial.println("Couldn't find PCT2075 chip");
    while(1);  // Do not execute the rest of the program if the temp sensor is not present; loop indefinitely
  }
  Serial.println("Found PCT2075 chip");
  
  // Initialize the digital pins for the LEDs as output so we can pull them high and low
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  
  // Initialize the pin for the ALS as an input so we can read it with the ADC
  pinMode(ALS_PIN, INPUT);
  
  // Setup ESP32 as a Wifi access point
  WiFi.softAP(ssid, password);
}

// Helper function to set the PWM output for an LED
void angleOut(int angle, int pin) {
  if (angle > 0 && angle < 120) {
    analogWrite(pin, angle*255/120);
  } else if (angle >= 120 && angle < 240) {
    analogWrite(pin, (240-angle)*255/120);
  } else {
    analogWrite(pin, 0);
  }
}

// The loop routine runs over and over again forever:
void loop() {

  // RGB LED
  angleOut(redangle, LED_R);
  angleOut(greenangle, LED_G);
  angleOut(blueangle, LED_B);
  redangle = (redangle + 5) % 360; 
  greenangle = (greenangle + 5) % 360; 
  blueangle = (blueangle + 5) % 360; 
  delay(10);

  
  // Touch sensors
  Serial.println("---");
  Serial.print("Capacitive touch 1: "); Serial.println(touchRead(T1));
  Serial.print("Capacitive touch 2: "); Serial.println(touchRead(T2));
  Serial.print("Capacitive touch 3: "); Serial.println(touchRead(T14));
  if (touchRead(T1) > 50000) {
    redangle = 0;
  }
  if (touchRead(T2) > 50000) {
    greenangle = 0;
  }
  if (touchRead(T14) > 50000) {
    blueangle = 0;
  }
  delay(10);
  
  // Ambient Light sensor
  cur = analogRead(ALS_PIN);
  als_intensity_max = max(cur, als_intensity_max);
  Serial.print("ALS intensity: "); Serial.println((cur / als_intensity_max) * 255);
  delay(10);

  // Temperature sensors
  Serial.print("Temperature: "); Serial.print(PCT2075.getTemperature());Serial.println(" C");

  // Display ESP Wifi IP Address
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("ESP32-S2 IP: "); Serial.println(myIP);

  
  delay(100);  // Wait 100ms (0.1 seconds)
}
