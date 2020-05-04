#define led D5
#define ldr A0

void setup(){
  Serial.begin(115200);
  pinMode(led,OUTPUT);
  pinMode(ldr,INPUT);
}

void loop(){
  int luminosidade=analogRead(ldr); 
  Serial.println(luminosidade);
  delay(10);
  if(luminosidade>400){
    digitalWrite(led,HIGH);
  }
  else {
    digitalWrite(led,LOW);
  }
}
