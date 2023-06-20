//kombinasi ultasonik, relay, buzzer, dan lampu

const int triggerPin = D6;
const int echoPin = D5;
const int relayPin = D0;
const int buzzerPin = D1;
const int lampPin = D2;

void setup() {
  Serial.begin(9600); // Inisialisasi komunikasi serial
  pinMode(triggerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(lampPin, OUTPUT);
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
    digitalWrite(relayPin, HIGH); // Menghidupkan relay
    digitalWrite(lampPin, HIGH); // Menghidupkan lampu
    digitalWrite(buzzerPin, HIGH); // Menghidupkan buzzer
  } else if (distance < 15) {
    digitalWrite(relayPin, HIGH); // Menghidupkan relay
    blinkLamp(); // Memanggil fungsi blinkLamp untuk membuat lampu berkedip
    beepBuzzer(); // Memanggil fungsi beepBuzzer untuk menghasilkan suara beep
  } else {
    digitalWrite(relayPin, LOW); // Mematikan relay
    digitalWrite(lampPin, LOW); // Mematikan lampu
    digitalWrite(buzzerPin, LOW); // Mematikan buzzer
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(1000);
}

void blinkLamp() {
  digitalWrite(lampPin, HIGH); // Menghidupkan lampu
  delay(100); // Mempertahankan lampu dalam keadaan nyala selama 500 milidetik (ms)
  digitalWrite(lampPin, LOW); // Mematikan lampu
  delay(100); // Mempertahankan lampu dalam keadaan mati selama 500 milidetik (ms)
}

void beepBuzzer() {
  digitalWrite(buzzerPin, HIGH); // Menghidupkan buzzer
  delay(100); // Mempertahankan buzzer dalam keadaan nyala selama 100 milidetik (ms)
  digitalWrite(buzzerPin, LOW); // Mematikan buzzer
  delay(100); // Mempertahankan buzzer dalam keadaan mati selama 100 milidetik (ms)
}
