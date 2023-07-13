//Sensor DHt22, Firebase Dan Ultrasonic

#include <DHT.h>
#include <HCSR04.h>
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

#define WIFI_SSID "PRODUCTION"
#define WIFI_PASSWORD "asdfghjkl"

#define DHT_PIN D3
#define TRIGGER_PIN D5
#define ECHO_PIN D6

DHT dht(DHT_PIN, DHT22);
FirebaseData firebaseData;
HCSR04 ultrasonic(TRIGGER_PIN, ECHO_PIN);

void setup() {
  Serial.begin(9600);
  delay(10);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Hubungkan ke jaringan WiFi...");
  }

  Serial.println("Terhubung ke jaringan WiFi");

  Firebase.begin("https://sensor-dht22-a067c-default-rtdb.asia-southeast1.firebasedatabase.app/", "YOUR_FIREBASE_API_KEY");

  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  float distance = ultrasonic.distanceInCentimeters();

  if (isnan(temperature) || isnan(humidity) || distance == 0) {
    Serial.println("Failed to read temperature, humidity, or distance");
    sendDataToFirebase("Failed to read temperature, humidity, or distance", "Failed to read temperature, humidity, or distance", "Failed to read temperature, humidity, or distance");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  String temperatureString = String(temperature, 2) + " °C";
  String humidityString = String(humidity, 2) + " %";
  String distanceString = String(distance, 2) + " cm";

  sendDataToFirebase(temperatureString, humidityString, distanceString);

  delay(10000);
}

void sendDataToFirebase(String temperature, String humidity, String distance) {
  String path = "/";
  Firebase.setString(firebaseData, path + "Temperature", temperature);
  Firebase.setString(firebaseData, path + "Humidity", humidity);
  Firebase.setString(firebaseData, path + "Distance", distance);

  if (firebaseData.httpCode() != FIREBASE_ERROR_HTTP_CODE_OK) {
    Serial.println("Firebase data set failed");
    Serial.println("HTTP response code: " + String(firebaseData.httpCode()));
    Serial.println("Reason: " + firebaseData.errorReason());
  }
}
