/*
 * Minna Roberto
 * Arduino Maze with Magnetic Contact Sensors Project
 * December 6, 2019
*/

#include <Servo.h>

Servo servo1;
Servo servo2;

int joyX = 1;
int joyY = 0;
int joyVal;

const int led1 = 1;
const int led2 = 2; 
const int led2 = 4; 

const int sensor1 = 6;
const int sensor2 = 7;
const int sensor3 = 8; 

//checkpoints: check whether a magnet sensor is closed or not
int checkpoint1; 
int checkpoint2; 
int checkpoint3; 

void setup() {

  servo1.attach(3);
  servo2.attach(5);

  pinMode(sensor1, INPUT_PULLUP);
  pinMode(sensor2, INPUT_PULLUP);
  pinMode(sensor3, INPUT_PULLUP);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
    joyVal = analogRead(joyX);
    joyVal = map(joyVal, 0, 1023, 0, 179);
    servo1.write(joyVal);

    joyVal = analogRead(joyY);
    joyVal = map(joyVal, 0, 1023, 0, 179);
    servo2.write(joyVal);
  
    delay(15);


    checkpoint1 = digitalRead(sensor1); 
    checkpoint2 = digitalRead(sensor2);
    checkpoint3 = digitalRead(sensor3);

    //check if a magnet sensor is in contact with a magnet
    if (checkpoint1 == LOW){
     digitalWrite(led1, HIGH); //turn an led on
    }
    else{
      digitalWrite(led1, LOW); //led is off
    }
  
    //check if a magnet sensor is in contact with a magnet
    if (checkpoint2 == LOW){
      digitalWrite(led2, HIGH);
    }
    else{
     digitalWrite(led2, LOW);
    }
  
    //check if a magnet sensor is in contact with a magnet
    if (checkpoint3 == LOW){
      digitalWrite(led3, HIGH);
    }
    else{
      digitalWrite(led3, LOW);
    }
    delay(200);
}
