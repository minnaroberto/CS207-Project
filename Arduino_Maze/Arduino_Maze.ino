/*
 * Minna Roberto
 * Arduino Maze with Magnetic Contact Sensors Project
 * December 6, 2019
*/

#include <Servo.h>

Servo servo1; //servo to control the x-axis
Servo servo2; //servo to control the y-axis

int joyX = 1; //joystick controlling x-axis wired to analog 1
int joyY = 0; //joystick controlling y-axis wired to analog 0
int joyVal; //degree of the joystick being moved

//leds and their assigned pins
const int led1 = 1;
const int led2 = 2; 
const int led3 = 4; 

//magnet sensors and their assigned pins
const int sensor1 = 6;
const int sensor2 = 7;
const int sensor3 = 8; 

//checkpoints: check whether a magnet sensor is closed or not
int checkpoint1; 
int checkpoint2; 
int checkpoint3; 

void setup() {

  servo1.attach(3); //attach the servo to pin 3
  servo2.attach(5); //attach the servo to pin 5

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
      digitalWrite(led2, HIGH); //turn an led on
    }
    else{
     digitalWrite(led2, LOW); //led is off
    }
  
    //check if a magnet sensor is in contact with a magnet
    if (checkpoint3 == LOW){
      digitalWrite(led3, HIGH); //turn an led on
    }
    else{
      digitalWrite(led3, LOW); //led is off  
    }
    delay(200);
}
