#define test00 digitalWrite(inputA, LOW);digitalWrite(inputB, LOW);
#define test01 digitalWrite(inputA, LOW);digitalWrite(inputB, HIGH);
#define test10 digitalWrite(inputA, HIGH);digitalWrite(inputB, LOW);
#define test11 digitalWrite(inputA, HIGH);digitalWrite(inputB, HIGH);
#define results_not_0 (digitalRead(output1)=HIGH)||(digitalRead(output2)=HIGH)||(digitalRead(output3)=HIGH)||(digitalRead(output4)=HIGH)
#define results_not_1 (digitalRead(output1)=LOW)||(digitalRead(output2)=LOW)||(digitalRead(output3)=LOW)||(digitalRead(output4)=LOW)

int inputA = 2;
int inputB = 3;
int output1 = 4;
int output2 = 5;
int output3 = 6;
int output4 = 7;
int i, gate;
char serialinput[4];

void setup() {
  // initialize serial communication:
  Serial.begin(9600); 
   // initialize the pins:
        pinMode(inputA, OUTPUT);
        pinMode(inputB, OUTPUT);
        pinMode(output1, INPUT);
        pinMode(output2, INPUT);
        pinMode(output3, INPUT);
        pinMode(output4, INPUT);

void loop() {
  // read the sensor:
  while (Serial.available() != 1);
  for(i=0; Serial.available() > 0; ++1){
    if (i<4) serialinput[i] = Serial.read();
  }
  //if (Serial.available() > 0) {
    //int inByte = Serial.read();

  if ((serialinput[0]='a')||(serialinput[0]='A')){
    gate = 1; //AND
  }
  if ((serialinput[0]='o')||(serialinput[0]='O')){
    gate = 2; //OR
  }
  if ((serialinput[0]='x')||(serialinput[0]='X')){
    gate = 3; //XOR
  }
  if ((serialinput[0]='n')||(serialinput[0]='N')){
      if ((serialinput[1]='a')||(serialinput[1]='A')){
      gate = 4; //NAND
      }
      else gate = 5; //NOR
  }

/*    result = 1;
  for(m1=0,m1<5,m1++)
    digitalWrite(pin1,l1[m1]);
    digitalWrite(pin1,l2[m1]);
    delay(50);
    val = digitalRead(pin3);
    if(array[gate][m1] != val)
        result = '0'
   
*/   
    switch (gate) {
        case 1:
          test00
          if (results_not_0){
            Serial.read("FAILED!\n")
            break;
          }
          test01
          if (results_not_0){
            Serial.read("FAILED!\n")
            break;
          }
          test10
          if (results_not_0){
            Serial.read("FAILED!\n")
            break;
          }
          test11
          if (results_not_1){
            Serial.read("FAILED!\n")
            break;
          }
          Serial.read("PASSED!\n")
          break;
        case 2: 
          test00
          if (results_not_0){
            Serial.read("FAILED!\n")
            break;
          }
          test01
          if (results_not_1){
            Serial.read("FAILED!\n")
            break;
          }
          test10
          if (results_not_1){
            Serial.read("FAILED!\n")
            break;
          }
          test11
          if (results_not_1){
            Serial.read("FAILED!\n")
            break;
          }
          Serial.read("PASSED!\n")
          break;
        case 3:
          test00
          if (results_not_0){
            Serial.read("FAILED!\n")
            break;
          }
          test01
          if (results_not_1){
            Serial.read("FAILED!\n")
            break;
          }
          test10
          if (results_not_1){
            Serial.read("FAILED!\n")
            break;
          }
          test11
          if (results_not_0){
            Serial.read("FAILED!\n")
            break;
          }
          Serial.read("PASSED!\n")
          break;
        case 4: 
          test00
          if (results_not_1){
            Serial.read("FAILED!\n")
            break;
          }
          test01
          if (results_not_1){
            Serial.read("FAILED!\n")
            break;
          }
          test10
          if (results_not_1){
            Serial.read("FAILED!\n")
            break;
          }
          test11
          if (results_not_0){
            Serial.read("FAILED!\n")
            break;
          }
          Serial.read("PASSED!\n")
          break;
        case 5:
          test00
          if (results_not_1){
            Serial.read("FAILED!\n")
            break;
          }
          test01
          if (results_not_0){
            Serial.read("FAILED!\n")
            break;
          }
          test10
          if (results_not_0){
            Serial.read("FAILED!\n")
            break;
          }
          test11
          if (results_not_0){
            Serial.read("FAILED!\n")
            break;
          }
          Serial.read("PASSED!\n")
          break;
      }


