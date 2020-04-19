> Modelo sendo criado ainda, após isso teremos um esboço

<!-- LOGO -->
<h1 align="center">
  <br>
  <a href="#"><img src="assets/automation.png" alt="A smart house logo" width="100"></a>
  <br>
  NodeMCU para IoT
  <br>
</h1>


<h4 align="center">Um guia definitivo para para aprender <a href="https://www.nodemcu.com/index_en.html" target="_blank">NodeMCU</a> com diversos exemplos práticos, incluindo aplicações de Internet das Coisas! Step-by-Step</h4>

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


<!-- SOBRE O PROJETO -->
## Sobre o projeto
O projeto tem como objetivo apresentar um conteúdo prático, objetivo e de fácil consulta para um pessoa a partir de qualquer conhecimento que ela possua sobre Automação! Este guia conterá projetos iniciais como acender uma LED até como criar um servidor, integrar com um BOT e não sei oq.

### Softwares usados
Falamos algo do tipo de que *só* vamos usar isso
* [Arduino](https://www.arduino.cc/en/Main/Software)
* [Fritzing](https://fritzing.org/download/) (Opcional)

### Hardwares usado
Falar sobre alguns extras que são usado, mas na maioria são:
* Placa de desenvolvimento NodeMCU
* Resistores
* Push Buttons
* Jumpers

<!-- Organização -->
## Organização
Aqui fazemos uma breve descrição sobre a trilha de conhecimento do manual

> Sugiro a gente fazer uma imagem dessa pra ficar bem legal e ilustrativo!

![asd](assets/trilha.svg)

<!-- ESBOÇO -->
## Lista a vera:

<!--FAZER LINKS EM TODOS OS ITENS-->

### Noções básicas de programação e conhecimento do kit de desenvolvimento NodeMCU: (Tempo estimado: 15h)
	
Descrição: Aqui se trata de conhecer o kit de desenvolvimento, saber programar a placa para realizar leituras e escritas digitais e analógicas em circuitos básicos.

Pastas relacionadas: 1, 2

1. Conhecer a placa de desenvolvimento (os Microcontroladores, as GIPOs, Pinout, Nível de tensão, entre outros);
2. Saber o BÁSICO de alguma linguagem de programação como C, Lua, Python para programar o microcontrolador
3. Saber como upar um código para a placa usando alguma IDE (ou não)
4. Realizar pequenos circuitos com sensores e atuadores:
	Abaixo um exemplo de caminho legal para seguir:
	- Acender e apagar uma LED (Blinking) (Habilidade trabalhada > Escrita digital)
	- Ler estado de um botão e exibir no computador via serial (Habilidade trabalhada > Leitura digital)
	- Acender algumas LED's dependendo de alguns botões pressionados ou não (Habilidade trabalhada > Sensor + Atuador acoplados)
	- Mudar o brilho de uma lâmpada ao decorrer do tempo (Fading in e Fading out) (Habilidade trabalhada > Escrita analógica)
	- Acender uma led com brilho variável através de um potênciômetro (Habilidade trabalhada > Sensor + Atuador com sinais analógicos) Extra: entender PWM

Importante: Interessante usar o monitor serial ou plotter serial para debugar saídas e entradas ou fornecer informações adicionais

Ao término deste tópico o estudante deverá (trocar essa palavra) ter as habilidades de conhecer o básico do microcontrolador, saber programar e constuir circuitos simples para a leitura e escrita digital e analógica, instigando-o para o proximo tópico que é implementar algumas automações de pequenos circuitos em situações mais próximas do mundo real

### Noções de implementações de automação no mundo real: (Tempo estimado: 25h)
Descrição: Nesta etapa espera-se atingir outras habilidades como conhecimento dos diversos sensores e atuadores que se pode usar com estes microcontroladores. Basicamente a melhor forma de continuar os estudos será praticar mais circuitos!

Importante: Interessante usar o monitor serial ou plotter serial para debugar saídas e entradas ou fornecer informações adicionais

#### Sensores:
1. Circuito e programa com sensor de luminosidade LDR
2. Circuito e programa com sensor de distância
3. Circuito e programa com sensor de temperatura   \_ Existe um sensor que mede temperatura + umidade
4. Circuito e programa com sensor de umidade       /
5. Circuito e programa com sensor de presença PIR
6. Circuito e programa com sensor de infra vermelho

Comentar outros tipos de sensores: vazão de água, sensor de corrente, sensor de chuva, pressão de gás, sensor de vibraçao e outros bem mais específicos contudo o principio de funcionamento é o mesmo

#### Atuadores/Módulos:
1. Circuito e programa com relé controlado por algum sensor
2. Circuito e programa de um buzzer sendo controlado por botões ou um potênciômetro
3. Circuito e programa de um servo motor com alimentação externa controlado por um potenciômetro ou outro sensor
4. Circuito e programa de um motor usando Ponte H e controle através de potenciômetro ou outro sensor
5. Circuito e programa de alguma coisa sendo escrita em um display LCD (podendo usar o protocolo I2C)

### Noções de como levar informação para o mundo virtual!
Descrição: 


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