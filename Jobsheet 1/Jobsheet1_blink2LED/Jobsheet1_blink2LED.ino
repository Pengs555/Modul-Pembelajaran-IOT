const int ledPin1 = 33; // LED pertama (gunakan pin yang mendukung output)
const int ledPin2 = 32; // LED kedua

void setup() 
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  // Nyalakan LED pertama, matikan LED kedua
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  delay(1000); // Tunggu 1 detik

  // Matikan LED pertama, nyalakan LED kedua
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, HIGH);
  delay(1000); // Tunggu 1 detik
}