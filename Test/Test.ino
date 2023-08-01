#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h> // Library Firebase ESP8266 Client
#include <CTBot.h>

// Masukkan wifi dan password
#define WIFI_SSID "PRODUCTION"
#define WIFI_PASSWORD "asdfghjkl"

// Masukkan token dan chat id bot telegram
#define BOT_TOKEN "1306451202:AAFL84nqcQjbAsEpRqVCziQ0VGty4qIAxt4"
#define TELEGRAM_CHAT_ID -1001939397003 // Ganti dengan ID chat yang valid

#define SENSOR_1_PIN D3
#define SENSOR_2_PIN D4

#define Relay_1 D5 // Pin untuk relay
#define Relay_2 D7 // Pin untuk relay

OneWire oneWire1(SENSOR_1_PIN);
OneWire oneWire2(SENSOR_2_PIN);
DallasTemperature sensors1(&oneWire1);
DallasTemperature sensors2(&oneWire2);

WiFiClientSecure client;
FirebaseData firebaseData;
CTBot myBot;

bool fanState = false;   // Variable untuk menyimpan status kipas
bool heaterState = false; // Variable untuk menyimpan status pemanas

void setup()
{
    Serial.begin(9600);
    delay(10);

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Hubungkan ke WiFi...");
    }

    Serial.println("Terhubung ke WiFi");

    Firebase.begin("https://suhu-aquarium-default-rtdb.asia-southeast1.firebasedatabase.app/", "AIzaSyDIIIwWkLBBk7HYMyATDDrj9cB-hrZXyK4");

    sensors1.begin();
    sensors2.begin();

    myBot.wifiConnect(WIFI_SSID, WIFI_PASSWORD);
    myBot.setTelegramToken(BOT_TOKEN);

    pinMode(Relay_1, OUTPUT);
    pinMode(Relay_2, OUTPUT);
}

void loop()
{
    sensors1.requestTemperatures();
    sensors2.requestTemperatures();

    float temperature1 = sensors1.getTempCByIndex(0);
    float temperature2 = sensors2.getTempCByIndex(0);
    float averageTemperature = (temperature1 + temperature2) / 2; // Hitung rata-rata suhu dari kedua sensor

    Serial.print("Sensor 1 Suhu: ");
    Serial.print(temperature1);
    Serial.println(" °C");

    Serial.print("Sensor 2 Suhu: ");
    Serial.print(temperature2);
    Serial.println(" °C");

    Serial.print("Hasil Perbandingan: ");
    Serial.print(averageTemperature);
    Serial.println(" °C");

    String message;

    // Logika perbandingan suhu berdasarkan rata-rata
    if (averageTemperature < 25)
    {
        message = "Suhu Monitoring\n\n"
                  "Sensor 1 Suhu: " + String(temperature1) + " °C\n"
                  "Sensor 2 Suhu: " + String(temperature2) + " °C\n"
                  "Hasil Perbandingan: " + String(averageTemperature) + " °C\n"
                  "Keterangan: Dingin";
        heaterState = true; // Nyalakan pemanas
    }
    else if (averageTemperature >= 25 && averageTemperature <= 30)
    {
        fanState = false;   // Matikan kipas angin
        heaterState = false; // Matikan pemanas
    }
    else if (averageTemperature > 30)
    {
        message = "Suhu Monitoring\n\n"
                  "Sensor 1 Suhu: " + String(temperature1) + " °C\n"
                  "Sensor 2 Suhu: " + String(temperature2) + " °C\n"
                  "Hasil Perbandingan: " + String(averageTemperature) + " °C\n"
                  "Keterangan: Panas";
        fanState = true; // Nyalakan kipas angin
    }

    if (!message.isEmpty())
    {
        sendTelegramMessage(message); // Kirim pesan ke Telegram
    }

    controlFan();    // Panggil fungsi untuk mengontrol kipas angin
    controlHeater(); // Panggil fungsi untuk mengontrol pemanas

    // Kirim data ke Firebase
    String path = "/";
    Firebase.setString(firebaseData, path + "Suhu1", String(temperature1));
    Firebase.setString(firebaseData, path + "Suhu2", String(temperature2));
    Firebase.setString(firebaseData, path + "Hasil_perbandingan", String(averageTemperature));
    Firebase.setString(firebaseData, path + "fanState", String(fanState));
    Firebase.setString(firebaseData, path + "heaterState", String(heaterState));

    if (firebaseData.httpCode() != FIREBASE_ERROR_HTTP_CODE_OK)
    {
        Serial.println("Firebase data set failed");
        Serial.println("HTTP response code: " + String(firebaseData.httpCode()));
        Serial.println("Reason: " + firebaseData.errorReason());
    }

    delay(5000);
}

void sendTelegramMessage(String message)
{
    myBot.sendMessage(TELEGRAM_CHAT_ID, message);
}

void controlFan()
{
    if (fanState)
    {
        digitalWrite(Relay_1, LOW); // Matikan relay (mematikan relay kipas angin)
    }
    else
    {
        digitalWrite(Relay_1, HIGH); // Nyalakan relay (nyalakan relay kipas angin)
    }
}

void controlHeater()
{
    if (heaterState)
    {
        digitalWrite(Relay_2, LOW); // Matikan relay (mematikan relay pemanas)
    }
    else
    {
        digitalWrite(Relay_2, HIGH); // Nyalakan relay (nyalakan relay pemanas)
    }
}
