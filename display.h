
/*
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D

*/

#define PIN_A 12
#define PIN_B 8
#define PIN_C A2
#define PIN_D A1
#define PIN_E A0
#define PIN_F 11
#define PIN_G A3

#define PIN_DIGIT_1 13
#define PIN_DIGIT_2 10
#define PIN_DIGIT_3 9

#define NO_DIGIT -1
#define DISP_DELAY 3

void pickDigit(int digit_pin) {
  switch(digit_pin) {
    case PIN_DIGIT_1:
      digitalWrite(PIN_DIGIT_1, LOW);
      digitalWrite(PIN_DIGIT_2, HIGH);
      digitalWrite(PIN_DIGIT_3, HIGH);
      break;
    case PIN_DIGIT_2:
      digitalWrite(PIN_DIGIT_1, HIGH);
      digitalWrite(PIN_DIGIT_2, LOW);
      digitalWrite(PIN_DIGIT_3, HIGH);
      break;
    case PIN_DIGIT_3:
      digitalWrite(PIN_DIGIT_1, HIGH);
      digitalWrite(PIN_DIGIT_2, HIGH);
      digitalWrite(PIN_DIGIT_3, LOW);
      break;
    default:
      digitalWrite(PIN_DIGIT_1, HIGH);
      digitalWrite(PIN_DIGIT_2, HIGH);
      digitalWrite(PIN_DIGIT_3, HIGH);
      break;
  }
}

void clearDigit() {
  digitalWrite(PIN_A, LOW);
  digitalWrite(PIN_B, LOW);
  digitalWrite(PIN_C, LOW);
  digitalWrite(PIN_D, LOW);
  digitalWrite(PIN_E, LOW);
  digitalWrite(PIN_F, LOW);
  digitalWrite(PIN_G, LOW);
}


void initDisplay() {
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
  pinMode(PIN_E, OUTPUT);
  pinMode(PIN_F, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_DIGIT_1, OUTPUT);
  pinMode(PIN_DIGIT_2, OUTPUT);
  pinMode(PIN_DIGIT_3, OUTPUT);
  pickDigit(NO_DIGIT);
  clearDigit();
  delay(DISP_DELAY);
}

int loop_position = 0;
//int loop_values[10][2] = 
//  {{PIN_DIGIT_1,PIN_A},{PIN_DIGIT_1,PIN_F},{PIN_DIGIT_1,PIN_E},{PIN_DIGIT_1,PIN_D},{PIN_DIGIT_2,PIN_D},
//   {PIN_DIGIT_3,PIN_D},{PIN_DIGIT_3,PIN_C},{PIN_DIGIT_3,PIN_B},{PIN_DIGIT_3,PIN_A},{PIN_DIGIT_2,PIN_A}};

int loop_values[6][2] = 
  {{PIN_DIGIT_3,PIN_A},{PIN_DIGIT_3,PIN_F},{PIN_DIGIT_3,PIN_E},
   {PIN_DIGIT_3,PIN_D},{PIN_DIGIT_3,PIN_C},{PIN_DIGIT_3,PIN_B}};

void nextLoop() {
  clearDigit();
  pickDigit(PIN_DIGIT_1);
  if(loop_values[loop_position][0] == PIN_DIGIT_1) digitalWrite(loop_values[loop_position][1], HIGH);
  delay(DISP_DELAY);

  clearDigit();
  pickDigit(PIN_DIGIT_2);
  if(loop_values[loop_position][0] == PIN_DIGIT_2) digitalWrite(loop_values[loop_position][1], HIGH);
  delay(DISP_DELAY);

  clearDigit();
  pickDigit(PIN_DIGIT_3);
  if(loop_values[loop_position][0] == PIN_DIGIT_3) digitalWrite(loop_values[loop_position][1], HIGH);
  delay(DISP_DELAY);

  loop_position = (loop_position + 1) % 6;
}
 
void zero()  //define 0 as cathode pin switch
{
  digitalWrite(PIN_A, HIGH);
  digitalWrite(PIN_B, HIGH);
  digitalWrite(PIN_C, HIGH);
  digitalWrite(PIN_D, HIGH);
  digitalWrite(PIN_E, HIGH);
  digitalWrite(PIN_F, HIGH);
  digitalWrite(PIN_G, LOW);
}
 
void one()  // define 1 as cathode pin switch
{
  digitalWrite(PIN_A, LOW);
  digitalWrite(PIN_B, HIGH);
  digitalWrite(PIN_C, HIGH);
  digitalWrite(PIN_D, LOW);
  digitalWrite(PIN_E, LOW);
  digitalWrite(PIN_F, LOW);
  digitalWrite(PIN_G, LOW);
}
 
