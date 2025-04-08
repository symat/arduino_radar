#define LEFT -2
#define MID_LEFT -1
#define CENTER 0
#define MID_RIGHT 1
#define RIGHT 2

int current_analog_read = 512;

int current_pos = CENTER;
int button_pressed = 0;

int prev_read_pos = CENTER;
int prev_read_pressed = 0;

void initJoystick() {
  pinMode(A4, INPUT_PULLUP);
}

int analogToPos(int a) {
  if(a < 100) return RIGHT;
  if(a < 462) return MID_RIGHT;
  if(a < 562) return CENTER;
  if(a < 924) return MID_LEFT;
  return LEFT;
}

void updateJoystick() {
  current_analog_read = analogRead(A5);
  if(analogToPos(current_analog_read) == prev_read_pos) current_pos = prev_read_pos;
  prev_read_pos = analogToPos(current_analog_read);

  int current_button_read = !digitalRead(A4);
  if(current_button_read == prev_read_pressed) button_pressed = current_button_read;
  prev_read_pressed = current_button_read;
}

