#define CPAD1 18 //swipe up
#define CPAD2 19 //tap
#define CPAD3 21 //swipe down
#define CPAD4 22 //swipe back
#define CPAD5 23 //swipe forward

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(CPAD1, INPUT);
  pinMode(CPAD2, INPUT);
  pinMode(CPAD3, INPUT);
  pinMode(CPAD4, INPUT);
  pinMode(CPAD5, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//  Serial.println("swipe up:");
//  Serial.println(digitalRead(CPAD1));
//  Serial.println("tap:");
//  Serial.println(digitalRead(CPAD2));
  if (digitalRead(CPAD1)) {
    Serial.println("swipe up");
  }
  if (digitalRead(CPAD2)) {
    Serial.println("tap");
  }
  if (digitalRead(CPAD3)) {
    Serial.println("swipe down");
  }
  if (digitalRead(CPAD4)) {
    Serial.println("swipe back");
  }
  if (digitalRead(CPAD5)) {
    Serial.println("swipe forward");
  }
  delay(10);
}
