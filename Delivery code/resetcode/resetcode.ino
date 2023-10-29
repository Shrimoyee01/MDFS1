#include <Servo.h>
Servo servo;  //create object servo

void setup() {
  // put your setup code here, to run once:
  servo.attach(7);  // (pin, min, max)
  delay(500);
  servo.write(0);  //servo motor moves 90 degress
  delay(500);
  servo.attach(7);  // (pin, min, max)
}

void loop() {
  // put your main code here, to run repeatedly:
}
