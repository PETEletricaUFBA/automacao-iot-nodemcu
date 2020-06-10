# 4. Acender um LED com brilho variável através de um potênciômetro

Esse projeto consiste no controle do brilho de um LED utilizando a função ```analogWrite()``` através da informação analógica obtida com o ```analogRead()```

Aprendemos a escrever sinais analógicos no item [3](link), agora vamos aprender como obter leituras de informações analógicas também. Em muitas aplicações temos a necessidade de obtermos uma informação assim, como por exemplo a maioria dos sensores nos fornecem sinais analógicos sensor de distância, sensor de temperatura, sensor de umidade, sensor de luminosidade. Todas estas grandezas não são binárias! Por isso devemos ser capaz de realizar uma leitura analógica. Deste modo, somos capazes de realizar qualquer leitura e qualquer escrita básica, são elas:

- [x] Leitura Digital
- [x] Escrita Digital
- [x] Leitura Analógica
- [x] Escrita Analógica

> Nesse projeto você irá aprender como relizar uma escrita analógica, utilizando a função ```analogWrite``` através do controle de um brilho de uma lâmpada, bem como a ler uma entrada analógica utilizando a função ```analogRead```

## Conteúdo
- [Materiais Necessários](#materiais-necessários)
- [Montagem do Circuito](#montagem-do-circuito)
- [O Código do Circuito](#código-do-circuito)

## Materiais Necessários
1. NodeMCU
2. 1 LED
3. 1 Resistor de 220Ω
4. Protoboard
5. Jumpers
6. Potenciômetro 10kΩ (ou outro)

## Montagem do Circuito
O circuito deve ser montado como mostra a figura abaixo, representado na protoboard.

![Protoboard](https://raw.githubusercontent.com/PETEletricaUFBA/IoT/master/3/assets/pinout.png)

É necessário conectar um terminal do LED em um pino digital do NODEMCU com capacidade para gerar PWM, pois através dessa conexão, é possível, por conta do pino ser digital, controlar o envio de 5V ou 0V para o LED (ligando/desligando) e além disso, pela capacidade de gerar PWM, controla-se o valor intermediário de tensão enviado para a saída. 

Essas são os pinos dísponúveis para o uso do PWM:
![Imagem do PWM](https://raw.githubusercontent.com/PETEletricaUFBA/IoT/master/3/assets/pinout.jpg)


O outro terminal, deve ser conectado a um resistor de 220Ω limitador de corrente e, em seguida, ir direto para o GND.

O potenciômetro é uma entrada que gera um sinal analógico ao longo do tempo e por esse mesmo motivo o terminal central do potenciômetro deve ser conectado ao pino analógico do ESP. Os terminais da extremidade devem ser conectados no VCC e no GND.

## O código do Circuito

Use o código que está em [code](code/code.ino) ou copie o código abaixo:
 
```C++
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
  
```
O código acima começa com a declaração e associação das saídas e entradas utilizadas. O LED foi associado à constante 14 (D5) e o potenciômetro à porta analógica A0. Feito isso, partimos para o ```void setup``` onde é necessário iniciar a comunicação serial através do comando "Serial.begin" e declarar as entradas e saídas por meio do pinMode.

Posteriormente, no ```void loop``` iniciamos com a declaração de uma variável e o uso da função ```analogRead```  que obterá informação analógica através da leitura da variável pot e armazenará essa informação na variável potenciometro de forma analógica quantizada com uma resolução de 10 bits. 

Além disso, utiliza-se a função ```analogWrite``` que tem a seguinte sintaxe: ```analogWrite(pin,value)```. O ```pin``` é justamente a entrada ou saída declarada no ```void setup```, enquanto que ```value``` é um parâmetro que varia entre um valor entre 0 (sempre desligado) e 255 (sempre ligado). 


Caso tenha tido algum problema abra uma _issue_ clicando [aqui](https://github.com/PETEletricaUFBA/IoT/issues/new)

![Circuit](https://raw.githubusercontent.com/PETEletricaUFBA/IoT/master/3/assets/circuit.gif)

> Pense na utilização da função ```analogRead``` em outras aplicações e com outras entradas. 
