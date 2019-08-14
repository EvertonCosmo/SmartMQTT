#include <ESP8266WiFi.h>
#include <PubSubClient.h> // which allows us to connect to a MQTT broker and publish/subscribe messages in topics.

// Network credentials
const char* SSID = "brisa-466158";
const char* PASSWORD =  "jldbrwwy";
#define TOPIC_PUBLISHER "Sensors"

WiFiClient espClient; // Cria o objeto espClient
PubSubClient MQTT(espClient);// Instancia o Cliente MQTT passando o objeto espClient

const char*  BROKER_MQTT  ="";
int BROKER_PORT = ; 

void callback(char* topic, byte* payload, unsigned int length);

void setup () { 
    Serial.begin(112500);
    Wifi.begin(SSID,PASSWORD);
   
}

void initWifi(){ 
   Serial.println("------Conexao WI-FI------");
    Serial.print("Conectando-se na rede: ");
    Serial.println(SSID);
    Serial.println("Aguarde");
    while(!MQTT.connected()){
        Serial.print("* Tentando se conectar ao Broker MQTT: ");
        Serial.println(BROKER_MQTT);
    }
}

void loop(){
    client.loop();
}

void callback(char* topic, byte* payload, unsigned int length){

    Serial.print("Message arrived in topic");
    Serial.println(topic);

    Serial.print("Message:");
    for(int i = 0; i < length; i++){
        Serial.print((char)payload[i]);
    }

    Serial.println();
    Serial.println("-------------------");
}