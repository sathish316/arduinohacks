#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);//RX, TX
const int ledPin = 13;
int BluetoothData;
int enableSerial = 1;

void setup() {
  if(enableSerial){
    Serial.begin(9600);
    Serial.println("Bluetooth on. Press 1 or 0");
  }
  BTSerial.begin(9600);
  BTSerial.println("Bluetooth on. Press 1 or 0");
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if(BTSerial.available() > 0){
    BluetoothData = BTSerial.read();
    if(enableSerial){
      Serial.print("Got data:");
      Serial.println(BluetoothData);
    }
    if(BluetoothData == '1'){
      digitalWrite(ledPin, HIGH);
      BTSerial.println("LED ON");
      if(enableSerial){
        Serial.println("LED ON");
      }
    }
    if(BluetoothData == '0'){
      digitalWrite(ledPin, LOW);
      BTSerial.println("LED OFF");
      if(enableSerial){
        Serial.println("LED OFF");
      }
    }
  }
  delay(100);
}
