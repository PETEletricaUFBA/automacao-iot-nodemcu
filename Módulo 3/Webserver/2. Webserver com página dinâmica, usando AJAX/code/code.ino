#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
 
 
/********** PLEASE CHANGE THIS *************************/
const char* ssid = "HUAWEI-2.4G-Uppx";
const char* password = "eBTPrJ4a";

IPAddress ip(192,168,100,234); 
IPAddress gateway(192,168,100,0); 
IPAddress subnet(255,255,255,0);
 
ESP8266WebServer server(80);
 
uint8_t lightPin = D0;
bool lightStatus = LOW;

uint8_t outletPin = D2;
bool outletStatus = LOW;

uint8_t doorPin = D4;
bool doorStatus = LOW;

uint8_t airPin = D5;
bool airStatus = LOW;
 
void setup() {
  Serial.begin(115200);
  pinMode(lightPin, OUTPUT);
  pinMode(outletPin, OUTPUT);
  pinMode(doorPin, OUTPUT);
  pinMode(airPin, OUTPUT);
 
  Serial.println("Connecting to ");
  Serial.println(ssid);
 
  //connect to your local wi-fi network
  WiFi.begin(ssid, password);
  WiFi.config(ip, gateway, subnet);
 
  //check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());
 
  server.on("/", handleRoot);
  server.on("/toggleLight", updateLight);
  server.on("/toggleOutlet", updateOutlet);
  server.on("/toggleDoor", updateDoor);
  server.on("/toggleAir", updateAir);
  server.onNotFound(handleNotFound);
 
  server.begin();
  Serial.println("HTTP server started");
}
 
void handleRoot() {
  server.send(200, "text/html", prepareHTML());
}
 
void updateLight() {
  String ledStatusParam = server.arg("lightStatus");
  if (ledStatusParam == "ON")
    lightStatus =  HIGH;
  else
    lightStatus =  LOW;
  digitalWrite(lightPin, lightStatus);
 
  server.send(200, "text/plain", "Success!");
}

void updateOutlet() {
  String outletStatusParam = server.arg("outletStatus");
  if (outletStatusParam == "ON")
    outletStatus =  HIGH;
  else
    outletStatus =  LOW;
  digitalWrite(outletPin, outletStatus);
 
  server.send(200, "text/plain", "Success!");
}

void updateDoor() {
  String doorStatusParam = server.arg("doorStatus");
  if (doorStatusParam == "ON")
    doorStatus =  HIGH;
  else
    doorStatus =  LOW;
  digitalWrite(doorPin, doorStatus);
 
  server.send(200, "text/plain", "Success!");
}


void updateAir() {
  String airStatusParam = server.arg("airStatus");
  if (airStatusParam == "ON")
    airStatus =  HIGH;
  else
    airStatus =  LOW;
  digitalWrite(airPin, airStatus);
 
  server.send(200, "text/plain", "Success!");
}
 
 
void handleNotFound() {
  server.send(404, "text/plain", "Not found");
}

void loop() {
  server.handleClient();
}

