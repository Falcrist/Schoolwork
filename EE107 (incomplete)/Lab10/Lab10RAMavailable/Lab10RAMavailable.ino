int fact;
void setup() {
  // initialize serial communication:
  Serial.begin(9600); 
}
int freeRam () {  //free RAM function to check remainaing RAM 
  extern int __heap_start, *__brkval;
  int v;
  return (int)  &v - (__brkval == 0?
  (int) &__heap_start : (int) __brkval);
}
int fact_funct (int input){  //factorial function
  Serial.println(freeRam ());   //displaying the available memory
  if (input>=1){                
  return fact = input * fact_funct(input-1); //recursion of function
  }
  else return fact;              //end of calculation
}
void loop() {
  // read the sensor:
  int in_arr[4];
  int place = 1;
  int input = 0;
  int i;
  fact = 1;
  Serial.println("Enter a number: ");  //enter integer from 1 to 1000
  while (Serial.available() != 1);
  for (i=0; Serial.available() > 0; ++i){ 
    in_arr[i] = Serial.read() - '0';
    delay(10);
  }
  for (--i; i>=0; --i){   //determine the decimal value of the number entered
    input += in_arr[i] * place;
    place *= 10;
  }
  Serial.println(input);    //to see what the input was
  Serial.println(fact_funct(input)); //print the vaule
}//max input was 213, it would work one time for 214 but then stopped after calculation
 //89 bytes remaining is always displayed before crash


