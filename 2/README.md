# 2. Ler estado de um botão e exibir no computador via serial

Esse projeto consiste no controle de um LED (liga/desliga) através de um botão, exibindo no "monitor serial" a informação digital do botão (HIGH/LOW).

O circuito também conhecido como "escrita digital/leitura digital" pode ser empregado de formas distintas na vida cotidiana. Habilitar ou desabilitar uma saída, apesar de simples, é uma prática fundamental e bem comum. Ao invés de se utilizar um LED, podemos utilizar esse circuito como base e, por exemplo, acionar uma sirene que nos informa, através de efeito sonoro, o vazamento de um produto venenoso em uma indústria de produtos químicos.

> Nesse projeto você irá aprender a transmitir as informações entre diferentes circuitos através da programação e utilizar os botões (PushBottom).

## Conteúdo
- [Materiais Necessários](#materiais-necessários)
- [Montagem do Circuito](#montagem-do-circuito)
- [Código do Circuito](#código-do-circuito)
  - [sub 3](#sub-3)
  - [sub 4](#sub-4)


## Materiais Necessários
1. NodeMCU
2. LED
3. PushButton
4. Resistor
5. Protoboard

## Montagem do Circuito

![Protoboard](assets/protoboard.png)
![Schematic](assets/schematic.png)

O circuito deve ser montado como mostra a figura acima, representado de maneira esquemática e em protoboard. Ele dividido em duas partes, uma do LED e a outra do PushButton.

É necessário conectar um terminal do LED em uma porta digital do NODEMCU, pois através dessa conexão, é possível controlar o envio de 5V ou 0V para o LED (ligando/desligando). O outro terminal, deve ser conectado a um resistor limitador de corrente e, em seguida, ir direto para o GND.

A outra etapa de montagem do circuito é a conexão do PushButton. Nesse sentido, é necessário entender um pouco sobre Pull-Up e Pull-Down.

![Circuito Pull-Up e Pull-Down](assets/PULLUPPULLDOWN.jpg)

O circuito Pull-UP garante que antes de apertar o botão, a entrada digital do NODEMCU apresente 5V (o NODEMCU possui alta impedância e o circuito se comporta como um aberto, assim impedindo a passagem de corrente, não havendo, então, queda no Resistor de Pull-Up). O circuito Pull-Down, por sua vez, garante 5V somente após e enquanto o botão for pressionado. Desse modo, essa parte do circuito visualizado na figura "Schematic", é implementado a partir do circuito Pull-Down.

Na imagem e no circuito em específico, o terminal "MCU" é uma entrada digital do NODEMCU.


## O código do Circuito

Inline `code` has `back-ticks around` it.
 
```C++
const int pushButton = 15;
const int led        = 16;

void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(pushButton);
  Serial.println(buttonState);
  digitalWrite(led,buttonState);
  delay(1);
}
```
O código acima começa com a declaração e associação da entrada e saída utilizada. O botão foi associado à constante 15 do NODEMCU e o LED à constante 16. Feito isso, partimos para o void setup onde é necessário iniciar a comunicação serial através do comando "Serial.begin" e declarar as entradas e saídas por meio do pinMode.

Após isso, dentro do void loop, declaramos uma variável "buttonState", que lê o valor digital da entrada do PushButton utilizando a função digitalRead. Essa variável será utilizada em dois momentos: 1) ao utilizarmos a função Serial.println para exibir os valores que essa variável assume no monitor serial e 2) controlar o LED a partir do digitalWrite e com os níveis UP/DOWN da variável.


![Circuit](assets/circuit.gif)

> Tente colocar mais botões usando mais portas!
