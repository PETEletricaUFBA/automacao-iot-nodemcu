#include <Servo.h>
Servo servo;
const int pot = A0;

void setup() {
  pinMode(A0, INPUT);
  servo.attach(2); //D4
  servo.write(0);
  delay(2000);
}

void loop() {
  servo.write(map(analogRead(A0),0,1024,0,180));
}
