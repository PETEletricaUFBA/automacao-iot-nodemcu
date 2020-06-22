const int pushButton = D8;
const int led        = D0;

void setup() {
  Serial.begin(115200);
  pinMode(pushButton, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(pushButton);
  Serial.println(buttonState);
  digitalWrite(led,buttonState);
  delay(1);
}
