
const int modePin = 2;    // the state of this switch determines the shlft direction
const int clockPin = 3;    // this is the clock input
const int leftInputPin = 4;    // left serial input
const int rightInputPin = 5;    // left serial input
const int ledPin1 = 10;  //these are the outputs
const int ledPin2 = 11;
const int ledPin3 = 12;
const int ledPin4 = 13;

void setup() {
  // initialize the inputs:
  pinMode(modePin, INPUT);
  pinMode(clockPin, INPUT);
  pinMode(leftInputPin, INPUT);
  pinMode(rightInputPin, INPUT);
  // initialize the LEDs as outputs:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
}


void loop() {
  while(digitalRead(clockPin)==HIGH); //wait for the switch to go low
  delay(2); //delay to prevent bounce
  while(digitalRead(clockPin)==LOW); //wait for the switch to go high
    if (digitalRead(modePin) == HIGH) { //if modepin is high shift right
      digitalWrite(ledPin4, digitalRead(ledPin3));
      digitalWrite(ledPin3, digitalRead(ledPin2));
      digitalWrite(ledPin2, digitalRead(ledPin1));
      digitalWrite(ledPin1, digitalRead(leftInputPin));
    }
    else { //if modepin is low shift left
      digitalWrite(ledPin1, digitalRead(ledPin2));
      digitalWrite(ledPin2, digitalRead(ledPin3));
      digitalWrite(ledPin3, digitalRead(ledPin4));
      digitalWrite(ledPin4, digitalRead(rightInputPin));
    }
    delay(2); //delay to prevent bounce
}
