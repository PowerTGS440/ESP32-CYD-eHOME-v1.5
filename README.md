# eHome System v1.5 🏠🌡️📅

Zaawansowany system automatyki domowej i autonomicznej stacji monitorującej oparty na module **ESP32 Cheap Yellow Display (ESP32-2432S028R)** oraz czujniku **Bosch BME280**. 

System charakteryzuje się modułową strukturą (C++), nieblokującym harmonogramem zadań (`Top-Down Scheduler` na bazie `millis()`) oraz zaawansowanym wykorzystaniem pamięci stałej **PROGMEM (Flash)** do obsługi rocznej bazy danych.

---

## 🚀 Główne Funkcjonalności

* **Telemetria Środowiskowa**: Odczyt temperatury, ciśnienia oraz wilgotności z czujnika BME280, odizolowany do bezpiecznej struktury danych z szybkim dostępem (gettery).
* **Roczny Kalendarz FLASH (PROGMEM)**: Kompletna, bezobsługowa baza danych imienin oraz świąt nietypowych na wszystkie 365 dni roku przechowywana bezpośrednio w pamięci krzemu. Wyświetla dane cyklicznie na Serial Monitorze oraz na stronie WWW.
* **Bezprzewodowy Panel HTTP**: Wbudowany serwer sieciowy (`http://IP_URZADZENIA/logs`) prezentujący elegancki boks informacyjny z dzisiejszą datą, imieninami i świętem, a także panel do pobierania i usuwania logów CSV.
* **Rotacja Logów Miesięcznych**: Automatyczne tworzenie niezależnych plików CSV (np. `/log_2026_06.csv`) na karcie SD co miesiąc w celu ochrony przed przepełnieniem.
* **Automatyka EKO (LDR)**: Dynamiczna kontrola podświetlenia ekranu (PWM) za pomocą wbudowanego fotorezystora – ekran automatycznie przygasza się po zgaszeniu światła w pokoju (skalibrowany próg: `900`).
* **Sygnalizacja Sieci RGB**: Nadzór nad łącznością WiFi i sygnalizowanie statusu wbudowaną diodą RGB (zielony: OK, migający czerwony: reconnect).
* **Bezpiecznik Termiczny**: Autonomiczny moduł ochrony krzemu monitorujący temperaturę wewnętrzną rdzenia ESP32 (awaryjne wygaszanie ekranu przy 85°C).
* **Łączność ESP-NOW**: Gotowa, zoptymalizowana warstwa radiowa do bezprzewodowej, bezpośredniej wymiany danych z innymi węzłami w domu.

---

## 🛠️ Wymagane Biblioteki

Projekt wymaga zainstalowania poniższych bibliotek z poziomu Menedżera Bibliotek Arduino IDE:

1. **Adafruit BME280 Library** – [Menedżer / GitHub](https://github.com)
2. **Adafruit Unified Sensor** – [Menedżer / GitHub](https://github.com)
3. **TFT_eSPI** – [Menedżer / GitHub](https://github.com)

---

## 🗺️ Struktura Plików Projektu

```text
eHome_v1_5/
├── eHome_v1_5.ino          # Główna pętla programu i scheduler zadań
├── config.h                # Konfiguracja makr czasowych, pinów i trybu debugowania
├── calendar_data.h         # Kompletna roczna baza imienin w pamięci FLASH (PROGMEM)
├── holidays_data.h         # Kompletna roczna baza świąt nietypowych we FLASH (PROGMEM)
├── calendar_manager.h      # Logika wyszukiwania i cyklicznego zrzutu kalendarza
├── system_manager.h        # Strażnik termiczny i diagnostyka rdzenia ESP32
├── bme_sensor.h            # Moduł obsługi czujnika Bosch BME280
├── wifi_manager.h          # Zarządzanie siecią WiFi, reconnect i diodą RGB
├── time_manager.h          # Obsługa serwerów NTP i wbudowanego zegara RTC
├── display_manager.h       # Silnik graficzny TFT, wskaźnik RSSI oraz automatyka LDR
└── web_server_manager.h    # Serwer HTTP, panel HTML kalendarza i pobieranie CSV z SD
```

---

## 🔌 Połączenie Czujnika BME280 (I2C)

Podłącz czujnik do portu rozszerzeń **CN1** na płytce ESP32 CYD:
* **VCC** ➡️ `3.3V`
* **GND** ➡️ `GND`
* **SDA** ➡️ `GPIO 27`
* **SCL** ➡️ `GPIO 22`

---

## 📝 Licencja

Projekt udostępniany na licencji MIT. Copyright (c) 2026 Tomasz Majcher. Wszelkie prawa zastrzeżone.
