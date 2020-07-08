#define sensor D5

void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(115200);
}

void loop() {
  int sensorState=digitalRead(sensor);
  if (sensorState) {
     Serial.print("O SOLO NÃO ESTÁ ÚMIDO ");
  } else {
     Serial.print("O SOLO ESTÁ ÚMIDO ");
  }
}
