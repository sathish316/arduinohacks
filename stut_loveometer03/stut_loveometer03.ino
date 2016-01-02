const int ledPin = 13;

int sensorValue;
int sensorLow = 1024;
int sensorHigh = 0;
int sensorRange;
int sensorOffset;

void setup() {
  // Start serial port
  Serial.begin(9600);
  // assign ledpin to output
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
  sensorRange = sensorHigh - sensorLow;
  // stop calibration  
  digitalWrite(ledPin, LOW);
  Serial.println("Calibration completed");
  Serial.print("minValue=");
  Serial.print(sensorLow);
  Serial.print(",maxValue=");
  Serial.print(sensorHigh);
  Serial.print(",range=");
  Serial.println(sensorRange);
  // assign led output pins
  for(int x=4; x<8; x++){
    pinMode(x, HIGH);
    digitalWrite(x, LOW);
  }
}

void loop() {
  // read ldr sensor value
  sensorValue = analogRead(A0); // using a light sensor instead of temp sensor
  Serial.print("value=");
  Serial.print(sensorValue);
  Serial.print(",band=");
  sensorOffset = sensorValue - sensorLow;
  if(sensorOffset > 0 && sensorOffset < 0.25 * sensorRange){
    Serial.println(1);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  } else if(sensorOffset >= 0.25 * sensorRange && sensorOffset < 0.5 * sensorRange){
    Serial.println(2);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);  
  } else if(sensorOffset >= 0.5 * sensorRange && sensorOffset < 0.75 * sensorRange){
    Serial.println(3);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
  } else if(sensorOffset >= 0.75 * sensorRange){
    Serial.println(4);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
  } else {
    Serial.println(0);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);    
  }
}
