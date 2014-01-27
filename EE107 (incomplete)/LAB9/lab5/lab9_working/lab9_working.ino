/*
Erik Reiter
Jacob Hohenstern
04/02/2013
Lab 9 - Program that uses the arduino board to verify IC chips
*/
int in_x = 13;
int in_y = 12;
int out_z = 11;
int z = digitalRead(out_z);
int serialinput1, serialinput2 = 0;
int x[4] = {0,0,1,1};  /*X inputs for truth tables*/
int y[4] = {0,1,0,1};  /*Y inputs for truth tables*/
int i,j,k;  /*variables used in for loops as counters for array elements*/
int table[5][4] = 
{
  {1,1,1,0},  /*NAND logic values table[0][0]-table[0][3]*/
  {1,0,0,0},  /*NOR logic values table[1][0]-table[1][3]*/
  {0,0,0,1},  /*AND logic values table[2][0]-table[2][3]*/
  {0,1,1,1},  /*OR logic values table[3][0]-table[3][3]*/
  {0,1,1,0},  /*XOR logic values table[4][0]-table[4][3]*/
};
void setup()
{
  Serial.begin(9600); // open the serial port at 9600 bps
  pinMode(in_x, OUTPUT);
  pinMode(in_y, OUTPUT);
  pinMode(out_z, INPUT);
}
void loop()
{
  Serial.println("Please enter a device type to test: "); 
  while(!Serial.available());
  serialinput1 = Serial.read();
  serialinput2 = Serial.read();
   if ((serialinput1=='N')&&(serialinput2=='A'))  /*NAND gate*/
  {
    Serial.println("Testing...");
    for (i=0,j=0;i<4;i++,j++)  /*go through the 2 input array*/
    {
        digitalWrite(in_x, x[i]);  /*assign an input based on the element of the array*/
        digitalWrite(in_y, y[i]);
        if ((int)table[0][i]!= z)  /*check the output from the IC chip against the correct outputs*/
          {
            Serial.print("Failed");  /*if it doesn't match, the test failed, so break the loop*/
            break;
          }
     }
     Serial.print("Passed");  /*if it successfully makes it through it passes*/
  }
  else if ((serialinput1=='N')&&(serialinput2=='O'))  /*NOR gate*/
  {
    Serial.println("Testing...");
    for (i=0,j=0;i<4;i++,j++)
    {
        digitalWrite(in_x, x[i]);
        digitalWrite(in_y, y[i]);
        if ((int)table[1][i]!= z)  /*check the output from the IC chip against the correct outputs*/
          {
            Serial.print("Failed");  /*if it doesn't match, the test failed, so break the loop*/
            break;
          }
     }
     Serial.print("Passed");  
  }
  else if (serialinput1=='A')  /*AND gate*/
  {
    Serial.println("Testing...");
    for (i=0,j=0;i<4;i++,j++)
    {
        digitalWrite(in_x, x[i]);
        digitalWrite(in_y, y[i]);
        if ((int)table[2][i]!= z)  /*check the output from the IC chip against the correct outputs*/
          {
            Serial.print("Failed");  /*if it doesn't match, the test failed, so break the loop*/
            break;
          }
     }
     Serial.print("Passed");  
  }
  else if (serialinput1=='O')  /*OR gate*/
  {
    Serial.println("Testing...");
    for (i=0,j=0;i<4;i++,j++)
      {
        digitalWrite(in_x, x[i]);
        digitalWrite(in_y, y[i]);
        if ((int)table[3][i]!= z)  /*check the output from the IC chip against the correct outputs*/
          {
            Serial.print("Failed");  /*if it doesn't match, the test failed, so break the loop*/
            break;
          }
     }
     Serial.print("Passed");  
  }
  else if (serialinput1=='X')  /*XOR gate*/
  {
    Serial.println("Testing...");
    for (i=4,j=0;i<4;i++,j++)
    {
        digitalWrite(in_x, x[i]);
        digitalWrite(in_y, y[i]);
        if ((int)table[4][i]!= z)  /*check the output from the IC chip against the correct outputs*/
          {
            Serial.print("Failed");  /*if it doesn't match, the test failed, so break the loop*/
            break;
          }
     }
     Serial.print("Passed");  
  }
  else
  {
  Serial.println("Please enter a valid gate."); 
  }
}
