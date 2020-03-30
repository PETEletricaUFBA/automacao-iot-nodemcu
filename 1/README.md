# Começando 

Para começar vamos utilizar um programa para testar se está tudo OK com o processo de compilação. Para fins de simplificação, iremos usar também a IDE do arduino e começar a se familiarizar com a pinagem do NodeMCU.

## Configurando a IDE do Arduino para programar o NodeMCU 

### 1. Colocando o URL adicional para Gerenciador de Placas

Para fazer isso, na IDE do Arduino, clique em:

```Arquivo -> Preferências```

E cole o seguinte link no lugar a seguir

```http://arduino.esp8266.com/stable/package_esp8266com_index.json```

![Adicionando arquivo JSON](assets/JSON.png)

Assim a sua IDE estará com a extensão do ESP8266!

### 2. Instalando o suporte a placa esp8266

```Ferramentas -> Placa -> Gerenciador de Placas``` 

Instale a placa _**esp8266 by ESP8266 Community**_

![Instalando placa](assets/board.png)

Após isso, em ```Ferramentas -> Placa``` selecione _**Generic ESP8266 Module**_

Pronto, sua IDE está preparada para programar um ESP!

## Compilando o circuito Blinking

Para testar se está tudo OK, nananam nananam.. bla bla bla..

### Monte o circuito como mostra abaixo:

![Circuito](assets/protoboard.png)

A aplicação elucidada através da imagem acima permite ligar e desligar a luz do led e é conhecida também como "Pisca-LED" ou "Blinking". Apesar de extremamente simples, aplicações como essas nos permite criar conhecimentos e estratégias interessantes para acionamentos de outros dispositivos como lâmpadas, motores ou qualquer elemento que represente uma saída no seu circuito. Para viabilizar a montagem correta do circuito é necessário apresentar um LED de (qualquer cor), um resistor com um valor próximo a 1KΩ, esse último, será responsável por limitar a corrente que circula no circuito, evitando que ultrapasse a corrente de operação do LED e o queime. 

Além de resistor e LED, é preciso que se conheça a pinagem do NODEMCU8266 e é importante salientar que a posição dos pinos modificam conforme a versão do NODEMCU8266 que o usuário apresente. No entanto, para a nossa felicidade, apesar de se encontrar em posições diferentes, a aplicabilidade dos pinos é universal, ou seja, ao encontrarmos o GPIO16 em um NODEMCU v1.1 e identificarmos o GPIO16 em uma outra posição em um outro NODEMCU8266, este pino apresentará as mesmas especificações e aplicabilidade no kit de desenvolvimento aterior.

Explicação genérica do circuito aqui... bla bla bla falar que a pinagem pode ser diferente, mostrar exemplo

FALAR PINAGEM SOBRE GPIO e DX pra consultar tabela

![Pinout](assets/pinoutv3.png)

### Hora do código!

Use o código que está em [code](code) ou copie o código abaixo:

```
print('code example')
print('code example')
print('code example')
print('code example')
```

Tente carregar e nananam...

Se você fez tudo certo a LED vai acender e apagar a cada segundo, isto significa que você configurou certo e ta tudo funcionando e está pronto para aprender mais coisa.


![Real Circuit](assets/circuit.gif)
