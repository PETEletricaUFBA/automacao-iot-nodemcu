# IoT

Esboço inicial para manual de automação:

_____________________________________________________
1) Noções básicas de programação e conhecimento do kit de desenvolvimento NodeMCU: (Tempo estimado: 15h)
	
Descrição: Aqui se trata de conhecer o kit de desenvolvimento, saber programar a placa para realizar leituras e escritas digitais e analógicas em circuitos básicos.

a) Conhecer a placa de desenvolvimento (os Microcontroladores, as GIPOs, Pinout, Nível de tensão, entre outros);
b) Saber o BÁSICO de alguma linguagem de programação como C, Lua, Python para programar o microcontrolador
c) Saber como upar um código para a placa usando alguma IDE (ou não)
d) Realizar pequenos circuitos com sensores e atuadores:
	Abaixo um exemplo de caminho legal para seguir:
	- Acender e apagar uma LED (Blinking) (Habilidade trabalhada > Escrita digital)
	- Ler estado de um botão e exibir no computador via serial (Habilidade trabalhada > Leitura digital)
	- Acender algumas LED's dependendo de alguns botões pressionados ou não (Habilidade trabalhada > Sensor + Atuador acoplados)
	- Mudar o brilho de uma lâmpada ao decorrer do tempo (Fading in e Fading out) (Habilidade trabalhada > Escrita analógica)
	- Acender uma led com brilho variável através de um potênciômetro (Habilidade trabalhada > Sensor + Atuador com sinais analógicos) Extra: entender PWM

Importante: Interessante usar o monitor serial ou plotter serial para debugar saídas e entradas ou fornecer informações adicionais

Ao término deste tópico o estudante deverá (trocar essa palavra) ter as habilidades de conhecer o básico do microcontrolador, saber programar e constuir circuitos simples para a leitura e escrita digital e analógica, instigando-o para o proximo tópico que é implementar algumas automações de pequenos circuitos em situações mais próximas do mundo real

_____________________________________________________
2) Noções de implementações de automação no mundo real: (Tempo estimado: 25h)
Descrição: Nesta etapa espera-se atingir outras habilidades como conhecimento dos diversos sensores e atuadores que se pode usar com estes microcontroladores. Basicamente a melhor forma de continuar os estudos será praticar mais circuitos!

Importante: Interessante usar o monitor serial ou plotter serial para debugar saídas e entradas ou fornecer informações adicionais

Sensores:
a) Circuito e programa com sensor de luminosidade LDR
b) Circuito e programa com sensor de distância
c) Circuito e programa com sensor de temperatura   \_ Existe um sensor que mede temperatura + umidade
d) Circuito e programa com sensor de umidade       /
e) Circuito e programa com sensor de presença PIR
f) Circuito e programa com sensor de infra vermelho

Comentar outros tipos de sensores: vazão de água, sensor de corrente, sensor de chuva, pressão de gás, sensor de vibraçao e outros bem mais específicos contudo o principio de funcionamento é o mesmo

Atuadores/Módulos:
a) Circuito e programa com relé controlado por algum sensor
b) Circuito e programa de um buzzer sendo controlado por botões ou um potênciômetro
c) Circuito e programa de um servo motor com alimentação externa controlado por um potenciômetro ou outro sensor
d) Circuito e programa de um motor usando Ponte H e controle através de potenciômetro ou outro sensor
e) Circuito e programa de alguma coisa sendo escrita em um display LCD (podendo usar o protocolo I2C)

_____________________________________________________
3) Noções de como levar informação para o mundo virtual!
Descrição: 

_______
4) 
_______

Outros:
- Criar uma API
- MQTT