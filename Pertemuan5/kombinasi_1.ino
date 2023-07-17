//Sensor DHt22, Firebase Dan Ultrasonic

#include <DHT.h>
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

#define WIFI_SSID "PRODUCTION"
#define WIFI_PASSWORD "asdfghjkl"

#define DHT_PIN D3

#define TRIGGER_PIN D5
#define ECHO_PIN D6

DHT dht(DHT_PIN, DHT22);
FirebaseData firebaseData;

void setup() {
  Serial.begin(9600);
  delay(10);

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

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
  float distance = getUltrasonicDistance();

  if (isnan(temperature) || isnan(humidity) || distance == -1) {
    Serial.println("Gagal membaca suhu, kelembaban, atau jarak");
    sendDataToFirebase("Gagal membaca data", "Gagal membaca data", "Gagal membaca data");
    return;
  }

  Serial.print("Suhu: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Kelembaban: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  String temperatureString = String(temperature, 2) + " °C";
  String humidityString =  String(humidity, 2) + " %";
  String distanceString = String(distance, 2) + " cm";

  sendDataToFirebase(temperatureString, humidityString, distanceString);

  delay(1000);
}

void sendDataToFirebase(String temperature, String humidity, String distance) {
  String path = "/";
  Firebase.setString(firebaseData, path + "Suhu", temperature);
  Firebase.setString(firebaseData, path + "Kelembaban", humidity);
  Firebase.setString(firebaseData, path + "Jarak", distance);

  if (firebaseData.httpCode() != FIREBASE_ERROR_HTTP_CODE_OK) {
    Serial.println("Firebase data set failed");
    Serial.println("HTTP response code: " + String(firebaseData.httpCode()));
    Serial.println("Reason: " + firebaseData.errorReason());
  }
}

float getUltrasonicDistance() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  unsigned long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2; // Dalam cm

  // Cek apakah nilai jarak valid (tidak melebihi batas maksimum atau mendekati nol)
  if (distance >= 400 || distance <= 0) {
    return -1; // Nilai jarak tidak valid
  }

  return distance;
}
