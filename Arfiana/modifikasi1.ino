//menyalakan kipas angin dengan sensor suhu dan lampu LED
#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <CTBot.h>

#define WIFI_SSID "PRODUCTION"
#define WIFI_PASSWORD "asdfghjkl"
#define BOT_TOKEN "1306451202:AAFL84nqcQjbAsEpRqVCziQ0VGty4qIAxt4"

#define TELEGRAM_CHAT_ID 1136312864 // Ganti dengan ID chat yang valid

#define SENSOR_1_PIN D1
#define SENSOR_2_PIN D2

#define FAN_PIN D3 // Pin untuk kipas DC
#define LED_1 D5 // Pin untuk LED Merah
#define LED_2 D6 // Pin untuk LED Hijau

OneWire oneWire1(SENSOR_1_PIN);
OneWire oneWire2(SENSOR_2_PIN);
DallasTemperature sensors1(&oneWire1);
DallasTemperature sensors2(&oneWire2);

WiFiClientSecure client;
CTBot myBot;

bool fanState = false; // Variable untuk menyimpan status kipas
bool ledState = false; // Variable untuk menyimpan status LED

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

  pinMode(FAN_PIN, OUTPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
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
    fanState = false; // Matikan kipas DC
    ledState = false; // Matikan LED
  } else if (temperature1 > 33) {
    message = "Temperature Monitoring\n\n"
              "Sensor 1 Temperature: " + String(temperature1) + " °C\n"
              "Keterangan: Panas";
    fanState = true; // Nyalakan kipas DC
    ledState = true; // Nyalakan LED
  }
  
  if (!message.isEmpty()) {
    sendTelegramMessage(message);
  }

  controlFan(); // Panggil fungsi untuk mengontrol kipas
  controlLED(); // Panggil fungsi untuk mengontrol LED

  delay(10000);
}

void sendTelegramMessage(String message) {
  myBot.sendMessage((int64_t)TELEGRAM_CHAT_ID, message);
}

void controlFan() {
  if (fanState) {
    digitalWrite(FAN_PIN, HIGH); // Nyalakan kipas DC
  } else {
    digitalWrite(FAN_PIN, LOW); // Matikan kipas DC
  }
}

void controlLED() {
  if (ledState) {
    digitalWrite(LED_1, HIGH); // Nyalakan MERAH
    digitalWrite(LED_2, LOW); // Nyalakan HIJAU
  } else {
    digitalWrite(LED_1, LOW); // Matikan Merah
    digitalWrite(LED_2, HIGH); // Matikan Hijau
  }
}
