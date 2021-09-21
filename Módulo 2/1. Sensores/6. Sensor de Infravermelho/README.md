# 1. Circuito e programa com sensor infravermelho

O projeto se baseia no uso da função ```digitalRead``` e do sensor infravermelho, buscando o desenvolvimento de aplicações.

O sensor infravermelho (ou de refletância) é um componente eletrônico muito usado para a detecção de obstáculos. Seu funcionamento consiste na emissão de um raio infravermelho pelo LED branco (emissor) e recepção desse raio refletido pelo LED preto (receptor). Se houver a reflexão da luz emitida, um obstáculo terá sido detectado.

**Nota: O sensor infravermelho não consegue detectar obstáculos de cores mais escuras, pois eles absorvem grande parte da luz infravermelha.**

O alcance da detecção varia entre 2 cm e 40 cm e pode ser regulado pelo potenciômetro trimpot presente no módulo. Ressalta-se ainda que se um obstáculo for detectado, o nível lógico lido será LOW.

Uma de suas aplicações pode ser associada ao uso desse sensor em robôs para permitir que eles detectem obstáculos enquanto se movimentam e, com isso, possam evitá-los.

O circuito envolvendo o sensor infravermelho possibilita o aprendizado das seguintes competências trabalhadas no módulo 1:

- [x] Leitura Digital
- [x] Escrita Digital

> Nesse projeto você irá aprender a utilizar sensor infravermelho, juntamente com o processo de escrita digital com a função  ```digitalWrite```, bem como o de leitura digital usando a função  ```digitalRead```

## Conteúdo

- [Materiais Necessários](#materiais-necessários)
- [Montagem do Circuito](#montagem-do-circuito)
- [O Código do Circuito](#o-c&oacute;digo-do-circuito)

## Materiais Necessários

1. NodeMCU
2. 1 Sensor infravermelho
3. 1 LED
4. 1 Resistor de 220Ω
5. Protoboard
6. Jumpers

## Montagem do Circuito

O circuito deve ser montado como mostra a figura abaixo, representado na protoboard.

![Protoboard](https://i.imgur.com/iasZ4qO.png)

É necessário conectar um terminal do LED em um pino digital do NODEMCU, pois através dessa conexão, é possível, por conta do pino ser digital, controlar o envio de 3.3V ou 0V para o LED (ligando/desligando).

O outro terminal, deve ser conectado a um resistor de 220Ω limitador de corrente e, em seguida, ir direto para o GND.

O pino OUT do sensor infravermelho deve ser conectado a alguma porta digital do NodeMCU para que seu sinal digital possa ser lido. Além desse pino, seus outros terminais devem ser conectados ao GND e ao VCC conforme suas denominações.

**É importante saber que o Sensor infravermelho só funciona quando o seu VCC está conectado a uma fonte de 3,3V a 5V, por esse motivo, é necessário conectar o seu VCC ao terminal de 5V disponível no ESP ou arduíno, se necessario em caso de não haver saidas 5V usar alimentação externa.**

## O código do Circuito

Use o código que está em [code](code/code.ino) ou copie o código abaixo:

```C++
#define led 12
#define infravermelho 5

void setup(){
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pinMode(infravermelho, INPUT);
}

void loop(){
  bool obstaculo = digitalRead(infravermelho); 
  Serial.println(obstaculo);
  delay(10);
  if(obstaculo){
    digitalWrite(led, LOW);
  }
  else{
    digitalWrite(led, HIGH);
  }
}
  
```

O código inicia com a declaração e associação das saídas e entradas utilizadas. O LED foi associado à constante 12 (D6) e o pino OUT do sensor infravermelho à constante 5 (D1). Posteriormente, o comportamento dos pinos é definido pelo ```pinMode```. A comunicação serial também é iniciada no ```void setup``` pelo comando ```Serial.begin```.

O ```void loop``` inicia com a declaração da variável booleana ```obstaculo``` a qual armazena o valor digital lido da variável ```infravermelho```. Essa leitura é feita pela função ```digitalRead```.

Depois disso, utiliza-se uma estrutura condicional ```if```, de modo que se a variável ```obstaculo``` estiver com o nível lógico 1 (HIGH), então o LED permanece desligado, pois nenhum obstáculo foi detectado. Enquanto que, se essa variável estiver com o nível lógico 0 (LOW), o LED acende, indicando a detecção de um obstáculo.

Para controlar o estado do LED, faz-se uso da função ```digitalWrite``` a qual recebe como parâmetros, respectivamente,  o pino que se deseja definir o estado lógico (nesse caso o pino do led) e o nível lógico que esse pino deve assumir (HIGH/LOW).

Caso tenha tido algum problema abra uma _issue_ clicando [aqui](https://github.com/PETEletricaUFBA/IoT/issues/new)

![Circuit](assets/circuit.gif)

> Pense na utilização do sensor infravermelho na sua casa ou em outras aplicações do seu cotidiano.
