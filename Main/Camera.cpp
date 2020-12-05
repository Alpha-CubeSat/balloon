#include "Camera.h"

Camera::Camera(HardwareSerial *hwSerial, usb_serial_class *swSerial): adaCam(hwSerial){
  softwareSerial = swSerial;
}

void Camera::setup(){
  //254 is BUILTIN_SDCARD
  (SD.begin(254)) ? getSoftwareSerial().println("SD card found") : getSoftwareSerial().println("SD card not found");
  adaCam.begin() ? getSoftwareSerial().println("Camera found") : getSoftwareSerial().println("Camera not found");
  adaCam.setImageSize(VC0706_640x480);  
  getSoftwareSerial().println("Camera is setup");
}


void Camera::takePhoto(){
  if (!adaCam.takePicture()){ 
    getSoftwareSerial().println("Photo not taken");
  }
  else{
    getSoftwareSerial().println("Photo taken");

    // Create an image with the name IMAGExx.JPG
    char filename[13];
    strcpy(filename, "IMAGE00.JPG");
    for (int i = 0; i < 100; i++) {
      filename[5] = '0' + i/10;
      filename[6] = '0' + i%10;
      // create if does not exist, do not open existing, write, sync after write
      if (!SD.exists(filename)) {
        break;
      }
    }
      
    // Open the file for writing
    File imgFile = SD.open(filename, FILE_WRITE);
    
    // Get the size of the image (frame) taken  
    uint16_t jpglen = adaCam.frameLength();
    
    // Read all the data up to # bytes!
    byte wCount = 0; // For counting # of writes
    while (jpglen > 0) {
      // read 32 bytes at a time;
      uint8_t *buffer;
      uint8_t bytesToRead = min(64, jpglen); // change 32 to 64 for a speedup but may not work with all setups!
      buffer = adaCam.readPicture(bytesToRead);
      imgFile.write(buffer, bytesToRead);
      if(++wCount >= 64) { // Every 2K, give a little feedback so it doesn't appear locked up
        wCount = 0;
      }
      jpglen -= bytesToRead;
    }
    imgFile.close();
    getSoftwareSerial().println("Photo saved");
  }
}



