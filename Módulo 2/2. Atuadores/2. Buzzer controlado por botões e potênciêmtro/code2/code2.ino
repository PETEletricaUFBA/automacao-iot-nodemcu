const int DO = D0;
const int RE = D1;
const int MI = D2;
const int FA = D5;
const int SOL= D6;

int estadoDo  = 0;
int estadoRe  = 0;
int estadoMi  = 0;
int estadoFa  = 0;
int estadoSol = 0;

const int som = D7;

int semiperiodo = 0;

void setup() {
  pinMode(som, OUTPUT);
  pinMode(DO,  INPUT);
  pinMode(RE,  INPUT);
  pinMode(MI,  INPUT);
  pinMode(FA,  INPUT);
  pinMode(SOL, INPUT);
}

void loop() {
  estadoDo = digitalRead(DO);
  estadoRe = digitalRead(RE);
  estadoMi = digitalRead(MI);
  estadoFa = digitalRead(FA);
  estadoSol= digitalRead(SOL);

  if(estadoDo && !estadoRe && !estadoMi && !estadoFa && !estadoSol) semiperiodo = 1894/3; // 264*3 Hz
  if(!estadoDo && estadoRe && !estadoMi && !estadoFa && !estadoSol) semiperiodo = 1684/3; // 297*3 Hz
  if(!estadoDo && !estadoRe && estadoMi && !estadoFa && !estadoSol) semiperiodo = 1515/3; // 330*3 Hz
  if(!estadoDo && !estadoRe && !estadoMi && estadoFa && !estadoSol) semiperiodo = 1420/3; // 352*3 Hz
  if(!estadoDo && !estadoRe && !estadoMi && !estadoFa && estadoSol) semiperiodo = 1263/3; // 396*3 Hz
  
  if(semiperiodo > 0) {
    digitalWrite(som, HIGH);
    delayMicroseconds(semiperiodo);   
    digitalWrite(som, LOW);
    delayMicroseconds(semiperiodo);
    semiperiodo = 0;
  }
}
