const int RED = 9;
const int BLUE = 10;
const int GREEN = 11;
const int DISPLAY_TIME = 10;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  int x;
  for(x=0; x<768; x++){
    showRGB(x);
    delay(DISPLAY_TIME);
  }
}

void showRGB(int color){
  int redValue;
  int greenValue;
  int blueValue;

  if(color <= 255){
    redValue = 255 - color;
    greenValue = 0;
    blueValue = 0;
  } else if (color <= 511){
    redValue = 0;
    greenValue = 255 - (color - 255);
    blueValue = 0;
  } else {
    redValue = 0;
    greenValue = 0;
    blueValue = 255 - (color - 512);
  }
  analogWrite(RED, redValue);
  analogWrite(GREEN, greenValue);
  analogWrite(BLUE, blueValue);
}

