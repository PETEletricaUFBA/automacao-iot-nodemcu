#define sensor = D6;
#define rele = D1;

void setup() {
  pinMode(rele, OUTPUT);
  pinMode(sensor,INPUT);
}

void loop() {
  int pir = digitalRead(sensor);
  if (pir == HIGH) {
    digitalWrite(rele, HIGH);
    delay(5000);
}
else{
    digitalWrite(rele, LOW);
    delay(5000);
  }
}
