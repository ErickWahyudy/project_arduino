#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <CTBot.h>

//masukkan wifi dan password
#define WIFI_SSID "PRODUCTION"
#define WIFI_PASSWORD "asdfghjkl"

//masukkan token dan chat id bot telegram
#define BOT_TOKEN "1306451202:AAFL84nqcQjbAsEpRqVCziQ0VGty4qIAxt4"
#define TELEGRAM_CHAT_ID -1001939397003 // Ganti dengan ID chat yang valid

#define SENSOR_1_PIN D1
#define SENSOR_2_PIN D2

OneWire oneWire1(SENSOR_1_PIN);
OneWire oneWire2(SENSOR_2_PIN);
DallasTemperature sensors1(&oneWire1);
DallasTemperature sensors2(&oneWire2);

WiFiClientSecure client;
CTBot myBot;

void setup() {
  Serial.begin(9600);
  delay(10);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");

  sensors1.begin();
  sensors2.begin();

  myBot.wifiConnect(WIFI_SSID, WIFI_PASSWORD);
  myBot.setTelegramToken(BOT_TOKEN);
}

void loop() {
  sensors1.requestTemperatures();
  sensors2.requestTemperatures();

  float temperature1 = sensors1.getTempCByIndex(0);
  float temperature2 = sensors2.getTempCByIndex(0);

  Serial.print("Sensor 1 Temperature: ");
  Serial.print(temperature1);
  Serial.println(" °C");

  Serial.print("Sensor 2 Temperature: ");
  Serial.print(temperature2);
  Serial.println(" °C");

  String message;
  
  if (temperature1 < 28) {
    message = "Temperature Monitoring\n\n"
              "Sensor 1 Temperature: " + String(temperature1) + " °C\n"
              "Keterangan: Dingin";
  } else if (temperature1 > 33) {
    message = "Temperature Monitoring\n\n"
              "Sensor 1 Temperature: " + String(temperature1) + " °C\n"
              "Keterangan: Panas";
  }
  
  if (!message.isEmpty()) {
    sendTelegramMessage(message);
  }

  delay(10000);
}

void sendTelegramMessage(String message) {
  myBot.sendMessage((int64_t)TELEGRAM_CHAT_ID, message);
}
