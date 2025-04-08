#include <Stepper.h>

const int STEPS_PER_REVOLUTION = 2048;  // change this to fit the number of steps per revolution
// for your motor

const int ONE_MOVE = 8;  // number of steps taken in one move

const int SLOW_SPEED = 1;
const int MID_SPEED = 2;
const int HIGH_SPEED = 5;
/*
const int SLOW_SPEED = 3;
const int MID_SPEED = 8;
const int HIGH_SPEED = 12;
*/

int currentPosition = 0;
int direction = 1;
int current_speed = MID_SPEED;


Stepper myStepper(STEPS_PER_REVOLUTION, 7, 5, 6, 4);

void setSpeed(int speed) {
  current_speed = speed;
  myStepper.setSpeed(current_speed);
}


void setSpeedByValue(int speedPercentage) {
  current_speed =  SLOW_SPEED + (int)( (float)( HIGH_SPEED - SLOW_SPEED  ) * speedPercentage / 100.0);
  myStepper.setSpeed(current_speed);
}

void forward() {
  myStepper.step(ONE_MOVE);
}

void backward() {
  myStepper.step(-ONE_MOVE);
}

void initContinousMove() {
  currentPosition = 0;
  direction = 1;
}

void move() {
  int nextPosition = currentPosition + (direction > 0 ? ONE_MOVE : -ONE_MOVE);
  
  myStepper.step(nextPosition - currentPosition);
  currentPosition = nextPosition;
  if(currentPosition == 0 || currentPosition == STEPS_PER_REVOLUTION/2) {
    direction *= -1;
  }
}
