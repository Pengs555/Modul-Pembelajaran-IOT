#define BLYNK_TEMPLATE_ID "TMPL6ubmFc1C1"
#define BLYNK_TEMPLATE_NAME "DHT BLYNK"
#define BLYNK_AUTH_TOKEN "qDD37SGObXCRpfPMwRi7B3eFMBw6FMDe"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h> // DHT_kxn

#define DHTPIN 4 // definisi pin sensor DHT
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);  // Konstruktor DHT dengan pin dan tipe sensor

char ssid[] = "Fxx";
char pass[] = "123456789";

BlynkTimer timer;

void setup() {
  Serial.begin(115200);
  Serial.println("Mencoba terhubung ke WiFi...");
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi terhubung"); // Tambahan print WiFi terhubung
  dht.begin();   // Inisialisasi sensor
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(2000L, sendDataToBlynk);
}

void loop() {
  Blynk.run();
  timer.run();
}

void sendDataToBlynk() {
  float temperature = dht.readTemperature(); // <- benar
  float humidity = dht.readHumidity();       // <- benar

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Gagal membaca sensor!");
    return;
  }

  Blynk.virtualWrite(V0, temperature); // ganti sesuai pin virtual di Blynk
  Blynk.virtualWrite(V1, humidity); // ganti sesuai pin virtual di Blynk
  Serial.println("Data terkirim ke Blynk!");
}