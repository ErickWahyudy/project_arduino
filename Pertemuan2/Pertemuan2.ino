const int triggerPin = D6;
const int echoPin = D5;
const int relayPin = D7;

void setup() {
  Serial.begin(9600); // Inisialisasi komunikasi serial
  pinMode(triggerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(echoPin, INPUT);
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
  delay(1000);
}
