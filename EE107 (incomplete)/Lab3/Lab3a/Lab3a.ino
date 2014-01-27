// constants won't change. Used here to 
// set pin numbers:
const int led1 = 13;     // the number of the LED pin

void setup() {
  // set the digital pin as output:
  pinMode(led1, OUTPUT);
  }

void loop()
{
  digitalWrite(led1, HIGH);
  delay(9);
  digitalWrite(led1, LOW);
  delay(9);
}


