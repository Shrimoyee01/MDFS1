#include <Servo.h>
#include <Stepper.h>

// 2 servo motors
Servo squashServo;
Servo tennisServo;

// initialise the stepper motors
Stepper captureStepper(200, 19, 20, 21, 22);  // on arduino pins
Stepper liftStepper(200, 23, 24, 25, 26);
Stepper squashStepper(200, 35, 36, 37, 38);
Stepper tennisStepper(200, 10, 36, 8, 9);        // DO NOT TOUCH
Stepper tennisStepperRail(200, 13, 12, 11, 43);  // DO NOT TOUCH

//driver 1
// Motor A connections - forward right
const unsigned int D1_enA = 2;   // speed
const unsigned int D1_in1 = 22;  // spinning direction
const unsigned int D1_in2 = 24;  // spinning direction

// Motor B connections - front left
const unsigned int D1_enB = 3;   // speed
const unsigned int D1_in3 = 26;  // spinning direction
const unsigned int D1_in4 = 28;  // spinning direction

// driver 2
// Motor C connections - back right
const unsigned int D2_enA = 7;   // speed
const unsigned int D2_in1 = 50;  // spinning direction
const unsigned int D2_in2 = 52;  // spinning direction

// Motor D connections - back left
const unsigned int D2_enB = 6;   // speed
const unsigned int D2_in3 = 46;  // 46;  // spinning direction
const unsigned int D2_in4 = 48;  // 48;  // spinning direction

void setup() {

  // stepper motor set up
  captureStepper.setSpeed(60);  //  60 revolutions per minute
  liftStepper.setSpeed(60);     //  60 rpm
  squashStepper.setSpeed(60);   //  60 rpm
  tennisStepper.setSpeed(60);   //  60 rpm
  tennisStepperRail.setSpeed(60);

  // pin for the servos
  squashServo.attach(47);
  tennisServo.attach(48);

  // set up pins for motor on driver 1
  pinMode(D1_enA, OUTPUT);
  pinMode(D1_enB, OUTPUT);
  pinMode(D1_in1, OUTPUT);
  pinMode(D1_in2, OUTPUT);
  pinMode(D1_in3, OUTPUT);
  pinMode(D1_in4, OUTPUT);

  // set up for driver 2
  pinMode(D2_enA, OUTPUT);
  pinMode(D2_enB, OUTPUT);
  pinMode(D2_in1, OUTPUT);
  pinMode(D2_in2, OUTPUT);
  pinMode(D2_in3, OUTPUT);
  pinMode(D2_in4, OUTPUT);

  tennisDelivery();
}

void loop() {
  //  forward(1050);
  //  backwards(1050);
  //  left(5000);
  //  right(5000);
}


// squash ball delivery function - DO NOT TOUCH
void squashDelievery() {
  squashStepper.step(-1020);  //Drive motor forward
  delay(200);
  squashServo.write(0);
  // squashServo.attach(7);  // (pin, min, max)
  delay(500);
  squashServo.write(180);

  delay(5000);

  squashStepper.step(1020);  //Drive motor backwards
}

// tennis ball delivery function
void tennisDelivery() {
  tennisStepper.step(100);
  tennisStepperRail.step(-1020);
  //  delay(200);
  //  tennisServo.write(0);
  //  tennisServo.write(180);

  delay(3000);

  // tennisStepper.step(-1020);
}

void forward(unsigned long duration) {
  // set all motors to full speed
  analogWrite(D1_enA, 255);
  analogWrite(D1_enB, 255);
  analogWrite(D2_enA, 255);
  analogWrite(D2_enB, 255);

  // move all wheels clockwise
  //forward right
  digitalWrite(D1_in1, HIGH);
  digitalWrite(D1_in2, LOW);

  //forward left
  digitalWrite(D1_in3, HIGH);
  digitalWrite(D1_in4, LOW);

  // back right
  digitalWrite(D2_in1, HIGH);
  digitalWrite(D2_in2, LOW);

  // back left
  digitalWrite(D2_in3, HIGH);
  digitalWrite(D2_in4, LOW);

  delay(duration);
  stopMotors();
}

void backwards(unsigned long duration) {
  // set all motors to full speed
  analogWrite(D1_enA, 255);
  analogWrite(D1_enB, 255);
  analogWrite(D2_enA, 255);
  analogWrite(D2_enB, 255);

  // move all wheels counter-clockwise
  digitalWrite(D1_in1, LOW);
  digitalWrite(D1_in2, HIGH);
  digitalWrite(D1_in3, LOW);
  digitalWrite(D1_in4, HIGH);

  digitalWrite(D2_in1, LOW);
  digitalWrite(D2_in2, HIGH);
  digitalWrite(D2_in3, LOW);
  digitalWrite(D2_in4, HIGH);

  delay(duration);
  stopMotors();
}

void left(unsigned long duration) {
  // set all motors to full speed
  analogWrite(D1_enA, 255);
  analogWrite(D1_enB, 255);
  analogWrite(D2_enA, 255);
  analogWrite(D2_enB, 255);

  // move wheels ccw
  digitalWrite(D1_in1, HIGH);
  digitalWrite(D1_in2, LOW);
  digitalWrite(D2_in3, HIGH);
  digitalWrite(D2_in4, LOW);

  // move wheels cw
  digitalWrite(D1_in3, LOW);
  digitalWrite(D1_in4, HIGH);
  digitalWrite(D2_in1, LOW);
  digitalWrite(D2_in2, HIGH);

  delay(duration);
  stopMotors();
}

void right(unsigned long duration) {
  // set all motors to full speed
  analogWrite(D1_enA, 50);
  analogWrite(D1_enB, 50);
  analogWrite(D2_enA, 50);
  analogWrite(D2_enB, 50);

  // move wheels ccw
  digitalWrite(D1_in3, LOW);
  digitalWrite(D1_in4, HIGH);
  digitalWrite(D2_in1, HIGH);
  digitalWrite(D2_in2, LOW);

  // move wheels cw
  digitalWrite(D1_in1, HIGH);
  digitalWrite(D1_in2, LOW);
  digitalWrite(D2_in3, LOW);
  digitalWrite(D2_in4, HIGH);

  delay(duration);
  stopMotors();
}

void stopMotors() {
  analogWrite(D1_enA, 0);
  analogWrite(D1_enB, 0);
  analogWrite(D2_enA, 0);
  analogWrite(D2_enB, 0);
}