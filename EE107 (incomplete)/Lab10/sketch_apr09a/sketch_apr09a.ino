double fact;
void setup() {
  // initialize serial communication:
  Serial.begin(9600); 
}
int freeRam () {
  extern int __heap_start, *__brkval;
  int v;
  return (int)  &v - (__brkval == 0?
  (int) &__heap_start : (int) __brkval);
}
double fact_funct (int input){
  Serial.println(freeRam ());
  if (input>=1){ 
  return fact = input * fact_funct(input-1);
  }
  else return fact;
}
void loop() {
  // read the sensor:
  int in_arr[4];
  int place = 1;
  int input = 0;
  int i;
  fact = 1;
  Serial.println("Enter a number: ");
  while (Serial.available() != 1);
  for (i=0; Serial.available() > 0; ++i){
    in_arr[i] = Serial.read() - '0';
    delay(10);
  }
  for (--i; i>=0; --i){
    input += in_arr[i] * place;
    place *= 10;
  }
  Serial.println(input);
  //fact = fact_funct(input);
  Serial.println(fact_funct(input));
}


