const int ledPin = 13;
const int piezoPin = 9;
int sensorValue;
int sensorLow = 1024;
int sensorHigh = 0;
int freqLow = 50;
int freqHigh = 4000;

void setup() {
  pinMode(ledPin, OUTPUT);
  // start calibration
  digitalWrite(ledPin, HIGH);
  while(millis() < 5000){
    sensorValue = analogRead(A0);
    // find sensor high value
    if(sensorValue > sensorHigh){
      sensorHigh = sensorValue;
    }
    // find sensor low value
    if(sensorValue < sensorLow){
      sensorLow = sensorValue;
    }
  }
  // stop calibration  
  digitalWrite(ledPin, LOW);
}

void loop() {
  // read ldr sensor value
  sensorValue = analogRead(A0);
  int pitch = map(sensorValue, sensorLow, sensorHigh, freqLow, freqHigh);
  tone(piezoPin, pitch, 20);
  delay(10);
}
