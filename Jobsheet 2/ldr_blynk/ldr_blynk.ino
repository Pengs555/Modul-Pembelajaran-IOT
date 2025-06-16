#define BLYNK_TEMPLATE_ID "TMPL6_MYpZj-q"
#define BLYNK_TEMPLATE_NAME "LDR to Blynk"
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Konfigurasi WiFi
char ssid[] = "realme"; // Sesuaikan dengan jaringan anda
char pass[] = "12345678";

// Token Blynk
char auth[] = "1SY9_D1bQiV5l-c2NWsvj0dRlLqBKZt7"; // Ganti dengan token Anda

// Pin LDR
#define LDR_PIN 34

void setup() {
  Serial.begin(115200); // Baud rate Serial Monitor
  Blynk.begin(auth, ssid, pass); // Inisialisasi Blynk
}

void loop() {
  Blynk.run(); // Jalankan Blynk

  int ldrValue = analogRead(LDR_PIN);
  float voltage = (ldrValue * 3.3) / 4095.0; // Konversi ADC ke nilai tegangan

  // Kirim data ke Blynk
  Blynk.virtualWrite(V34, ldrValue); // Ubah virtual pin sesuai konfigurasi
  Blynk.virtualWrite(V1, voltage); 

  Serial.print("Nilai LDR: ");
  Serial.print(ldrValue);
  Serial.print(" | Tegangan: ");
  Serial.println(voltage);

  delay(1000);
}
