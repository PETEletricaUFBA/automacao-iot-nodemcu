# 3. Criando um ponto de acesso Wi-fi pelo NODEMCU e armazenando arquivos na memória flash do ESP8266

A partir do módulo 3 os projetos desenvolvidos nesse repositório passaram a depender do acesso a internet, isto é, as aplicações dependem de uma rede Wi-Fi para que o ESP 8266 possa se conectar. Contudo, nem sempre teremos uma rede Wi-fi estável ou disponível e ainda assim, precisaremos desenvolver aplicações de Internet das Coisas (IoT) que necessitam estar interconectados via uma rede. Felizmente é possível criar um ponto de acesso configurável e customizável através do ESP 8266. 

Além disso, objetivando uma maior facilidade na construção e gerenciamento de projetos, sobretudo projetos grandes, detalhados e com várias partes distintas, faz-se necessário reduzir a quantidade de códigos. Imagine, por exemplo, que você precisa criar um Web-server com várias páginas distintas e precisa conectá-lo ao seu projeto físico, será que não ficaria impráticável ter que codificar todas as páginas e colocar junto ao seu código principal? Portanto, através do que será ensinado nessa seção, aprenderemos uma maneira de gerenciar nosso projeto, deixando informações secundárias em uma pasta específica que não irá interferir no projeto principal.

