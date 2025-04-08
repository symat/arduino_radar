const int trigPin = 2;
const int echoPin = 3;

float duration, distance;

void initUltrasonic() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT_PULLUP);
}

int readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 90000); // should return with 0 if no ultrasonic sensor attached or distance is over 15m
  distance = (duration*.0343)/2;  
  return (int)distance;
}