void two()  // define 2 as cathode pin switch
{
  digitalWrite(PIN_A, HIGH);
  digitalWrite(PIN_B, HIGH);
  digitalWrite(PIN_C, LOW);
  digitalWrite(PIN_D, HIGH);
  digitalWrite(PIN_E, HIGH);
  digitalWrite(PIN_F, LOW);
  digitalWrite(PIN_G, HIGH);
}
 
void three()  // define 3 as cathode pin switch
{
  digitalWrite(PIN_A, HIGH);
  digitalWrite(PIN_B, HIGH);
  digitalWrite(PIN_C, HIGH);
  digitalWrite(PIN_D, HIGH);
  digitalWrite(PIN_E, LOW);
  digitalWrite(PIN_F, LOW);
  digitalWrite(PIN_G, HIGH);
}
 
void four()  // define 4 as cathode pin switch
{
  digitalWrite(PIN_A, LOW);
  digitalWrite(PIN_B, HIGH);
  digitalWrite(PIN_C, HIGH);
  digitalWrite(PIN_D, LOW);
  digitalWrite(PIN_E, LOW);
  digitalWrite(PIN_F, HIGH);
  digitalWrite(PIN_G, HIGH);
}
 
void five()  // define 5 as cathode pin switch
{
  digitalWrite(PIN_A, HIGH);
  digitalWrite(PIN_B, LOW);
  digitalWrite(PIN_C, HIGH);
  digitalWrite(PIN_D, HIGH);
  digitalWrite(PIN_E, LOW);
  digitalWrite(PIN_F, HIGH);
  digitalWrite(PIN_G, HIGH);
}
 
void six()  // define 6 as cathode pin switch
{
  digitalWrite(PIN_A, HIGH);
  digitalWrite(PIN_B, LOW);
  digitalWrite(PIN_C, HIGH);
  digitalWrite(PIN_D, HIGH);
  digitalWrite(PIN_E, HIGH);
  digitalWrite(PIN_F, HIGH);
  digitalWrite(PIN_G, HIGH);
}
 
void seven()  // define 7 as cathode pin switch
{
  digitalWrite(PIN_A, HIGH);
  digitalWrite(PIN_B, HIGH);
  digitalWrite(PIN_C, HIGH);
  digitalWrite(PIN_D, LOW);
  digitalWrite(PIN_E, LOW);
  digitalWrite(PIN_F, LOW);
  digitalWrite(PIN_G, LOW);
}
 
void eight()  // define 8 as cathode pin switch
{
  digitalWrite(PIN_A, HIGH);
  digitalWrite(PIN_B, HIGH);
  digitalWrite(PIN_C, HIGH);
  digitalWrite(PIN_D, HIGH);
  digitalWrite(PIN_E, HIGH);
  digitalWrite(PIN_F, HIGH);
  digitalWrite(PIN_G, HIGH);
}
 
void nine()  // define 9 as cathode pin switch
{
  digitalWrite(PIN_A, HIGH);
  digitalWrite(PIN_B, HIGH);
  digitalWrite(PIN_C, HIGH);
  digitalWrite(PIN_D, HIGH);
  digitalWrite(PIN_E, LOW);
  digitalWrite(PIN_F, HIGH);
  digitalWrite(PIN_G, HIGH);
}


void pickNumber(int x)   //define pickNumber(x)to display number x
{
  switch(x)
  {
  default: 
    zero(); 
    break;
  case 1: 
    one(); 
    break;
  case 2: 
    two(); 
    break;
  case 3: 
    three(); 
    break;
  case 4: 
    four(); 
    break;
  case 5: 
    five(); 
    break;
  case 6: 
    six(); 
    break;
  case 7: 
    seven(); 
    break;
  case 8: 
    eight(); 
    break;
  case 9: 
    nine(); 
    break;
  }
}
 

void printNumber(int n) {
  if(n>=100) {
    clearDigit();
    pickDigit(PIN_DIGIT_1);
    pickNumber((n/100) % 10);
    delay(DISP_DELAY);
  }

  if(n>=10) {
    clearDigit();
    pickDigit(PIN_DIGIT_2);
    pickNumber((n/10) % 10);
    delay(DISP_DELAY);
  }

  clearDigit();
  pickDigit(PIN_DIGIT_3);
  pickNumber(n % 10);
  delay(DISP_DELAY);

}

