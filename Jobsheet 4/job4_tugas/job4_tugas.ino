/*
#include <DHT.h>

// Konfigurasi pin dan tipe sensor
#define DHTPIN 4
#define DHTTYPE DHT11  // Ubah ke DHT11 jika Anda menggunakan DHT11

// Inisialisasi DHT
DHT dht(DHTPIN, DHTTYPE);

// Pin LED
const int led1 = 18;
const int led2 = 19;
const int led3 = 21;

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  float suhu = dht.readTemperature();

  // Periksa apakah pembacaan berhasil
  if (isnan(suhu)) {
    Serial.println("Gagal membaca dari sensor DHT!");
    return;
  }

  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.println(" °C");

  // Logika kontrol LED berdasarkan suhu
  if (suhu < 28) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  } else if (suhu >= 28 && suhu <= 33) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  } else { // suhu > 34
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }

  delay(2000); // Delay 2 detik antara pembacaan
}
*/

#define BLYNK_TEMPLATE_ID "TMPL6OlYTfS8p"
#define BLYNK_TEMPLATE_NAME "automatic fan speed"
#define BLYNK_AUTH_TOKEN "1b-PbL_QrcoGcZHpMwoZrBYbqGvulvFO"  // Ganti dengan token Anda

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

// WiFi credentials
char ssid[] = "fxx";        // Ganti dengan nama WiFi Anda
char pass[] = "12345678";    // Ganti dengan password WiFi Anda

// DHT sensor setup
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// LED pins
const int led1 = 18;
const int led2 = 19;
const int led3 = 21;

BlynkTimer timer;

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Baca suhu setiap 2 detik
  timer.setInterval(2000L, bacaDanKirimData);
}

void loop() {
  Blynk.run();
  timer.run();
}

void bacaDanKirimData() {
  float suhu = dht.readTemperature();

  if (isnan(suhu)) {
    Serial.println("Gagal membaca dari DHT!");
    return;
  }

  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.println(" °C");

  // Kirim suhu ke Blynk Virtual Pin V0
  Blynk.virtualWrite(V0, suhu);

  // Logika LED
  if (suhu < 29) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  } else if (suhu >= 29 && suhu <= 34) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  } else {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }
}