#include <Servo.h>
#include <Stepper.h>

Servo myservo;  // create servo object to control a servo

const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);  //L298n signal pins
// int stepCount = 0;
// const int myservo = 7;

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);

  myStepper.step(-1020);  //Drive motor forward
  delay(5000);
  myservo.write(0);
  myservo.attach(7);  // (pin, min, max)
  delay(500);
  myservo.write(180);

  delay(5000);

  myStepper.step(1020);  //Drive motor backwards

  // delay(500);

  // myservo.write(0);
}

void loop() {
  // myservo.write(180);

  // myservo.write(0);  // tell servo to go to a particular angle
  // delay(1000);

  // myservo.write(90);
  // delay(500);

  // myservo.write(135);
  // delay(500);

  // myservo.write(180);
  // delay(1500);
}