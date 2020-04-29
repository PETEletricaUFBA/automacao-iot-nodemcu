# 1. Circuito e programa com sensor de luminosidade LDR

Esse projeto consiste na utilização da função ```analogRead```  juntamente com o sensor LDR (_*Light Dependent Resistor*_) visando aplicações do mundo real.

O sensor LDR ou fotoresistor é um componente eletrônico que apresenta resistência variável conforme a  intensidade da luz incidente. É importante citar ainda que o LDR assim como um resistor comum, não apresenta polaridade e a resistência apresentada pelo sensor diminui à medida que se aumenta a intensidade da luz incidente.

Nesse momento você pode estar se perguntando: em qual situação eu posso utilizar um dispositivo que é sensível a luz no meu dia a dia?

Você pode até não saber disso, mas os fotoresistores são utilizados em inúmeras aplicações do mundo real. Os postes das milhares de ruas do nosso país acendem automaticamente, você já se perguntou o por quê? O LDR se encontra no sistema de iluminação pública para determinar quando a lâmpada do poste deve acender. Outra aplicação bastante comum é o uso do LDR em sensor crespuscular, dispositivo encontrado em veículos modernos para acendimento automático dos farois. Além dessas formas comuns do uso do LDR, você pode conceber um sistema que liga ou desliga um motor a depender do horário do dia, por exemplo.

Agora que já conhecemos a funcionalidade do sensor de luminosidade, vamos observar o seu funcionamento no circuito abaixo:



O circuito envolvendo o LDR envolve a seguinte competência trabalhada no módulo 1:

- [x] Escrita Digital
- [x] Leitura Analógica

> Nesse projeto você irá aprender a utilizar o LDR, juntamente com o processo de leitura digital com a função  ```digitalWrite```, bem como o de escrita analógica usando a  ```analogRead```
## Conteúdo
- [Materiais Necessários](#materiais-necessários)
- [Montagem do Circuito](#montagem-do-circuito)
- [O Código do Circuito](#código-do-circuito)

## Materiais Necessários
1. NodeMCU
2. 1 Sensor LDR
3. 1 Motor CC
4. 1 Resistor de 10KΩ
5. Protoboard
6. Jumpers

## Montagem do Circuito
O circuito deve ser montado como mostra a figura abaixo, representado na protoboard.

//![Protoboard](https://raw.githubusercontent.com/PETEletricaUFBA/IoT/master/3/assets/pinout.png)


É necessário conectar um terminal do LED em um pino digital do NODEMCU com capacidade para gerar PWM, pois através dessa conexão, é possível, por conta do pino ser digital, controlar o envio de 5V ou 0V para o LED (ligando/desligando) e além disso, pela capacidade de gerar PWM, controla-se o valor intermediário de tensão enviado para a saída. 

Essas são os pinos dísponúveis para o uso do PWM:
![Imagem do PWM](https://raw.githubusercontent.com/PETEletricaUFBA/IoT/master/3/assets/pinout.jpg)


O outro terminal, deve ser conectado a um resistor de 220Ω limitador de corrente e, em seguida, ir direto para o GND.

O potenciômetro é uma entrada que gera um sinal analógico ao longo do tempo e por esse mesmo motivo o terminal central do potenciômetro deve ser conectado ao pino analógico do ESP. Os terminais da extremidade devem ser conectados no VCC e no GND.

## O código do Circuito

Use o código que está em [code](code/code.ino) ou copie o código abaixo:
 
```C++
#define led 12
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
  else{
    digitalWrite(led,LOW);
}
}
  
```
O código acima começa com a declaração e associação das saídas e entradas utilizadas. O LED foi associado à constante 12 (D6) e o LDR à porta analógica A0. Feito isso, partimos para o ```void setup``` onde é necessário iniciar a comunicação serial através do comando "Serial.begin" e declarar as entradas e saídas por meio do pinMode.

Posteriormente, no ```void loop``` iniciamos com a declaração de uma variável e o uso da função ```analogRead```  que obterá informação analógica através da leitura da variável ldr e armazenará essa informação na variável luminosidade de forma analógica quantizada com uma resolução de 10 bits. 

Além disso, utiliza-se uma estrutura condicional ```if```, de modo que se a variável luminosidade estiver maior que 400, então liga-se o LED, abaixo desse valor, o LED é desligado. Você deve ter percebido o uso da função ```digitalWrite``` que tem a seguinte sintaxe: ```digitalWrite(pin,value)```. O ```pin``` é justamente a entrada ou saída declarada no ```void setup```, enquanto que ```value``` é um parâmetro que varia entre ligado e desligado(HIGH/LOW).


Caso tenha tido algum problema abra uma _issue_ clicando [aqui](https://github.com/PETEletricaUFBA/IoT/issues/new)

![Circuit](https://raw.githubusercontent.com/PETEletricaUFBA/IoT/master/3/assets/circuit.gif)

> Pense na utilização do LDR na sua casa ou em outras aplicações do seu cotidiano. 
