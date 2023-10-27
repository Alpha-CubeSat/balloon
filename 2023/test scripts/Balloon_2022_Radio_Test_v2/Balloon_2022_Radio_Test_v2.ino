#include <SoftwareSerial.h>

SoftwareSerial RockblockSerial(28,29);

void setup()
{
mySerial.begin(19200);
Serial.begin(19200);
}

void loop()
{
  if (RockblockSerial.available()){
    Serial.print(RockblockSerial.read());
  }
}
