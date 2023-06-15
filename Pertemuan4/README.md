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

### E. HASIL PERCOBAAN

Catat setiap kenaikan suhu yang muncul pada terminal monitor Arduino IDE, kemudian amati
kecepatan perubahan suhu pada real time database google firebase. Kemudian hitung rata-rata
kecepatan data yang terkirim pada google firebase. Gunakan quality of service (QoS).

### F. EVALUASI

Kembangkan coding dengan menambahkan kelembapan udara integrasikan di firebase, rubah delay
time sleep sesuai instruksi instruktur.
