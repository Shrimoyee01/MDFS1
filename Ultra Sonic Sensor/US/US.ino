const int trig_tennis = 38;
const int echo_tennis = 36;

long duration;
int distance;
void setup()
{
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig, LOW);
  delay(2); // Wait for 1000 millisecond(s)
  digitalWrite(trig, HIGH);
  delay(100); // Wait for 1000 millisecond(s)
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  
  distance = duration * 0.034/2;
  
  Serial.print("Distance: ");
  Serial.println(distance);


  if (44 <= distance <= 50)
  {
    //stop the motor to deliever the tennis balls
  } 
}