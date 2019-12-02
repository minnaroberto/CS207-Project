/*
 * Minna Roberto
 * Arduino Maze Project
 * test check
 */

#include <Servo.h>

Servo servo1;
Servo servo2;

int joyX = 1;
int joyY = 0;

int joyVal;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(3);
  servo2.attach(5);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly

    joyVal = analogRead(joyX);
    joyVal = map(joyVal, 0, 1023, 0, 179);
    servo1.write(joyVal);

    joyVal = analogRead(joyY);
    joyVal = map(joyVal, 0, 1023, 0, 179);
    servo2.write(joyVal);
  
      delay(15);
}
