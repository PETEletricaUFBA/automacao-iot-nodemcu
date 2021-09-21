#define sensor A0
void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(115200);
}

void loop() {
  int analogSensor= analogRead(sensor);
  Serial.println(analogSensor); 
  delay(10);
}
