// import libary sensor dht
#include <DHT.h>

// Konfigurasi pin dan tipe sensor DHT
#define DHTPIN 4      // Pin data DHT22 ke GPIO4 ESP32
#define DHTTYPE DHT11 // Tipe sensor DHT22

DHT dht(DHTPIN, DHTTYPE);  // Inisialisasi objek DHT

void setup() {
    Serial.begin(115200);
    Serial.println("Memulai Sensor DHT11...");
    dht.begin(); // Memulai sensor DHT11
}

void loop() {
    float temperature = dht.readTemperature();  // Membaca suhu dalam °C
    float humidity = dht.readHumidity();        // Membaca kelembaban dalam %

    // Cek apakah pembacaan valid
    if (isnan(temperature) || isnan(humidity)) {
        Serial.println("Gagal membaca dari DHT11!");
    } else {
        // Tampilkan hasil ke Serial Monitor
        Serial.print("Suhu: ");
        Serial.print(temperature);
        Serial.print("°C  |  Kelembaban: ");
        Serial.print(humidity);
        Serial.println("%");
    }

    delay(2000); // Tunggu 2 detik sebelum membaca kembali
}
