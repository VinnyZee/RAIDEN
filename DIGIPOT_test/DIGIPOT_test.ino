#include <Wire.h>

//I2C pins
#define I2C_SDA 16
#define I2C_SCL 4

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin(I2C_SDA, I2C_SCL);
//  Wire.beginTransmission(40);
//  Wire.write(byte(0b01000001));
//  Wire.write(byte(0xff));
//  Wire.endTransmission();
//  Wire.write(byte(0b10010000));
//  Wire.write(byte(0x00));
//  Wire.endTransmission();
  Serial.println("Done");
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(40);
  Wire.write(byte(0b00000011));
  Wire.write(byte(0xff));
  Wire.endTransmission();
  delay(1000);
  Wire.beginTransmission(40);
  Wire.write(byte(0b00000000));
  Wire.write(byte(0x00));
  Wire.endTransmission();
  delay(1000);
}
