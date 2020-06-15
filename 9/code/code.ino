#define led 12
#define pir 5

void setup(){
  Serial.begin(115200);
  pinMode(led,OUTPUT);
  pinMode(pir,INPUT);
}

void loop(){
  int presenca=digitalRead(pir); 
  Serial.println(presenca);
  delay(10);
  if(presenca){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
}