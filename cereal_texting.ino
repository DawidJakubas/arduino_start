char rx_byte = 0;
int led = LED_BUILTIN;
void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  //delay(5000);
}
void loop()
{
  if (Serial.available() > 0) {    // is a character available?
    srwrite(rx_byte /*txt*/, 100 /*delay*/, true /*LED On/Off*/);
  }
  else
  {
    analogWrite(led, LOW);
  }
}
void srwrite(char text, int delayTime, boolean ledOn)
{
  if (ledOn == true)
  {
    analogWrite(led, HIGH);
  }
  else
  {
    analogWrite(led, LOW);
  }
  rx_byte = Serial.read();       // get the character
  Serial.print(text);
  delay(delayTime);
}
