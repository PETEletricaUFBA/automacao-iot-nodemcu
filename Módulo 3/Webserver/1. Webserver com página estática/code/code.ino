#include <ESP8266WiFi.h>

const char* ssid = "HUAWEI-2.4G-Uppx";
const char* password = "eBTPrJ4a";

IPAddress ip(192,168,100,234); 
IPAddress gateway(192,168,100,0); 
IPAddress subnet(255,255,255,0);

WiFiServer server(80);

const int redPin    = D2;
const int greenPin  = D1;
const int bluePin   = D0;

const int led = D4;
boolean stateLed = 0;

void ledColor(char color) {
  switch (color) {
    case 'c':
      digitalWrite(redPin, 0);
      digitalWrite(greenPin, 0);
      digitalWrite(bluePin, 0);
      break;
    case 'r':
      digitalWrite(redPin, 255);
      digitalWrite(greenPin, 0);
      digitalWrite(bluePin, 0);
      break;
    case 'g':
      digitalWrite(redPin, 0);
      digitalWrite(greenPin, 255);
      digitalWrite(bluePin, 0);
      break;
    case 'b':
     digitalWrite(redPin, 0);
     digitalWrite(greenPin, 0);
     digitalWrite(bluePin, 255);
     break;
  }
}

void setup() {
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  
  pinMode(led,OUTPUT);

  ledColor('b');
  
  Serial.begin(115200);
  delay(10);
  
  Serial.println("");
  Serial.println("");
  Serial.print("Conectando a ");
  Serial.print(ssid);

  WiFi.begin(ssid, password);
  WiFi.config(ip, gateway, subnet);
  
  byte i=0;
  
  while (WiFi.status() != WL_CONNECTED) {
    if (i++%2==0) ledColor('b'); else ledColor('c');
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.print("Conectado a rede sem fio ");
  Serial.println(ssid);
  server.begin();
  Serial.println("Servidor iniciado");

  Serial.print("IP para se conectar ao NodeMCU: ");
  Serial.print("http://");
  Serial.println(WiFi.localIP());
  ledColor('g');
}

String split(String r) {
  if (r == "GET /favicon.ico HTTP/1.1") return r;
  String b = "";
  for(int i=5; i<10; i++) b+=r[i];
  return b;
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  Serial.println("Novo cliente se conectou!");
  /*
  while(!client.available()){
    delay(1);
  }
  */
  
  String request = client.readStringUntil('\r');
  
  if (split(request) == "ligar") { 
    digitalWrite(led, 0);
    stateLed = 1;
  }
  if (split(request) == "desli") { 
    digitalWrite(led, 1);
    stateLed = 0;
  }
  
  Serial.println(request);
  client.flush();

  client.println("HTTP/1.1 200 OK"); // ESCREVE PARA O CLIENTE A VERSÃO DO HTTP
  client.println("Content-Type: text/html"); 
  client.println("");
  // <html> <head> </head>
  client.println("<!DOCTYPE html><html> <head> <meta charset='utf-8'> <meta http-equiv='X-UA-Compatible' content='IE=edge'> <meta name='viewport' content='width=device-width, initial-scale=1, shrink-to-fit=no'> <meta name='mobile-web-app-capable' content='yes'> <meta name='apple-mobile-web-app-status-bar-style' content='black-translucent'/> <meta name='theme-color' content='#0275d8'> <link rel='icon' type='image/x-icon' href='https://raw.githubusercontent.com/PETEletricaUFBA/automacao-iot-nodemcu/master/assets/automation.png'/> <title>Automação da Sala</title> <script src='https://code.jquery.com/jquery-2.1.4.min.js'></script> <script src='https://cdnjs.cloudflare.com/ajax/libs/tether/1.4.0/js/tether.min.js'></script> <link rel='stylesheet' href='https://cdnjs.cloudflare.com/ajax/libs/tether/1.4.0/css/tether.min.css'> <script> $(document).ready(function (){       var sideslider = $('[data-toggle=collapse-side]');    var sel = sideslider.attr('data-target');    var sel2 = sideslider.attr('data-target-2');    sideslider.click(function(event){    $(sel).toggleClass('in');    $(sel2).toggleClass('out');    });});$(document).ready(function() {    const $valueSpan = $('.valueSpan');    const $value = $('#slider11');    $valueSpan.html($value.val());    $value.on('input change', () => {        $valueSpan.html($value.val());    });  }); </script> <link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.6/css/bootstrap.min.css' integrity='sha384-rwoIResjU2yc3z8GV/NPeZWAv56rSmLldC3R/AZzGRnGxQQKnKkoFVhFQhNUwEyJ' crossorigin='anonymous'> <script src='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.6/js/bootstrap.min.js' integrity='sha384-vBWWzlZJ8ea9aCX4pEW3rVHjgjt7zpkNpZk+02D9phzyeVkE+jo0ieGizqPLForn' crossorigin='anonymous'></script> <style>*{    font-family: 'Raleway', sans-serif;}   pre {    tab-size: 8;}body{    background-color: #f9f9f9;}.container-fluid{    padding: 20px;}.navbar-brand{    font-family: 'Montserrat', sans-serif;}.card{    margin-bottom: 20px;    text-align: center;}.card, .card-text{    width: 100vw;    color: #333;}@media (min-width: 768px) {     .card, .card-text{        width: 40vw;    }}.card-text{    width:100%;    word-wrap: break-word;}.navbar-inverse .navbar-toggler{    border-color: rgba(255,255,255,0.5);}.fa-bars{    color: rgba(255,255,255,0.5);}.card-title{    font-size: 60px;}.card-title img{    height: 60px;}.fa-positivo{    color: limegreen;}.fa-negativo{    color:red;}.fa-invalido{    color:#FFDA44;}.fa-bomba{    color: dodgerblue;}.logo {    width: 75px;    height: 75px;    display: block;    margin: 5px auto;    padding: 10px;}.slidecontainer {    width: 100%;  }    .slider {    -webkit-appearance: none;    width: 100%;    height: 10px;    border-radius: 5px;    background: #d3d3d3;    outline: none;    opacity: 0.8;    -webkit-transition: .2s;    transition: opacity .2s;  }    .slider:hover {    opacity: 1;  }    .slider::-webkit-slider-thumb {    -webkit-appearance: none;    appearance: none;    width: 25px;    height: 25px;    border-radius: 50%;    background: rgb(30, 85, 187);    cursor: pointer;  }    .slider::-moz-range-thumb {    width: 25px;    height: 25px;    border-radius: 50%;    background: rgb(30, 85, 187);    cursor: pointer;  }  .center {    display: block;    margin: 10px auto;    max-width: 70%;  }</style> <link href='https://fonts.googleapis.com/css?family=Montserrat|Raleway' rel='stylesheet'> <script src='https://kit.fontawesome.com/a552ae84ad.js' crossorigin='anonymous'></script> </head>");
  // <body> <nav> </nav>
  client.println("<body> <nav class='navbar navbar-toggleable-md navbar-inverse bg-primary'> <button class='navbar-toggler navbar-toggler-right' type='button' data-toggle='collapse' data-target='#navbarSupportedContent' aria-controls='navbarSupportedContent' aria-expanded='false' aria-label='Toggle Navigation'> <i class='fa fa-bars' aria-hidden='true'></i> </button> <img class='logo' src='https://raw.githubusercontent.com/PETEletricaUFBA/automacao-iot-nodemcu/master/assets/automation.png'> <h1 class='navbar-brand mb-0 text-center'>Automação da Sala do PET</h1> <div class='collapse navbar-collapse' id='navbarSupportedContent'> <ul class='navbar-nav mr-auto'> <li class='nav-item active'> <a class='nav-link' href='index.html'>Home</a> <span class='sr-only'>(current)</span> </li> <li class='nav-item'> <a class='nav-link' href='sobre.html'>Sobre</a> </li> </ul> </div> </nav>");
  // <container> <row>
  client.println("<div class='container-fluid'> <div class='row'> ");
  
  // ------ LED --------
  // <card>
  client.println("<div class='col-sm'> <div class='card center'> <div class='card-block center'>");
  if(stateLed==0) {
    client.println("<span class='card-title'><i class='fa fa-lightbulb' aria-hidden='true' style='color:#dddddd;'></i></span>");
    client.println("<br><span><b>Luzes:</b> Desligadas</span>");
    client.println("<form action='/ligar' method='get'>");//Cria um botao GET para o link /LED
    client.println("<input class='btn btn-success' type='submit' value='ON' id='frm1_submit'/></form>");
  } else {
    client.println("<span class='card-title'><i class='fa fa-lightbulb' aria-hidden='true' style='color:rgb(255, 238, 0);'></i></span>");
    client.println("<br><span><b>Luzes:</b> Ligadas</span>");
    client.println("<form action='/desligar' method='get'>");//Cria um botao GET para o link /LED
    client.println("<input class='btn btn-danger' type='submit' value='OFF' id='frm1_submit'/></form>");
  }
  // </card>
  client.println("</div> </div> </div>");
  // ------------------

  // </container> </row>
  client.println("</div> </div>");

  // </body> </html>
  client.println("</body> </html>");
  
  delay(1); 
  Serial.println("Cliente desconectado"); 
  Serial.println(""); 
}
