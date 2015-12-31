const int SENSOR = 0;
const int LED = 9;
int lightLevel, high = 0, low = 1023;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  lightLevel = analogRead(SENSOR); // analogRead returns values from 0 to 1023
  lightLevel = map(lightLevel, 0, 1023, 0, 255);
  lightLevel = constrain(lightLevel, 0, 255);
  analogWrite(LED, lightLevel); // analogWrite expects values from 0 to 255  
}
