int cm = 0;

void setup()
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
