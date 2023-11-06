#include <SoftwareSerial.h>

SoftwareSerial RockblockSerial(29,28);

void setup()
{
RockblockSerial.begin(19200);
Serial.begin(9600);
}

void loop()
{
 
  if (RockblockSerial.available()){
    Serial.print(RockblockSerial.read());
  }
  else{
    Serial.print("Rockblock Serial Unavaiable");
  }
}
