int cm = 0;

<<<<<<< HEAD
void setup()
=======
Adafruit_INA219 ina219;
int startPin = 9;
int ledPin = 10;
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
    //Serial.print("Load Voltage:  "); Serial.print(loadvoltage); Serial.println(" V");
    Serial.print("Current:       "); Serial.print(current_mA); Serial.println(" mA");
    Serial.print("Power:         "); Serial.print(power_mW); Serial.println(" mW");
    //Serial.println("");

    line = measurementStep+","+
      String(shuntvoltage)+","+
      String(bustvoltage)+","+
      String(current_mA)+","+
      String(power_mW)+","+
      String(loadvoltage)"\n";
    
    if (mFile) {
      Serial.print("Writing to data.csv...");
      mFile.println(line);
    }
  }
}

void setup(void) 
>>>>>>> 971777c68f0d87c16516e26c4298eb84ca2b9ed1
{
  Serial.begin(9600);
  pinMode(7,INPUT);
}

void loop() {
  Serial.print("Distancia: ");
  cm = 0.01723 * digitalRead(7);
  Serial.println(cm);
  delay(500);
}
