#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "index.h"
 
 
/********** PLEASE CHANGE THIS *************************/
const char* ssid = "HUAWEI-2.4G-Uppx";
const char* password = "eBTPrJ4a";
 
ESP8266WebServer server(80);
 
uint8_t lightPin = D0;
bool lightStatus = LOW;
 
uint8_t buzzerPin = D1;
bool buzzerStatus = LOW;
 
void setup() {
  Serial.begin(115200);
  pinMode(lightPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
 
  Serial.println("Connecting to ");
  Serial.println(ssid);
 
  //connect to your local wi-fi network
  WiFi.begin(ssid, password);
 
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
  server.on("/toggleBuzzer", updateBuzzerSound);
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
 
void updateBuzzerSound() {
  String buzzerStatusParam = server.arg("buzzerStatus");
  if (buzzerStatusParam == "ON")
    buzzerStatus =  HIGH;
  else
    buzzerStatus =  LOW;
 
  if (buzzerStatus)
    tone(buzzerPin, 1200);
  else
    noTone(buzzerPin);
 
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
"\n        <style>"
"\n          .onoffswitch {"
"\n            position: relative; width: 110px;"
"\n            -webkit-user-select:none; -moz-user-select:none; -ms-user-select: none;"
"\n          }"
"\n          .onoffswitch-checkbox {"
"\n              position: absolute;"
"\n              opacity: 0;"
"\n              pointer-events: none;"
"\n          }"
"\n          .onoffswitch-label {"
"\n              display: block; overflow: hidden; cursor: pointer;"
"\n              border: 2px solid #798A99; border-radius: 20px;"
"\n          }"
"\n          .onoffswitch-inner {"
"\n              display: block; width: 200%; margin-left: -100%;"
"\n              transition: margin 0.3s ease-in 0s;"
"\n          }"
"\n          .onoffswitch-inner:before, .onoffswitch-inner:after {"
"\n              display: block; float: left; width: 50%; height: 23px; padding: 0; line-height: 23px;"
"\n              font-size: 14px; color: white; font-family: Trebuchet, Arial, sans-serif; font-weight: bold;"
"\n              box-sizing: border-box;"
"\n          }"
"\n          .onoffswitch-inner:before {"
"\n              content: \"Ligado\";"
"\n              padding-left: 10px;"
"\n              background-color: #0275D8; color: #FFFFFF;"
"\n          }"
"\n          .onoffswitch-inner:after {"
"\n              content: \"Desligado\";"
"\n              padding-right: 10px;"
"\n              background-color: #EEEEEE; color: #999999;"
"\n              text-align: right;"
"\n          }"
"\n          .onoffswitch-switch {"
"\n              display: block; width:17px; margin: 5px;"
"\n              background: #F7F7F7;"
"\n              position: absolute; top: 0; bottom: 0;"
"\n              border: 2px solid #798A99; border-radius: 20px;"
"\n              transition: all 0.3s ease-in 0s; "
"\n          }"
"\n          .onoffswitch-checkbox:checked + .onoffswitch-label .onoffswitch-inner {"
"\n              margin-left: 0;"
"\n          }"
"\n          .onoffswitch-checkbox:checked + .onoffswitch-label .onoffswitch-switch {"
"\n              right: 0px; "
"\n          }"
"\n        <\/style>"
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
"\n                  <!--<span class=\"card-title\"><i class=\"fa fa-lightbulb\" aria-hidden=\"true\" style=\"color:#dddddd;\"><\/i><\/span>-->"
"\n                  <span class=\"card-title\"><i class=\"fa fa-lightbulb\" aria-hidden=\"true\" style=\"color:rgb(255, 238, 0);\"><\/i><\/span>"
"\n                  <br><b>Luzes:<\/b>"
"\n                  <div class=\"onoffswitch center\">"
"\n                    <input type=\"checkbox\" name=\"onoffswitch\" class=\"onoffswitch-checkbox\" id=\"light\" tabindex=\"0\" checked>"
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
"\n                  <!--<span class=\"card-title\"><i class=\"fa fa-plug\" aria-hidden=\"true\" style=\"color:#dddddd;\"><\/i><\/span>-->"
"\n                  <span class=\"card-title\"><i class=\"fa fa-plug\" aria-hidden=\"true\" style=\"color:rgb(206, 3, 3)\"><\/i><\/span>"
"\n                  <br><b>Tomadas<\/b>"
"\n                  <br>"
"\n                  <div class=\"onoffswitch center\">"
"\n                    <input type=\"checkbox\" name=\"onoffswitch\" class=\"onoffswitch-checkbox\" id=\"outlet\" tabindex=\"0\" checked>"
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
"\n                  <!--<span class=\"card-title\"><i class=\"fas fa-door-closed\" aria-hidden=\"true\" style=\"color:#dddddd;\"><\/i><\/span>-->"
"\n                  <span class=\"card-title\"><i class=\"fas fa-door-open\" aria-hidden=\"true\" style=\"color:#59c031\"><\/i><\/span>"
"\n                  <br><b>Porta<\/b>"
"\n                  <div class=\"onoffswitch center\">"
"\n                    <input type=\"checkbox\" name=\"onoffswitch\" class=\"onoffswitch-checkbox\" id=\"door\" tabindex=\"0\" checked>"
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
"\n                  <!--<span class=\"card-title\"><i class=\"fas fa-wind\" aria-hidden=\"true\" style=\"color:#dddddd;\"><\/i><\/span>-->"
"\n                  <span class=\"card-title\"><i class=\"fas fa-wind\" aria-hidden=\"true\" style=\"color:rgb(99, 163, 247);\"><\/i><\/span>"
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
"\n                    <input type=\"checkbox\" name=\"onoffswitch\" class=\"onoffswitch-checkbox\" id=\"air\" tabindex=\"0\" checked>"
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
"\n              console.log(\"ON\");"
"\n            } else {"
"\n              lightStatus = \"OFF\";"
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
"\n          document.getElementById(\'buzzerSwitch\').onclick = function() {"
"\n            \/\/ access properties using this keyword"
"\n            var buzzerStatus;"
"\n            if ( this.checked ) {"
"\n              buzzerStatus = ON;"
"\n            } else {"
"\n              buzzerStatus = OFF;"
"\n            }"
"\n            var xhttp = new XMLHttpRequest();"
"\n            xhttp.onreadystatechange = function() {"
"\n              if (this.readyState == 4 && this.status == 200) {"
"\n                "
"\n              }"
"\n            };"
"\n            xhttp.open(GET, \"toggleBuzzer?buzzerStatus\"+buzzerStatus, true);"
"\n            xhttp.send();"
"\n          };"
"\n        <\/script>"
"\n    <\/body>"
"\n<\/html>"
"\n";
 
 
  return html;
}
