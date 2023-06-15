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
3. cara menghubungkan vcc dan ground power supply ke vcc dan ground modul sensor ultarasonik menggunakan kabel penghubung yang sudah disediakan.
4. Hubungkan pada framework ardino ide
5. Letakkan benda yang akan diukur pada batas modul sensor utrasonik kemudian perhatikan jarak pada serial monitor.
6. Catat kondisi perubahan jarak

### E. HASIL PERCOBAAN

| Masukan       | Pengukuran 1                | Pengukuran 2                | Pengukuran 3                |
|---------------|-----------------------------|-----------------------------|-----------------------------|
| Triplek       |                             |                             |                             |
| Karpet        |                             |                             |                             |
| Kardus        |                             |                             |                             |
| Spon          |                             |                             |                             |

Hasil Analisis ?

### F. EVALUASI

Buatlah proses pengukuran volume air dengan parameter level tinggi,sedang,rendah melalui
indikator 3 unit LED. Perhatikan juga ukuran luas alas dan diameter benda kerja? 
