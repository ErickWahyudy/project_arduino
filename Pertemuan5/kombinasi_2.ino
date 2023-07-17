//Sensor DHt22, Firebase Dan Relay

#include <DHT.h>
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

#define WIFI_SSID "PRODUCTION"
#define WIFI_PASSWORD "asdfghjkl"

#define DHT_PIN D3
#define RELAY_PIN D4

DHT dht(DHT_PIN, DHT22);
FirebaseData firebaseData;

void setup() {
  Serial.begin(9600);
  delay(10);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Relay dimatikan saat awal

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Hubungkan ke WiFi...");
  }

  Serial.println("Terhubung ke WiFi");

  Firebase.begin("https://sensor-dht22-a067c-default-rtdb.asia-southeast1.firebasedatabase.app/",
                 "AIzaSyDaFbMLuj1kDMFbDrrWE1ZMFNDFwmyj9PM");

  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Gagal membaca suhu dan kelembaban");
    sendDataToFirebase(-999, -999, false); // Nilai -999 menunjukkan bahwa data tidak valid
    return;
  }

  Serial.print("Suhu: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Kelembaban: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Kondisi untuk menghidupkan atau mematikan relay berdasarkan suhu
  bool relayStatus = false;
  if (temperature >= 30.0) {
    digitalWrite(RELAY_PIN, HIGH); // Menghidupkan relay jika suhu lebih besar atau sama dengan 30°C
    relayStatus = true;
  } else {
    digitalWrite(RELAY_PIN, LOW); // Mematikan relay jika suhu kurang dari 30°C
    relayStatus = false;
  }

  sendDataToFirebase(temperature, humidity, relayStatus);

  delay(2000); // Beri jeda 2 detik sebelum membaca suhu lagi
}

void sendDataToFirebase(float temperature, float humidity, bool relayStatus) {
  String path = "/";
  Firebase.setFloat(firebaseData, path + "Suhu", temperature);
  Firebase.setFloat(firebaseData, path + "Kelembaban", humidity);
  Firebase.setBool(firebaseData, path + "RelayStatus", relayStatus);

  if (firebaseData.httpCode() != FIREBASE_ERROR_HTTP_CODE_OK) {
    Serial.println("Firebase data set failed");
    Serial.println("HTTP response code: " + String(firebaseData.httpCode()));
    Serial.println("Reason: " + firebaseData.errorReason());
  }
}
