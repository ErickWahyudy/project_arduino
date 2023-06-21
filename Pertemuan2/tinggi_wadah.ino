const int trig_pin = D5;
const int echo_pin = D4;
long echotime;

void setup() {
  Serial.begin(9600);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  digitalWrite(trig_pin, LOW);
}

void loop() {
  
  float jarak_pantul, tinggi_gelas;

  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  echotime = pulseIn(echo_pin, HIGH);

  jarak_pantul = (0.034 * echotime) / 2;

  Serial.print("Tinggi gelas = ");
  Serial.print(jarak_pantul);
  Serial.println(" cm");
  Serial.println("============");

  delay(2000);
}
