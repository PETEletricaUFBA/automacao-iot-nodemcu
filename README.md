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

<!--RESOLVER ISSO-->
![asd](assets/trilha.png)

## Módulos:

### 1) Noções básicas de programação e conhecimento do kit de desenvolvimento NodeMCU
	
**Descrição:** Apresenta-se conhecimentos sobre o kit NodeMCU e como programar uma placa para realizar leituras e escritas digitais e analógicas em circuitos básicos.

**Conteúdo:**
1. Primeiros passos
  - Conhecendo a placa de desenvolvimento: o microcontrolador, as GIPOs, pinout, níveis de tensão, entre outros;
  - Configurando a IDE do Arduino para programar o NodeMCU;
  - Compilar um programa teste que acende e apaga um LED (Blinking).

2. Leitura de sinais digitais: Ler estado de um botão e exibir no computador via serial;

3. Escrita analógica: Mudar o brilho de uma lâmpada ao decorrer do tempo (Fading in e Fading out);

4. Leitura e escrita analógica: Acender um LED com brilho variável através de um potênciômetro com PWM.

<br/>

### 2) Noções de implementações de automação no mundo real

**Descrição:** Apresentação de outras habilidades utilizando diversos sensores e atuadores, a partir de aplicações práticas. 

#### **Sensores:**

1. Sensor de presença PIR;
2. Sensor de luminosidade LDR;   
3. Sensor de distância;          
4. Sensor de temperatura; (Breve)  
5. Sensor de umidade; (Breve)  
6. Sensor de infra vermelho. (Breve)    

#### **Atuadores:**

1. Relé controlado por sensor; (Breve)
2. Buzzer controlado por botões ou potênciômetro; (Breve)
3. Servo motor com alimentação externa controlado por um potenciômetro ou outro sensor; (Breve)
4. Motor usando Ponte H e controle através de potenciômetro ou outro sensor; (Breve)
5. Escrita em um display LCD com o protocolo I2C. (Breve)

<br/>

### 3) Noções sobre a criação de bots e uso de servidores

**Descrição:**

> EM BREVE!

<br/>

### 4) Como levar a informação para o mundo virtual?
**Descrição:**

> EM BREVE!

<br/>

## Contribuindo

Contribuições são o que tornam a comunidade de código aberto um lugar incrível para aprender, inspirar e criar. Todas as contribuições que você fizer são **muito bem vindas**!

Aqui está a estrutura de uma pasta, se você quiser contribuir com um tutorial completo <3:
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
2. Crie sua _Branch_ (`git checkout -b feature/AmazingFeature`)
3. Dê um _Commit_ nas suas mudanças com uma mensagem (`git commit -m 'Coloquei um recurso legal'`)
4. _Push_ para esta _Branch_ (`git push origin feature/AmazingFeature`)
5. Abra uma [_Pull Request_](pulls) e aguarde :D


## Licença

Distribuído sob a licença MIT. Veja [LICENSE](LICENSE) para mais informações.

## Contato

PET Elétrica - [@peteletricaufba](https://www.instagram.com/peteletricaufba/?hl=pt-br) - peteletricaufbadee@gmail.com

Link do Projeto: [https://github.com/PETEletricaUFBA/automacao-iot-nodemcu](https://github.com/PETEletricaUFBA/automacao-iot-nodemcu)
