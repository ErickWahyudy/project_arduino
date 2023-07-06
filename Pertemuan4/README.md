# JOBSHEET 4
## INTEGRASI FIREBASE PADA PROSES OTOMASI SENSOR DHT 11

### A. TUJUAN
1. Membuat integrasi google firebase pada sistem otomasi dengan tranduser DHT 11.
2. Menghasilkan proses analisis dari proses integrasi

### B. DASAR TEORI

Firebase adalah suatu layanan dari Google untuk memberikan kemudahan bahkan mempermudah
para developer aplikasi dalam mengembangkan aplikasinya. Firebase alias BaaS (Backend as a
Service) merupakan solusi yang ditawarkan oleh Google untuk mempercepat pekerjaan developer.
Dengan menggunakan Firebase, apps developer bisa fokus dalam mengembangkan aplikasi tanpa
memberikan effort yang besar untuk urusan backend

DHT 11 module sensor yang berfungsi untuk mensensing objek suhu dan kelembaban yang
memiliki output tegangan analog yang dapat diolah lebih lanjut menggunakan mikrokontroler, Modul DHT11 merupakan sensor suhu dan kelembapan digital tingkat dasar dan murah.

### C. ALAT DAN BAHAN

1. Modul trainer NodeMcu ESP 8266
2. Kabel Jumper, LED
3. Catu daya 5V
4. Arduino IDE framework
5. Modul trainer Sensor DHT 11
6. Google Firebase framework

### D. LANGKAH PERCOBAAN

1. Lakukan wiring pada pin I/O nodemcu dengan sensor DHT 11.
2. Berilah modul gerbang sensor DHT 11 tegangan sebesar 5 VDC dengan cara menghubungkan vin dan ground nodemcu, ke vcc dan ground modul sensor DHT 11 menggunakan kabel penghubung yang sudah disediakan.
3. Buat realtime database pada firebase, buat auth key kemudian pasangkan pada Arduino ide.
4. Hubungkan pada framework Arduino IDE lakukan uploading.
5. Amati perubahan suhu dan data yang terkirim pada google firebase.
6. Lakukan juga pengecekan pada library firebase jika data tidak terkirim.

#### Langkah merangkai sensor DHT 11 dengan NodeMCU ESP8266
1. Siapkan alat dan bahan yang dibutuhkan.
2. Siapkan modul sensor DHT 11, NodeMCU ESP8266, kabel jumper, dan kabel USB.
3. Hubungkan kabel USB ke NodeMCU ESP8266 dan laptop.
4. Hubungkan kabel jumper ke modul sensor DHT 11 dan NodeMCU ESP8266.
5. Hubungkan kabel jumper merah ke pin VCC pada modul sensor DHT 11 dan pin Vin pada NodeMCU ESP8266.
6. Hubungkan kabel jumper hitam ke pin GND pada modul sensor DHT 11 dan pin GND pada NodeMCU ESP8266.
7. Hubungkan kabel jumper kuning ke pin S pada modul sensor DHT 11 dan pin D4 pada NodeMCU ESP8266.

#### Langkah membuat realtime database pada firebase
1. Buka browser dan masuk ke website firebase.
2. Klik menu `Go to console` pada pojok kanan atas.
3. Klik `Add project` untuk membuat project baru.
4. Masukkan nama project, lalu klik `Continue`.
5. Klik `Create project`.
6. Klik 'Authentication' pada menu Develop.
7. Klik `Set up sign-in method`.
8. Pilih `anonymous`, lalu klik `Enable'
9. Klik `Database` pada menu Develop.
10. Klik `Create database`.
11. Pilih `Start in test mode`, lalu klik `Enable`.
12. Klik `Rules` dan ubah menjadi seperti berikut.
```
{
  "rules": {
    ".read": true,
    ".write": true
  }
}
```
13. Klik `Publish`.
14. Klik `Project Overview` pada pojok kiri atas.
15. Klik `Add Firebase to your web app`.
16. Untuk mendapatkan `auth key`, klik icon `Setting` pada pojok kanan atas.
17. Klik `Project settings`.
18. Kemudian klik `General`.
19. Gulir ke bawah cari `Web API Key` dan salin `Web API Key` tersebut.
20. Salin url database yang sudah dibuat pada menu 'Realtime Database' dan salin `databaseURL` tersebut.

#### Langkah menghubungkan NodeMCU ESP8266 dengan firebase
21. Buka Arduino IDE dan buka sketch `Firebase_ESP8266_DHT11`.
22. Salin kode yang sudah disalin tadi ke dalam sketch.
23. Ubah `ssid` dan `password` sesuai dengan WiFi yang digunakan.
24. Ubah `auth` sesuai dengan `auth key` yang sudah dibuat.
25. Ubah `databaseURL` sesuai dengan `databaseURL` yang sudah dibuat.
26. Upload sketch ke NodeMCU ESP8266.
27. Buka serial monitor.
28. Amati perubahan suhu dan data yang terkirim pada google firebase.

### E. HASIL PERCOBAAN

Catat setiap kenaikan suhu yang muncul pada terminal monitor Arduino IDE, kemudian amati
kecepatan perubahan suhu pada real time database google firebase. Kemudian hitung rata-rata
kecepatan data yang terkirim pada google firebase. Gunakan quality of service (QoS).

Delay time sleep yang digunakan adalah 10 detik
| Percobaan             | Perubahan Suhu        |
|-----------------------|-----------------------|
| Percobaan 1           | 24.20°c               |
| Percobaan 2           | 24.20°c               |
| Percobaan 3           | 24.20°c               |
| Percobaan 4           | 24.30°c               |
| Percobaan 5           | 24.40°c               |

Hasil analisis data yang terkirim pada google firebase
1. Rata-rata perubahan suhu yang terkirim pada google firebase adalah 24.26°c
3. Quality of service (QoS) yang digunakan adalah 0
4. Quality of service (QoS) yang digunakan adalah 1
5. Quality of service (QoS) yang digunakan adalah 2
6. Quality of service (QoS) yang digunakan adalah 3

### F. EVALUASI

Kembangkan coding dengan menambahkan kelembapan udara integrasikan di firebase, rubah delay
time sleep sesuai instruksi instruktur.

Delay time sleep yang digunakan adalah 10 detik
| Percobaan             | Perubahan Suhu        | Perubahan Kelembaban   |
|-----------------------|-----------------------|------------------------|
| Percobaan 1           | 24.20°c               | 51.30%                 |
| Percobaan 2           | 24.20°c               | 52.00%                 |
| Percobaan 3           | 24.20°c               | 51.40%                 |
| Percobaan 4           | 24.30°c               | 51.40%                 |
| Percobaan 5           | 24.40°c               | 51.20%                 |

Hasil analisis data yang terkirim pada google firebase
1. Rata-rata perubahan suhu yang terkirim pada google firebase adalah 24.26°c
2. Rata-rata perubahan kelembaban yang terkirim pada google firebase adalah 51.46%
3. Quality of service (QoS) yang digunakan adalah 0
4. Quality of service (QoS) yang digunakan adalah 1
5. Quality of service (QoS) yang digunakan adalah 2
6. Quality of service (QoS) yang digunakan adalah 3