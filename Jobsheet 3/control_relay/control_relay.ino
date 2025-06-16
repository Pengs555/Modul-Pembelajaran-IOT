#define BLYNK_TEMPLATE_ID "TMPL6gxnYBjaF"               // ID template dari Blynk
#define BLYNK_TEMPLATE_NAME "relay"                     // Nama template Blynk
#define BLYNK_AUTH_TOKEN "dXHRIoywsLZpAEzIRDU2anbypi1I6f6J"  // Token autentikasi Blynk

#include <WiFi.h>                   // Library untuk koneksi WiFi (ESP32)
#include <BlynkSimpleEsp32.h>       // Library Blynk untuk ESP32

// Konfigurasi WiFi
char ssid[] = "fxx";                // Nama WiFi
char pass[] = "12345678";           // Password WiFi

// Pin Relay
#define RELAY_PIN 26                // Gunakan GPIO 26 untuk relay

// Fungsi kontrol relay dari aplikasi Blynk
BLYNK_WRITE(V0) {
  int status = param.asInt();                    // Baca nilai dari tombol (0 atau 1)
  digitalWrite(RELAY_PIN, status);               // Atur relay sesuai status
  Serial.print("Relay: ");
  Serial.println(status ? "NYALA" : "MATI");     // Cetak status ke Serial Monitor
}

void setup() {
  Serial.begin(115200);                          // Inisialisasi komunikasi serial
  pinMode(RELAY_PIN, OUTPUT);                    // Atur pin sebagai output
  digitalWrite(RELAY_PIN, LOW);                  // Pastikan relay mati di awal

  // Tampilkan proses koneksi
  Serial.print("Menghubungkan ke WiFi dan Blynk...\n");

  // Set mode WiFi ke Station (bukan access point)
  WiFi.mode(WIFI_STA);

  // Hubungkan ke Blynk (sekalian WiFi)
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Tunggu sampai benar-benar tersambung WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Terhubung!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  Blynk.run();  // Jalankan loop Blynk
}