const int ledPin1 = 32; // Gunakan pin GPIO 32 untuk LED

void setup() {
  pinMode(ledPin1, OUTPUT); // Konfigurasi LED sebagai output
  Serial.begin(115200); // Inisialisasi komunikasi serial
  Serial.println("Ketik 'ON' untuk menyalakan LED, 'OFF' untuk mematikan LED.");
}

void loop() {
  if (Serial.available() > 0) { // Jika ada data dari Serial Monitor
    String command = Serial.readStringUntil('\n'); // Baca input hingga enter

    if (command == "ON") {
      digitalWrite(ledPin1, HIGH); // Nyalakan LED
      Serial.println("LED ON");
    } 
    else if (command == "OFF") {
      digitalWrite(ledPin1, LOW); // Matikan LED
      Serial.println("LED OFF");
    } 
    else {
      Serial.println("Perintah tidak dikenali. Gunakan 'ON' atau 'OFF'.");
    }
  }
}