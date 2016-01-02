const int ledPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if(Serial.available() > 0){
    char ch = Serial.read();
    Serial.print("Received:");
    Serial.println(ch);
    if(ch == 'a'){
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
  } else {
    delay(100);
    Serial.println("NOMSG");
  }
  

}