Para esta seção, vamos utilizar o webserver desenvolvido na anterioreriormente, o [Webserver com página dinâmica, usando AJAX](https://github.com/PETEletricaUFBA/automacao-iot-nodemcu/tree/master/M%C3%B3dulo%203/Webserver/2.%20Webserver%20com%20p%C3%A1gina%20din%C3%A2mica%2C%20usando%20AJAX).

> Nessa seção você irá aprender a criar um ponto de acesso Wi-fi com o ESP8266 e utilizar o sistema de arquivos do ESP8266, o SPIFFS (SPI Flash File System) para salvar códigos, imagens, arquivos de texto dentro do seu microcontrolador, retirando assim,os códigos secundários, páginas, imagens do seu webserver do seu código principal em C, possibilitando, portanto, um gerenciamento eficiente do seu projeto e a idependência de uma rede com acesso a internet. 

___

O ESP8266 apresenta um sistema de gerenciamento de arquivos responsável por armazenar arquivos pequenos chamado de SPIFFS (SPI Flash Filing System). Esse sistema, por sua vez, foi desenvolvido para que pudesse servir como uma memória para dispositivos que apresentam um baixo uso de memória RAM, como é o caso do módulo NODEMCU 8266.

A partir do SPIFFS permite-se o acesso à memória flash do ESP8266 possibilitando instalar e armazenar os diferentes arquivos que estão sendo usados pelo seu programa, como pode ser visualizado na figura abaixo:

![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_c4e076123db7ba554769e0b0b99ac9ea.png)

No entanto, o sistema SPIFFS apresenta algumas características e limitações como:

- Os arquivos são armazenados em um mesmo diretório e, portanto, não é possível armazenar pastas.
- O nome dos arquivos não pode ser maior que 32 caracteres.
- Um nome de arquivo pode começar com o caracter `"/"`. Exemplo:  `/exemplo/teste.html`.

## Conteúdo
- [Materiais Necessários](#materiais-necessários)
- [Montagem do Circuito](#montagem-do-circuito)
- [Preparando a IDE com as ferramentas de programação](#preparando-a-ide-com-as-ferramentas-de-programação)
- [O Código do Circuito](#o-c&oacute;digo-do-circuito)

## Materiais Necessários
1. NodeMCU
2. 4 LEDs
3. 4 Resistores de 220Ω a 1KΩ
4. Protoboard
5. Jumpers

## Preparando a IDE com as ferramentas de programação

### Instalando o gravador do sistema de arquivos na IDE do Arduino

1. Navegue até este [ link de download](https://github.com/esp8266/arduino-esp8266fs-plugin/releases) e baixe a última versão do arquivo .zip. Exemplo: `ESP8266FS-0.5.0.zip`

![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_ec967aed16e2ae8e97c7fad3472b2bba.png)

2. O segundo passo é ir até o local no seu computador onde a IDE do Arduino foi instalada. Depois disso, encontre a pasta tools.

![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_c13d1aa7e7f82c4e1d727d220cda280e.jpg)

3. Extraia o arquivo dentro da pasta tools que foi mostrada no item anterior:

![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_ee74bf8ede48495347e89dfeba9a9853.jpg)


Após extrair, a sua estrutura de arquivos ficará da seguinte forma:
```
tools
└── ESP8266FS
    └── tool
        └── esp8266fs.jar
```

4. Reinicie a IDE do Arduino.

5. Para verificar se o gravador do sistema de arquivos está instalado corretamente na IDE do Arduino. Vá para Ferramentas e verifique se o gravador foi instalado com sucesso, como pode ser visualizado na figura a seguir:

![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_e1dd4fc24fd26666300d2ca2bb2921e6.jpg)


### Instalando as bibliotecas para criação do 

## Montagem do Circuito
O circuito deve ser montado como mostra a figura abaixo, representado na protoboard.

<p align="center">
  <img src="assets/circuit.jpg" alt="Protoboard"/>
</p>

Para esta aplicação utilizamos quatro LEDs de cores diferentes. Como visualizado na figura, cada LED deve ser conectado a um pino digital e ao GND. O detalhe importante é a utilização e necessidade de um resistor para controle de corrente.

## O código do Circuito

Use o código que está em [code](code/code.ino)

A primeira coisa você deve fazer é mudar este trecho de código, inserindo o nome da sua rede WiFi e a sua senha (fique tranquilo(a), essa informação não será divulgada na internet). Realizar essa ação só permite que o seu ESP se conecte na sua rede Wi-fi, assim como o seu celular e outros dispositivos móveis, por exemplo.

```c++
const char* ssid = "NOME DA SUA REDE";
const char* password = "SENHA DA SUA REDE";
```

E por último, você deve editar essas linhas. Os parâmetros da segunda e da terceira linha se referem ao gateway padrão e máscara de sub-rede que podem ser encontradas seguindo este [tutorial](https://www.sony.com.br/electronics/support/laptop-pc-sve-series/sve15111ebs/articles/00022321). Os três primeiros parâmetros do _ip_ você deve mantê-los iguais aos do _gateway_, já no último parâmetro você coloca um número entre 100 e 255. Escolhemos, de forma pessoal, o número 234

```c++
IPAddress ip(192,168,100,234); 
IPAddress gateway(192,168,100,0); 
IPAddress subnet(255,255,255,0);
```
Um outro trecho de código que vale a pena uma explicação mais detalhada é a seguinte:
```c++
void updateLight() {
  String ledStatusParam = server.arg("lightStatus");
  if (ledStatusParam == "ON")
    lightStatus =  HIGH;
  else
    lightStatus =  LOW;
  digitalWrite(lightPin, lightStatus);
  server.send(200, "text/plain", "Sucesso!");
}
  ```

`String ledStatusParam=server.arg("lightStatus") `permite consultar o valor da variável lightStatus através do parâmetro em javascript que foi adicionado anteriormente. (É uma conexão entre o projeto físico e a parte virtual do projeto)

Posteriormente, através da estrutura condicional, e após consultar o estado da variável, garantimos, a mudança do estado de saída para HIGH ou LOW

```c++
void updateAir() {
  String airStatusParam = server.arg("airStatus");
  String airTempParam   = server.arg("airTemp");
  if (airStatusParam == "ON")
    analogWrite(airPin,map(airTempParam.toInt(), 15, 28, 0, 1023));
  else
    digitalWrite(airPin, LOW);
  server.send(200, "text/plain", "Sucesso!");
}
```
Diferentemente das outras três funções que foram implementadas para a lâmpada, porta e tomadas, o ar condicionado é uma grandeza analógica quantizada, assume uma faixa de valores previamente definidas, isto é, o ar condicionado da sua residência consegue variar entre 16°C e 28°C, enquanto a tomada e as lâmpadas estão ligadas ou desligadas, apenas.

Semelhante ao que foi feito para as outras saídas, armazena-se o estado da variável `airStatus` e `airTem`. Nesse sentido, caso um usuário deseje alterar o valor atual da temperatura, a requisição efetuada pelo usuário enviará ao servidor a informação `"ON"` + a alteração do valor de temperatura.

`analogWrite(airPin,map(airTempParam.toInt(), 15, 28, 0, 1023))`

Semelhante ao que você aprendeu em escrita analógica, há a conversão direta entre a informação analógica 15°C~28°C e a informação processada pelo ADC de 10 bits que varia de 0 a 1023.

Por fim, caso o usuário queira desligar o aparelho, a informação enviada ao servidor Web é `LOW` e com isso altera-se o seu estado atual para desligado.

Uma vez que se houve a compreensão da parte inicial do nosso código, faz-se necessário entender os processos que são realizados com Javascript. Falaremos somente um pouco sobre as funções, caso você queira aprender mais sobre JavaScript, [clique aqui](https://www.w3schools.com/js/default.asp). A seguir explicaremos um pouco as funções do `JavaScript`. Note que o código pode estar um pouco diferente em algums momentos como no lugar de `"` tem um `\"`, isso se deve ao fato de o código Javascript está dentro de uma string em C, por isso, teve que ser feito esse artifício. O primeiro processo que vale a pena destacar é o realizado pela `function init()` que está abaixo:
```c++
function init() {
    var xhttp1 = new XMLHttpRequest();
    xhttp1.open("GET", "toggleLight?lightStatus="+lightStatus, true);
    xhttp1.send();
    var xhttp2 = new XMLHttpRequest();
    xhttp2.open("GET", "toggleOutlet?outletStatus="+outletStatus, true);
    xhttp2.send();
    var xhttp3 = new XMLHttpRequest();
    xhttp3.open("GET", "toggleDoor?doorStatus="+doorStatus, true);
    xhttp3.send();
    var xhttp4 = new XMLHttpRequest();
    xhttp4.open("GET", "toggleAir?airStatus="+airStatus+"&airTemp="+slideAir.value, true);
    xhttp4.send();
}
```

Através dessa função obtém-se o estado atual da página de cada saída, isto é, a lâmpada está ligada ou desligada? O ar condicionado está ligado? Se sim, está configurado em qual temperatura? Dessa forma, a função é capaz de obter informações preliminares e atualizar o estado dos ícones do nosso web-server e dos seus dispositivos físicos.

Uma outra função que vale a pena destacar e que se repete para as outras saídas do nosso projeto é a ```air.onclick = function()``` a seguir:
```c++
var air = document.getElementById('air');
var airStatus = air.checked ? "ON" : "OFF";
document.getElementById("airIcon").style.color = air.checked? "cornflowerblue" : "lightgray";
var slideAir = document.getElementById("slider11");
air.onclick = function() {
    console.log("Botao do ar clicado");
    if (this.checked) {
        airStatus = "ON";
        document.getElementById("airIcon").style.color = \"cornflowerblue\";
        console.log("ON");
    } else {
        airStatus = "OFF";
        document.getElementById("airIcon").style.color = "lightgray";
        console.log(\"OFF\");"
    }
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            console.log(\"Requisicao recebida\");"
        }
    };
    xhttp.open("GET", "toggleAir?airStatus="+airStatus+"&airTemp="+slideAir.value, true);
    xhttp.send();
};
```

Caso você não se recorde, em um primeiro momento comentamos sobre a função ```
void updateAir()```, responsável por verificar o status de airStatus e alterar o estado da saída, de forma física, certo? Na função ```air.onclick=function()```, veremos como alterar o valor de `airStatus`

Antes de falar propriamente da função, é necessário criar um objeto responsável por ser o parâmetro que vai indicar o Status do ar condicionado. Inicialmente temos três objetos diferentes: `air`, `airStauts` e o `sliderAir` que informaram ao servidor se o ar condicionado está ligado e se sim, em qual temperatura ele se encontra.

Nesse caso, a partir da função ```air.onclick=function()```, o usuário consegue interagir com o webserver (apertando o botão) e fazendo com que alguns parâmetros sejam alterados. Por exemplo, se o usuário clicar no botão que é uma caixa de seleção, a caixa ficará selecionada e o status da variável `airStatus` assumirá ON e a cor do objeto no ser será alterada.

A partir de ```var xhttp = new XMLHttpRequest();```, acontece uma requisição do servidor ao cliente, que de forma assíncrona, atualiza as informações alteradas, sem que haja a necessidade de atualizar a página inteira.

```c++
slideAir.oninput = function() {
    console.log("Valor do ar mudado");
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            console.log(\"Requisicao recebida\");"
        }
    };"
    xhttp.open("GET", "toggleAir?airStatus="+airStatus+"&airTemp="+slideAir.value, true);
    xhttp.send();
};
```
Para o funcionamento do ar condicionado em específico criamos uma nova função ```slideAir.oninput = function()``` que é responsável por passar informações ao servidor sobre o valor de temperatura e o status do ar condicionado quando o usuário deslizar o botão, selecionando uma temperatura em específico. Lembrando que, com a utilização do AJAX, as alterações são processadas de forma assíncrona.

As demais funções utilizadas neste código, são funções padrão das bibliotecas e por motivos de simplificação, não serão explicadas. 

É possível configurar um apelido para o ip do seu servidor no seu computador como mostra a imagem a seguir:
<p align="center">
  <img width="400px" src="assets/host.png" alt="host"/>
</p>

Para fazer isso no Linux, basta adicionar uma linha no arquivo `/etc/hosts`:
```bash
# Host addresses
127.0.0.1        localhost
...
192.168.100.234  automacao <-- Adicione essa linha
```

No windows, este arquivo está no diretório `C: > Windows > System32 > Drivers > etc`.

<p align="center">
  <img src="assets/circuit.gif" alt="circuito"/>
</p>

Neste webserver importamos alguns códigos externos de bibliotecas para estilização da página. Estes códigos estão hospedados na internet, isto faz com que nosso webserver exiba a página adequadamente apenas quando a rede que este ESP está conectado estiver com acesso à internet. Isto pode ser um problema se quisermos implementar um sistema em algum local com uma rede que não tem acesso a internet.

Além disso, embora o webserver que criamos neste post não seja mais uma página estática, ele ainda é uma página única, sem redirecionamento para outras páginas. E se quiséssemos colocar mais páginas nesse webserver?

Visando resolver este problema, podemos utilizar a memória flash do ESP com o objetivo de armazenar estes códigos e possíveis páginas sem depender do acesso à internet. Inclusive, o NodeMCU consegue criar o seu próprio ponto de acesso Wi-fi, sem a necessidade de estar conectado a uma rede com acesso a internet.

Dessa forma, visando superar essas barreiras e necessidades de acesso a internet, no próximo post ensinaremos como armazenar códigos e páginas do seu projeto na memória flash e ainda, explicaremos, de forma detalhada, como criar o seu próprio ponto de acesso Wi-fi com o seu ESP.

Caso tenha tido algum problema abra uma _issue_ clicando [aqui](https://github.com/PETEletricaUFBA/IoT/issues/new)

> É importante saber que o uso de *web servers* não se restringe a esse projeto. Após a compreensão do que foi feito no post, experimente criar uma outra aplicação física e integrá-la a um web server. É possível, por exemplo, controlar todas as lâmpadas de sua casa ou um eletrodoméstico, ativar ou desativar alarme de segurança via navegador do seu celular ou computador.
