const int led = 14;

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
}

void loop() {
  for(int i=0; i<255; i++) {
    analogWrite(led,i);
    Serial.println(i);
    delay(10);
  }
}
