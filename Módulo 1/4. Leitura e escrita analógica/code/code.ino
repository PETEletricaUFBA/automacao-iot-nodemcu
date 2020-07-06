#define led D5
#define pot A0

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
  
