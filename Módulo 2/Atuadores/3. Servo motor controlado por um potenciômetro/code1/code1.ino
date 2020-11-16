#include <Servo.h>
Servo servo;

void setup() {
  servo.attach(2); //D4
  servo.write(0);
  delay(2000);
}

void loop() {
  for(int i=0; i<=90; i++) {
    servo.write(i);
    delay(20);
  }
  for(int i=90; i>=0; i--) {
    servo.write(i);
    delay(10);
  }
}
