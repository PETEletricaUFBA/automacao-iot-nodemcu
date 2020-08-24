# 3. Motor usando Ponte H e controle através de potenciômetro;
Por meio desse módulo aprenderemos o que são e como funcionam alguns importantes e usuais atuadores. Dessa vez, aprenderemos um pouco mais sobre o circuito ponte H e motores;


O quarto projeto que desenvolveremos consiste na utilização de um motor usando ponte H controlado através de potenciômetro. Por meio desse desse circuito concebemos uma montagem capaz de controlar motores em geral, extremamente utilizada em robôs seguidores de linha, por exemplo.


Nesse momento você pode estar se perguntando o que é ou como funciona uma ponte H. A ponte H é um circuito eletrônico que possibilita uma série de facilidades, entre elas, permitir que o motor ligue e desligue, altere o sentido e a velocidade de rotação.

O circuito eletrônico que representa a ponte H pode ser visualizado na imagem abaixo:

![ponte-h](assets/rele.jpg)

Quando queremos que o motor gire para um lado, basta acionar as chaves CH AD e CH BE. Caso queiramos que o motor gire para o lado inverso, abre-se as chaves anteriores e fecha-se as chaves CH AE e CH BD.

Percebe-se que por meio da comutação de chaves pode-se fazer o motor assumir dois estados de rotação (horário e antihorário). Diferentemente do que a foto induz, o acionamento das chaves ocorre de forma eletrônica por meio de um chip embarcado.
- [x] Leitura Digital
- [x] Escrita Digital

## Conteúdo
- [Materiais Necessários](#materiais-necessários)
- [Montagem do Circuito](#montagem-do-circuito)
- [O Código do Circuito](#o-c&oacute;digo-do-circuito)

## Materiais Necessários
1. NodeMCU
2. Ponte H L298n
3. Potenciômetro
4. Protoboard
5. Jumpers

## Montagem do Circuito
O circuito deve ser montado como mostra a figura abaixo, representado na protoboard. 

![Protoboard](assets/atuador4.png)

Como visualizado na imagem acima, o sensor de presença apresenta seis terminais distintos (3 pinos e 3 "parafusos"). Dos pinos, um deles será conectado em uma porta digital do NODEMCU, enquanto as outras duas deverão ser conectadas no VCC e GND. 

Os outros 3 terminais da outra extremidade que se conectam com a saída (neste caso a saída representa o circuito contendo a lâmpada) apresentam especificidades que precisam ser explicadas: Os relés possuem dois tipos diferentes de contatos elétricos – normalmente aberto – NA (NO – Normally Open) e normalmente fechado – NF (NC – Normally Closed).

A tensão de alimentação de 120-240V, que acionará a lâmpada, está estabelecida no relé pelo terminal comum (terminal central) independentemente da configuração preterida. Para usar os contatos normalmente abertos, usamos o terminal NO – assim, a lâmpada permanecerá apagada enquanto o sensor não ativar o circuito. Para usar os contatos normalmente fechados, usamos o terminal NC – neste caso, a lâmpada permaneceria acesa até o circuito ser ativado pelo sensor.

A escolha dos contatos depende de como queremos que o interruptor seja empregado. Neste projeto queremos que a lâmpada seja acesa com o acionamento do relé, portanto queremos ligá-la, e por isso usaremos os contatos NO (NA) do relé

## O código do Circuito

Use o código que está em [code](code/code1.ino) ou copie o código abaixo:
 
```C++
#define sensor=D6;
#define rele = D1;

void setup() {
  pinMode(rele, OUTPUT);
  pinMode(sensor,INPUT);
}

void loop() {
  int pir = digitalRead(sensor);
  if (pir == HIGH) {
    digitalWrite(rele,HIGH);
    delay(5000);
}
else{
    digitalWrite(rele,LOW);
    delay(5000);
  }
}
  
```
O código acima começa com a declaração e associação das saídas e entradas utilizadas. O PIR foi associado à constante 12 (D6) e o PIR à constante 5 (D1). Feito isso, partimos para o void setup onde é necessário declarar as entradas e saídas por meio do pinMode.

Posteriormente, no void loop iniciamos com a declaração de uma variável e o uso da função digitalRead que obterá informação digital através da leitura da variável sensor. A informação será armazenada na variável pir

Além disso, utiliza-se uma estrutura condicional if, de modo que se a variável pir estiver com um nível lógico 1, então o relé atua ligando a lâmpada, e com o nível lógico 0, a lâmpada se encontra desligada. Você deve ter percebido o uso da função digitalWrite que tem a seguinte sintaxe: digitalWrite(pin,value). O pin é justamente a entrada ou saída declarada no void setup, enquanto que value é um parâmetro que varia entre ligado e desligado(HIGH/LOW).

![Circuit](assets/circuit.gif)

> Pense na utilização do Sensor de Umidade do Solo na sua casa ou em outras aplicações do seu cotidiano. 

