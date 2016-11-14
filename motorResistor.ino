/*
 * motors controlled by Photo Resistor
 * 
 * modified 14 November 2016
 * by Aiden Gallagher & Alastair Cooper
 */

 const int LedPin = 13;
 const int leftMotor1 = 4;
 const int leftMotor2 = 5;
 const int rightMotor1 = 6;
 const int rightMotor2 = 7;
 const int pResistorFront1 = A0;
 const int pResistorFront2 = A1;
 int resistorValue;

// set up runs upon reset or powering on of the board
void setup(){
    //initialize digital output
    Serial.begin(9600);
    pinMode(LedPin, OUTPUT);
    pinMode(leftMotor1, OUTPUT);
    pinMode(leftMotor2, OUTPUT);
    pinMode(rightMotor1, OUTPUT);
    pinMode(rightMotor2, OUTPUT);
    //initialize analog input
    pinMode(pResistorFront1, INPUT);
    pinMode(pResistorFront2, INPUT);
}

// loop functions run continuously
void loop(){
  /*resistorValue = (analogRead(pResistorFront1) + analogRead(pResistorFront2));
  Serial.print(resistorValue);
  if(resistorValue > 500){
   digitalWrite(LedPin, LOW);
   goBackwards();
  } else {
    digitalWrite(LedPin, HIGH);
    goForwards();
  }
  */
  goForwards();
  delay(3000);
  goBackwards();
  delay(3000);
}

void goForwards(){
 digitalWrite(leftMotor1, LOW);
 digitalWrite(leftMotor2, LOW);
 digitalWrite(rightMotor1, LOW);
 digitalWrite(rightMotor2, LOW);
}
void goBackwards(){
 digitalWrite(leftMotor1, HIGH);
 digitalWrite(leftMotor2, HIGH);
 digitalWrite(rightMotor1, HIGH);
 digitalWrite(rightMotor2, HIGH);
}
