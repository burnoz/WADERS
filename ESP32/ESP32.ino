#include <ArduinoJson.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "time.h"

const int sensor = 34;       
float valor = 0;
float valor1 = 0;
float R1 = 10000;                                            
float logR2, R2, TK, TC;                           
float A = 0.001129148, B= 0.000234125, C = 0.0000000876741;

unsigned long epochTime;
unsigned long dataMillis = 0;

const char* ntpServer = "pool.ntp.org";
const char* serverName = "https://us-east-2.aws.data.mongodb-api.com/app/data-vxqzj/endpoint/waders/h2o/h2o_chiquitin";



const char* ssid = " ";
const char* password = " ";

StaticJsonDocument<500> doc;

void setup(){
  Serial.begin(115200);

  WiFi.begin(ssid,password);
    Serial.println("Conectando...");

  while (WiFi.status() != WL_CONNECTED){
        Serial.print(".");
        delay(300);
  }
    Serial.println();
    Serial.print("Conectado. IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();

    configTime(0, 0, ntpServer);
}

void loop(){
  if (millis() - dataMillis > 15000 || dataMillis == 0)
  {
      dataMillis = millis();

      epochTime = getTime();
      Serial.print("Epoch Time: ");
      Serial.println(epochTime);

      valor = analogRead(sensor);
      valor1 = map(valor, 0, 4095, -55, 125); 
      R2 = R1 * (1023.0 / (float)valor1 - 1.0);                  
      logR2 = log(R2);                                             
      TK = (1.0 / (A + B * logR2 + C * logR2 * logR2 * logR2)); 
      TC = TK - 273.15;    

      Serial.print("Temperatura: ");
      Serial.print(String(TC));
      Serial.println("\n");
      
      doc["sensors"]["temperature"] = String(TC);
      doc["sensors"]["timestamp"] = String(epochTime);

      Serial.println("Uploading data... ");
      POSTData();
  }
}

unsigned long getTime(){
  time_t now;
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)){
    return(0);
  }
  time(&now);
  return now;
}

void POSTData(){
    if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;

      http.begin(serverName);
      http.addHeader("Content-Type","application/json");

      String json;
      serializeJson(doc["sensors"], json);

      Serial.println(json);
      int httpResponseCode = http.POST(json);
      Serial.println(httpResponseCode);

      if (httpResponseCode == 204){
        Serial.println("Data uploaded.");
      } else {
        Serial.println("ERROR: Couldn't upload data.");
      }


      //if (httpResponseCode > 0):
      //Serial.println(httpResponseCode);

    }
}