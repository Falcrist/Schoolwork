int input = 0;
float temperature;

void setup()
{
    Serial.begin(9600);
}
void loop()
{
    temperature = (analogRead(input) / 20.46) - 27.3;
    Serial.print(temperature);
    Serial.println(" degC");
    delay(500);
}
