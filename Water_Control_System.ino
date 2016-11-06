
/*
   Water Control System
   Twice daily open external valve

   created 18 July 2016
   modified 28 July 2016
   by Aiden Gallagher & Alastair Cooper
*/

#include <Time.h>
#include <String.h>
#include <Servo.h>
Servo valveServo;
const int servoPower = 7;
const int ledPin = 13;
int timeHour = 0;
int timeMinute = 0;
int waterTap = 0;
const int waitTimeOn = 8500;
const int waitTimeOff = 2000;

// set up runs upon reset or powering on of the board
void setup() {
  //initialize digital output
  //set the current time
  setTime(07,57,20,22,8,2016);
  //attach the valve servo
  valveServo.attach(9);
  //set the valve to the initial state of 0
  valveServo.write(waterTap);
  Serial.begin(9600);
  pinMode(servoPower, OUTPUT);
  //flash the LED pin
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
}

// loop functions run continuously
void loop() {
  timeHour = hour();
  timeMinute = minute();
  Serial.print(timeHour);
  Serial.print(":");
  Serial.print(timeMinute);
  Serial.println();
  //if one of the two watering times
  if ((timeHour == 7) && (timeMinute == 57)){
    //put power on for the servo and turn on the light
    digitalWrite(servoPower, LOW);
    digitalWrite(ledPin, HIGH);
    //increment the tap value by one until open
    while(waterTap != 75){
      valveServo.write(waterTap);
      waterTap++;
      delay(150);
    }
    delay(waitTimeOn);
    //decrement the tap value by one until closed
    while(waterTap != 0){
      valveServo.write(waterTap);
      waterTap--;
      delay(150);
    }
    delay(waitTimeOff);
    while(waterTap != 75){
      valveServo.write(waterTap);
      waterTap++;
      delay(150);
    }
    delay(waitTimeOn);
    //decrement the tap value by one until closed
    while(waterTap != 0){
      valveServo.write(waterTap);
      waterTap--;
      delay(150);
    }
     digitalWrite(servoPower, HIGH);
     delay(5500);
  }
  else if ((timeHour == 19) && (timeMinute == 45)){
    //put power on for the servo and turn on the light
    digitalWrite(servoPower, LOW);
    digitalWrite(ledPin, HIGH);
    //increment the tap value by one until open
    while(waterTap != 75){
      valveServo.write(waterTap);
      waterTap++;
      delay(150);
    }
    delay(waitTimeOn);
    //decrement the tap value by one until closed
    while(waterTap != 0){
      valveServo.write(waterTap);
      waterTap--;
      delay(150);
    }
    delay(waitTimeOff);
    while(waterTap != 75){
      valveServo.write(waterTap);
      waterTap++;
      delay(150);
    }
    delay(waitTimeOn);
    //decrement the tap value by one until closed
    while(waterTap != 0){
      valveServo.write(waterTap);
      waterTap--;
      delay(150);
    }
     digitalWrite(servoPower, HIGH);
     delay(5000);
  }
  else{
    //turn off the servo and light
    digitalWrite(servoPower, HIGH);
    digitalWrite(ledPin, LOW);
  }
  //check the time once every minute
  delay(60000);
}

