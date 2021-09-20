# 2. Webserver com página dinâmica, usando AJAX

<p align="center">
  <img width="400px" src="assets/ajax.png" alt="ajax"/>
</p>

Ao final do post anterior vimos que a utilização do [Webserver com página estática](https://github.com/PETEletricaUFBA/automacao-iot-nodemcu/tree/master/M%C3%B3dulo%203/Webserver/1.%20Webserver%20com%20p%C3%A1gina%20est%C3%A1tica) apresenta alguns inconvenientes que comprometem significativamente o controle e a supervisão de um processo em tempo real. Portanto, para resolver esse problema, aprenderemos como criar um Webserver capaz de atualizar a sua página e garantir o monitoramento e controle em tempo real.

O AJAX, acrônimo de Asynchronous Javascript and XML (Javascript e XML assíncronos), possibilita o uso de um recurso no servidor que garante a utilização de um código Javascript no navegador web. A característica mais atraente e de nosso interesse é que, a natureza assíncrona, faz com que se possa enviar/receber informações e apenas uma parte da página da web atualize, sem necessidade de atualizar a página por inteiro.

As imagens a seguir mostram as diferenças do funcionamento de um Webserver com e sem AJAX:

[![](https://mermaid.ink/img/eyJjb2RlIjoic3RhdGVEaWFncmFtLXYyXG4gICAgc3RhdGUgQ29udmVuY2lvbmFsIHtcbiAgICAgICAgQ2xpZW50ZS0tPldlYlNlcnZlciA6IFJlcXVpc2nDp8OjbyBIVFRQXG4gICAgICAgIFdlYlNlcnZlci0tPkNsaWVudGUgOiBBdHVhbGl6YSBhIHDDoWdpbmFcbiAgICAgICAgc3RhdGUgQ2xpZW50ZSB7XG4gICAgICAgICAgICBjbGllbnRlOkNvbXB1dGFkb3IgZSBDZWx1bGFyIChIVE1MLCBDU1MsIEpTKVxuICAgICAgICB9XG4gICAgICAgIHN0YXRlIFdlYlNlcnZlciB7XG4gICAgICAgICAgICBzZXJ2ZXI6V2ViIHNlcnZlciAoTm9kZU1DVSBFU1A4MjY2KVxuICAgICAgICAgICAgZmlzaWNvOiBBY2VuZGUgTEVEc1xuICAgICAgICAgICAgZmlzaWNvIC0tPiBzZXJ2ZXIgOiBcbiAgICAgICAgICAgIHNlcnZlciAtLT4gZmlzaWNvXG4gICAgICAgIH1cbiAgICAgICAgbm90ZSByaWdodCBvZiBXZWJTZXJ2ZXJcbiAgICAgICAgICAgIE8gc2Vydmlkb3IgcHJvY2Vzc2EgdW1hIG5vdmEgcMOhZ2luYSBlIGRldm9sdmUgcGFyYSBvIGNsaWVudGVcbiAgICAgICAgZW5kIG5vdGVcbiAgICB9IiwibWVybWFpZCI6e30sInVwZGF0ZUVkaXRvciI6ZmFsc2V9)](https://mermaid-js.github.io/mermaid-live-editor/#/edit/eyJjb2RlIjoic3RhdGVEaWFncmFtLXYyXG4gICAgc3RhdGUgQ29udmVuY2lvbmFsIHtcbiAgICAgICAgQ2xpZW50ZS0tPldlYlNlcnZlciA6IFJlcXVpc2nDp8OjbyBIVFRQXG4gICAgICAgIFdlYlNlcnZlci0tPkNsaWVudGUgOiBBdHVhbGl6YSBhIHDDoWdpbmFcbiAgICAgICAgc3RhdGUgQ2xpZW50ZSB7XG4gICAgICAgICAgICBjbGllbnRlOkNvbXB1dGFkb3IgZSBDZWx1bGFyIChIVE1MLCBDU1MsIEpTKVxuICAgICAgICB9XG4gICAgICAgIHN0YXRlIFdlYlNlcnZlciB7XG4gICAgICAgICAgICBzZXJ2ZXI6V2ViIHNlcnZlciAoTm9kZU1DVSBFU1A4MjY2KVxuICAgICAgICAgICAgZmlzaWNvOiBBY2VuZGUgTEVEc1xuICAgICAgICAgICAgZmlzaWNvIC0tPiBzZXJ2ZXIgOiBcbiAgICAgICAgICAgIHNlcnZlciAtLT4gZmlzaWNvXG4gICAgICAgIH1cbiAgICAgICAgbm90ZSByaWdodCBvZiBXZWJTZXJ2ZXJcbiAgICAgICAgICAgIE8gc2Vydmlkb3IgcHJvY2Vzc2EgdW1hIG5vdmEgcMOhZ2luYSBlIGRldm9sdmUgcGFyYSBvIGNsaWVudGVcbiAgICAgICAgZW5kIG5vdGVcbiAgICB9IiwibWVybWFpZCI6e30sInVwZGF0ZUVkaXRvciI6ZmFsc2V9)

[![](https://mermaid.ink/img/eyJjb2RlIjoic3RhdGVEaWFncmFtLXYyXG4gICAgc3RhdGUgQUpBWCB7XG4gICAgICAgIENsaWVudGUtLT5DaGFtYWRhQUpBWCA6IENoYW1hZGEgZG8gSmF2YVNjcmlwdFxuICAgICAgICBDaGFtYWRhQUpBWCAtLT4gV2ViU2VydmVyIDogUHJvY2Vzc2Egb3MgZGFkb3NcbiAgICAgICAgV2ViU2VydmVyLS0-Q2hhbWFkYUFKQVggOiBFbnZpYSBkYWRvcyBYTUxcbiAgICAgICAgQ2hhbWFkYUFKQVggLS0-IENsaWVudGUgOiBSZWFsaXphIGFzIGF0dWFsaXphw6fDtWVzIG5hIHDDoWdpbmFcbiAgICAgICAgc3RhdGUgQ2xpZW50ZSB7XG4gICAgICAgICAgICBjbGllbnRlOkNvbXB1dGFkb3IgZSBDZWx1bGFyIChIVE1MLCBDU1MsIEpTKVxuICAgICAgICAgICAgamF2YXNjcmlwdDogSmF2YXNjcmlwdFxuICAgICAgICAgICAgamF2YXNjcmlwdCAtLT4gY2xpZW50ZSA6IEVzdGlsaXphIGEgcMOhZ2luYSBcbiAgICAgICAgICAgIGNsaWVudGUgLS0-IGphdmFzY3JpcHQgOiBVc3XDoXJpbyBjbGljYSBubyBib3TDo29cbiAgICAgICAgfVxuICAgICAgICBzdGF0ZSBDaGFtYWRhQUpBWCB7IFxuICAgICAgICAgICAgYXM6TWVjYW5pc21vIGVtIEphdmFzY3JpcHRcbiAgICAgICAgfVxuICAgICAgICBzdGF0ZSBXZWJTZXJ2ZXIge1xuICAgICAgICAgICAgc2VydmVyOldlYiBzZXJ2ZXIgKE5vZGVNQ1UgRVNQODI2NilcbiAgICAgICAgICAgIGZpc2ljbzogQWNlbmRlIExFRHNcbiAgICAgICAgICAgIGZpc2ljbyAtLT4gc2VydmVyIDogXG4gICAgICAgICAgICBzZXJ2ZXIgLS0-IGZpc2ljb1xuICAgICAgICB9XG4gICAgICAgIG5vdGUgcmlnaHQgb2YgV2ViU2VydmVyXG4gICAgICAgICAgICBPIHNlcnZpZG9yIHByb2Nlc3NhIGluZm9ybWHDp8O1ZXMgXG4gICAgICAgICAgICBlIGF0dWFsaXphIGEgcMOhZ2luYSBkbyBjbGllbnRlIFxuICAgICAgICAgICAgYXNzaW5jcm9uYW1lbnRlLCBzZW0gcmVjYXJyZWdhciBhIHDDoWdpbmFcbiAgICAgICAgZW5kIG5vdGVcbiAgICB9IiwibWVybWFpZCI6e30sInVwZGF0ZUVkaXRvciI6ZmFsc2V9)](https://mermaid-js.github.io/mermaid-live-editor/#/edit/eyJjb2RlIjoic3RhdGVEaWFncmFtLXYyXG4gICAgc3RhdGUgQUpBWCB7XG4gICAgICAgIENsaWVudGUtLT5DaGFtYWRhQUpBWCA6IENoYW1hZGEgZG8gSmF2YVNjcmlwdFxuICAgICAgICBDaGFtYWRhQUpBWCAtLT4gV2ViU2VydmVyIDogUHJvY2Vzc2Egb3MgZGFkb3NcbiAgICAgICAgV2ViU2VydmVyLS0-Q2hhbWFkYUFKQVggOiBFbnZpYSBkYWRvcyBYTUxcbiAgICAgICAgQ2hhbWFkYUFKQVggLS0-IENsaWVudGUgOiBSZWFsaXphIGFzIGF0dWFsaXphw6fDtWVzIG5hIHDDoWdpbmFcbiAgICAgICAgc3RhdGUgQ2xpZW50ZSB7XG4gICAgICAgICAgICBjbGllbnRlOkNvbXB1dGFkb3IgZSBDZWx1bGFyIChIVE1MLCBDU1MsIEpTKVxuICAgICAgICAgICAgamF2YXNjcmlwdDogSmF2YXNjcmlwdFxuICAgICAgICAgICAgamF2YXNjcmlwdCAtLT4gY2xpZW50ZSA6IEVzdGlsaXphIGEgcMOhZ2luYSBcbiAgICAgICAgICAgIGNsaWVudGUgLS0-IGphdmFzY3JpcHQgOiBVc3XDoXJpbyBjbGljYSBubyBib3TDo29cbiAgICAgICAgfVxuICAgICAgICBzdGF0ZSBDaGFtYWRhQUpBWCB7IFxuICAgICAgICAgICAgYXM6TWVjYW5pc21vIGVtIEphdmFzY3JpcHRcbiAgICAgICAgfVxuICAgICAgICBzdGF0ZSBXZWJTZXJ2ZXIge1xuICAgICAgICAgICAgc2VydmVyOldlYiBzZXJ2ZXIgKE5vZGVNQ1UgRVNQODI2NilcbiAgICAgICAgICAgIGZpc2ljbzogQWNlbmRlIExFRHNcbiAgICAgICAgICAgIGZpc2ljbyAtLT4gc2VydmVyIDogXG4gICAgICAgICAgICBzZXJ2ZXIgLS0-IGZpc2ljb1xuICAgICAgICB9XG4gICAgICAgIG5vdGUgcmlnaHQgb2YgV2ViU2VydmVyXG4gICAgICAgICAgICBPIHNlcnZpZG9yIHByb2Nlc3NhIGluZm9ybWHDp8O1ZXMgXG4gICAgICAgICAgICBlIGF0dWFsaXphIGEgcMOhZ2luYSBkbyBjbGllbnRlIFxuICAgICAgICAgICAgYXNzaW5jcm9uYW1lbnRlLCBzZW0gcmVjYXJyZWdhciBhIHDDoWdpbmFcbiAgICAgICAgZW5kIG5vdGVcbiAgICB9IiwibWVybWFpZCI6e30sInVwZGF0ZUVkaXRvciI6ZmFsc2V9)


Dessa forma, a característica primordial a ser acrescida no nosso webserver com a utilização do AJAX é a atualização de partes de uma página a partir de eventos de um usuário, ou seja, caso algum sensor ou atuador mudem de estado, pela natureza do processo ou pela interação com o usuário, o seu estado será atualizado sem a necessidade de atualizar a página inteira.

> Nesse projeto você irá aprender a criar um web server com página dinâmica utilizando AJAX na rede interna e integrá-lo ao seu projeto físico no ESP 8266.

## Conteúdo
- [Materiais Necessários](#materiais-necessários)
- [Montagem do Circuito](#montagem-do-circuito)
- [O Código do Circuito](#o-c&oacute;digo-do-circuito)

## Materiais Necessários
1. NodeMCU
2. 4 LEDs
3. 4 Resistores de 220Ω a 1KΩ
4. Protoboard
5. Jumpers

## Montagem do Circuito
O circuito deve ser montado como mostra a figura abaixo, representado na protoboard.

<p align="center">
  <img src="assets/circuit.jpg" alt="Protoboard"/>
</p>

Para esta aplicação utilizamos quatro LEDs de cores diferentes. Como visualizado na figura, cada LED deve ser conectado a um pino digital e ao GND. O detalhe importante é a utilização e necessidade de um resistor para controle de corrente.


## O código do Circuito

Use o código que está em [code](code/code.ino)

A primeira coisa você deve fazer é mudar este trecho de código, inserindo o nome da sua rede WiFi e a sua senha (fique tranquilo(a), essa informação não será divulgada na internet). Realizar essa ação só permite que o seu ESP se conecte na sua rede Wi-fi, assim como o seu celular e outros dispositivos móveis, por exemplo.

```c++=5
const char* ssid = "NOME DA SUA REDE";
const char* password = "SENHA DA SUA REDE";
```

E por último, você deve editar essas linhas. Os parâmetros da segunda e da terceira linha se referem ao gateway padrão e máscara de sub-rede que podem ser encontradas seguindo este [tutorial](https://www.sony.com.br/electronics/support/laptop-pc-sve-series/sve15111ebs/articles/00022321). Os três primeiros parâmetros do _ip_ você deve mantê-los iguais aos do _gateway_, já no último parâmetro você coloca um número entre 100 e 255. Escolhemos, de forma pessoal, o número 234

```c++=9
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
```js=341
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
```js=305
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

```js=330
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
