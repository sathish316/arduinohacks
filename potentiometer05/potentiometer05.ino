const int SENSOR = 0;
const int LED = 12;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  int sensorValue;
  sensorValue = analogRead(SENSOR);
  digitalWrite(LED, HIGH);
  delay(sensorValue);
  digitalWrite(LED, LOW);
  delay(sensorValue);
}
