#include <OneWire.h>
#include <DallasTemperature.h>

// Menginisialisasi pin data untuk sensor DS18B20
const int oneWireBusPin = D5;  // Ubah pin sesuai dengan koneksi yang digunakan

// Objek OneWire dan DallasTemperature
OneWire oneWire(oneWireBusPin);
DallasTemperature sensors(&oneWire);

void setup() {
  // Memulai komunikasi serial
  Serial.begin(9600);

  // Memulai sensor DS18B20
  sensors.begin();
}

void loop() {
  // Mendapatkan suhu dalam derajat Celsius
  sensors.requestTemperatures();
  float temperatureC = sensors.getTempCByIndex(0);

  // Mendapatkan suhu dalam derajat Fahrenheit
  float temperatureF = sensors.toFahrenheit(temperatureC);

  // Menampilkan hasil suhu pada Serial Monitor
  Serial.print("Suhu (C): ");
  Serial.print(temperatureC);
  Serial.print(" | Suhu (F): ");
  Serial.println(temperatureF);

  delay(1000); // Menunda pengukuran selama 1 detik
}
