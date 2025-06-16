
#define BLYNK_TEMPLATE_ID "TMPL6LZ1Wp5v5"	// Sesuaikan Template ID
#define BLYNK_TEMPLATE_NAME "led"	// Sesuaikan Nama template
#define BLYNK_AUTH_TOKEN "fXxxHjpr5NTqd6TOrEQnU1GOOSYkeqvm" // Sesuaikan Auth Token

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Konfigurasi WiFi
char ssid[] = "fxx";             // Nama WiFi
char pass[] = "12345678";        // Password WiFi

// Pin LED di ESP32
#define LED_PIN 32

// Fungsi untuk mengontrol LED via Virtual Pin V0
BLYNK_WRITE(V0) {
  int status = param.asInt();         // Baca nilai dari tombol (0 atau 1)
  digitalWrite(LED_PIN, status);      // Aktifkan/matikan LED
  Serial.println(status ? "LED ON" : "LED OFF");
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);           // Set pin sebagai output
  digitalWrite(LED_PIN, LOW);         // Pastikan LED mati saat boot

  Serial.print("Menghubungkan ke WiFi: ");
  Serial.println(ssid);

  // Coba koneksi manual ke WiFi (supaya bisa tampil status)
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println(); // baris baru setelah titik-titik
  Serial.println("WiFi Terhubung!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Mulai koneksi ke Blynk
  Blynk.config(BLYNK_AUTH_TOKEN);
  Blynk.connect();  // Terkoneksi ke server Blynk
}

void loop() {
  Blynk.run();                        // Jalankan proses Blynk
}


/*
#include <WiFi.h>

// Ganti dengan SSID dan password WiFi Anda
const char* ssid = "fxx";
const char* password = "12345678";

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.print("Menghubungkan ke WiFi: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  // Tunggu hingga terhubung
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nTerhubung ke WiFi!");
  Serial.print("IP Address ESP32: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Tidak ada proses berulang dalam loop
}
*/