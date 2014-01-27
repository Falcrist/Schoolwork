int PWMpin = 3; // PWM output to drive the motor
int POTpin = 0; // analog input from the POT
int val = 0; // variable used to read the analog input
int PWMout = 0; // variable used to write the PWM duty cycle
// The setup() method runs once, when the sketch starts
void setup() {
TCCR2B = TCCR2B & 0b11111000 | 0x07; // 1024 divider for tmr 2
}
// the loop() method runs over and over again,
// as long as the Arduino has power
void loop()
{
  val = analogRead(POTpin); // read data from the POT
  PWMout = val / 4;
  analogWrite(PWMpin, PWMout); // update PWM output signal
}
