#define LDR_PIN 34 // Gunakan pin analog yang sesuai pada ESP32

void setup() {
    Serial.begin(115200); // Memulai komunikasi serial
}

void loop() {
    int ldrValue = analogRead(LDR_PIN); // Membaca nilai dari sensor LDR
    float voltage = (ldrValue / 4095.0) * 3.3; // Konversi nilai ADC ke tegangan
    
    Serial.print("Nilai LDR: ");
    Serial.print(ldrValue);
    Serial.print(" - Tegangan: ");
    Serial.print(voltage);
    Serial.println(" V");
    
    delay(1000); // Delay 1 detik sebelum membaca kembali
}
