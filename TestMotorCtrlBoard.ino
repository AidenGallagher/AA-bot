//Valid commands: 'PWR on', 'PWR off', 'Forward' and 'Backward'.

const int DIR_CTRL = 7;
const int PWR_CTRL = 6;
String cmd = "";
int period = 500;

void setup() {
  // put your setup code here, to run once:
pinMode(DIR_CTRL, OUTPUT);
pinMode(PWR_CTRL, OUTPUT);
Serial.begin(9600);
digitalWrite(DIR_CTRL, LOW);
digitalWrite(PWR_CTRL, LOW);
Serial.println("Code Start");
}

void loop() {
  cmd = "";
  cmd = checkPort();
  processCmd(cmd);
  delay(period);
}


String checkPort() {
  String current;
  if (Serial.available()) {
    current = Serial.readString();
  } else {
    current = "NA";
  }
  return current;
}

void processCmd(String current) {
  if (current == "NA") {
    //do nothing
  } else if (current == "PWR on") {
    Serial.println("turning PWR_CTRL on");
    digitalWrite(PWR_CTRL, HIGH);
  } else if (current == "PWR off") {
    Serial.println("turning PWR_CTRL off");
    digitalWrite(PWR_CTRL, LOW);
  } else if (current == "Forward") {
    Serial.println("turning DIR_CTRL on");
    digitalWrite(DIR_CTRL, HIGH);
  } else if (current == "Backward") {
    Serial.println("turning DIR_CTRL off");
    digitalWrite(DIR_CTRL, LOW);  
  } else {
    Serial.println("unrecognised command: " + current);
  }
}
