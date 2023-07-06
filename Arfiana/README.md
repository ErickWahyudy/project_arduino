# MENGGUNAKAN SENSOR DS1820B MENGUKUR SUHU TEMPERATUR DAN INTEGRASIKAN DENGAN FIREBASE DAN TELEGRAM BOT

#### Langkah merangkai sensor DS1820B pada NodeMCU ESP8266
1. Siapkan sensor DS1820B, NodeMCU ESP8266, dan kabel jumper
2. Hubungkan kaki GND sensor DS1820B dengan kaki GND NodeMCU ESP8266 menggunakan kabel jumper
3. Hubungkan kaki VCC sensor DS1820B dengan kaki 3V NodeMCU ESP8266 menggunakan kabel jumper
4. Hubungkan kaki DQ sensor DS1820B dengan kaki D4 NodeMCU ESP8266 menggunakan kabel jumper

#### Langkah instalasi sensor DS1820B pada Arduino IDE
1. Buka Arduino IDE
Jika belum menginstall Arduino IDE, silahkan download terlebih dahulu [disini](https://www.arduino.cc/en/software)
2. Install library OneWire dan DallasTemperature
Jika belum mengatur package manager berikut cara mengaturnya:
- Buka Arduino IDE
- Klik File > Preferences
- Pada Additional Boards Manager URLs, masukkan link berikut:
```
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```
- Klik OK
- Klik Tools > Board > Boards Manager
- Ketikkan esp8266 pada kolom pencarian
- Klik Install pada esp8266 by ESP8266 Community
- Tunggu hingga proses instalasi selesai
- Klik Close
3. Install library OneWire dan DallasTemperature
- Klik Sketch > Include Library > Manage Libraries
- Ketikkan OneWire pada kolom pencarian
- Klik Install pada OneWire by adafruit
- Ketikkan DallasTemperature pada kolom pencarian
- Klik Install pada DallasTemperature by adafruit
- Klik Close
4. Install library Firebase ESP8266 Client
- Klik Sketch > Include Library > Manage Libraries
- Ketikkan Firebase ESP8266 Client pada kolom pencarian
- Klik Install pada Firebase ESP8266 Client by adafruit
- Klik Close
5. Install library CtBot
- Klik Sketch > Include Library > Manage Libraries
- Ketikkan CtBot pada kolom pencarian
- Klik Install pada CtBot by adafruit
- Klik Close
6. Masukkan kode program berikut pada Arduino IDE
```
#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#include <CtBot.h>

Untuk script lengkapnya dapat dilihat pada file [modifikasi1.ino]
```
7. Upload kode program tersebut ke NodeMCU ESP8266
8. Buka Serial Monitor
9. Amati hasil keluaran pada Serial Monitor