// Programa: comunicação MQTT com ESP32
// Autor: Pedro Bertoleti
// Alguns comentários adicionados por: Maurício Taffarel (taffarel55)
// https://www.newtoncbraga.com.br/index.php/microcontroladores/143-tecnologia/17117-comunicando-se-via-mqtt-com-o-esp32-mic404.html

/* Headers */
#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h> // Documentação: https://pubsubclient.knolleary.net/api

/* Defines do MQTT */
#define TOPICO_SUBSCRIBE "taffarel55_recebe_informacao"
#define TOPICO_PUBLISH "taffarel55_envia_informacao"
#define ID_MQTT "taffarel55_Cliente_MQTT"

/* Variáveis e constantes globais */
const char *SSID = "HUAWEI-2.4G-Uppx";
const char *PASSWORD = "eBTPrJ4a";

/* Configurações do Broker */
const char *BROKER_MQTT = "broker.hivemq.com";
int BROKER_PORT = 1883;

/* Variáveis e objetos globais */
// https://pubsubclient.knolleary.net/api#PubSubClient1
WiFiClient espClient;         // client - the network client to use, for example WiFiClient
PubSubClient MQTT(espClient); // Creates a partially initialised client instance.

// Prototypes
void init_serial(void);
void init_wifi(void);
void init_mqtt(void);
void reconnect_wifi(void);
void mqtt_callback(char *topic, byte *payload, unsigned int length);
void verifica_conexoes_wifi_mqtt(void);

/*
 *  Implementações das funções
 */
void setup()
{
  init_serial();
  init_wifi();
  init_mqtt();
}

/* Função: inicializa comunicação serial com baudrate 115200 (para fins de monitorar no terminal serial
 *          o que está acontecendo.
 * Parâmetros: nenhum
 * Retorno: nenhum
 */
void init_serial()
{
  Serial.begin(115200);
}

/* Função: inicializa e conecta-se na rede WI-FI desejada
 * Parâmetros: nenhum
 * Retorno: nenhum
 */
void init_wifi(void)
{
  delay(10);
  Serial.println("------ Conexao WI-FI ------");
  Serial.print("Conectando-se na rede: ");
  Serial.println(SSID);
  Serial.println("Aguarde");
  reconnect_wifi();
}

/* Função: inicializa parâmetros de conexão MQTT(endereço do
 *         broker, porta e seta função de callback)
 * Parâmetros: nenhum
 * Retorno: nenhum
 */
void init_mqtt(void)
{
  /* informa a qual broker e porta deve ser conectado */
  // https://pubsubclient.knolleary.net/api#PubSubClient1
  MQTT.setServer(BROKER_MQTT, BROKER_PORT); // client.setServer("broker.example.com",1883);

  /* atribui função de callback (quando qualquer informação do tópico subescrito chega) */
  // https://pubsubclient.knolleary.net/api#setCallback
  MQTT.setCallback(mqtt_callback); // PubSubClient* setCallback (callback)
}

/* Função: função de callback
 *          esta função é chamada toda vez que uma informação de
 *          um dos tópicos subescritos chega)
 * Parâmetros: nenhum
 * Retorno: nenhum
 * */

// https://pubsubclient.knolleary.net/api#callback
void mqtt_callback(char *topic, byte *payload, unsigned int length)
{
  String msg;

  // obtem a string do payload recebido
  for (int i = 0; i < length; i++)
  {
    char c = (char)payload[i];
    msg += c;
  }
  Serial.print("[MQTT] Mensagem recebida: ");
  Serial.println(msg);
}

/* Função: reconecta-se ao broker MQTT (caso ainda não esteja conectado ou em caso de a conexão cair)
 *          em caso de sucesso na conexão ou reconexão, o subscribe dos tópicos é refeito.
 * Parâmetros: nenhum
 * Retorno: nenhum
 */
void reconnect_mqtt(void)
{
  while (!MQTT.connected())
  {
    Serial.print("* Tentando se conectar ao Broker MQTT: ");
    Serial.println(BROKER_MQTT);
    if (MQTT.connect(ID_MQTT))
    {
      Serial.println("Conectado com sucesso ao broker MQTT!");
      MQTT.subscribe(TOPICO_SUBSCRIBE);
    }
    else
    {
      Serial.println("Falha ao reconectar no broker.");
      Serial.println("Havera nova tentatica de conexao em 2s");
      delay(2000);
    }
  }
}

/* Função: reconecta-se ao WiFi
 * Parâmetros: nenhum
 * Retorno: nenhum
 */
void reconnect_wifi()
{
  /* se já está conectado a rede WI-FI, nada é feito.
     Caso contrário, são efetuadas tentativas de conexão */
  if (WiFi.status() == WL_CONNECTED)
    return;

  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Conectado com sucesso na rede ");
  Serial.print(SSID);
  Serial.println("IP obtido: ");
  Serial.println(WiFi.localIP());
}

/* Função: verifica o estado das conexões WiFI e ao broker MQTT.
 *         Em caso de desconexão (qualquer uma das duas), a conexão
 *         é refeita.
 * Parâmetros: nenhum
 * Retorno: nenhum
 */
void verifica_conexoes_wifi_mqtt(void)
{
  /* se não há conexão com o WiFI, a conexão é refeita */
  reconnect_wifi();
  /* se não há conexão com o Broker, a conexão é refeita */
  if (!MQTT.connected())
    reconnect_mqtt();
}

/* programa principal */
void loop()
{
  /* garante funcionamento das conexões WiFi e ao broker MQTT */
  verifica_conexoes_wifi_mqtt();

  /* Envia frase ao broker MQTT */
  // https://pubsubclient.knolleary.net/api#publish
  MQTT.publish(TOPICO_PUBLISH, "ESP32 se comunicando com MQTT");
  // boolean publish (topic, payload, [length], [retained])

  /* keep-alive da comunicação com broker MQTT */
  // https://pubsubclient.knolleary.net/api#loop
  MQTT.loop();

  /* Agurda 1 segundo para próximo envio */
  delay(1000);
}