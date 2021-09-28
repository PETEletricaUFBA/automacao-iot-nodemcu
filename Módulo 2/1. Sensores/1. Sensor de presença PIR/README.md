# 1. Circuito e programa com sensor de presença PIR

Esse projeto consiste na utilização da função ```digitalRead```  juntamente com o sensor PIR (_*Piroelétrico*_) visando aplicações do mundo real.

O sensor PIR ou sensor de presença  é um componente eletrônico capaz de detectar a variação de luz infravermelha emitida pelo corpo humano, em outras palavras esse dispositivo detecta movimentos de objetos que exalam calor e que estejam dentro do seu raio de detecção que alcança até 7 metros. É importante citar ainda que o corpo humano emite radiação e consequentemente há uma variação de luz infravermelha quando pessoas se movimentam.

**Nota: O sensor PIR detecta variação de radiação infravermelha e não a radiação, logo, uma pessoa parada não será detectada pelo mesmo.**

O PIR é utilizado em diversas aplicações, seja para segurança, economia de energia, entre outros. Este dispositivo é encontrado facilmente em corredores, estacionamentos e lobbies de condomínios, controlando a iluminação do local e assim economizando energia. Além disso ele pode ser utilizado para reforçar a segurança ao ser integrado a algum sistema de alarme.

Durante a utilização do sensor PIR, muitas pessoas fazem relação ou se confundem com o sensor de distância ultrassônico, no entanto, são sensores que utilizam princípios de funcionamento diferentes e os seus usos, comumente, são em situações divergentes. Enquanto o sensor ultrassônico utiliza ondas mecânicas e detecta a distância de qualquer objeto -independente se emite calor ou não- ao seu emissor, o sensor PIR utiliza infravermelho, ou melhor, diferença de intensidade do infravermelho, de modo que o sensor PIR consegue detectar qualquer corpo que emita calor e esteja dentro do seu raio de ação.

O circuito envolvendo o PIR possibilita o aprendizado da seguinte competência trabalhada no módulo 1:

- [x] Leitura Digital
- [x] Escrita Digital

> Nesse projeto você irá aprender a utilizar o PIR, juntamente com o processo de leitura digital com a função  ```digitalWrite```, bem como o de escrita digital usando a função  ```digitalRead```

## Conteúdo

- [Materiais Necessários](#materiais-necessários)
- [Montagem do Circuito](#montagem-do-circuito)
- [O Código do Circuito](#o-c&oacute;digo-do-circuito)

## Materiais Necessários

1. NodeMCU
2. 1 Sensor PIR
3. 1 LED
4. 1 Resistor de 220Ω
5. Protoboard
6. Jumpers

## Montagem do Circuito

O circuito deve ser montado como mostra a figura abaixo, representado na protoboard.

<p align="center">
  <img src="assets/protoboard.png" alt="Protoboard"/>
</p>

É necessário conectar um terminal do LED em um pino digital do NODEMCU, pois através dessa conexão, é possível, por conta do pino ser digital, controlar o envio de 3.3V ou 0V para o LED (ligando/desligando).

O outro terminal, deve ser conectado a um resistor de 220Ω limitador de corrente e, em seguida, ir direto para o GND.

O sensor de presença é uma entrada que gera um sinal digital e por esse mesmo motivo o terminal de saída do sensor (terminal central) deve ser conectado a um pino digital do ESP. Os outros terminais devem ser conectados no VCC e no GND.

**É importante saber que o Sensor PIR só funciona quando o seu VCC está conectado a uma fonte de 4,5V a 20V, por esse motivo, é necessário conectar o seu VCC ao terminal de 5V disponível no ESP ou arduíno, se necessario em caso de não haver saidas 5V usar alimentação externa.**

## O código do Circuito

Use o código que está em [code](code/code.ino) ou copie o código abaixo:

```C++
#define led 12 //D6
#define pir 5  //D1

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
  
```

O código acima começa com a declaração e associação das saídas e entradas utilizadas. O LED foi associado à constante 12 (D6) e o PIR à constante 5 (D1). Feito isso, partimos para o ```void setup``` onde é necessário iniciar a comunicação serial através do comando "Serial.begin" e declarar as entradas e saídas por meio do pinMode.

Posteriormente, no ```void loop``` iniciamos com a declaração de uma variável e o uso da função ```digitalRead```  que obterá informação digital através da leitura da variável pir (sensor de presença). A informação será armazenada na variável ```presenca```  

Além disso, utiliza-se uma estrutura condicional ```if```, de modo que se a variável presenca estiver com um nível lógico 1, então liga-se o LED, e com o nível lógico 0, o LED é desligado. Você deve ter percebido o uso da função ```digitalWrite``` que tem a seguinte sintaxe: ```digitalWrite(pin,value)```. O ```pin``` é justamente a entrada ou saída declarada no ```void setup```, enquanto que ```value``` é um parâmetro que varia entre ligado e desligado(HIGH/LOW).

Caso tenha tido algum problema abra uma _issue_ clicando [aqui](https://github.com/PETEletricaUFBA/IoT/issues/new)

![Circuit](assets/circuit.gif)

> Pense na utilização do PIR na sua casa ou em outras aplicações do seu cotidiano.
