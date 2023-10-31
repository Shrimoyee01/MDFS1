const int trig_tennis = 38;
const int echo_tennis = 36;
const int trig_front = 42;
const int echo_front - 46;
long duration;
int distance;
void setup() {

  pinMode(trig_tennis, OUTPUT);
  pinMode(echo_tennis, INPUT);
  pinMode(trig_front, OUTPUT);
  pinMode(echo_front, INPUT)
  Serial.begin(9600);
}

void loop() {

  if (sonicDistance(trig_front, echo_front) > 15)
  {
    // stop all motors
    // move backwards
  }

  if (44 <= sonicDistance(trig_tennis, const int echo_tennis) <= 50) {
    // stop the motor 
    // deliever the tennis balls
    // move back to the start zone
  }
}

void sonicDistance(const int trig, const int echo) {
  digitalWrite(trig, LOW);
  delay(2);  // Wait for 1000 millisecond(s)
  digitalWrite(trig, HIGH);
  delay(100);  // Wait for 1000 millisecond(s)
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);
}