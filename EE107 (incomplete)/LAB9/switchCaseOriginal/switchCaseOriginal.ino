#define test00 digitalWrite(inA, LOW);digitalWrite(inB, LOW);
#define test01 digitalWrite(inA, LOW);digitalWrite(inB, HIGH);
#define test10 digitalWrite(inA, HIGH);digitalWrite(inB, LOW);
#define test11 digitalWrite(inA, HIGH);digitalWrite(inB, HIGH);
#define results_not_0 (digitalRead(out1)=HIGH)||(digitalRead(out2)=HIGH)||(digitalRead(out3)=HIGH)||(digitalRead(out4)=HIGH)
#define results_not_1 (digitalRead(out1)=LOW)||(digitalRead(out2)=LOW)||(digitalRead(out3)=LOW)||(digitalRead(out4)=LOW)

int inA = 2;
int inB = 3;
int out1 = 4;
int out2 = 5;
int out3 = 6;
int out4 = 7;
int i, gate;
char serialinput[4];

void setup() {
  // initialize serial communication:
  Serial.begin(9600); 
   // initialize the pins:
        pinMode(inA, OUTPUT);
        pinMode(inB, OUTPUT);
        pinMode(out1, INPUT);
        pinMode(out2, INPUT);
        pinMode(out3, INPUT);
        pinMode(out4, INPUT);

void loop() {
  // read the sensor:
  while (Serial.available() != 1);
  for(i=0; Serial.available() > 0; ++1){
    if (i<4) serialinput[i] = Serial.read();
  }
  //if (Serial.available() > 0) 
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
    switch (gate) {
        case 1:
          test00
          if (results_not_0){
            Serial.read("FAILED!\n");
            break;
          }
          test01
          if (results_not_0){
            Serial.read("FAILED!\n");
            break;
          }
          test10
          if (results_not_0){
            Serial.read("FAILED!\n");
            break;
          }
          test11
          if (results_not_1){
            Serial.read("FAILED!\n");
            break;
          }
          Serial.read("PASSED!\n");
          break;
        case 2: 
          test00
          if (results_not_0){
            Serial.read("FAILED!\n");
            break;
          }
          test01
          if (results_not_1){
            Serial.read("FAILED!\n");
            break;
          }
          test10
          if (results_not_1){
            Serial.read("FAILED!\n");
            break;
          }
          test11
          if (results_not_1){
            Serial.read("FAILED!\n");
            break;
          }
          Serial.read("PASSED!\n");
          break;
        case 3:
          test00
          if (results_not_0){
            Serial.read("FAILED!\n");
            break;
          }
          test01
          if (results_not_1){
            Serial.read("FAILED!\n");
            break;
          }
          test10
          if (results_not_1){
            Serial.read("FAILED!\n");
            break;
          }
          test11
          if (results_not_0){
            Serial.read("FAILED!\n");
            break;
          }
          Serial.read("PASSED!\n");
          break;
        case 4: 
          test00
          if (results_not_1){
            Serial.read("FAILED!\n");
            break;
          }
          test01
          if (results_not_1){
            Serial.read("FAILED!\n");
            break;
          }
          test10
          if (results_not_1){
            Serial.read("FAILED!\n");
            break;
          }
          test11
          if (results_not_0){
            Serial.read("FAILED!\n");
            break;
          }
          Serial.read("PASSED!\n");
          break;
        case 5:
          test00
          if (results_not_1){
            Serial.read("FAILED!\n");
            break;
          }
          test01
          if (results_not_0){
            Serial.read("FAILED!\n");
            break;
          }
          test10
          if (results_not_0){
            Serial.read("FAILED!\n");
            break;
          }
          test11
          if (results_not_0){
            Serial.read("FAILED!\n");
            break;
          }
          break;
      }
      Serial.read("PASSED!\n");
}
