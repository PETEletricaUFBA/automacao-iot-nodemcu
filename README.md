<h1 align="center">
  <br>
  <a href="#"><img src="assets/automation.png" alt="A smart house logo" width="100"></a>
  <br>
  Automação & IoT com NodeMCU
  <br>
</h1>

<h4 align="center">Um guia definitivo para aprender <a href="https://www.nodemcu.com/index_en.html" target="_blank">NodeMCU</a> com diversos exemplos práticos, incluindo aplicações de Internet das Coisas! Step-by-Step</h4>

<p align="center">
  <a href="http://www.peteletrica.eng.ufba.br/2017/" target="_blank"><img src="https://badgen.net/badge/icon/PET Elétrica/blue?icon=bitcoin-lightning&label" alt="Site do PET Elétrica"></a>
  <a href="https://app.codacy.com/gh/PETEletricaUFBA/IoT?utm_source=github.com&utm_medium=referral&utm_content=PETEletricaUFBA/IoT&utm_campaign=Badge_Grade_Dashboard" target="_blank">
    <img src="https://badgen.net/codacy/grade/a1b5adec51bb42ef90d079504bba374d">
  </a>
  <a href="https://github.com/PETEletricaUFBA/IoT/commits/" target="_blank">
    <img src="https://badgen.net/github/commits/PETEletricaUFBA/IoT">
  </a>
  <a href="https://github.com/PETEletricaUFBA/IoT/graphs/contributors" target="_blank">
    <img src="https://badgen.net/github/contributors/PETEletricaUFBA/IoT">
  </a>
  <a href="https://github.com/PETEletricaUFBA/IoT/blob/master/LICENSE">
    <img src="https://badgen.net/badge/license/MIT/red">
  </a>
  <img src="https://badgen.net/github/last-commit/PETEletricaUFBA/IoT">
</p>

<!-- Menu Principal -->
<!--
<p align="center">
  <a href="#sobre-o-projeto">Sobre o projeto</a> •
  <a href="#trilha-do-conhecimento">Conteúdo</a> •
  <a href="#contribuindo">Contribuir</a> •
  <a href="#licença">Licença</a> •
  <a href="#contato">Contato</a>
</p>
-->

## Sumário

