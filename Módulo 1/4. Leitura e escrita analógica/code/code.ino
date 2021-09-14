#define led 14 //D5
#define pot 17 //A0

void setup(){
  Serial.begin(115200);
  pinMode(led,OUTPUT);
  pinMode(pot,INPUT);
}

void loop(){
  int potenciometro=analogRead(pot); 
  Serial.println(potenciometro);
  analogWrite(led,potenciometro);
}
