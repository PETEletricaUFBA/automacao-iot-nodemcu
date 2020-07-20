# 1. Circuito e programa com sensor de Infravermelho

O projeto se baseia no uso da função ```digitalRead``` e do sensor infravermelho, buscando o desenvolvimento de aplicações.

O sensor infravermelho (ou de refletância) é um componente eletrônico muito usado para a detecção de obstáculos. Seu funcionamento consiste na emissão de um raio infravermelho pelo LED branco (emissor) e recepção desse raio refletido pelo LED preto (receptor). Se houver a reflexão da luz emitida, um obstáculo terá sido detectado.

**Nota: O sensor de infravermelho não consegue detectar obstáculos de cores mais escuras, pois eles absorvem grande parte da luz infravermelha.**

O alcance da detecção varia entre 2 cm e 40 cm e pode ser regulado pelo potenciômetro trimpot presente no módulo. Ressalta-se ainda que se um obstáculo for detectado, o nível lógico lido será LOW.

Uma de suas aplicações pode ser associada ao uso desse sensor em robôs para permitir que eles detectem obstáculos enquanto se movimentam e, com isso, possam evitá-los.

O circuito envolvendo o sensor Infravermelho possibilita o aprendizado das seguintes competências trabalhadas no módulo 1:

- [x] Leitura Digital
- [x] Escrita Digital

> Nesse projeto você irá aprender a utilizar sensor de Infravermelho, juntamente com o processo de escrita digital com a função  ```digitalWrite```, bem como o de leitura digital usando a função  ```digitalRead```
## Conteúdo
- [Materiais Necessários](#materiais-necessários)
- [Montagem do Circuito](#montagem-do-circuito)
- [O Código do Circuito](#o-c&oacute;digo-do-circuito)

## Materiais Necessários
1. NodeMCU
2. 1 Sensor de Infravermelho
3. 1 LED
4. 1 Resistor de 220Ω
5. Protoboard
6. Jumpers

## Montagem do Circuito
O circuito deve ser montado como mostra a figura abaixo, representado na protoboard.

![Protoboard](assets/protoboard.png)


É necessário conectar um terminal do LED em um pino digital do NODEMCU, pois através dessa conexão, é possível, por conta do pino ser digital, controlar o envio de 5V ou 0V para o LED (ligando/desligando).



O outro terminal, deve ser conectado a um resistor de 220Ω limitador de corrente e, em seguida, ir direto para o GND.

O pino OUT do sensor de Infravermelho deve ser conectado a alguma porta digital do NodeMCU para que seu sinal digital possa ser lido. Além desse pino, seus outros terminais devem ser conectados ao GND e ao VCC conforme suas denominações.

**É importante saber que o Sensor Infravermelho só funciona quando o seu VCC está conectado a uma fonte de 3,3V a 5V, por esse motivo, é necessário conectar o seu VCC ao terminal de 5V disponível no ESP ou arduíno**

## O código do Circuito

Use o código que está em [code](code/code.ino) ou copie o código abaixo:
 
```C++
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
  
```
O código acima começa com a declaração e associação das saídas e entradas utilizadas. O LED foi associado à constante 12 (D6) e o PIR à constante 5 (D1). Feito isso, partimos para o ```void setup``` onde é necessário iniciar a comunicação serial através do comando "Serial.begin" e declarar as entradas e saídas por meio do pinMode.

Posteriormente, no ```void loop``` iniciamos com a declaração de uma variável e o uso da função ```digitalRead```  que obterá informação digital através da leitura da variável pir(sensor de presença). A informação será armazenada na variável ```presenca```  

Além disso, utiliza-se uma estrutura condicional ```if```, de modo que se a variável presenca estiver com um nível lógico 1, então liga-se o LED, e com o nível lógico 0, o LED é desligado. Você deve ter percebido o uso da função ```digitalWrite``` que tem a seguinte sintaxe: ```digitalWrite(pin,value)```. O ```pin``` é justamente a entrada ou saída declarada no ```void setup```, enquanto que ```value``` é um parâmetro que varia entre ligado e desligado(HIGH/LOW).


Caso tenha tido algum problema abra uma _issue_ clicando [aqui](https://github.com/PETEletricaUFBA/IoT/issues/new)

![Circuit](assets/circuit.gif)

> Pense na utilização do PIR na sua casa ou em outras aplicações do seu cotidiano. 
