#define BLYNK_TEMPLATE_ID "TMPL6Hf8fII4L"
#define BLYNK_TEMPLATE_NAME "Automatic LED"
#define BLYNK_AUTH_TOKEN "VFw4I1KB1--xwg_Bn_l8ebpgIIdb9bQR"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Ganti dengan WiFi Anda
char ssid[] = "fxx";
char pass[] = "12345678";

const int ldrPin = 34;
const int ledPin = 4;

int ldrValue = 0;
bool ledState = false;
bool autoMode = true;       // Default: mode otomatis
int manualControl = 0;      // Nilai kontrol manual dari Blynk

#define VPIN_MODE V0        // Virtual pin untuk switch mode (auto/manual)
#define VPIN_LDR V1         // Virtual pin untuk menampilkan nilai LDR
#define VPIN_MANUAL V2      // Virtual pin untuk tombol manual LED

void setup() {
  Serial.begin(115200);
  pinMode(ldrPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

// Mode otomatis/manual dari Blynk (Switch)
BLYNK_WRITE(VPIN_MODE) {
  autoMode = param.asInt();
}

// Kontrol LED manual dari Blynk
BLYNK_WRITE(VPIN_MANUAL) {
  manualControl = param.asInt();
}

void loop() {
  Blynk.run();

  ldrValue = analogRead(ldrPin);

  // Tampilkan nilai LDR ke Serial dan Blynk
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);
  Blynk.virtualWrite(VPIN_LDR, ldrValue);

  // Logika kontrol LED
  if (autoMode) {
    // Mode otomatis: LED nyala jika gelap
    if (ldrValue > 2500) {
      digitalWrite(ledPin, HIGH);
      ledState = true;
    } else {
      digitalWrite(ledPin, LOW);
      ledState = false;
    }
  } else {
    // Mode manual: kontrol LED via tombol Blynk
    digitalWrite(ledPin, manualControl ? HIGH : LOW);
    ledState = manualControl;
  }

  // Tampilkan status LED ke Serial
  Serial.print("LED Status: ");
  Serial.println(ledState ? "ON" : "OFF");

  delay(1000);
}