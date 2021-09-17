const int LM35 = 17; //A0
float temperatura;
 
void setup() {
  Serial.begin(115200);
}
 
void loop() {
  temperatura = map(analogRead(LM35), 0, 1023, 0, 150);
  Serial.print("Temperatura: ");
  Serial.println(temperatura);
  delay(2000);
}
