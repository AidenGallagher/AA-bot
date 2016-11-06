/*
 * motors controlled by Photo Resistor
 * 
 * modified 11 April 2016
 * by Aiden Gallagher
 */

 const int LedPin = 13;
 const int leftMotor = 26;
 const int rightMotor = 6;
 const int pResistor = A0;
 int resistorValue;

// set up runs upon reset or powering on of the board
void setup(){
    //initialize digital output
    Serial.begin(9600);
    pinMode(LedPin, OUTPUT);
    pinMode(leftMotor, OUTPUT);
    pinMode(rightMotor, OUTPUT);
    //initialize analog input
    pinMode(pResistor, INPUT);
}

// loop functions run continuously
void loop(){
  resistorValue = analogRead(pResistor);
  Serial.print(resistorValue);
  if(resistorValue > 500){
    digitalWrite(LedPin, LOW);
    digitalWrite(leftMotor, HIGH);
    digitalWrite(rightMotor, HIGH);
  } else {
    digitalWrite(LedPin, HIGH);
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, LOW);
  }
  delay(2000);
}

