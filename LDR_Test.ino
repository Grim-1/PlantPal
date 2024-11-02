#include <Servo.h>
#include <Wire.h>

const int ldrLeft = A0;
const int ldrCenter = A1;
const int ldrRight = A2;
const int motorLeftForward = 9;
const int motorLeftBackward = 10;
const int motorRightForward = 11;
const int motorRightBackward = 12;
const int lightThreshold = 900;  

void setup() {
    Serial.begin(9600);
    pinMode(ldrLeft, INPUT);
    pinMode(ldrCenter, INPUT);
    pinMode(ldrRight, INPUT);
    pinMode(motorLeftForward, OUTPUT);
    pinMode(motorLeftBackward, OUTPUT);
    pinMode(motorRightForward, OUTPUT);
    pinMode(motorRightBackward, OUTPUT);
    Serial.println("Bot test started - Testing LDR and motor functionality.");
  }
void loop() {
  
  int leftLight = analogRead(ldrLeft);
  int centerLight = analogRead(ldrCenter);
  int rightLight = analogRead(ldrRight);
  Serial.print("Left LDR: ");
  Serial.print(leftLight);
  Serial.print(" | Center LDR: ");
  Serial.print(centerLight);
  Serial.print(" | Right LDR: ");
  Serial.println(rightLight);
  if (centerLight < lightThreshold) {
    moveForward();
    Serial.println("Moving Forward");
  } else if (leftLight < rightLight) {
    turnRight(); 
    Serial.println("Turning Right");
  } else if (rightLight < leftLight) {
    turnLeft(); 
    Serial.println("Turning Left");
  } else {
    stopMovement(); 
    Serial.println("Stopping");
  }

  delay(5000);

void moveForward() {
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorRightForward, HIGH);
  digitalWrite(motorRightBackward, LOW);
}

void turnLeft() {
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorLeftBackward, HIGH);
  digitalWrite(motorRightForward, HIGH);
  digitalWrite(motorRightBackward, LOW);
}

void turnRight() {
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorRightForward, LOW);
  digitalWrite(motorRightBackward, HIGH);
}

void stopMovement() {
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorRightForward, LOW);
  digitalWrite(motorRightBackward, LOW);
}