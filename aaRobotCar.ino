/*
 * AA-bot Robot Car
 * 
 * created 14 November 2016
 * modified 4 December 2016
 * by Aiden Gallagher & Alastair Cooper
 */

 const int LedPin = 13;
 const int leftReverse = 4;
 const int rightReverse = 5;
 const int leftPower = 9;
 const int rightPower = 10;
 const int pResistorFront1 = A0;
 const int pResistorFront2 = A1;
 int resistorValue;

// set up runs upon reset or powering on of the board
void setup(){
    //initialize digital output
    pinMode(LedPin, OUTPUT);
    pinMode(leftReverse, OUTPUT);
    pinMode(rightReverse, OUTPUT);
    pinMode(leftPower, OUTPUT);
    pinMode(rightPower, OUTPUT);
    
    //initialize analog input
    pinMode(pResistorFront1, INPUT);
    pinMode(pResistorFront2, INPUT);
}

// loop functions run continuously
void loop(){

  standStill();
  delay(300);
  goForwards();
  delay(300);
  wideRightTurn();
  wideLeftTurn();
  goBackwards();
  delay(300);
  tightLeftTurn();
  tightRightTurn();
  goForwards();
  delay(300);
  goBackwards();
  delay(300);
  standStill();
}

void standStill(){
 digitalWrite(leftReverse, LOW);
 digitalWrite(rightReverse, LOW);
 digitalWrite(leftPower, LOW);
 digitalWrite(rightPower, LOW);

}
void goBackwards(){
 digitalWrite(leftReverse, HIGH);
 digitalWrite(rightReverse, HIGH);
 digitalWrite(leftPower, HIGH);
 digitalWrite(rightPower, HIGH);
}

void goForwards(){
 digitalWrite(leftReverse, LOW);
 digitalWrite(rightReverse, LOW);
 digitalWrite(leftPower, HIGH);
 digitalWrite(rightPower, HIGH);
}

void wideLeftTurn(){
 digitalWrite(leftReverse, LOW);
 digitalWrite(rightReverse, LOW);
 digitalWrite(leftPower, HIGH);
 digitalWrite(rightPower, LOW);
 delay(300);
}

void wideRightTurn(){
 digitalWrite(leftReverse, LOW);
 digitalWrite(rightReverse, LOW);
 digitalWrite(leftPower, LOW);
 digitalWrite(rightPower, HIGH);
 delay(300);
}

void tightLeftTurn(){
 digitalWrite(leftReverse, LOW);
 digitalWrite(rightReverse, HIGH);
 digitalWrite(leftPower, HIGH);
 digitalWrite(rightPower, HIGH);
 delay(300);
}

void tightRightTurn(){
 digitalWrite(leftReverse, HIGH);
 digitalWrite(rightReverse, LOW);
 digitalWrite(leftPower, HIGH);
 digitalWrite(rightPower, HIGH);
 delay(300);
}