String prepareHTML() {
  // BuildMyString.com generated code. Please enjoy your string responsibly.
 
  String html = "<!DOCTYPE html>"
"\n<html lang=\"en\">"
"\n    <head>"
"\n        <meta charset=\"utf-8\">"
"\n        <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">"
"\n        <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">"
"\n        <meta name=\"mobile-web-app-capable\" content=\"yes\">"
"\n        <meta name=\"apple-mobile-web-app-status-bar-style\" content=\"black-translucent\" \/>"
"\n        <meta name=\"theme-color\" content=\"#0275d8\">"
"\n        <link rel=\"icon\" type=\"image\/x-icon\" href=\"https:\/\/cdn.jsdelivr.net\/gh\/PETEletricaUFBA\/automacao-iot-nodemcu@master\/assets\/automation.png\"\/>"
"\n        <title>Automa\u00E7\u00E3o da Sala<\/title>"
"\n        <script src=\"https:\/\/code.jquery.com\/jquery-2.1.4.min.js\"><\/script>"
"\n        <script src=\"https:\/\/cdnjs.cloudflare.com\/ajax\/libs\/tether\/1.4.0\/js\/tether.min.js\"><\/script>"
"\n        <link rel=\"stylesheet\" href=\"https:\/\/cdnjs.cloudflare.com\/ajax\/libs\/tether\/1.4.0\/css\/tether.min.css\">"
"\n        <script src=\"https:\/\/cdn.jsdelivr.net\/gh\/PETEletricaUFBA\/automacao-iot-nodemcu@master\/M%C3%B3dulo%203\/Webserver\/2.%20Webserver%20com%20p%C3%A1gina%20din%C3%A2mica%2C%20usando%20AJAX\/pageAssets\/script.js\"><\/script>"
"\n        <link rel=\"stylesheet\" href=\"https:\/\/maxcdn.bootstrapcdn.com\/bootstrap\/4.0.0-alpha.6\/css\/bootstrap.min.css\" integrity=\"sha384-rwoIResjU2yc3z8GV\/NPeZWAv56rSmLldC3R\/AZzGRnGxQQKnKkoFVhFQhNUwEyJ\" crossorigin=\"anonymous\">"
"\n        <link rel=\"stylesheet\" href=\"https:\/\/cdn.jsdelivr.net\/gh\/PETEletricaUFBA\/automacao-iot-nodemcu@master\/M%C3%B3dulo%203\/Webserver\/2.%20Webserver%20com%20p%C3%A1gina%20din%C3%A2mica%2C%20usando%20AJAX\/pageAssets\/style.css\" >"
"\n        <script src=\"https:\/\/maxcdn.bootstrapcdn.com\/bootstrap\/4.0.0-alpha.6\/js\/bootstrap.min.js\" integrity=\"sha384-vBWWzlZJ8ea9aCX4pEW3rVHjgjt7zpkNpZk+02D9phzyeVkE+jo0ieGizqPLForn\" crossorigin=\"anonymous\"><\/script>"
"\n        <link href=\"https:\/\/fonts.googleapis.com\/css?family=Montserrat|Raleway\" rel=\"stylesheet\">"
"\n        <script src=\"https:\/\/kit.fontawesome.com\/a552ae84ad.js\" crossorigin=\"anonymous\"><\/script>"
"\n    <\/head>"
"\n    <body>     "
"\n      <nav class=\"navbar navbar-toggleable-md navbar-inverse bg-primary\">"
"\n        <button class=\"navbar-toggler navbar-toggler-right\" type=\"button\" data-toggle=\"collapse\" data-target=\"#navbarSupportedContent\" aria-controls=\"navbarSupportedContent\" aria-expanded=\"false\" aria-label=\"Toggle Navigation\">"
"\n          <i class=\"fa fa-bars\" aria-hidden=\"true\"><\/i>"
"\n        <\/button>"
"\n        <img class=\"logo\" src=\"https:\/\/cdn.jsdelivr.net\/gh\/PETEletricaUFBA\/automacao-iot-nodemcu@master\/assets\/automation.png\">"
"\n        <h1 class=\"navbar-brand mb-0 text-center\">Automa\u00E7\u00E3o da Sala do PET<\/h1>"
"\n        <div class=\"collapse navbar-collapse\" id=\"navbarSupportedContent\">"
"\n          <ul class=\"navbar-nav mr-auto\">"
"\n            <li class=\"nav-item active\">"
"\n              <a class=\"nav-link\" href=\"#\">Home<\/a>"
"\n                  <span class=\"sr-only\">(current)<\/span>"
"\n              <\/li>"
"\n              <li class=\"nav-item\">"
"\n                  <a class=\"nav-link\" href=\"#\">Sobre<\/a>"
"\n              <\/li>"
"\n          <\/ul>"
"\n        <\/div>"
"\n      <\/nav>"
"\n      <!-- DEFAULT AT\u00C9 AQUI -->"
"\n        <div class=\"container-fluid\"> "
"\n          <div class=\"row\">"
"\n            <div class=\"col-sm\">"
"\n              <div class=\"card center\">"
"\n                <div class=\"card-block center\">"
"\n                  <span class=\"card-title\"><i id=\"lightIcon\" class=\"fa fa-lightbulb\" aria-hidden=\"true\" style=\"color:lightgray;\"><\/i><\/span>"
"\n                  <br><b>Luzes:<\/b>"
"\n                  <div class=\"onoffswitch center\">"
"\n                    <input type=\"checkbox\" name=\"onoffswitch\" class=\"onoffswitch-checkbox\" id=\"light\" tabindex=\"0\">"
"\n                    <label class=\"onoffswitch-label\" for=\"light\">"
"\n                        <span class=\"onoffswitch-inner\"><\/span>"
"\n                        <span class=\"onoffswitch-switch\"><\/span>"
"\n                    <\/label>"
"\n                  <\/div> "
"\n                <\/div>"
"\n              <\/div>"
"\n            <\/div>"
"\n            <div class=\"col-sm\">"
"\n              <div class=\"card center\">"
"\n                <div class=\"card-block center\">"
"\n                  <span class=\"card-title\"><i id=\"outletIcon\" class=\"fa fa-plug\" aria-hidden=\"true\" style=\"color:lightgray;\"><\/i><\/span>"
"\n                  <br><b>Tomadas<\/b>"
"\n                  <br>"
"\n                  <div class=\"onoffswitch center\">"
"\n                    <input type=\"checkbox\" name=\"onoffswitch\" class=\"onoffswitch-checkbox\" id=\"outlet\" tabindex=\"0\">"
"\n                    <label class=\"onoffswitch-label\" for=\"outlet\">"
"\n                        <span class=\"onoffswitch-inner\"><\/span>"
"\n                        <span class=\"onoffswitch-switch\"><\/span>"
"\n                    <\/label>"
"\n                  <\/div>            "
"\n                <\/div>"
"\n              <\/div>"
"\n            <\/div>"
"\n            <div class=\"col-sm\">"
"\n              <div class=\"card center\">"
"\n                <div class=\"card-block\">"
"\n                  <span class=\"card-title\"><i id=\"doorIcon\" class=\"fas fa-door-open\" aria-hidden=\"true\" style=\"color:lightgray;\"><\/i><\/span>"
"\n                  <br><b>Porta<\/b>"
"\n                  <div class=\"onoffswitch center\">"
"\n                    <input type=\"checkbox\" name=\"onoffswitch\" class=\"onoffswitch-checkbox\" id=\"door\" tabindex=\"0\">"
"\n                    <label class=\"onoffswitch-label\" for=\"door\">"
"\n                        <span class=\"onoffswitch-inner\"><\/span>"
"\n                        <span class=\"onoffswitch-switch\"><\/span>"
"\n                    <\/label>"
"\n                  <\/div>            "
"\n                <\/div>"
"\n              <\/div>"
"\n            <\/div>"
"\n            <div class=\"col-sm\">"
"\n              <div class=\"card center\">"
"\n                <div class=\"card-block center\">"
"\n                  <span class=\"card-title\"><i id=\"airIcon\" class=\"fas fa-wind\" aria-hidden=\"true\" style=\"color:lightgray;\"><\/i><\/span>"
"\n                  <br><b>Ar Condicionado<\/b>"
"\n                  <br>"
"\n                  <div class=\"d-flex justify-content-center my-4 slidecontainer\">"
"\n                    <form class=\"range-field\">"
"\n                      <input id=\"slider11\" class=\"border-0 slider\" type=\"range\" min=\"16\" max=\"28\"\/>"
"\n                    <\/form>"
"\n                    <span class=\"font-weight-bold text-primary ml-2 mt-1 valueSpan\"><\/span>"
"\n                    <span class=\"font-weight-bold text-primary ml-2 mt-1\">\u00BAC<\/span>"
"\n                  <\/div>"
"\n                  <div class=\"onoffswitch center\">"
"\n                    <input type=\"checkbox\" name=\"onoffswitch\" class=\"onoffswitch-checkbox\" id=\"air\" tabindex=\"0\">"
"\n                    <label class=\"onoffswitch-label\" for=\"air\">"
"\n                        <span class=\"onoffswitch-inner\"><\/span>"
"\n                        <span class=\"onoffswitch-switch\"><\/span>"
"\n                    <\/label>"
"\n                <\/div>            "
"\n                <\/div>"
"\n              <\/div>"
"\n            <\/div>"
"\n          <\/div>"
"\n        <\/div>"
"\n        <script>"
"\n          document.getElementById(\'light\').onclick = function() {"
"\n            \/\/ access properties using this keyword"
"\n            var ledStatus;"
"\n            console.log(\"Deu BOM\");"
"\n            if ( this.checked ) {"
"\n              lightStatus = \"ON\";"
"\n              document.getElementById(\"lightIcon\").style.color = \"yellow\";"
"\n              console.log(\"ON\");"
"\n            } else {"
"\n              lightStatus = \"OFF\";"
"\n              document.getElementById(\"lightIcon\").style.color = \"lightgray\";"
"\n              console.log(\"OFF\");"
"\n            }"
"\n            var xhttp = new XMLHttpRequest();"
"\n            xhttp.onreadystatechange = function() {"
"\n              if (this.readyState == 4 && this.status == 200) {"
"\n                console.log(\"Successfully received\");"
"\n              }"
"\n            };"
"\n            xhttp.open(\"GET\", \"toggleLight?lightStatus=\"+lightStatus, true);"
"\n            xhttp.send();"
"\n          };"
"\n          document.getElementById(\'outlet\').onclick = function() {"
"\n            \/\/ access properties using this keyword"
"\n            var outletStatus;"
"\n            console.log(\"Deu BOM\");"
"\n            if ( this.checked ) {"
"\n              outletStatus = \"ON\";"
"\n              document.getElementById(\"outletIcon\").style.color = \"red\";"
"\n              console.log(\"ON\");"
"\n            } else {"
"\n              outletStatus = \"OFF\";"
"\n              document.getElementById(\"outletIcon\").style.color = \"lightgray\";"
"\n              console.log(\"OFF\");"
"\n            }"
"\n            var xhttp = new XMLHttpRequest();"
"\n            xhttp.onreadystatechange = function() {"
"\n              if (this.readyState == 4 && this.status == 200) {"
"\n                console.log(\"Successfully received\");"
"\n              }"
"\n            };"
"\n            xhttp.open(\"GET\", \"toggleOutlet?outletStatus=\"+outletStatus, true);"
"\n            xhttp.send();"
"\n          };"
"\n          document.getElementById(\'door\').onclick = function() {"
"\n            \/\/ access properties using this keyword"
"\n            var doorStatus;"
"\n            console.log(\"Deu BOM\");"
"\n            if ( this.checked ) {"
"\n              doorStatus = \"ON\";"
"\n              document.getElementById(\"doorIcon\").style.color = \"green\";"
"\n              console.log(\"ON\");"
"\n            } else {"
"\n              doorStatus = \"OFF\";"
"\n              document.getElementById(\"doorIcon\").style.color = \"lightgray\";"
"\n              console.log(\"OFF\");"
"\n            }"
"\n            var xhttp = new XMLHttpRequest();"
"\n            xhttp.onreadystatechange = function() {"
"\n              if (this.readyState == 4 && this.status == 200) {"
"\n                console.log(\"Successfully received\");"
"\n              }"
"\n            };"
"\n            xhttp.open(\"GET\", \"toggleDoor?doorStatus=\"+doorStatus, true);"
"\n            xhttp.send();"
"\n          };"
"\n          document.getElementById(\'air\').onclick = function() {"
"\n            \/\/ access properties using this keyword"
"\n            var airStatus;"
"\n            console.log(\"Deu BOM\");"
"\n            if ( this.checked ) {"
"\n              airStatus = \"ON\";"
"\n              document.getElementById(\"airIcon\").style.color = \"cornflowerblue\";"
"\n              console.log(\"ON\");"
"\n            } else {"
"\n              airStatus = \"OFF\";"
"\n              document.getElementById(\"airIcon\").style.color = \"lightgray\";"
"\n              console.log(\"OFF\");"
"\n            }"
"\n            var xhttp = new XMLHttpRequest();"
"\n            xhttp.onreadystatechange = function() {"
"\n              if (this.readyState == 4 && this.status == 200) {"
"\n                console.log(\"Successfully received\");"
"\n              }"
"\n            };"
"\n            xhttp.open(\"GET\", \"toggleAir?airStatus=\"+airStatus, true);"
"\n            xhttp.send();"
"\n          };"
"\n        <\/script>"
"\n    <\/body>"
"\n<\/html>"
"\n";
 
 
  return html;
}
