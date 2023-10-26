// C++ code
const int redLED = 13;
const int blueLED = 12;
const int button = 11;

bool buttonState = false;

void setup()
{  
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(button, INPUT);
}

void loop()
{
	buttonState = digitalRead(button);
  
  if (buttonState)
  {
    digitalWrite(blueLED, HIGH);
  }
}


