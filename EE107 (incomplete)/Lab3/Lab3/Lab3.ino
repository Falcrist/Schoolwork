// constants won't change. Used here to 
// set pin numbers:
const int led1 = 10;
const int led2 = 11;
const int led3 = 12;
const int led4 = 13;     // the number of the LED pin

void setup() {
  // set the digital pin as output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);     
}

void loop()
{
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  delay(analogRead(0)/41+5);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(analogRead(0)/41+5);
}


