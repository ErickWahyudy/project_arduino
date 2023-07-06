//Sensor DHt22 Dan Firebase

#include <DHT.h>
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h> // Library Firebase ESP8266 Client

// Masukkan wifi dan password
#define WIFI_SSID "PRODUCTION"
#define WIFI_PASSWORD "asdfghjkl"

#define DHT_PIN D3

DHT dht(DHT_PIN, DHT22);
FirebaseData firebaseData;

void setup() {
  Serial.begin(9600);
  delay(10);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Hubungkan ke WiFi...");
  }

  Serial.println("Terhubung ke WiFi");

  // Masukkan URL database dan API key Firebase
  Firebase.begin("https://sensor-dht22-a067c-default-rtdb.asia-southeast1.firebasedatabase.app/", "AIzaSyDaFbMLuj1kDMFbDrrWE1ZMFNDFwmyj9PM");

  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Gagal membaca suhu dan kelembaban");
    sendDataToFirebase("Gagal membaca suhu dan kelembaban", "Gagal membaca suhu dan kelembaban");
    return;
  }

  Serial.print("Suhu: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Kelembaban: ");
  Serial.print(humidity);
  Serial.println(" %");

  String temperatureString = String(temperature, 2) + " °C";
  String humidityString =  String(humidity, 2) + " %";

  sendDataToFirebase(temperatureString, humidityString); // Kirim data ke Firebase

  delay(1000);
}

void sendDataToFirebase(String temperature, String humidity) {
  String path = "/";
  Firebase.setString(firebaseData, path + "Suhu", temperature);
  Firebase.setString(firebaseData, path + "Kelembaban", humidity);

  if (firebaseData.httpCode() != FIREBASE_ERROR_HTTP_CODE_OK) {
    Serial.println("Firebase data set failed");
    Serial.println("HTTP response code: " + String(firebaseData.httpCode()));
    Serial.println("Reason: " + firebaseData.errorReason());
  }
}
