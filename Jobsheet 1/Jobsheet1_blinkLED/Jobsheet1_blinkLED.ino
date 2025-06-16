
const int ledPin1 = 32; // gunakan pin yang mendukung output

void setup() {
  Serial.begin(115200); // Inisialisasi komunikasi serial
  pinMode(ledPin1, OUTPUT); // konfigurasi ledPin1 sebagai output
}

void loop() {
  // Nyalakan LED pertama, matikan LED kedua
  digitalWrite(ledPin1, HIGH);
  Serial.println("LED ON");
  delay(1000); // Tunggu 1 detik

  digitalWrite(ledPin1, LOW);
  Serial.println("LED OFF");
  delay(1000); // Tunggu 1 detik
}