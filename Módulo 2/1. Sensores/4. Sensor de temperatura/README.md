# 4. Circuito e programa com sensor de temperatura

Esse projeto consiste na utilização da função ```analogRead```  juntamente com o sensor de temperatura visando aplicações do mundo real.

O sensor de temperatura  é um componente eletrônico capaz de medir a temperatura ao seu redor. Este dispositivo é composto por diodos sensíveis à temperatura. Assim, quando há uma mudança nessa grandeza, a tensão que passa pelo sensor é modificada. Com isso, é possível criar uma escala para converter a tensão que o NodeMCU recebe em uma escala de temperatura, como Celsius, Fahrenheit e Kelvin. O sensor LM35, por exemplo, apresenta uma taxa de variação conhecida de 10mV/°C e lê valores de -55°C até 150°C, com uma precisão de ± 0.5°C a 25°C.

A seguir, temos algumas das principais aplicações do sensor:
* Regulação da temperatura de um ar-condicionado;
* Medição da temperatura corpórea nos termômetros;
* Auxílio em processos industriais dependentes de temperatura;
* Regulação da temperatura de _freezers_;


Seja criativo para pensar em outras aplicações!

O circuito envolvendo o sensor de temperatura envolve as seguintes competências trabalhadas no módulo 1:

- [x] Leitura Analógica
- [x] Escrita Analógica

> Nesse projeto você irá aprender a utilizar o sensor de temperatura, juntamente com o processo de leitura analógica com a função  ```analogRead``` associada à função ```map```.

## Conteúdo
- [Materiais Necessários](#materiais-necessários)
- [Montagem do Circuito](#montagem-do-circuito)
- [O Código do Circuito](#o-c&oacute;digo-do-circuito)

## Materiais Necessários
1. NodeMCU
2. 1 Sensor de temperatura LM35
3. 1 LED RGB
4. 3 Resistores de 220Ω
5. Protoboard
6. Jumpers

## Montagem do Circuito
O circuito deve ser montado como mostra a figura abaixo, representado na protoboard.

![Protoboard](https://i.imgur.com/XPTSixc.png)

É necessário conectar os 3 terminais menores do LED em saídas PWM do NODEMCU, com um resistor de 220Ω entre as conexões (para limitar a corrente), pois através dessa conexão é possível, por conta do pino ser PWM, controlar o envio de diferentes valores de tensão para os terminais do LED, assim modificando sua cor.

Já o terminal maior, deve ser conectado ao VCC caso o LED seja ânodo comum, ou ao GND caso seja cátodo comum (nesse caso conectado ao GND).

O sensor de temperatura é uma entrada que gera um sinal analógico e por esse mesmo motivo o terminal do meio do sensor deve ser conectado a um pino analógico do NodeMCU. Os outros terminais devem ser conectados no VCC e no GND, conforme a figura abaixo:

![terminals](https://i.imgur.com/Cn9wVTX.png)





## O código do Circuito

Use o código que está em [code](code/code.ino) ou copie o código abaixo:
 
```C++
//Pino do sensor de temperatura
const int LM35 = 17;      //A0

//Pinos das cores
const int redPin    = 4;  //D2
const int greenPin  = 5;  //D1
const int bluePin   = 16; //D0


float temperatura;

void ledColor(int temperatura) {
  if(temperatura < 20){
    digitalWrite(redPin, 0);
    digitalWrite(greenPin, 0);
    digitalWrite(bluePin, 255);
  }else if(temperatura >= 20 and temperatura <= 70){
    digitalWrite(redPin, 0);
    digitalWrite(greenPin, 255);
    digitalWrite(bluePin, 0);
  }else if(temperatura > 70){
    digitalWrite(redPin, 255);
    digitalWrite(greenPin, 0);
    digitalWrite(bluePin, 0);
  }
}


void setup() {
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);

  pinMode(LM35, INPUT);
  
  Serial.begin(115200);
}

 
void loop() {
  temperatura = map(analogRead(LM35), 0, 1023, -55, 150);

  ledColor(temperatura);
  
  Serial.print("Temperatura: ");
  Serial.println(temperatura);
  
  delay(2000);
}
```


O código acima começa com a declaração e associação das saídas e entradas utilizadas. O pino de leitura do sensor foi associado à constante 17 (A0) e os pinos de controle da luz foram associados às constantes 4, 5 e 16 (D2, D1 e D0). Declara-se também a variável, no formato ```float```, que irá armazenar a temperatura.

Depois, temos uma função denominada:
```C++
void ledColor (int temperatura)
```
Com o valor da temperatura, ela define a cor do Led, segundo esta regra:
* Azul para menor que 20°C
* Verde para maior que 20°C e menor que 70°C
* Vermelho para maior que 70°C e menor que 150°C

Tendo em vista que o sensor é um aparelho eletrônico que trabalha no alcance de -55°C a 150°C, optamos por medir temperaturas que sejam fáceis de reproduzir em casa, ou seja, de 0°C a 150°C, não incluindo os valores negativos, embora qualquer valor abaixo de 0°C também resulte na cor azul.

Feito isso, partimos para o ```void setup``` onde é necessário iniciar a comunicação serial através do comando ``Serial.begin`` e declarar as entradas e saídas por meio do ``pinMode``.

**Nota:** O pino A0 é o único input, visto que ele recebe o sinal do sensor de temperatura.

Posteriormente no ```void loop```, usamos a função:

```temperatura = map(analogRead(LM35), 0, 1023, -55, 150);```

Ela faz com que a leitura analógica do sensor (que varia de 0 a 1023) seja recebida pela variável ```temperatura``` numa escala de -55 a 150, variando proporcionalmente e representando a temperatura real. Então, declaramos a função ```ledColor(temperatura)``` que vai ser responsável por obter a leitura do sensor e a partir disso definir a cor do Led. Além disso, configuramos o monitor serial para mostrar a temperatura obtida, a fim de ter conhecimento da leitura exata e conferir o bom funcionamento do circuito.




Caso tenha encontrado algum problema abra uma _issue_ clicando [aqui](https://github.com/PETEletricaUFBA/IoT/issues/new)


> Pense na utilização do sensor de temperatura Lm35 na sua casa ou em outras aplicações do seu cotidiano. 
