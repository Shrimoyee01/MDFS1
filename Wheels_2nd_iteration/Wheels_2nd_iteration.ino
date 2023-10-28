//driver 1
// Motor A connections - forward left
const unsigned int D1_enA = 6;   // speed
const unsigned int D1_in1 = 50;  // spinning direction
const unsigned int D1_in2 = 51;  // spinning direction

// Motor B connections - front right
const unsigned int D1_enB = 7;   // speed
const unsigned int D1_in3 = 30;  // spinning direction
const unsigned int D1_in4 = 32;  // spinning direction

// driver 2
// Motor C connections - back left
const unsigned int D2_enA = 8;   // speed
const unsigned int D2_in1 = 12;  // spinning direction
const unsigned int D2_in2 = 13;  // spinning direction

// Motor D connections - back right
const unsigned int D2_enB = 9;   // speed
const unsigned int D2_in3 = 15;  // spinning direction
const unsigned int D2_in4 = 16;  // spinning direction

void setup() {

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
}

void loop() {
  forward(5000);
  backwards(5000);
  left(5000);
  right(5000);
}

void forward(unsigned long duration) {
  // set all motors to full speed
  analogWrite(D1_enA, 255);
  analogWrite(D1_enB, 255);
  analogWrite(D2_enA, 255);
  analogWrite(D2_enB, 255);

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
  stopMotors();
}

void right(unsigned long duration) {
  // set all motors to full speed
  analogWrite(D1_enA, 255);
  analogWrite(D1_enB, 255);
  analogWrite(D2_enA, 255);
  analogWrite(D2_enB, 255);

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
  stopMotors();
}

void stopMotors() {
  analogWrite(D1_enA, 0);
  analogWrite(D1_enB, 0);
  analogWrite(D2_enA, 0);
  analogWrite(D2_enB, 0);
}