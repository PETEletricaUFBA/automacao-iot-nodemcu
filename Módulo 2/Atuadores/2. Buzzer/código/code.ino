#define pino_buzzer 16
#define pino_do1 5
#define pino_re 4
#define pino_mi 0
#define pino_fa 2
#define pino_sol 14
#define pino_la 12
#define pino_si 13
#define pino_do2 15
#define tempo 1000

void setup()
{
  pinMode(pino_buzzer, OUTPUT);
  pinMode(pino_do1, INPUT);
  pinMode(pino_re, INPUT);
  pinMode(pino_mi, INPUT);
  pinMode(pino_fa, INPUT);
  pinMode(pino_sol, INPUT);
  pinMode(pino_la, INPUT);
  pinMode(pino_si, INPUT);
  pinMode(pino_do2, INPUT);
}

void loop()
{
  if (digitalRead(pino_do1)) {
    tone(pino_buzzer, 264, tempo);
  }
  if (digitalRead(pino_re)) {
    tone(pino_buzzer, 297, tempo);
    delay(tempo);
    noTone(pino_buzzer);
  }
  if (digitalRead(pino_mi)) {
    tone(pino_buzzer, 330, tempo);
    delay(tempo);
    noTone(pino_buzzer);
  }
  if (digitalRead(pino_fa)) {
   tone(pino_buzzer, 352, tempo);
    delay(tempo);
    noTone(pino_buzzer);
  }
  if (digitalRead(pino_sol)) {
   tone(pino_buzzer, 396, tempo);
    delay(tempo);
    noTone(pino_buzzer);
  }
  if (digitalRead(pino_la)) {
   tone(pino_buzzer, 440, tempo);
    delay(tempo);
    noTone(pino_buzzer);
  }
  if (digitalRead(pino_si)) {
   tone(pino_buzzer, 495, tempo);
    delay(tempo);
    noTone(pino_buzzer);
  }
  if (digitalRead(pino_do2)) {
   tone(pino_buzzer, 528, tempo);
    delay(tempo);
    noTone(pino_buzzer);
  }
}