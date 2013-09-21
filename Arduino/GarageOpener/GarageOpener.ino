
#include <XBee.h>
XBee xbee;
XBeeAddress64 coordinatorAddress;
XBeeResponse response;
ZBRxResponse zbrx;

#define LEDPIN 13

void setup()
{

  Serial.begin(9600);  
  pinMode(LEDPIN, OUTPUT);
}

void blink(int times)
{
  for (int i = 0; i < times; i++)
  {
    digitalWrite(LEDPIN, HIGH);
    delay(20);
    digitalWrite(LEDPIN, LOW);
    delay(20);
  }
  delay(30); 
  digitalWrite(LEDPIN, HIGH);
}

void loop()
{
  if (Serial.available() > 0)
  {
    Serial.println(Serial.read());
  }
  
}



