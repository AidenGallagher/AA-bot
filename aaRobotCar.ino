/*
 * AA-bot Robot Car
 * 
 * created 14 November 2016
 * modified 8 December 2016
 * by Aiden Gallagher & Alastair Cooper
 */

 const int LedPin = 13;
 const int leftRelay1 = 10;
 const int leftRelay2 = 8;
 const int rightRelay1 = 6; 
 const int rightRelay2 = 4;
 const int pResistorFront1 = A0;
 const int pResistorFront2 = A1;
 int resistorValue;

// set up runs upon reset or powering on of the board
void setup(){
    //initialize digital output
    pinMode(LedPin, OUTPUT);
    pinMode(leftRelay1, OUTPUT);
    pinMode(leftRelay2, OUTPUT);
    pinMode(rightRelay1, OUTPUT);
    pinMode(rightRelay2, OUTPUT);
    
    //initialize analog input
    pinMode(pResistorFront1, INPUT);
    pinMode(pResistorFront2, INPUT);
}

// loop functions run continuously
void loop(){

  standStill();
  delay(1000);
  goForwards();
  delay(1000);
  wideForwardRightTurn();
  wideForwardLeftTurn();
  goBackwards();
  delay(1000);
  tightLeftTurn();
  tightRightTurn();
  goForwards();
  delay(1000);
  goBackwards();
  delay(1000);
  standStill();
  wideBackwardRightTurn();
  wideBackwardLeftTurn();
  standstill();
}

void standStill(){
 digitalWrite(leftRelay1, HIGH);
 digitalWrite(leftRelay2, HIGH);
 digitalWrite(rightRelay1, HIGH);
 digitalWrite(rightRelay2, HIGH);

}
void goBackwards(){
 digitalWrite(leftRelay1, LOW);
 digitalWrite(leftRelay2, HIGH);
 digitalWrite(rightRelay1, LOW);
 digitalWrite(rightRelay2, HIGH);
}

void goForwards(){
 digitalWrite(leftRelay1, HIGH);
 digitalWrite(leftRelay2, LOW);
 digitalWrite(rightRelay1, HIGH);
 digitalWrite(rightRelay2, LOW);
}

void wideForwardLeftTurn(){
 digitalWrite(leftRelay1, HIGH);
 digitalWrite(leftRelay2, HIGH);
 digitalWrite(rightRelay1, HIGH);
 digitalWrite(rightRelay2, LOW);
 delay(1000);
}

void wideBackwardLeftTurn(){
 digitalWrite(leftRelay1, HIGH);
 digitalWrite(leftRelay2, HIGH);
 digitalWrite(rightRelay1, LOW);
 digitalWrite(rightRelay2, HIGH);
 delay(1000);
}

void wideForwardRightTurn(){
 digitalWrite(leftRelay1, HIGH);
 digitalWrite(leftRelay2, LOW);
 digitalWrite(rightRelay1, HIGH);
 digitalWrite(rightRelay2, HIGH);
 delay(1000);
}

void wideBackwardRightTurn(){
 digitalWrite(leftRelay1, LOW);
 digitalWrite(leftRelay2, HIGH);
 digitalWrite(rightRelay1, HIGH);
 digitalWrite(rightRelay2, HIGH);
 delay(1000);
}

void tightLeftTurn(){
 digitalWrite(leftRelay1, LOW);
 digitalWrite(leftRelay2, HIGH);
 digitalWrite(rightRelay1, HIGH);
 digitalWrite(rightRelay2, LOW);
 delay(1000);
}

void tightRightTurn(){
 digitalWrite(leftRelay1, HIGH);
 digitalWrite(leftRelay2, LOW);
 digitalWrite(rightRelay1, LOW);
 digitalWrite(rightRelay2, HIGH);
 delay(1000);
}

