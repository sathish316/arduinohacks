const int redLed1 = 8;
const int redLed2 = 9;
const int yellowLed = 3;

const int switchPin = 2;

void setup() {
  // declare leds as output
  pinMode(redLed1, OUTPUT);
  pinMode(redLed2, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  // declare switch as input
  pinMode(switchPin, INPUT);
}

void loop() {
  int switchState;
  switchState = digitalRead(switchPin);
  if(switchState == LOW){
    // turn main led off
    digitalWrite(yellowLed, LOW);
    // blink red leds
    digitalWrite(redLed1, HIGH);
    digitalWrite(redLed2, LOW);
    delay(250);
    digitalWrite(redLed1, LOW);
    digitalWrite(redLed2, HIGH);
    delay(250);
  } else {
    // turn off blinking leds
    digitalWrite(redLed1, LOW);
    digitalWrite(redLed2, LOW);
    // turn on main leds
    digitalWrite(yellowLed, HIGH);
  }
}
