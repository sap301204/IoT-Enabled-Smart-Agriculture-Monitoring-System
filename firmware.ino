# ESP32 Firmware Code
#include <WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
const char* ssid="Your_SSID";
const char* pass="Your_Pass";
const char* mqtt_server="broker.hivemq.com";
WiFiClient espClient;
PubSubClient client(espClient);
int soilPin=34, ldrPin=35, relayPin=25;
void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid,pass);
  while(WiFi.status()!=WL_CONNECTED) delay(500);
  client.setServer(mqtt_server,1883);
  dht.begin(); pinMode(relayPin,OUTPUT); digitalWrite(relayPin,HIGH);
}
void reconnect(){ while(!client.connected()){ client.connect("farmNode1"); } }
void loop(){
  if(!client.connected()) reconnect();
  float t=dht.readTemperature();
  float h=dht.readHumidity();
  int soil=analogRead(soilPin);
  int light=analogRead(ldrPin);
  char msg[200];
  snprintf(msg,sizeof(msg),"{\"temp\":%.1f,\"hum\":%.1f,\"soil\":%d,\"light\":%d}",t,h,soil,light);
  client.publish("farm/node1/data",msg);
  if(soil<1500){ digitalWrite(relayPin,LOW); client.publish("farm/node1/status","PumpON"); }
  else { digitalWrite(relayPin,HIGH); client.publish("farm/node1/status","PumpOFF"); }
  delay(5000);
}
