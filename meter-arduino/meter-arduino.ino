#include <Wire.h>
#include <Adafruit_INA219.h>
#include <SPI.h>
#include <SD.h>

Adafruit_INA219 ina219;
// Ensure startPin matches your arduino configuration
int startPin = 10;
// Pin 13 is the in-build arduino LED
int ledPin = 13;
boolean measuring = false;
int measurementStep = 0;
File mFile;
String line = "";
int val;

void measure() {
  if (measuring) {
    measurementStep += 1;
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
    
    Serial.print("Bus Voltage:   "); Serial.print(busvoltage); Serial.println(" V");
    Serial.print("Shunt Voltage: "); Serial.print(shuntvoltage); Serial.println(" mV");
    Serial.print("Load Voltage:  "); Serial.print(loadvoltage); Serial.println(" V");
    Serial.print("Current:       "); Serial.print(current_mA); Serial.println(" mA");
    Serial.print("Power:         "); Serial.print(power_mW); Serial.println(" mW");
    //Serial.println("");

    line = String(measurementStep)+","+
      String(shuntvoltage)+","+
      String(busvoltage)+","+
      String(current_mA)+","+
      String(power_mW)+","+
      String(loadvoltage) + "\n";
    
    if (mFile) {
      Serial.print("Writing to data.csv...");
      mFile.println(line);
    }
  }
}

void setup(void) 
{
  Serial.begin(9600);
  while (!Serial) {
      // will pause Zero, Leonardo, etc until serial console opens
      delay(1);
  }

  uint32_t currentFrequency;
  
  if (! ina219.begin()) {
    Serial.println("Failed to find INA219 chip");
    while (1) { delay(10); }
  }
  Serial.println("Measuring voltage and current with INA219 ...");

  Serial.println("Setting up the digital pins!");
  pinMode(ledPin, OUTPUT);
  // INPUT_PULLUP enables the button's internal resistor
  pinMode(startPin, INPUT_PULLUP);

  Serial.print("Initializing SD card...");
  if (!SD.begin(5)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("SD initialization done.");
}

void loop(void) 
{
  // Start Button
  val = digitalRead(startPin);
  if (val == LOW) {                // if button pressed
    if (!measuring) {
      measuring = true;
      mFile = SD.open("data.csv", FILE_WRITE);
      digitalWrite(ledPin, HIGH);  // turn ON OFF - start measuring
      delay(500);
    } else {
      measuring = false;
      measurementStep = 0;
      mFile.close();
      digitalWrite(ledPin, LOW);  // turn LED OFF - stop measuring
      delay(500);
    } 
  } 

  measure();
}
