#include "motor.h"
#include "ultrasonic.h"
//#include "joystick.h"
//#include "display.h"
#include "rgb.h"


#define MODE_RGB_LOOP 0
#define MODE_RGB_MANUAL 1
#define MODE_RGB_ULTRASONIC 2

int mode = MODE_RGB_LOOP;
int step = 0;

#define DEBUG 1
#define SENSOR_READ_STEPS 3

void setup() {
  setSpeed(MID_SPEED);
  initContinousMove();
  initUltrasonic();
  //initJoystick();
  initRgb();
  //initDisplay();
  if(DEBUG) {
    Serial.begin(9600);
  }
}

void loop() {
  
  if(step == SENSOR_READ_STEPS) {
    step = 0;
    int distance = readDistance();
    pinMode(A0, INPUT_PULLUP); // so that we read ~1023 with the next analog read, when no potentiometer is connected

    // we have a 10K resistor to 5V and a 10K poentiometer. 
    // So total left should be: ~512; total right: ~0 (in practice: 600 ... 40)
    int current_analog_read = analogRead(A0);
    long x = current_analog_read - 30;
    if(x < 0) x = 0;
    if(x > 549) x = 549;
    int current_potmeter_percentage = 100 - (int)(x * 100 / 550);

    int color_percentage = 0; 

    int old_mode = mode;
    if(current_analog_read > 900) { // we have no potentiometer
      mode = MODE_RGB_LOOP;  
      rgbLoop();
      if(old_mode != mode) setSpeed(MID_SPEED); 
    } else if(distance == 0) {      // we have no ultrasonic sensor (or distance over 15 meters)
      mode = MODE_RGB_MANUAL;       
      color_percentage = current_potmeter_percentage;
      setColorByValue(color_percentage);
      if(old_mode != mode) setSpeed(MID_SPEED); 
    } else {                        // we have everything
      mode = MODE_RGB_ULTRASONIC;
      if(old_mode != mode) initContinousMove();     
      long y = distance;
      if(y > 399) y = 399;
      // 0cm: full red (0%); 400cm+: full blue (66%)
      color_percentage = (int)(y *100 / 600);
      setColorByValue(color_percentage);
      setSpeedByValue(current_potmeter_percentage);
    }

    if(DEBUG) {
      Serial.println(
        (String)"pos:" + currentPosition + 
        " dist:" + distance + "cm" +
        " speed:" + current_speed + 
     // " btn:" + button_pressed + 
        " mode:" + mode + 
        " potm:" + current_potmeter_percentage + 
        "% colorP:" + color_percentage + 
        " rgb:" + current_red + "," + current_green + "," + current_blue +
        " (pot:" + current_analog_read + ")"
      );
    }
  }
  step += 1;
  move();


}