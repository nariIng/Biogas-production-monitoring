#include <WiFi.h>
#include <EEPROM.h>
#include <HX711_ADC.h>

#define HX711_DATA_PIN  22
#define HX711_CLOCK_PIN 23
#define pump 25

HX711_ADC LoadCell(HX711_DATA_PIN, HX711_CLOCK_PIN);
WiFiServer server(80);

const char *ssid = "esp_gpci";
const char *password = "gpci2025";

char buffer[10];
float calfactor;
float poids;

float act_poids = 0;

void setup() {
  // put your setup code here, to run once:
  WiFi.softAP(ssid, password);
  
  Serial.begin(57600);
  server.begin();

  Serial.println("ESP32 Access Point started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  pinMode(pump, OUTPUT);
  digitalWrite(pump, HIGH);
  start_loadCell();
  delay(2000);  
}

void loop() {
  // put your main code here, to run repeatedly:
    WiFiClient client = server.available();
    poids = estab_pound() + act_poids;
//    poids = estab_pound() + (act_poids * 1000);
//    poids = poids/1000;
    Serial.println(poids);
    if (client) {
      String request = client.readStringUntil('\r');
      client.flush();

      if (request.indexOf("GET /poids") != -1) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/plain");
          dtostrf(poids, 6, 1, buffer);
          String pound = String(buffer);
          client.println();
          client.println(pound); // Retourner la valeur de vol_2
          
      }

      if (request.indexOf("GET /start") != -1) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/plain");
          client.println();
          client.println("Message affiché");
          act_poids = 0;
          tare_1();
      }
      if (estab_pound() > 500){
        act_poids = poids;
        while (estab_pound() > 5){
          digitalWrite(pump, LOW);
        }
        tare_1();
        digitalWrite(pump, HIGH);
      }
      if (request.indexOf("GET /start_test") != -1) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/plain");
          client.println();
          client.println("Message affiché");
          digitalWrite(pump, LOW);
          delay(10000);
          digitalWrite(pump, HIGH);
      }
    }
}

void start_loadCell() {
  LoadCell.begin();
  LoadCell.start(2000);

  EEPROM.get(0, calfactor);
  Serial.println(calfactor);
  LoadCell.setCalFactor(2065.21);
  delay(1000);
  tare_1();
}

float estab_pound(){
  float buffer_arr[30];
  float avgval = 0;

    for (int i = 0; i < 30; i++) {
      LoadCell.update();
      buffer_arr[i] = LoadCell.getData();
    }
  // Tri à bulles
  for (int i = 0; i < 29; i++) {
    for (int j = 0; j < 29 - i; j++) {
      if (buffer_arr[j] > buffer_arr[j + 1]) {
        float temp = buffer_arr[j];
        buffer_arr[j] = buffer_arr[j + 1];
        buffer_arr[j + 1] = temp;
      }
    }
  }

  // Calcul de la moyenne des valeurs médianes
  for (int i = 0; i < 30; i++) {
    avgval += buffer_arr[i];
  }
  float pd = avgval/30;
  if (pd < 0){
    pd = 0;
  }
  return (pd);
}

void tare_1(){
  LoadCell.tare(); // Définir la tare pour LoadCell1
  Serial.println("Tare1 completed");
}
