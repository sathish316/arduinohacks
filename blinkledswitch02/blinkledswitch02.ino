const int LED = 13;
const int BUTTON = 2;
int val = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  digitalWrite(BUTTON, HIGH);
}

void loop() {
  val = digitalRead(BUTTON);
  digitalWrite(LED, val);
}
