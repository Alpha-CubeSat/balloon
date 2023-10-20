
/*
* Alpha Flight Hardware Acceptance Tests
* Photoresistor
* 
* Test on breadboard with a Teesny 3.5 (test unit, not flight) and 10k resistor
* Follow electrical schematic to wire sensor to the Teensy
* Test teensy will not have V-USB trace cut out. Use with normal micro-USB cable 
* No external power supply needed beyond USB cable.
* 
* Acceptance criteria: resistance value is in 100's of kOhm range when covered by hand, and orders of magnitude lower when exposed to light
* 
* Written by JSU4 March 06 2021
*/
 
// Light sensor constants //
#define LIGHT_SENSE A8 //this may need to be fixed to Pin 20
int lightR2 = 10000; //10kohm resistor
const float VOLTAGE_REF = 3.3;  // Reference voltage for analog read
int RESOLUTION = 1023; // 10 bit resolution of Teensy 3.5
 
// Light sensor global variables
int lightReadVal;
float lightReadVolt;
float photoresistance;

void setup() {
  Serial.begin(9600);
}


 
void readPhotoresistor(){
  lightReadVal = analogRead(LIGHT_SENSE);
  lightReadVolt = lightReadVal*VOLTAGE_REF/RESOLUTION;
  photoresistance = lightR2*(VOLTAGE_REF-lightReadVolt)/lightReadVolt;
  // using VOLTAGE_REF in line above because teensy regulated 3.3V is now fed to photoresistor
  // in other words, 3.3V is now the Vin to the voltage divider
  Serial.print("photoresistance: "); Serial.print(photoresistance);
  Serial.println(" Ohms");
}
 
void loop() {
  // put your main code here, to run repeatedly:
  readPhotoresistor();
  delay(500);
}
