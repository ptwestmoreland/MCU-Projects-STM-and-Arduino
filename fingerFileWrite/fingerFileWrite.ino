#include <Adafruit_Fingerprint.h>
#include <SD.h> // spi and SD needed to write to txt file 
#include <SPI.h>

#if (defined(__AVR__) || defined(ESP8266)) 

SoftwareSerial mySerial(2, 3);

#endif

File outFile; // create file 
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial); // create finger

void setup()
{
  //File outFile; // create file 
  while (!Serial); //open serial and wait 
  Serial.begin(9600); // serial transmit rate 
 
  finger.begin(57600); // data transfer rate 

 
  unsigned int ID = 65; // my stored fingerprint ID 
    downloadFinger(ID);

    outFile = SD.open("fingerData.txt", FILE_WRITE); // open file 
  
} // end set up 

uint8_t downloadFinger(uint16_t id)
{

  uint8_t k = finger.loadModel(id); // load i
  switch (k) {
    case FINGERPRINT_OK: // defined const 
      break;
    default:
      Serial.print("Error: "); Serial.println(k);
      return k;
  }

  k = finger.getModel();
  uint8_t bytesArr[534]; // storepackets, some of info is not important 
  memset(bytesArr, 0xff, 534); // set aside mem 

  uint32_t starttime = millis();
  int i = 0;
  while (i < 534 && (millis() - starttime) < 20000) {
    if (mySerial.available()) {
      bytesArr[i++] = mySerial.read(); // read sent in data 
    }
  }
  uint8_t fingerData[512]; // finger byte array 
  memset(fingerData, 0xff, 512);

  int indx0 = 9, index = 0;
  memcpy(fingerData + index, bytesArr + indx0, 256);   // Stur first half of bytes
  indx0 += 256;      
  indx0 += 2;        
  indx0 += 9;        
  index += 256;       
  memcpy(fingerData + index, bytesArr + indx0, 256);   // Stur second portion of data 

  for (int i = 0; i < 512; ++i) {
    
    Serial.print(fingerData[i], 2); // print binary data 

   if(outFile) { // executes when file opens succesfully
      Serial.print("Write to file: ");
      outFile.println(fingerData[i],2);
    } 
    
  }

  return k;
  outFile.close();

} // end function 

void loop() {
  while(true) { 
    continue; // infinite loop to terminate program 
  }
 

}
