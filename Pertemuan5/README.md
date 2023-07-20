# JOBSHEET 5
## RELAY DAN AKUATOR

### A. TUJUAN
1. Mengintegrasikan relay serta akuator pada proses otomasi.
2. Menganalisis proses integrasi relay dan akuator berdasarkan sensor yang digunakan.

### B. DASAR TEORI

##### Relay
adalah komponen listrik yang bekerja berdasarkan prinsip induksi medan elektromagnetis.Jika
sebuah penghantar dialiri oleh arus listrik, maka di sekitar penghantar tersebut timbul medan
magnet. Medan magnet yang dihasilkan oleh arus listrik tersebut selanjutnya diinduksikan ke
logam ferromagnetis.
Pada dasarnya, Relay terdiri dari 4 komponen dasar yaitu :
1. Electromagnet (Coil)
2. Armature
3. Switch Contact Point (Saklar)
4. Spring
Kontak Poin (Contact Point) Relay terdiri dari 2 jenis yaitu :
* Normally Close (NC) yaitu kondisi awal sebelum diaktifkan akan selalu berada di posisi
CLOSE (tertutup)
Normally Open (NO) yaitu kondisi awal sebelum diaktifkan akan selalu berada di posisi OPEN
(terbuka)

### C. ALAT DAN BAHAN

1. Modul trainer Sensor DHT 11, Relay, LED
2. NodeMcu ESP 8266
3. Kabel Jumper
4. Catu daya 5V
5. Arduino IDE framework

### D. LANGKAH PERCOBAAN

1. Lakukan wiring pada pin I/O dengan sensor dan relay. 
2. Berilah modul gerbang sensor DHT 11 tegangan sebesar 5 VDC dengan cara menghubungkan vin dan ground nodemcu, ke vcc dan ground modul sensor DHT 11 menggunakan kabel penghubung yang sudah disediakan.
3. Hubungkan kabel jumper merah ke pin VCC pada modul sensor DHT 11 dan pin 5V pada NodeMCU ESP8266.
4. Hubungkan kabel jumper hitam ke pin GND pada modul sensor DHT 11 dan pin GND pada NodeMCU ESP8266.
5. Hubungkan kabel jumper kuning ke pin S pada modul sensor DHT 11 dan pin D4 pada NodeMCU ESP8266.
6. Hubungkan arduino ke laptop menggunakan kabel USB.
7. Buka Arduino IDE, lalu buka file `relay_dht11.ino`.
8. Pilih board `NodeMCU 1.0 (ESP-12E Module)`.
9. Pilih port `COM3 (Arduino/Genuino Uno)`.
10. Klik `Upload` untuk mengunggah program ke NodeMCU ESP8266.
11. Amati perubahan suhu dan data yang terkirim pada google firebase.

### E. HASIL PERCOBAAN

Buat hasil analisis pengamatan dalam bentuk laporan singkat

| Percobaan             | Perubahan Suhu        | Delay Time Sleep      | Kondisi Relay         |
|-----------------------|-----------------------|-----------------------|-----------------------|
| Percobaan 1           | 28.20°c               | 2 detik               | Relay OFF             |
| Percobaan 2           | 28.20°c               | 2 detik               | Relay OFF             |
| Percobaan 3           | 27.90°c               | 2 detik               | Relay OFF             |
| Percobaan 4           | 27.90°c               | 2 detik               | Relay OFF             |
| Percobaan 5           | 27.80°c               | 2 detik               | Relay OFF             |

Jawaban hasil analisis
1. Hasil pengamatan pada tabel diatas adalah suhu yang terbaca oleh sensor DHT 11.
2. Hasil analisis yang didapat dari pengamatan diatas adalah suhu yang terbaca oleh sensor DHT 11.
3. Fungsi dari relay pada proses otomasi adalah untuk menghubungkan dan memutuskan arus listrik.
4. Fungsi dari akuator pada proses otomasi adalah untuk menggerakkan sesuatu.
5. Fungsi dari delay time sleep pada proses otomasi adalah untuk menunda waktu.
6. Fungsi dari sensor DHT 11 pada proses otomasi adalah untuk mengukur suhu dan kelembaban.
7. Fungsi dari LED pada proses otomasi adalah untuk menampilkan indikator.
8. Relay akan menyala jika suhu yang terbaca oleh sensor DHT 11 lebih dari 30°c.

### F. EVALUASI

Buat simulasi dan kembangkan coding agar terhubung dengan real time database google firebase
Hasil simulasi dan coding yang telah dikembangkan

Jawaban hasil analisis
1. Hasil pengamatan pada tabel diatas adalah suhu yang terbaca oleh sensor DHT 11.
2. Hasil analisis yang didapat dari pengamatan diatas adalah suhu yang terbaca oleh sensor DHT 11.
3. Fungsi dari relay pada proses otomasi adalah untuk menghubungkan dan memutuskan arus listrik.
4. Fungsi dari akuator pada proses otomasi adalah untuk menggerakkan sesuatu.
5. Fungsi dari delay time sleep pada proses otomasi adalah untuk menunda waktu.
6. Fungsi dari sensor DHT 11 pada proses otomasi adalah untuk mengukur suhu dan kelembaban.
7. Fungsi dari LED pada proses otomasi adalah untuk menampilkan indikator.
8. Fungsi dari firebase pada proses otomasi adalah untuk menghubungkan data dari sensor DHT 11 ke database.
9. Firebase adalah suatu layanan dari Google untuk memberikan kemudahan bahkan mempermudah para developer aplikasi dalam mengembangkan aplikasinya.
10. Dengan firebase, apps developer bisa fokus dalam mengembangkan aplikasi tanpa memberikan effort yang besar untuk urusan backend.
