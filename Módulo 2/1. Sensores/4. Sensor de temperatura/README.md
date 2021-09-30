# 4. Sensor de Temperatura

Esse projeto consiste na utilização da função ```analogRead``` com o Sensor de Temperatura, possivelmente o TMP36, visando aplicações do mundo real.

O sensor de temperatura  é um módulo eletrônico que, como o próprio nome indica, é capaz de detectar as variações na temperatura ambiente. É importante salientar ainda que esse medidor utiliza a medição analógica. Portanto, ele deve ser conectado a uma porta do Arduino que faça essa leitura e retornará variados valores dentro da faixa de leitura.

O sensor pode ser visto na imagem abaixo e seu princípio de funcionamento é bem simples. O módulo eletrônico utiliza duas pontas de prova e através deles, circula uma corrente pelo solo de modo que a sua leitura é baseada na resistência elétrica resultante do solo, uma vez que quanto maior for a quantidade de água no solo, mais baixa é a resistência do solo e mais fácil fica a condução entre as pontas de prova. De forma contrária, quando o solo está seco, a condutividade é baixa, logo a resistência é alta.

![Sensor](assets/sensor.png)

Sensores de Umidade do Solo são amplamentes utilizados em plantações e jardins em geral, permitindo ter conhecimento de quando a sua planta necessita de água e quando está integrado com uma válvula solenoide é possível a criação de um sistema de irrigação automático.

O circuito envolvendo o Sensor de Umidade do Solo possibilita o aprendizado da seguinte competência trabalhada no Módulo 1:

- [x] Leitura Digital
- [x] Leitura Analógica

> Nesse projeto você irá aprender a utilizar o higrômetro utilizando o processo de leitura digital com a função  ```digitalRead```, bem como o de leitura analógica por meio da função  ```analogRead```
>
## Conteúdo

- [Materiais Necessários](#materiais-necessários)
- [Montagem do Circuito](#montagem-do-circuito)
- [O Código do Circuito](#o-c&oacute;digo-do-circuito)

## Materiais Necessários

1. NodeMCU
2. 1 Sensor de Umidade do Solo
3. Protoboard
4. Jumpers

## Montagem do Circuito

O circuito deve ser montado como mostra a figura abaixo, representado na protoboard. É importante destacar que na primeira imagem temos a montagem usando leitura digital e, na segunda, leitura analógica.

![Protoboard](assets/circuito-digital.png)
![Protoboard](assets/circuito-analogico.png)

Como visualizado na imagem acima, é necessário conectar os dois fios dos eletrodos do medidor de umidade do solo no drive (não tem polaridade nesse caso). A saída do drive do higrômetro apresenta quatro terminais distintos: VCC, GND, A0 e D0.

Como o sensor funciona com uma tensão de operação de 3,3V - 5V, então a saída VCC pode ir para um terminal com uma tensão de 3,3V ou 5V do NODEMCU e o GND, naturalmente, irá no GND do microcontrolador. Por fim, é preciso conectar o A0 (pino analógico) ou o D0 (pino digital), terminais essenciais para o funcionamento do seu circuito, de acordo com o uso escolhido.

Como o sensor de umidade do solo representa uma entrada que possibilita a geração de um sinal tanto digital quanto analógico, então realize a conexão do D0 a um terminal digital e o A0 em um terminal analógico do seu NodeMCU.

Com isso, você deve ter percebido a presença de um trimpot (pequeno potenciômetro de giro) no drive do sensor. Esse trimpot é utilizado quando se deseja empregar o sensor em seu modo digital. Através do giro do trimpot pode-se regular a sensibilidade e por consequência quando o sensor vai mudar de nível lógico HIGH/LOW no circuito.

## O código do Circuito

Use o código que está em [code1](code1/code1.ino) ou copie o código abaixo:

```C++
#define sensor 14 //D5

void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(115200);
}

void loop() {
  int sensorState=digitalRead(sensor);
  if (sensorState) {
     Serial.println("O SOLO NÃO ESTÁ ÚMIDO ");
  } else {
     Serial.println("O SOLO ESTÁ ÚMIDO ");
  }
  delay(1000);
}
  
```

>Desde o início da explicação evidenciamos que o módulo sensor pode ser utilizado tanto de forma digital quanto analógica. O código apresentado acima empregará o sensor em seu modo digital.

O código acima começa com a declaração e associação da entrada  utilizada. O sensor foi associado ao terminal D5 do NODEMCU. Feito isso, partimos para o ```void setup```  onde é necessário iniciar a comunicação serial através do comando ```Serial.begin``` definindo a taxa de transmissão de dados e declarar as entradas e saídas por meio do ```pinMode```.

Após isso, dentro do ```void loop```, declaramos uma variável denominada "sensorState", que lê o valor digital da entrada do sensor na váriavel ```sensor```, utilizando a função ```digitalRead``` e a armazena .

Além disso, utiliza-se uma estrutura condicional ```if```, de modo que se a variável estiver com um nível lógico 1, então mostra-se no monitor serial a mensagem "O SOLO NÃO ESTÁ ÚMIDO", e com o nível lógico 0, aparece a mensagem "O SOLO ESTÁ ÚMIDO".

>Depois de utilizar o sensor em seu modo digital, vamos explorar o seu funcionamento analógico:

Use o código que está em [code2](code2/code2.ino) ou copie o código abaixo:

```C++
#define sensor 17 //A0
void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(115200);
}

void loop() {
  int analogSensor= analogRead(sensor);
  Serial.println(analogSensor); 
  delay(10);
}
```

O código acima começa com a declaração e associação das saídas e entradas utilizadas. O sensor foi associado à porta analógica A0. Posteriormente, no ```void setup```, é necessário iniciar a comunicação serial através do comando ```Serial.begin``` e declarar as entradas e saídas por meio do ```pinMode```.

No ```void loop``` iniciamos com a declaração de uma variável e o uso da função ```analogRead``` que obterá informação analógica através da leitura da variável sensor e armazenará essa informação na variável analogSensor de forma analógica quantizada com uma resolução de 10 bits.

Para efeitos de visualização e posterior calibração, abra o monitor serial e visualize a variação da variável analogSensor. Por meio de valores previamente definidos, pode-se calibrar o sensor a partir de um determinado valor.

Caso tenha tido algum problema abra uma _issue_ clicando [aqui](https://github.com/PETEletricaUFBA/IoT/issues/new)

Os LEDs foram adicionados para melhor visualização das leituras dos sensores.
![Digital Circuit](assets/digitalcircuit.gif)
![Analog Circuit](assets/analogcircuit.gif)

> Pense na utilização do Sensor de Umidade do Solo na sua casa ou em outras aplicações do seu cotidiano.
