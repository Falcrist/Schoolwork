int in;   // input from incoming serial data
int led1=8;
int led2=2;
int led3=3;
int led4=4;
int led5=5;
int led6=6;
int led7=7;

void setup()
{
	Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);
	pinMode(led3, OUTPUT);
	pinMode(led4, OUTPUT);
	pinMode(led5, OUTPUT);
	pinMode(led6, OUTPUT);
	pinMode(led7, OUTPUT);

}

void loop() {

        // send data only when you receive data:
        while (!Serial.available());

         // read the incoming byte:
        in = Serial.read();

        if (in == '0')
	{
	 digitalWrite(led1, HIGH);
	 digitalWrite(led2, HIGH);
	 digitalWrite(led3, HIGH);
	 digitalWrite(led4, LOW);
	 digitalWrite(led5, HIGH);
	 digitalWrite(led6, HIGH);
	 digitalWrite(led7, HIGH);
	}
        if (in == '1')
	{
	 digitalWrite(led1, LOW);
	 digitalWrite(led2, LOW);
	 digitalWrite(led3, HIGH);
	 digitalWrite(led4, LOW);
	 digitalWrite(led5, LOW);
	 digitalWrite(led6, HIGH);
	 digitalWrite(led7, LOW);
	}
        if (in == '2')
	{
	 digitalWrite(led1, HIGH);
	 digitalWrite(led2, LOW);
	 digitalWrite(led3, HIGH);
	 digitalWrite(led4, HIGH);
	 digitalWrite(led5, HIGH);
	 digitalWrite(led6, LOW);
	 digitalWrite(led7, HIGH);
	}
        if (in == '3')
	{
	 digitalWrite(led1, HIGH);
	 digitalWrite(led2, LOW);
	 digitalWrite(led3, HIGH);
	 digitalWrite(led4, HIGH);
	 digitalWrite(led5, LOW);
	 digitalWrite(led6, HIGH);
	 digitalWrite(led7, HIGH);
	}
        if (in == '4')
	{
	 digitalWrite(led1, LOW);
	 digitalWrite(led2, HIGH);
	 digitalWrite(led3, HIGH);
	 digitalWrite(led4, HIGH);
	 digitalWrite(led5, LOW);
	 digitalWrite(led6, HIGH);
	 digitalWrite(led7, LOW);
	}
        if (in == '5')
	{
	 digitalWrite(led1, HIGH);
	 digitalWrite(led2, HIGH);
	 digitalWrite(led3, LOW);
	 digitalWrite(led4, HIGH);
	 digitalWrite(led5, LOW);
	 digitalWrite(led6, HIGH);
	 digitalWrite(led7, HIGH);
	}
        if (in == '6')
	{
	 digitalWrite(led1, HIGH);
	 digitalWrite(led2, HIGH);
	 digitalWrite(led3, LOW);
	 digitalWrite(led4, HIGH);
	 digitalWrite(led5, HIGH);
	 digitalWrite(led6, HIGH);
	 digitalWrite(led7, HIGH);
	}
        if (in == '7')
	{
	 digitalWrite(led1, HIGH);
	 digitalWrite(led2, LOW);
	 digitalWrite(led3, HIGH);
	 digitalWrite(led4, LOW);
	 digitalWrite(led5, LOW);
	 digitalWrite(led6, HIGH);
	 digitalWrite(led7, LOW);
	}
        if (in == '8')
	{
	 digitalWrite(led1, HIGH);
	 digitalWrite(led2, HIGH);
	 digitalWrite(led3, HIGH);
	 digitalWrite(led4, HIGH);
	 digitalWrite(led5, HIGH);
	 digitalWrite(led6, HIGH);
	 digitalWrite(led7, HIGH);
	}
        if (in == '9')
	{
	 digitalWrite(led1, HIGH);
	 digitalWrite(led2, HIGH);
	 digitalWrite(led3, HIGH);
	 digitalWrite(led4, HIGH);
	 digitalWrite(led5, LOW);
	 digitalWrite(led6, HIGH);
	 digitalWrite(led7, HIGH);
	}
}