* [Sobre o projeto](#sobre-o-projeto)
  * [Softwares usados](#softwares-usados)
  * [Hardwares usados](#hardwares-usados)
* [Trilha do Conhecimento](#trilha-do-conhecimento)
* [Módulos](#módulos)
  * [Noções básicas de programação e conhecimento do kit de desenvolvimento NodeMCU](#1-noções-básicas-de-programação-e-conhecimento-do-kit-de-desenvolvimento-nodemcu)
  * [Noções de implementações de automação no mundo real](#2-noções-de-implementações-de-automação-no-mundo-real)
  * [Noções sobre a criação de bots e uso de servidores](#3-noções-sobre-a-criação-de-bots-e-uso-de-servidores)
  * [Como levar a informação para o mundo virtual?](#4-como-levar-a-informação-para-o-mundo-virtual)
* [Contribuindo](#contribuindo)
* [Licença](#licença)
* [Contato](#contato)

## Sobre o projeto

O projeto busca apresentar um conteúdo prático, objetivo e de fácil consulta. Além disso as atividades desenvolvidas são acessíveis para qualquer pessoa, independente do nível de conhecimento em Automação.
Este guia conterá projetos com diferentes níveis de complexidade que utilizam o NODEMCU: desde como acender um LED até um manual de como criar um servidor, integrá-lo com um bot e manter as informações do seu projeto físico de forma online.

### Softwares usados

* [Arduino](https://www.arduino.cc/en/Main/Software)
* [Fritzing](https://fritzing.org/download/) (Opcional)
* [Tinkercad](https://www.tinkercad.com/) (Opcional)

### Hardwares usados

* Atuadores (Ex: LED, motores etc)
* Fonte de energia (Ex: bateria)
* Jumpers
* Placa de desenvolvimento NodeMCU
* Protoboard
* Push Buttons
* Resistores
* Sensores (Ex: Potenciômetro, LDR etc)

## Trilha do conhecimento

Dividiremos o conteúdo em alguns módulos:

* **1) Noções básicas de programação e conhecimento do kit de desenvolvimento NodeMCU:** Conceitos iniciais de lógica de programação e suas aplicações em circuitos básicos.
* **2) Noções de implementações de automação no mundo real:** Estudos sobre alguns sensores e atuadores e suas interações com o mundo físico.
* **3) Noções sobre a criação de bots e uso de servidores:** Competências relacionadas a conectividade e a integração de sensores e atuadores através da Internet.
* **4) Como levar a informação para o mundo virtual?** Agora é hora de colocar nossas aplicações na nuvem!

![asd](assets/trilha.png)

## Módulos

### 1) [Noções básicas de programação e conhecimento do kit de desenvolvimento NodeMCU](https://github.com/PETEletricaUFBA/automacao-iot-nodemcu/tree/master/M%C3%B3dulo%201)

**Descrição:** Apresenta-se conhecimentos sobre o kit NodeMCU e como programar uma placa para realizar leituras e escritas digitais e analógicas em circuitos básicos.

**Conteúdo:**

1. [Primeiros passos](https://github.com/PETEletricaUFBA/automacao-iot-nodemcu/tree/master/M%C3%B3dulo%201/1.%20Primeiros%20passos)

* Conhecendo a placa de desenvolvimento: o microcontrolador, as GPIOs, pinout, níveis de tensão, entre outros;
* Configurando a IDE do Arduino para programar o NodeMCU;
* Compilar um programa teste que acende e apaga um LED (Blinking).

1. [Leitura de sinais digitais](https://github.com/PETEletricaUFBA/automacao-iot-nodemcu/tree/master/M%C3%B3dulo%201/2.%20Leitura%20de%20sinais%20digitais): Ler estado de um botão e exibir no computador via serial;

1. [Escrita analógica](https://github.com/PETEletricaUFBA/automacao-iot-nodemcu/tree/master/M%C3%B3dulo%201/3.%20Escrita%20anal%C3%B3gica): Mudar o brilho de uma lâmpada ao decorrer do tempo (Fading in e Fading out);

1. [Leitura e escrita analógica](https://github.com/PETEletricaUFBA/automacao-iot-nodemcu/tree/master/M%C3%B3dulo%201/4.%20Leitura%20e%20escrita%20anal%C3%B3gica): Acender um LED com brilho variável através de um potênciômetro com PWM.

<br/>

### 2) [Noções de implementações de automação no mundo real](https://github.com/PETEletricaUFBA/automacao-iot-nodemcu/tree/master/M%C3%B3dulo%202)

**Descrição:** Apresentação de outras habilidades utilizando diversos sensores e atuadores, a partir de aplicações práticas.

#### **[Sensores](https://github.com/PETEletricaUFBA/automacao-iot-nodemcu/tree/master/M%C3%B3dulo%202/Sensores):**

1. [Sensor de presença PIR](https://github.com/PETEletricaUFBA/automacao-iot-nodemcu/tree/master/M%C3%B3dulo%202/Sensores/1.%20Sensor%20de%20presen%C3%A7a%20PIR): Utilizar o estado atual do sensor de presença (HIGH ou LOW) para alterar o estado de uma saída
1. [Sensor de luminosidade LDR](https://github.com/PETEletricaUFBA/automacao-iot-nodemcu/tree/master/M%C3%B3dulo%202/Sensores/2.%20Sensor%20de%20luminosidade%20LDR): Mudando o estado de uma saída de acordo com os níveis de luminosidade do ambiente
1. [Sensor de distância](https://github.com/PETEletricaUFBA/automacao-iot-nodemcu/tree/master/M%C3%B3dulo%202/Sensores/3.%20Sensor%20de%20dist%C3%A2ncia): Realizando medições com o sensor de distância
1. Sensor de temperatura; (Em construção)  
1. [Sensor de umidade](https://github.com/PETEletricaUFBA/automacao-iot-nodemcu/tree/master/M%C3%B3dulo%202/Sensores/5.%20Sensor%20de%20umidade); Aprendendo a utilizar o sensor de umidade e configurá-lo para realizar leitura digital ou analógica
1. Sensor de infra vermelho. (Breve)

#### **[Atuadores](https://github.com/PETEletricaUFBA/automacao-iot-nodemcu/tree/master/M%C3%B3dulo%202/Atuadores):**

1. [Relé controlado por sensor](https://github.com/PETEletricaUFBA/automacao-iot-nodemcu/tree/master/M%C3%B3dulo%202/Atuadores/1.%20Rel%C3%A9%20controlado%20por%20sensor): Compreendendo o funcionamento de um relé ativado por um sensor qualquer e o seu para controlar o estado de uma lâmpada residencial
1. [Buzzer controlado por botões ou potênciômetro](https://github.com/PETEletricaUFBA/automacao-iot-nodemcu/tree/master/M%C3%B3dulo%202/Atuadores/2.%20Buzzer%20controlado%20por%20bot%C3%B5es%20e%20pot%C3%AAnci%C3%AAmtro): Aprendendo sobre o funcionamento de um buzzer e o controle desse atuador através de um sensor digital ou analógico.
1. [Servo motor controlado por um potenciômetro](https://github.com/PETEletricaUFBA/automacao-iot-nodemcu/tree/master/M%C3%B3dulo%202/Atuadores/3.%20Servo%20motor%20controlado%20por%20um%20potenci%C3%B4metro): Compreendendo o que é um servomotor e aprendendo como controlar o sentido de giro através de um sensor analógico
1. Motor usando Ponte H e controle através de potenciômetro ou outro sensor; (Breve)
1. Escrita em um display LCD com o protocolo I2C. (Breve)

<br/>

### 3) Noções sobre a criação de bots e uso de servidores

**Descrição:** Serão apresentadas a criação de bots e a sua integração em projetos físicos os quais incluem os conhecimentos aprendidos nos módulos anteriores.

#### **Criação de Bots:**

1. [Criação de um BOT no Telegram](https://github.com/PETEletricaUFBA/automacao-iot-nodemcu/tree/master/M%C3%B3dulo%203/Cria%C3%A7%C3%A3o%20de%20Bots/1.%20Cria%C3%A7%C3%A3o%20de%20um%20BOT%20pelo%20Telegram): Aprendendo a criar e configurar o seu próprio BOT através do Telegram
1. [Integração do Bot em um projeto físico](https://github.com/PETEletricaUFBA/automacao-iot-nodemcu/tree/master/M%C3%B3dulo%203/Cria%C3%A7%C3%A3o%20de%20Bots/2.%20Integra%C3%A7%C3%A3o%20do%20BOT%20em%20um%20projeto%20f%C3%ADsico): Aprendendo a controlar projetos físicos por meio do BOT no Telegram e através de um celular, computador ou notebook.

#### **Webserver:**

1. [Webserver com página estática](https://github.com/PETEletricaUFBA/automacao-iot-nodemcu/tree/master/M%C3%B3dulo%203/Webserver/1.%20Webserver%20com%20p%C3%A1gina%20est%C3%A1tica): Aprendendo a criar o seu primeiro Webserver com página estática. Por meio desse projeto, você criará uma pequena página capaz de controlar e monitorar seu projeto físico.
1. [Webserver com página dinâmica, usando AJAX](https://github.com/PETEletricaUFBA/automacao-iot-nodemcu/blob/master/M%C3%B3dulo%203/Webserver/2.%20Webserver%20com%20p%C3%A1gina%20din%C3%A2mica,%20usando%20AJAX/README.md): Desenvolvendo um webserver dinâmico capaz de oferecer o controle e monitoramento em tempo real do seu projeto.
1. Webserver com o uso da memória flash e ponto de acesso
1. Acessar um Webserver através da Internet

<!--
- Módulo 4: Falar sobre o Thing Speak e a integração do Thing Speak com um projeto físico!
- Módulo 3/Módulo 4: Integrar o Thing Speak com Web-Server. Como receber as informações do Thing Speak em uma dashboard diferente da do próprio site.
- Heroku
-->

<br/>

<br/>

### 4) Como levar a informação para o mundo virtual?

**Descrição:**

> EM BREVE!

<br/>

## Contribuindo

Contribuições são o que tornam a comunidade de código aberto um lugar incrível para aprender, inspirar e criar. Todas as contribuições que você fizer são **muito bem vindas**!

Aqui está a estrutura de uma pasta, se você quiser contribuir com um tutorial completo ❤:

```
.
├── assets
│   ├── protoboard.png
│   └── pinoutv3.png
├── code
│   └── code.ino
├── fritzing
│   └── arquivo.fzz
└── README.md
```

E o modelo do arquivo README está aqui: [_MODELO_](MODELO.md).

Passos para enviar uma contribuição para nosso repositório:

1. Crie um _Fork_ do projeto
1. Crie sua _Branch_ (`git checkout -b feature/AmazingFeature`)
1. Dê um _Commit_ nas suas mudanças com uma mensagem (`git commit -m 'Coloquei um recurso legal'`)
1. _Push_ para esta _Branch_ (`git push origin feature/AmazingFeature`)
1. Abra uma [_Pull Request_](pulls) e aguarde :D

## Licença

Distribuído sob a licença MIT. Veja [LICENSE](LICENSE) para mais informações.

## Contato

PET Elétrica - [@peteletricaufba](https://www.instagram.com/peteletricaufba/?hl=pt-br) - peteletricaufbadee@gmail.com

Link do Projeto: [github.com/PETEletricaUFBA/automacao-iot-nodemcu](https://github.com/PETEletricaUFBA/automacao-iot-nodemcu)
