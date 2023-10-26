// Set the pins for the wheel motors
bool button = 11;
const int blueLED = 12;
const int redLED = 13;
const int motorFrontLeft = 3;
const int motorFrontRight = 4;
const int motorBackLeft = 5;
const int motorBackRight = 6;

bool buttonState = false;


void setup() {
  Serial.begin(9600);

  // Set up for the LEDs
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  // set up for the button
  pinMode(button, INPUT);

  // set up for the motors
  pinMode(motorFrontLeft, OUTPUT);
  pinMode(motorFrontRight, OUTPUT);
  pinMode(motorBackLeft, OUTPUT);
  pinMode(motorBackRight, OUTPUT);
}

void loop() {

  // while button on
  // led turns green
  // move forward function 10 seconds
  // wait 20 seconds to pick up squash balls
  // move right and back to the squal ball silo
  // wait 20 seconds to drop off the balls
  // move forward function - 10 seconds
  // delay for the robot to pick up tennis balls
  // move left
  // move forward
  // delay for the ball to go into the silo
  // move back into the start zone
  // led turned red to indicate the end


  buttonState = digitalRead(button);

  // if button is pressed
  if (buttonState) {
    // turn blue LED on
    digitalWrite(blueLED, HIGH);

    moveForward(10000); // moving forward fo 10 seconds - subject to change dependant on how long it will take to reach the balls

    // delay for the pick up
    delay(20000);

    // move to the squash ball silo (right and back)
    turnRight(10000);
    moveBackward(10000);

    // drop off the balls in the silo
    delay(10000);

    // move forward to the tennis balls
    moveForward(10000);

    // delay to pick up tennis balls
    delay(10000);

    // move to the tennis ball silo
    turnLeft(10000);

    // delay to drop off tennis balls
    delay(10000);

    // move back to the starting position
    moveBackward(10000);
    
    // turn on red LED to show that the process has been completed
    digitalWrite(redLED, HIGH);
  }
}

// set the pins for the wheel motors
// initialise the arduino board
// set the motor pins as output
// function to move forward
// funcion to move backwards
// function to move left
// function to move right

void moveForward(unsigned long duration) {
  // Set motor speeds for forward motion
  analogWrite(motorFrontLeft, 255);
  analogWrite(motorFrontRight, 255);
  analogWrite(motorBackLeft, 255);
  analogWrite(motorBackRight, 255);
  delay(duration);
  stopMotors();
}

void moveBackward(unsigned long duration) {
  // Set motor speeds for backward motion
  analogWrite(motorFrontLeft, 0);
  analogWrite(motorFrontRight, 0);
  analogWrite(motorRearLeft, 0);
  analogWrite(motorBackRight, 0);
  delay(duration);
  stopMotors();
}

void turnLeft(unsigned long duration) {
  // Set motor speeds for turning left
  analogWrite(motorFrontLeft, 0);
  analogWrite(motorFrontRight, 255);
  analogWrite(motorBackLeft, 0);
  analogWrite(motorBackRight, 255);
  delay(duration);
  stopMotors();
}

void turnRight(unsigned long duration) {
  // Set motor speeds for turning right
  analogWrite(motorFrontLeft, 255);
  analogWrite(motorFrontRight, 0);
  analogWrite(motorBackLeft, 255);
  analogWrite(motorBackRight, 0);
  delay(duration);
  stopMotors();
}

void stopMotors() {
  // Stop all motors
  analogWrite(motorFrontLeft, 0);
  analogWrite(motorFrontRight, 0);
  analogWrite(motorBackLeft, 0);
  analogWrite(motorBackRight, 0);
}