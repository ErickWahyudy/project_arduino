#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h> // Library Firebase ESP8266 Client
#include <CTBot.h>

//masukkan wifi dan password
#define WIFI_SSID "PRODUCTION"
#define WIFI_PASSWORD "asdfghjkl"

//masukkan token dan chat id bot telegram
#define BOT_TOKEN "1306451202:AAFL84nqcQjbAsEpRqVCziQ0VGty4qIAxt4"
#define TELEGRAM_CHAT_ID -1001939397003 // Ganti dengan ID chat yang valid

#define SENSOR_1_PIN D3
#define SENSOR_2_PIN D4

#define Relay_1 D5 // Pin untuk relay
#define Relay_2 D6 // Pin untuk relay

OneWire oneWire1(SENSOR_1_PIN);
OneWire oneWire2(SENSOR_2_PIN);
DallasTemperature sensors1(&oneWire1);
DallasTemperature sensors2(&oneWire2);

WiFiClientSecure client;
FirebaseData firebaseData;
CTBot myBot;

bool fanState = false; // Variable untuk menyimpan status kipas
bool heaterState = false; // Variable untuk menyimpan status pemanas

void setup() {
  Serial.begin(9600);
  delay(10);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Hubungkan ke WiFi...");
  }

  Serial.println("Terhubung ke WiFi");

  Firebase.begin("https://kontrol-suhu-aquarium-default-rtdb.asia-southeast1.firebasedatabase.app/", "AIzaSyBfio_vnzNn8R0gBkhZJo3FoqGQJrVBiCs");

  sensors1.begin();
  sensors2.begin();

  myBot.wifiConnect(WIFI_SSID, WIFI_PASSWORD);
  myBot.setTelegramToken(BOT_TOKEN);

  pinMode(Relay_1, OUTPUT);
  pinMode(Relay_2, OUTPUT);
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
              "Sensor 2 Temperature: " + String(temperature2) + " °C\n"
              "Keterangan: Dingin";
    heaterState = true; // Nyalakan pemanas
  } else if (temperature1 > 28 && temperature1 < 33) {
    fanState    = false; // Matikan kipas angin
    heaterState = false; // Matikan pemanas
  } else if (temperature1 > 33) {
    message = "Temperature Monitoring\n\n"
              "Sensor 1 Temperature: " + String(temperature1) + " °C\n"
              "Sensor 2 Temperature: " + String(temperature2) + " °C\n"
              "Keterangan: Panas";
    fanState = true; // Nyalakan kipas angin
  }

  if (!message.isEmpty()) {
    sendTelegramMessage(message); // Kirim pesan ke Telegram
  }

  controlFan(); // Panggil fungsi untuk mengontrol kipas angin
  controlHeater(); // Panggil fungsi untuk mengontrol pemanas

  // Kirim data ke Firebase
  String path = "/";
  Firebase.setString(firebaseData, path + "temperature1", String(temperature1));
  Firebase.setString(firebaseData, path + "temperature2", String(temperature2));
  Firebase.setString(firebaseData, path + "fanState", String(fanState));
  Firebase.setString(firebaseData, path + "heaterState", String(heaterState));

if (firebaseData.httpCode() != FIREBASE_ERROR_HTTP_CODE_OK) {
    Serial.println("Firebase data set failed");
    Serial.println("HTTP response code: " + String(firebaseData.httpCode()));
    Serial.println("Reason: " + firebaseData.errorReason());
  }

  delay(10000);
}

void sendTelegramMessage(String message) {
  myBot.sendMessage(TELEGRAM_CHAT_ID, message);
}

void controlFan() {
  if (fanState) {
    digitalWrite(Relay_1, LOW); // Matikan relay (mematikan relay kipas angin)
  } else {
    digitalWrite(Relay_1, HIGH); // Nyalakan relay (nyalakan relay kipas angin)
  }
}

void controlHeater() {
  if (heaterState) {
    digitalWrite(Relay_2, LOW); // Matikan relay (mematikan relay pemanas)
  } else {
    digitalWrite(Relay_2, HIGH); // Nyalakan relay (nyalakan relay pemanas)
  }
}
