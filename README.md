> Modelo sendo criado ainda, após isso teremos um esboço

<!-- LOGO -->
<h1 align="center">
  <br>
  <a href="#"><img src="assets/automation.png" alt="A smart house logo" width="100"></a>
  <br>
  NodeMCU para IoT
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
  <a href="#">
    <img src="https://badgen.net/github/license/PETEletricaUFBA/IoT">
  </a>
  <img src="https://badgen.net/github/last-commit/PETEletricaUFBA/IoT">
</p> 

<!-- Menu Principal -->
<!-- Aqui colocamos páginas principais como creditos, licença, como contribuir, coisas assim..-->
<p align="center">
  <a href="#key-features">Key Features</a> •
  <a href="#how-to-use">How To Use</a> •
  <a href="#contributing">Contribuir</a> •
  <a href="#credits">Creditos</a> •
  <a href="#authors">Autores</a> •
  <a href="#license">Licença</a>
</p>

## Sumário

* [Sobre o projeto](#sobre-o-projeto)
  * [Built With](#built-with)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installation](#installation)
* [Usage](#usage)
* [Roadmap](#roadmap)
* [Contributing](#contributing)
* [License](#license)
* [Contact](#contact)
* [Acknowledgements](#acknowledgements)

## Sobre o projeto
O projeto busca apresentar um conteúdo prático, objetivo e de fácil consulta. Ele é acessível para qualquer pessoa, independente do nível de conhecimento em Automação.
Este guia conterá projetos iniciais, como acender um LED,  criar um servidor e integrá-lo com um bot ou na internet.

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

<!-- Organização -->
## Trilha do conhecimento
Dividiremos o conteúdo em alguns módulos:
* **1) Noções básicas de programação e conhecimento do kit de desenvolvimento NodeMCU:** Conceitos iniciais de lógica de programação e suas aplicações em circuitos básicos.
* **2) Noções de implementações de automação no mundo real:** Estudos sobre alguns sensores e atuadores e suas interações com o mundo físico.
* **3) Noções sobre a criação de bots e uso de servidores:** Competências relacionadas a conectividade e a integração de sensores e atuadores através da Internet.
* **4) Como levar a informação para o mundo virtual?** Agora é hora de colocar nossas aplicações na nuvem!

<!--RESOLVER ISSO-->
![asd](assets/trilha.svg)

## Módulos:

### 1) Noções básicas de programação e conhecimento do kit de desenvolvimento NodeMCU:
	
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

### 2) Noções de implementações de automação no mundo real:

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

### 3) Noções sobre a criação de bots e uso de servidores:

**Descrição:**

> EM BREVE!

<br/>

### 4) Como levar a informação para o mundo virtual?
**Descrição:**

> EM BREVE!

<br/>

## Contribuindo

Contribuições são o que tornam a comunidade de código aberto um lugar incrível para aprender, inspirar e criar. Todas as contribuições que você fizer são **muito bem vindas**!

1. Crie um _Fork_ do projeto
2. Crie sua _Branch_ (`git checkout -b feature/AmazingFeature`)
3. Dê um _Commit_ nas suas mudanças com uma mensagem (`git commit -m 'Coloquei um recurso legal'`)
4. _Push_ para esta _Branch_ (`git push origin feature/AmazingFeature`)
5. Abra uma _Pull Request_ e aguarde :D

## Licença

Distribuído sob a licença MIT. Veja [LICENSE](license.md) para mais informações.

## Contato

PET Elétrica - [@peteletricaufba](instagram.com/peteletricaufba/) - peteletricaufbadee@gmail.com

Link do Projeto: [https://github.com/PETEletricaUFBA/IoT/](https://github.com/PETEletricaUFBA/IoT/)