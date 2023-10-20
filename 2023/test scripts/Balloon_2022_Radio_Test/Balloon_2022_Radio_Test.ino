/*
* Alpha Flight Hardware Acceptance Tests
* Rockblock
* 
* Test on breadboard with a Teesny 3.5 (test unit, not flight)
* Follow electrical schematic to wire sensor to the Teensy
* Test teensy will not have V-USB trace cut out. Use with normal micro-USB cable 
* No external power supply needed beyond USB cable.
* 
* Acceptance criteria: A message of 70 bytes of 0s should appear on the rockblock message portal.
*
* Written by LJG March 13 2021
*/
 
// Rockblock constants //
#define RockblockSerial Serial7; //(RX:28.TX:29 on Teensey 4.1)
 
// Rockblock Global Variables
int step = 0; //Variable to store where in send sequence
uint8_t report[70] = {0}; //empty report to uplink
 
void setup() {
  // put your setup code here, to run once:
  RockblockSerial.begin(19200);  
}
 
void loop() {
  // put your main code here, to run repeatedly:
    switch(step) {
      case 0:
      {
        delay(250);
        Serial.println("Sending AT");
        RockblockSerial.print("AT\r");
        step = 1;
        break; 
      }
      case 1:
      {
        delay(250);
        Serial.println("Awaiting AT response");
        if(RockblockSerial.read()==75){
          step = 2;
        } 
        break;
      }
      case 2:
      {
        delay(250);
        Serial.println("Sending flow control command");
        RockblockSerial.print("AT&K0\r");
        step = 3;
        break;
      }
      case 3:
      {
        delay(250);
        Serial.println("Awaiting flow control command response");
        if(RockblockSerial.read()==75){
          step = 4;
        }
        break;
      }
      case 4:
      {
        delay(250);
        Serial.println("Sending message length");
        RockblockSerial.print("AT+SBDWB=70\r");
        step = 5;
        break;
      }
      case 5:
      {
        delay(250);
        Serial.println("Awaiting message length response");
        if(RockblockSerial.read()==89){
          step = 6;
        } 
        break;
      }
      case 6:
      {
        delay(250);
        Serial.println("Send message");
        uint16_t checksum = 0;
        for (size_t i=0; i<sizeof(report); ++i){
          RockblockSerial.write(report[i]);
          checksum += (uint16_t)report[i];
        }
        RockblockSerial.write(checksum >> 8);
        RockblockSerial.write(checksum & 0xFF);
        step = 7;                
        break;
      }
      case 7:
      {
        delay(250);
        Serial.println("Await message response");
        uint8_t c = RockblockSerial.read();
        if(c == 48 || c == 49 || c == 50 || c == 51){
          if(c == 48){
            step = 8;
          }
          else{
            step = 6;
          }
        }
        break;
      }
      case 8:
      {
        delay(250);
        Serial.println("Send response");
        RockblockSerial.print("AT+SBDIX\r");
        step = 9;
        break;
      }
      case 9:
      {
        delay(250);
        Serial.println("Check portal");
 
        if(RockblockSerial.read() == 58){
          //This will print out the SBDIX response. If it starts with a 32, this means the signal quality is too low.
          while(RockblockSerial.available()){
            Serial.println((char)RockblockSerial.read());
          }
          //Uncomment if you are struggling to find signal and want to continuously retry
          step = 6;
          delay(10000);
        }
      }
    }
}
