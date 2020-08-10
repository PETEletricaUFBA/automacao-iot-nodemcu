const int pot = A0;
const int som = D7;


void setup() {
  Serial.begin(115200);
  pinMode(som, OUTPUT);
  pinMode(pot,  INPUT);
}

void loop() {
  int frequencia = 500+8*analogRead(pot);
  Serial.println(frequencia);
  tone(som,frequencia);
}
