# JOBSHEET 2
## SENSOR ULTRASONIC MENGUKUR PANTULAN

### A. TUJUAN

1. Menguji piranti hardware sensor ultrasonik
2. Mengukur sinyal keluaran sensor ultrasonic

### B. DASAR TEORI

##### Prinsip 1: Massa

Prinsip massa ini apabila gelombang menumbuk suatu permukaan, maka dia
akan menggetarkan permukaan ini. Semakin ringan permukaan, tentu saja semakin
mudah digetarkan oleh gelombang dan sebaliknya,

##### Prinsip 2: Dekopling Mekanik

Pada prinsipnya dekopling mekanik dilakukan untuk menghalangi gelombang
merambat dalam dinding,atau menghalangi getaran merambat dari permukaan dinding
ke permukaan yang lain. Energi suara/getaran akan “hilang” oleh material lain atau
udara yang ada diantara 2 permukaan. Yang seringkali dilupakan, dekopling mekanik
ini merupakan fungsi dari frekuensi suara,karena padasaat kita membuat dekopling,
kita menciptakan system resonansi

##### Prinsip 3: Absorpsi atau penyerapan energi suara

Penggunaan bahan penyerap suara dengan cara disisipkan dalam system
dinding insulasi akan meningkatkan kinerja insulasi, karena energy suara yang
merambat melewati bahan penyerap akan diubah menjadi energi panas (utk
menggetarkan partikel udara yang terperangkap dalam pori bahan penyerap. Bahan
penyerap ini juga akan menurunkan frekuensi resonansi system partisi/dinding
yang di dekopling.

##### Prinsip 4: Resonansi

Prinsip ini bekerja bertentangan dengan prinsip 1, 2, dan 3, karena resonansi
bersifat memudahkan terjadinya getaran. Bila getaran terjadi pada frekuensi yang sama
dengan frekuensi resonansi system dinding anda, maka energi suara akan dengan mudah
menembus dinding anda (seberapa tebal dan beratpun dinding anda). Ada 2 cara untuk
mengendalikan resonansi ini:Redam resonansinya, sehingga amplituda energi yang
sampai sisi lain dinding akan sangat berkurang

##### Prinsip 5: Konduksi

Ingat bahwa suara adalah gelombang mekanik, sehingga apabila dinding anda terhubung
secara mekanik kedua sisinya, maka suara akan dengan mudah merambat dari satu sisi ke
sisi lainnya. Untuk mengendalikannya tentu saja ada harus memotong hubungan mekanis
antara sisi satu dengan sisi yang lain, misalnya dengan dilatasi antar


### C. ALAT DAN BAHAN

1. Modul trainer Sensor Ultrasonik
2. NodeMcu ESP 8266
3. Kabel Jumper
4. Catu daya 5V
5. Arduino IDE framework

### D. LANGKAH PERCOBAAN

1. Lakukan wiring pada pin I/O nodemcu dengan sensor ultrasonic.
2. Berilah modul gerbang sensor utrasonik tegangan sebesar 9-12 VDC dengan
3. Sambungkan VCC pada modul sensor ultrasonik ke pin 3V pada NodeMcu ESP8266
4. Sambungkan GND pada modul sensor ultrasonik ke pin GND pada NodeMcu ESP8266
5. Sambungkan pin trig pada modul sensor ultrasonik ke pin D1 pada NodeMcu ESP8266
6. Sambungkan pin echo pada modul sensor ultrasonik ke pin D2 pada NodeMcu ESP8266
7. Hubungkan usb dari NodeMcu ESP8266 ke laptop/PC
8. Letakkan benda yang akan diukur pada batas modul sensor utrasonik kemudian perhatikan jarak pada serial monitor.
9. Catat kondisi perubahan jarak

### E. HASIL PERCOBAAN

| Masukan       | Pengukuran 1          | Pengukuran 2          | Pengukuran 3          | Respon waktu/jarak          |
|---------------|-----------------------|-----------------------|-----------------------|-----------------------------|
| Triplek       | 30cm                  |  32cm                 |  31cm                 |  1detik/30cm                |
| Karpet        | 33cm                  |  34cm                 |  33cm                 |  1detik/30cm                |
| Kardus        | 31cm                  |  31cm                 |  31cm                 |  1detik/30cm                |
| Spon          | 37cm                  |  35cm                 |  36cm                 |  1detik/30cm                |

Hasil Analisis ?
1.  Dari hasil percobaan diatas, dapat disimpulkan bahwa semakin jauh benda yang diukur maka semakin lama respon waktu yang dibutuhkan oleh sensor ultrasonic untuk mengukur jarak benda tersebut.
2.  Dengan demikian, dapat disimpulkan bahwa sensor ultrasonic dapat digunakan untuk mengukur jarak benda.

### F. EVALUASI

Buatlah proses pengukuran volume air dengan parameter level tinggi,sedang,rendah melalui
indikator 3 unit LED. Perhatikan juga ukuran luas alas dan diameter benda kerja? 

###### Jawab:
1. Percobaan dengan gelas air minum dengan ukuran jari-jari 3.5cm
2. menyiapkan gelas kosong kemudian cari tinggi gelas kosong dengan menggunakan sensor ultrasonic
dengan script berikut:
```
void loop() {
  
  float jarak_pantul, tinggi_gelas;

  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  echotime = pulseIn(echo_pin, HIGH);

  jarak_pantul = (0.034 * echotime) / 2;

  Serial.print("Tinggi gelas = ");
  Serial.print(jarak_pantul);
  Serial.println(" cm");
  Serial.println("============");

  delay(2000);
}
```
3. Setelah mengetahui tinggi gelas kosong, kemudian isi gelas dengan sedikit air dan cari volume air dengan menggunakan sensor ultrasonic
4. taruh sensor ultrasonic pada bagian atas gelas
5. setelah itu cari volume air dengan memasukkan script berikut :
```
void loop() {
  float luas_alas = 38.46;
  float tinggi_gelas = 6.77;
  float volume_air, tinggi_air, jarak_pantul;

  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  echotime = pulseIn(echo_pin, HIGH);

  jarak_pantul = (0.034 * (float)echotime) / 2;
  tinggi_air = tinggi_gelas - jarak_pantul;
  volume_air = luas_alas * tinggi_air;

  Serial.println("Jarak permukaan air = ");
  Serial.print(jarak_pantul);
  Serial.println(" cm");
  Serial.println("Tinggi air = ");
  Serial.print(tinggi_air);
  Serial.println(" cm");
  Serial.println("Volume air = ");
  Serial.print(volume_air);
  Serial.println(" cm3");
  Serial.println("====================================");

  // Mengatur LED berdasarkan level volume air
  if (volume_air >= 400) {
    digitalWrite(red_led_pin, HIGH);     // LED merah menyala
    digitalWrite(yellow_led_pin, LOW);   // LED kuning mati
    digitalWrite(green_led_pin, LOW);    // LED hijau mati
  } else if (volume_air >= 150 && volume_air < 400) {
    digitalWrite(red_led_pin, LOW);      // LED merah mati
    digitalWrite(yellow_led_pin, HIGH);  // LED kuning menyala
    digitalWrite(green_led_pin, LOW);    // LED hijau mati
  } else {
    digitalWrite(red_led_pin, LOW);      // LED merah mati
    digitalWrite(yellow_led_pin, LOW);   // LED kuning mati
    digitalWrite(green_led_pin, HIGH);   // LED hijau menyala
  }

  delay(2000);
}
```
6. lihat pada serial monitor untuk mengetahui volume air dan lihat lampu led untuk mengetahui level volume air yang telah ditentukan misalnya : volume air 400cm3 maka led merah menyala, volume air 150cm3 maka led kuning menyala, volume air 0cm3 maka led hijau menyala

### G. Hasil analisis
1. Dari hasil percobaan diatas, dapat disimpulkan bahwa semakin tinggi benda yang diukur maka semakin lama respon waktu yang dibutuhkan oleh sensor ultrasonic untuk mengukur jarak benda tersebut.
2. Sensor ultrasonic dapat digunakan untuk mengukur volume air dengan menggunakan rumus volume air = luas alas x tinggi air