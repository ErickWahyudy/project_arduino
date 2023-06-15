int led1Pin = D1; //menetapkan pin dan tipe data
int led2Pin = D2; //menetapkan pin dan tipe data
int led3Pin = D3; //menetapkan pin dan tipe data

void setup() {
  pinMode(led1Pin, OUTPUT); //menetapkan pin mode
  pinMode(led2Pin, OUTPUT); //menetapkan pin mode
  pinMode(led3Pin, OUTPUT); //menetapkan pin mode
}

void loop() {
  digitalWrite(led1Pin, HIGH); //memberi tegangan positif(+) pada pin LED 1
  delay(1000); //membari jeda waktu selama 0,5 detik
  digitalWrite(led1Pin, LOW); //memberi tegangan negatif(-) pada pin LED 1
  delay(1000); //membari jeda waktu selama 0,5 detik

  digitalWrite(led2Pin, HIGH); //memberi tegangan positif(+) pada pin LED 2
  delay(1000); //membari jeda waktu selama 0,5 detik
  digitalWrite(led2Pin, LOW); //memberi tegangan negatif(-) pada pin LED 2
  delay(1000); //membari jeda waktu selama 0,5 detik

  digitalWrite(led3Pin, HIGH); //memberi tegangan positif(+) pada pin LED 3
  delay(1000); //membari jeda waktu selama 0,5 detik
  digitalWrite(led3Pin, LOW); //memberi tegangan negatif(-) pada pin LED 3
  delay(1000); //membari jeda waktu selama 0,5 detik
}