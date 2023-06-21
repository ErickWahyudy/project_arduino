const int trig_pin = D5;
const int echo_pin = D4;
const int red_led_pin = D0;
const int yellow_led_pin = D1;
const int green_led_pin = D2;
long echotime;

void setup() {
  Serial.begin(9600);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(red_led_pin, OUTPUT);
  pinMode(yellow_led_pin, OUTPUT);
  pinMode(green_led_pin, OUTPUT);
  digitalWrite(trig_pin, LOW);
}

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
