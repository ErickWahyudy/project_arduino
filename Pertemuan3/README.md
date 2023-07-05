# JOBSHEET 3
## SENSOR DS1820B MENGUKUR SUHU TEMPERATUR

### A. TUJUAN
1. Menguji piranti hardware sensor DS1820B
2. Mengukur sinyal Data Temperatur suhu

### B. DASAR TEORI

Sensor suhu DS18B20 adalah sensor yang dapat membaca perubahan temperatur linkungan lalu
mengkonversikan temperatur tersebut menjadi sebuah tengangan listrik. Sensor ini memiliki
keluaran digital. Sensor DS18B20 ini memiliki tingkat akurasi yang cukup tinggi yaitu 0,5 yang
mampu membaca suhu dengan rentang antara -55 sampai 125 ℃. [7] Sensor DS18B20 memilki 3
pin yang terdiri dari Vs, Ground dan Data Input/Output. Kaki Vs merupakan kaki tegangan
sumber. Tegangan sumber untuk sensor suhu DS18B20 adalah 3V sampai 5.5V

### C. ALAT DAN BAHAN

1. Modul trainer NodeMcu ESP 8266
2. Kabel Jumper, LED
3. Catu daya 5V
4. Arduino IDE framework
5. Sensor DS1820B

### D. LANGKAH PERCOBAAN
1. Rangkai nodeMCU ESP8266 dengan sensor DS1820B.
#### Langkah merangkai sensor DS1820B pada NodeMCU ESP8266
1. Siapkan sensor DS1820B, NodeMCU ESP8266, dan kabel jumper
2. Hubungkan kaki GND sensor DS1820B dengan kaki GND NodeMCU ESP8266 menggunakan kabel jumper
3. Hubungkan kaki VCC sensor DS1820B dengan kaki 3V NodeMCU ESP8266 menggunakan kabel jumper
4. Hubungkan kaki DQ sensor DS1820B dengan kaki D4 NodeMCU ESP8266 menggunakan kabel jumper


2. Lakukan instalasi sensor DS1820B pada Arduino IDE
#### Langkah instalasi sensor DS1820B pada Arduino IDE
1. Buka Arduino IDE
2. Install library OneWire dan DallasTemperature
3. Masukkan kode program berikut pada Arduino IDE
```void loop() {
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
```
4. Upload kode program tersebut ke NodeMCU ESP8266
5. Buka Serial Monitor
6. Amati hasil keluaran pada Serial Monitor

### E. HASIL PERCOBAAN

Lakukan simulasi dengan mencelupkan sensor pada cairan yang berbeda, lakukan pengamatan dan analisis perubahan suhunya.

| Jenis Cairan          | Perubahan Suhu        |
|-----------------------|-----------------------|
| Air Suhu Ruang        | 25.06°                |
| Air Dingin            | 22.69°                |
| Tehu Pucuk            | 25.56°                |
| Kopi Susu             | 28.13°                |

Hasil Analisis ?
1. Perubahan suhu yang terjadi karena adanya perbedaan suhu pada cairan yang berbeda
2. Jika suhu cairan semakin tinggi maka nilai suhu yang terbaca semakin tinggi
3. sehingga sensor DS1820B dapat digunakan untuk mengukur suhu pada cairan

### F. EVALUASI

Silahkan menghubungi instruktur untuk tugas pertemuan berikutnya.
