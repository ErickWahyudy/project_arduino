# JOBSHEET 1
## LED OTOMASI FLIP FLOP

### A. TUJUAN
1. Membuat proses flip flop melalui otomasi hardware
2. Menganalisis luaran sinyal data untuk mengatur LED

### B. DASAR TEORI

Flip-flop adalah suatu rangkaian elektronika yang memiliki dua kondisi stabil dan dapat digunakan
untuk menyimpan informasi. Flip Flop merupakan pengaplikasian gerbang logika yang bersifat
Multivibrator Bistabil. Dikatakan Multibrator Bistabil karena kedua tingkat tegangan keluaran
pada Multivibrator tersebut adalah stabil dan hanya akan mengubah situasi tingkat tegangan
keluarannya saat dipicu (trigger).

##### Flip-flop mempunyai dua Output (Keluaran) yang salah satu outputnya merupakan komplemen Output yang lain.
1. JK Flip-flop ( Master slave JK Flip-flop )
JK Flip-flop adalah tidak adanya kondisi terlarang atau yang berarti di beri berapapun inputan
asalkan terdapat clock maka akan terjadi perubahan pada keluarannya / outputnya
2. RS Flip-Flop
RS FF ini adalah dasar dari semua Flip-flop yang memiliki 2 gerbang inputan / masukan yaitu R
dan S. R artinya “RESET” dan S artinya “SET”. Flip-flop yang satu ini mempunyai 2 keluaran /
outputyaitu Q dan Q`. Bila S diberi logika 1 dan R diberi logika 0, maka output Q akan berada
pada logika 0 dan Q not pada logika 1. Bila R diberi logika 1 dan S diberi logika 0 maka keadaan
output akan berubah menjadi Q berada pada logik 1 dan Q not pada logika 0. Sifat paling penting
dari Flip-Flop adalah bahwa sistem ini dapat menempati salah satu dari dua keadaan stabil yaitu
stabil I diperoleh saat Q =1 dan Q not = 0, stabil ke II diperoleh saat Q=0 dan Q not .



### C. ALAT DAN BAHAN

1. Modul trainer NodeMcu ESP 8266
2. Kabel Jumper, LED
3. Catu daya 5V
4. Arduino IDE framework

### D. LANGKAH PERCOBAAN

1. Lakukan wiring pada pin I/O dengan LED
2. Inputkan coding yang telah disiapkan pada Arduino IDE
3. Lakukan proses pengamatan.
4. Script terlampir

### E. HASIL PERCOBAAN

Buat hasil analisis pengamatan flip flop dalam bentuk laporan singkat

### F. EVALUASI

Modifikasi coding dengan membuat flip flop berdasarkan gerbang logika AND, OR, XOR, dengan
menyertakan pseudocode algoritma
