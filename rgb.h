// *Interfacing RGB LED with Arduino 

//Defining  variable and the GPIO pin on Arduino
#define PIN_RED 11
#define PIN_GREEN 10
#define PIN_BLUE 9
#define DELTA_COLOR 10

void setColor(int redValue, int greenValue,  int blueValue) {
  analogWrite(PIN_RED, redValue);
  analogWrite(PIN_GREEN,  greenValue);
  analogWrite(PIN_BLUE, blueValue);
}


void initRgb() {
  //Defining the pins as OUTPUT
  pinMode(PIN_RED,  OUTPUT);              
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
  setColor(255, 0, 0); // Red Color
}



int delta_red = -1;
int delta_green = +1;
int delta_blue = 0;
int current_red = 255;
int current_green = 0;
int current_blue = 0;


void  rgbLoop() {
  setColor(current_red, current_green,  current_blue); 
  if(current_red > 255 - DELTA_COLOR) {
    // full red reached:
    delta_red = -DELTA_COLOR;
    delta_green = DELTA_COLOR;
    delta_blue = 0;
    current_red = 255;
    current_green = 0;
    current_blue = 0;
  }
  if(current_green > 255 - DELTA_COLOR) {
    // full green reached:
    delta_red = 0;
    delta_green = -DELTA_COLOR;
    delta_blue = DELTA_COLOR;
    current_red = 0;
    current_green = 255;
    current_blue = 0;
  }
  if(current_blue > 255 - DELTA_COLOR) {
    // full blue reached:
    delta_red = DELTA_COLOR;
    delta_green = 0;
    delta_blue = -DELTA_COLOR;
    current_red = 0;
    current_green = 0;
    current_blue = 255;
  }
  current_red += delta_red;
  current_green += delta_green;
  current_blue += delta_blue;
}

// values: 0 .. 99 (0: full red, 33: full green; 66: full blue)
void setColorByValue(int percent) {
  if(percent < 33) {
    current_red = 255 - (256*percent/33);
    current_green = 256*percent/33;
    current_blue = 0;
  } else if(percent < 66) {
    current_red = 0;
    current_green = 255 - (256*(percent-33)/33);
    current_blue = 256*(percent-33)/33;
  } else {
    current_red = 256*(percent-66)/33;
    current_green = 0;
    current_blue = 255 - (256*(percent-66)/33);
  }
  setColor(current_red, current_green,  current_blue); 
}
