/*
   SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)
*/

#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;
File myFile;

int buttonPin = 9;
int ledPin = 10;
int count = 0;

bool LOGGER_ON = false;
bool FILE_OPENED = false;

void setup() {  
  uint32_t currentFrequency;
  
  // Init ina219
  if (! ina219.begin()) {
    while (1) { delay(10); }
  }

  // Init SD card
  if (!SD.begin(4)) {
    while (1) { delay(10); }
  }

  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if(digitalRead(buttonPin) == HIGH) {
    LOGGER_ON = !LOGGER_ON;
    count = 0;
    digitalWrite(ledPin, LOW);
    delay(2500);
  }

  if(LOGGER_ON == true) {
    if(FILE_OPENED == false) {
      myFile = SD.open("data.txt", FILE_WRITE);
      FILE_OPENED = true;
    }
    
    float shuntvoltage = 0;
    float busvoltage = 0;
    float current_mA = 0;
    float loadvoltage = 0;
    float power_mW = 0;
  
    shuntvoltage = ina219.getShuntVoltage_mV();
    busvoltage = ina219.getBusVoltage_V();
    current_mA = ina219.getCurrent_mA();
    power_mW = ina219.getPower_mW();
    loadvoltage = busvoltage + (shuntvoltage / 1000);
    
    String line = (String(count) + "," + 
                    String(shuntvoltage) + "," + 
                    String(busvoltage) + "," + 
                    String(current_mA) + "," +
                    String(power_mW) + "," +
                    String(loadvoltage));
                    
    myFile.println(line);

    count++;
    
    delayMicroseconds(1);
  } else {
    if(FILE_OPENED == true) {
      myFile.close();
      FILE_OPENED = false;
    }

    delay(1000);
  }

  if(FILE_OPENED == true) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
