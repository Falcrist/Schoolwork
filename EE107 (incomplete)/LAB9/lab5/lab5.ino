int inputA = 2;
int inputB = 3;
int output1 = 4;
int i, gate, result;
int serialinput1,serialinput2;
int in_arr[4][2] = {
  {0,0},
  {0,1},
  {1,0},
  {1,1}
};
int test_arr[4][5] = {
  {0,0,0,1,1},
  {0,1,1,1,0},
  {0,0,0,1,1},
  {1,1,0,0,0}
};


void setup() {
  // initialize serial communication:
  Serial.begin(9600); 
   // initialize the pins:
        pinMode(inputA, OUTPUT);
        pinMode(inputB, OUTPUT);
        pinMode(output1, INPUT);
}
void loop() {
  // read the sensor:
  Serial.println("Enter a gate to be tested: ");
  while (Serial.available() != 1);
  serialinput1 = Serial.read();
  while (Serial.available() != 1);
  serialinput2 = Serial.read();
  if ((serialinput1=='a')||(serialinput1=='A')) gate = 0; //AND
  if ((serialinput1=='o')||(serialinput1=='O')) gate = 1; //OR
  if ((serialinput1=='x')||(serialinput1=='X')) gate = 2; //XOR
  if ((serialinput1=='n')||(serialinput1=='N')){
      if ((serialinput2=='a')||(serialinput2=='A')) gate = 3; //NAND
      else gate = 4; //NOR
  }
  Serial.println(gate);
  result = 1;
  Serial.println("Testing...");
  for(i=0;i<4;i++)
  {
    digitalWrite(inputA,in_arr[i][0]);
    digitalWrite(inputB,in_arr[i][1]);
    delay(50);
    
    if((digitalRead(output1)) != (test_arr[gate][i])) result = 0;
  }
  if (result==1) Serial.print("Passed.");
  else Serial.print("Failed.");
}


