#include <ESP8266WiFi.h>
#include <PubSubClient.h> // which allows us to connect to a MQTT broker and publish/subscribe messages in topics.

// Network credentials
const char* SSID = "brisa-466158";
const char* PASSWORD =  "******";
#define TOPIC_PUBLISHER_ULTRASSONIC "Ultrassonic"
#define TOPIC_PUBLISHER_TEMPERATURE "Temperature"
#define ID_MQTT
WiFiClient espClient; // Create object 
PubSubClient MQTT(espClient);// Instance MQQTT 

// MQTT server 
const char*  BROKER_MQTT  ="";
int BROKER_PORT = ; 


// Sensor Ultrassonic
#define trigPin 12
#define echoPin 13
// float cmMSec = 0; // Data sensor CM 
// float temperature = 0;

Ultrasonic ultrasonic(trigPin,echoPin);


// Prototypes 

void sendDataSensors();
void initWifi();
void initMqtt();
void SendDataSensor();
void initSerial();

void setup () { 
   
    initSerial();
    initWifi();
    initMqtt();
  
  
}


void loop(){
    SendDataSensor();
    MQQTT.loop();
      

}


/*
*
*   SENSORS READING DATA
*
*/

void sendDataSensors () { 
  // Sending data from Ultrassonic Sensor
  float inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);


  // Show informations 
  Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  char  tempcmMsec [8];
  dtostrf(cmMSec,1,2,tempcmMsec);

  MQTT.publish(TOPIC_PUBLISHER_ULTRASSONIC,tempcmMsec);
  Serial.println("Dados enviados ao broker!");
  delay(1000);  

}



void initSerial() 
{
    Serial.begin(115200);
}
void initWifi(){ 
    Serial.println("------Conexao WI-FI------");
    Serial.print("Conectando-se na rede: ");
    Serial.println(SSID);
    Serial.println("Aguarde");
    if(Wifi.status() == WL_CONNECT) { 
        return ;
    }else { 
        Wifi.begin(SSID,PASSWORD) // CONNECT WIFI NETWORK
    }
    while( Wifi.status() != WL_CONNECT){ 
        delay(100);
        Serial.println(".");
    }
    Serial.print("Conectado com sucesso a rede "); 
    Serial.println(SSID);

}

void initMqtt(){ 
  MQQTT.setServer(BROKER_MQTT,BROKER_PORT); // Initialize Broker 
}





