// stepper libary
#include <Stepper.h>
// servo library
#include <Servo.h>

// buttons and leds
const int blueLED = 1;
const int button = 2;

bool buttonState = false;


//driver 1
// Motor A connections - forward left
const unsigned int D1_enA = 6;  // speed
const unsigned int D1_in1 = 3;  // spinning direction
const unsigned int D1_in2 = 5;  // spinning direction

// Motor B connections - front right
const unsigned int D1_enB = 7;   // speed
const unsigned int D1_in3 = 12;  // spinning direction
const unsigned int D1_in4 = 13;  // spinning direction

// driver 2
// Motor C connections - back left
const unsigned int D2_enA = 8;   // speed
const unsigned int D2_in1 = 15;  // spinning direction
const unsigned int D2_in2 = 16;  // spinning direction

// Motor D connections - back right
const unsigned int D2_enB = 9;   // speed
const unsigned int D2_in3 = 17;  // spinning direction
const unsigned int D2_in4 = 18;  // spinning direction

// steps per rotation
const int stepsPerRevolution = 200;

// initialise the stepper motors
Stepper captureStepper(stepsPerRevolution, 19, 20, 21, 22);  // on arduino pins
Stepper liftStepper(stepsPerRevolution, 23, 24, 25, 26);
Stepper squashStepper(stepsPerRevolution, 35, 36, 37, 38);
Stepper tennisStepper(stepsPerRevolution, 39, 40, 41, 42);

// 2 servo motors
Servo squashServo;
Servo tennisServo;

// 2 ultra sonic sensors
const int tennisTrig = 43;
const int tennisEcho = 44;
const int frontTrig = 45;
const int frontEcho = 46;

long duration;
int distance;

void setup() {
  // buttons and leds
  pinMode(blueLED, OUTPUT);
  pinMode(button, INPUT);

  // motors
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

  // stepper motor set up
  captureStepper.setSpeed(60);  //  60 revolutions per minute
  liftStepper.setSpeed(60);     //  60 rpm
  squashStepper.setSpeed(60);   //  60 rpm
  tennisStepper.setSpeed(60);   //  60 rpm

  // pin for the servos
  squashServo.attach(47);
  tennisServo.attach(48);
}

void loop() {
  // put your main code here, to run repeatedly:

  buttonState = digitalRead(button);

  while (buttonState) {
    digitalWrite(blueLED, HIGH);

    // move forward slowly to go to the squash balls
    forward(100, 5000);

    // delay to wait for the squash balls to be gathered
    delay(300);  // 300 ms delay - subject to change

    // stepper to pull up the balls and delievered to the delivery system
    captureStepper.step(100);

    backwards(100, 5000);  // go back to the squash ball silo

    // squash ball delivery
    squashDelievery();

    right(255, 5000);

    while (sonicDistance(frontTrig, frontEcho) < 10 || !(44 <= sonicDistance(tennisTrig, tennisEcho) <= 50)) {
      forward(255, 100);
      continue;
    }

    setMotorSpeed(0);

    liftStepper.step(1020);

    tennisDelivery();

    backwards(255, 5000);

    break;
  }

  digitalWrite(blueLED, LOW);
  buttonState = true;
  delay(120000);
}

// code for the wheels
void forward(const int speed, unsigned long duration) {  // set the speed of the motor and how long it would run for
  setMotorSpeed(speed);

  // move all wheels clockwise
  digitalWrite(D1_in1, HIGH);
  digitalWrite(D1_in2, LOW);
  digitalWrite(D1_in3, HIGH);
  digitalWrite(D1_in4, LOW);

  digitalWrite(D2_in1, HIGH);
  digitalWrite(D2_in2, LOW);
  digitalWrite(D2_in3, HIGH);
  digitalWrite(D2_in4, LOW);

  delay(duration);
  setMotorSpeed(0);  // stop moving
}

void backwards(const int speed, unsigned long duration) {  // set the speed of the motor and how long it would run for
  setMotorSpeed(speed);

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
  setMotorSpeed(0);  // stop moving
}

void left(const int speed, unsigned long duration) {  // set the speed of the motor and how long it would run for
  setMotorSpeed(speed);

  // move wheels ccw
  digitalWrite(D1_in1, LOW);
  digitalWrite(D1_in2, HIGH);
  digitalWrite(D2_in3, LOW);
  digitalWrite(D2_in4, HIGH);

  // move wheels cw
  digitalWrite(D1_in3, HIGH);
  digitalWrite(D1_in4, LOW);
  digitalWrite(D2_in1, LOW);
  digitalWrite(D2_in2, HIGH);

  delay(duration);
  setMotorSpeed(0);  // stop moving
}

void right(const int speed, unsigned long duration) {  // set the speed of the motor and how long it would run for
  setMotorSpeed(speed);

  // move wheels ccw
  digitalWrite(D1_in3, LOW);
  digitalWrite(D1_in4, HIGH);
  digitalWrite(D2_in1, LOW);
  digitalWrite(D2_in2, HIGH);

  // move wheels cw
  digitalWrite(D1_in1, HIGH);
  digitalWrite(D1_in2, LOW);
  digitalWrite(D2_in3, HIGH);
  digitalWrite(D2_in4, LOW);

  delay(duration);
  setMotorSpeed(0);
}

// set the speed of the motor depending on requirements - 0 to 255
void setMotorSpeed(const int speed) {
  // set all motors to full speed
  analogWrite(D1_enA, speed);
  analogWrite(D1_enB, speed);
  analogWrite(D2_enA, speed);
  analogWrite(D2_enB, speed);
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
  tennisStepper.step(1020);
  delay(200);
  tennisServo.write(0);
  tennisServo.write(180);

  delay(3000);

  tennisStepper.step(-1020);
}

// ultrasonic sensor
int sonicDistance(const int trig, const int echo) {
  digitalWrite(trig, LOW);
  delay(2);  // Wait for 1000 millisecond(s)
  digitalWrite(trig, HIGH);
  delay(100);  // Wait for 1000 millisecond(s)
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);

  distance = duration * 0.034 / 2;  // in centimeters

  Serial.print("Distance: ");
  Serial.println(distance);
}