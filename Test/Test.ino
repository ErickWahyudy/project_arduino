#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int triggerPin = D6;
const int echoPin = D5;
const int relayPin = D7;

LiquidCrystal_I2C lcd(0x27, 16, 2); // Inisialisasi objek LCD dengan alamat I2C, 16 karakter dan 2 baris

void setup() {
  Serial.begin(9600); // Inisialisasi komunikasi serial
  lcd.begin(16, 2); // Inisialisasi LCD
  lcd.init(); // Inisialisasi LCD
  lcd.backlight(); // Mengaktifkan backlight pada LCD
  pinMode(triggerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
}

void loop() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  if (distance < 10) {
    digitalWrite(relayPin, HIGH);
  } else {
    digitalWrite(relayPin, LOW);
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  lcd.setCursor(0, 1);
  lcd.print("                "); // Membersihkan baris kedua pada LCD
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");

  delay(1000);
}
