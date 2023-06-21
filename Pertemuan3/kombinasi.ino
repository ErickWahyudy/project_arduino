//menampilkan suhu pada serial monitor dan mengatur warna LED berdasarkan suhu

#include <OneWire.h>
#include <DallasTemperature.h>

// Menginisialisasi pin data untuk sensor DS18B20
const int oneWireBusPin = D5;  // Ubah pin sesuai dengan koneksi yang digunakan

// Objek OneWire dan DallasTemperature
OneWire oneWire(oneWireBusPin);
DallasTemperature sensors(&oneWire);

// Pin LED
const int redPin = D1;     // Ubah pin sesuai dengan pin yang digunakan untuk LED merah
const int yellowPin = D2;  // Ubah pin sesuai dengan pin yang digunakan untuk LED kuning
const int greenPin = D3;   // Ubah pin sesuai dengan pin yang digunakan untuk LED hijau

void setup() {
  // Memulai komunikasi serial
  Serial.begin(9600);

  // Memulai sensor DS18B20
  sensors.begin();

  // Mengatur pin LED sebagai OUTPUT
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
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

  // Mengatur warna LED berdasarkan suhu
  if (temperatureC > 30) {
    // Suhu tinggi, LED merah menyala, LED kuning dan hijau mati
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
  } else if (temperatureC > 20) {
    // Suhu sedang, LED kuning menyala, LED merah dan hijau mati
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, LOW);
  } else {
    // Suhu rendah, LED hijau menyala, LED merah dan kuning mati
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, HIGH);
  }

  delay(1000); // Menunda pengukuran selama 1 detik
}
