# 📘 Jobsheet IoT: Dari Dasar hingga Aplikasi Web

Repositori ini berisi rangkaian jobsheet praktikum Internet of Things (IoT) yang disusun bertahap dari pemahaman dasar mikrokontroler hingga implementasi sistem monitoring berbasis web secara lokal. Praktikum menggunakan board ESP32/ESP8266, Arduino IDE, dan platform pendukung seperti Blynk, Flask, PostgreSQL (pgAdmin), dan Grafana.

---

## 📂 Struktur Jobsheet

### 🔹 **Jobsheet 1: Blinking LED & Serial Control**
- Mempraktikkan dasar pengendalian LED menggunakan mikrokontroler ESP.
- LED dikendalikan secara otomatis dan manual melalui serial monitor.
- Tujuan: memahami struktur program Arduino dan kontrol output dasar.

### 🔹 **Jobsheet 2: Sistem Uplink**
- Mengirim data dari ESP32 ke aplikasi Blynk (virtual pin).
- Sensor LDR digunakan sebagai input data.
- Tujuan: memahami komunikasi satu arah dari device ke cloud.

### 🔹 **Jobsheet 3: Sistem Downlink**
- Menerima perintah dari aplikasi Blynk untuk mengontrol LED.
- Menggunakan tombol virtual (switch) di Blynk untuk menyalakan/mematikan output.
- Tujuan: memahami komunikasi dari cloud ke device.

### 🔹 **Jobsheet 4: Kombinasi Uplink & Downlink**
- Sistem menggabungkan input sensor (uplink) dan kontrol manual/otomatis (downlink).
- LED dapat menyala otomatis berdasarkan sensor, atau dikontrol manual dari aplikasi.
- Tujuan: membangun sistem interaktif IoT dua arah.

### 🔹 **Jobsheet 5: Web IoT Lokal (Flask, pgAdmin, Grafana)**
- Membuat website lokal untuk menampilkan dan menyimpan data sensor.
- Menggunakan Python Flask sebagai backend, PostgreSQL (via pgAdmin) untuk database, dan Grafana untuk visualisasi data.
- Tujuan: memahami arsitektur dasar sistem IoT berbasis web secara lokal.

---

## 💻 Teknologi yang Digunakan
- ESP32 / ESP8266
- Arduino IDE
- Blynk IoT Platform
- Python (Flask)
- PostgreSQL + pgAdmin
- Grafana
- HTML/CSS (basic frontend)

## 💻 Sensor dan Aktuator
- Sensor DHT11
- Sensor LDR
- LED
- Relay

---

## 📎 Catatan
- Setiap folder jobsheet berisi:
  - File kode program
  - Skema rangkaian (jika ada)
  - Penjelasan singkat (README per jobsheet)
- Pastikan library Blynk dan board ESP32 sudah terinstal di Arduino IDE sebelum memulai.
