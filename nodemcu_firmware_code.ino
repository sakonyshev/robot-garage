#define FORCE_SENSOR_PIN A0 //force resistor pin

// Define stepper motor connections and steps per revolution:
#define enableDriverPin 16 //D0 enable stepper driver
#define dirPin 12 //D6 direction stepper mottor driver pin
#define stepPin 14 //D5 step stepper mottor driver pin

#define enableBoardPin 13  //D7

#define endSwitchStop 5  //D1

#define stepsPerRevolution 1800 * 4

#define default_open_speed 110
#define default_close_speed 220

void setup() {
  //Power on
  pinMode(enableBoardPin, OUTPUT);
  digitalWrite(enableBoardPin, HIGH);
  
  pinMode(enableDriverPin, OUTPUT);
  digitalWrite(enableDriverPin, LOW);

  // Declare pins as output:

  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  // Serial.begin(115200);

  pinMode(endSwitchStop, INPUT);
}

void close(int speed) {
  int stop = 1;

  stop = digitalRead(endSwitchStop);  
  digitalWrite(dirPin, LOW);

  while (stop == 0) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(speed);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(speed);

    stop = digitalRead(endSwitchStop);
    yield();
  }
}

void open(int speed) {
  digitalWrite(dirPin, HIGH);

  // // Spin the stepper motor 1 revolution slowly:
  for (int i = 0; i < stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(speed);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(speed);
    yield();
  }
}

void waitRobotToDock(int docked) {
  
  while (docked != 0) {
    if (analogRead(FORCE_SENSOR_PIN) > 350) {
      docked--;
    }
    delay(2000);
    yield();
    //TODO add change robot position
  }
}


void powerOn() {
  digitalWrite(enableBoardPin, HIGH);
  digitalWrite(enableDriverPin, LOW);
}

void powerOff() {
  digitalWrite(enableDriverPin, HIGH);
  digitalWrite(enableBoardPin, LOW);
  delay(1000);
}

void loop() {
  close(85); //calibrate servo's start position
  open(default_open_speed); //open the garage

  waitRobotToDock(6); //waiting a wheel standing on the force resistor
  close(default_close_speed);
  powerOff();
}