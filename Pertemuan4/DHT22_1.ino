//sensor DHT22, ESP8266, Firebase, dan Telegram

#include <DHT.h>
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h> // Library Firebase ESP8266 Client
#include <CTBot.h>

// Masukkan wifi dan password
#define WIFI_SSID "PRODUCTION"
#define WIFI_PASSWORD "asdfghjkl"

// Masukkan token dan chat id bot telegram
#define BOT_TOKEN "1306451202:AAFL84nqcQjbAsEpRqVCziQ0VGty4qIAxt4"
#define TELEGRAM_CHAT_ID 1136312864 // Ganti dengan ID chat yang valid

#define DHT_PIN D3

DHT dht(DHT_PIN, DHT22);
WiFiClientSecure client;
FirebaseData firebaseData;
CTBot myBot;

void setup() {
  Serial.begin(9600);
  delay(10);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Hubungkan ke WiFi...");
  }

  Serial.println("Terhubung ke WiFi");

  Firebase.begin("https://sensor-dht22-a067c-default-rtdb.asia-southeast1.firebasedatabase.app/", "AIzaSyDaFbMLuj1kDMFbDrrWE1ZMFNDFwmyj9PM");

  dht.begin();

  myBot.wifiConnect(WIFI_SSID, WIFI_PASSWORD);
  myBot.setTelegramToken(BOT_TOKEN);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Gagal membaca suhu dan kelembaban");
    return;
  }

  Serial.print("Suhu: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Kelembaban: ");
  Serial.print(humidity);
  Serial.println(" %");

  String message = "Suhu and Kelembaban\n\n";
  message += "Suhu: " + String(temperature) + " °C\n";
  message += "Kelembaban: " + String(humidity) + " %";

  sendTelegramMessage(message); // Kirim pesan ke Telegram
  sendDataToFirebase(temperature, humidity); // Kirim data ke Firebase

  delay(10000);
}

void sendTelegramMessage(String message) {
  myBot.sendMessage(TELEGRAM_CHAT_ID, message);
}

void sendDataToFirebase(float temperature, float humidity) {
  String path = "/";
  Firebase.setFloat(firebaseData, path + "Suhu", temperature);
  Firebase.setFloat(firebaseData, path + "kelembaban", humidity);

  if (firebaseData.httpCode() != FIREBASE_ERROR_HTTP_CODE_OK) {
    Serial.println("Firebase data set failed");
    Serial.println("HTTP response code: " + String(firebaseData.httpCode()));
    Serial.println("Reason: " + firebaseData.errorReason());
  }
}
