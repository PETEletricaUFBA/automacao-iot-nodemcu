#define sensor D5

void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(115200);
}

void loop() {
  int sensorState=digitalRead(sensor);
  if (sensorState) {
     Serial.println("O SOLO NÃO ESTÁ ÚMIDO ");
  } else {
     Serial.println("O SOLO ESTÁ ÚMIDO ");
  }
  delay(1000);
}
