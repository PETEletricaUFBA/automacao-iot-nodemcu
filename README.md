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

<!-- Sumário -->
<!-- Tem um nome melhor pra isso? -->
<!-- Deixar por ultimo -->

## SUMÁRIO 

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


<!-- SOBRE O PROJETO -->
## SOBRE O PROJETO
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
## TRILHA DO CONHECIMENTO
Dividiremos o conteúdo em algumas etapas, são elas:
* **1) Noções básicas de programação e conhecimento do kit de desenvolvimento NodeMCU:** Conceitos iniciais de lógica de programação e suas aplicações em circuitos básicos.
* **2) Noções de implementações de automação no mundo real:** Estudos sobre alguns sensores e atuadores e suas interações com o mundo físico.
* **3) Noções sobre a criação de bots e uso de servidores:** 
* **4) Como levar a informação para o mundo virtual?**

![asd](assets/trilha.svg)


## PROGRAMAÇÃO:

<!--FAZER LINKS EM TODOS OS ITENS-->

### 1) Noções básicas de programação e conhecimento do kit de desenvolvimento NodeMCU: (Tempo estimado: 15h)
	
**Descrição:** Apresenta-se conhecimentos sobre o kit NodeMCU e como programar uma placa para realizar leituras e escritas digitais e analógicas em circuitos básicos.

**Dica:** Interessante usar o monitor serial ou plotter serial para debugar saídas e entradas ou fornecer informações adicionais.

**Pastas relacionadas:** 1, 2, 3 e 4.

**Conteúdo:**
1. A placa de desenvolvimento: o microcontrolador, as GIPOs, pinout, níveis de tensão, entre outros;
2. Uso da linguagem de programação (C++ e Python) para o microcontrolador;
3. Processo de  upar um código para a placa usando uma IDE;
4. Indicação de pequenos circuitos para testes:
	- Acender e apagar uma LED (Blinking);
	- Ler estado de um botão e exibir no computador via serial;
	- Acender LEDs com botões;
	- Mudar o brilho de uma lâmpada ao decorrer do tempo (Fading in e Fading out);
	- Acender uma led com brilho variável através de um potênciômetro + PWM.


### 2) Noções de implementações de automação no mundo real: (Tempo estimado: 25h)
**Descrição:** Apresentação de outras habilidades utilizando diversos sensores e atuadores, a partir de aplicações práticas. 

**Dica:** Interessante usar o monitor serial ou plotter serial para debugar saídas e entradas ou fornecer informações adicionais.

#### **SENSORES:**

 **Pastas relacionadas:** 5, 6, 7, 8, 9 e 10.

1. Sensor de luminosidade LDR;
2. Sensor de distância;
3. Sensor de temperatura; 
4. Sensor de umidade;
5. Sensor de presença PIR;
6. Sensor de infra vermelho;
7. Outros tipos de sensores.


#### **ATUADORES/MÓDULOS:**

**Pastas relacionadas:**

1. Relé controlado por sensor;
2. Buzzer controlado por botões ou potênciômetro;
3. Servo motor com alimentação externa controlado por um potenciômetro ou outro sensor;
4. Motor usando Ponte H e controle através de potenciômetro ou outro sensor;
5. Escrita em um display LCD com o protocolo I2C.

### 3) Noções sobre a criação de bots e uso de servidores:*
**Descrição:**

**Pastas relacionadas:**

### 4) Como levar a informação para o mundo virtual?
**Descrição:**

**Pastas relacionadas:**

### Outros:
- Criar uma API
- MQTT

<!-- FIM ESBOÇO-->

<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.

<!-- CONTACT -->
## Contact

Your Name - [@your_twitter](https://twitter.com/your_username) - email@example.com

Project Link: [https://github.com/your_username/repo_name](https://github.com/your_username/repo_name)



<!-- Pra usar a logo, devemos informar o autor -->
<div>Icons made by <a href="https://www.flaticon.com/authors/freepik" title="Freepik">Freepik</a> from <a href="https://www.flaticon.com/" title="Flaticon">www.flaticon.com</a></div>
