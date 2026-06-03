/**
 * @file        config.h
 * @brief       Plik konfiguracyjny systemu eHome (Makra, Piny, WiFi)
 * @date        2026-06-03
 * @author      Tomasz Majcher (tomasz.majcher@gmail.com)
 * @company     eHome
 * @version     0.6
 * @copyright   Copyright (c) 2026 Tomasz Majcher. Licencja: MIT
 */

#ifndef CONFIG_H
#define CONFIG_H

// =================================================================================
// LOGICZNE DEFINICJE INTERWAŁÓW CZASOWYCH (w milisekundach)
// =================================================================================

// Baza jednostek czasu
#define TIME_1_SEC            (1000ULL)
#define TIME_1_MIN            (60000ULL)

// Czasy krótkie: od 1 do 10 sekund (skok co 1 sekunda)
#define INT_1_SEC             (1  * TIME_1_SEC)
#define INT_2_SEC             (2  * TIME_1_SEC)
#define INT_3_SEC             (3  * TIME_1_SEC)
#define INT_4_SEC             (4  * TIME_1_SEC)
#define INT_5_SEC             (5  * TIME_1_SEC)
#define INT_6_SEC             (6  * TIME_1_SEC)
#define INT_7_SEC             (7  * TIME_1_SEC)
#define INT_8_SEC             (8  * TIME_1_SEC)
#define INT_9_SEC             (9  * TIME_1_SEC)
#define INT_10_SEC            (10 * TIME_1_SEC)

// Czasy średnie: od 15 do 45 sekund (skok co 15 sekund)
#define INT_15_SEC            (15 * TIME_1_SEC)
#define INT_30_SEC            (30 * TIME_1_SEC)
#define INT_45_SEC            (45 * TIME_1_SEC)

// Czasy długie: od 1 do 10 minut (skok co 1 minuta)
#define INT_1_MIN             (1  * TIME_1_MIN)
#define INT_2_MIN             (2  * TIME_1_MIN)
#define INT_3_MIN             (3  * TIME_1_MIN)
#define INT_4_MIN             (4  * TIME_1_MIN)
#define INT_5_MIN             (5  * TIME_1_MIN)
#define INT_10_MIN            (10 * TIME_1_MIN)

// Czasy bardzo długie: wybrane interwały godzinowe
#define INT_30_MIN            (30 * TIME_1_MIN)
#define INT_1_HOUR            (60 * TIME_1_MIN)

// =================================================================================
// TRYB DEBUGOWANIA (Zoptymalizowany pod kątem oszczędzania pamięci RAM)
// =================================================================================

#define ENABLE_DEBUG 1  // Ustaw na 1 aby włączyć Serial, lub na 0 aby wyłączyć

#if ENABLE_DEBUG
  #define DEBUG_BEGIN(speed)  Serial.begin(speed)
  // Makro F() automatycznie przenosi stałe teksty do pamięci Flash, uwalniając RAM
  #define DEBUG_PRINT(x)       Serial.print(F(x))
  #define DEBUG_PRINTLN(x)     Serial.println(F(x))
  
  // Osobne makra dla zmiennych dynamicznych i obiektów (makro F() ich nie obsługuje)
  #define DEBUG_PRINT_VAR(x)   Serial.print(x)
  #define DEBUG_PRINTLN_VAR(x) Serial.println(x)
  #define DEBUG_PRINTF(...)    Serial.printf(__VA_ARGS__)
#else
  #define DEBUG_BEGIN(speed)
  #define DEBUG_PRINT(x)
  #define DEBUG_PRINTLN(x)
  #define DEBUG_PRINT_VAR(x)
  #define DEBUG_PRINTLN_VAR(x)
  #define DEBUG_PRINTF(...)
#endif

// =================================================================================
// KONFIGURACJA SIECI WIFI
// =================================================================================

#define WIFI_SSID             "TwojaSiec"
#define WIFI_PASSWORD         "TwojeHaslo"
#define WIFI_CHECK_INT        INT_1_MIN     ///< Interwał sprawdzania stanu połączenia
#define WIFI_RSSI_INT         INT_10_SEC    ///< Interwał odświeżania ikony zasięgu WiFi


// =================================================================================
// KONFIGURACJA CZUJNIKA BME280 / I2C
// =================================================================================

#define I2C_SDA               27
#define I2C_SCL               22
#define BME_ADDRESS           0x76
#define SEALEVELPRESSURE_HPA  (1013.25)
#define SENSOR_INTERVAL       INT_30_SEC    ///< Interwał pobierania danych środowiskowych

// =================================================================================
// KONFIGURACJA CZASU NTP / RTC
// =================================================================================
#define NTP_SERVER_1          "pool.ntp.org"
#define NTP_SERVER_2          "time.nist.gov"
// Konfiguracja strefy czasowej dla Warszawy (obsługuje automatyczną zmianę czasu letni/zimowy)
#define TZ_WARSAW             "CET-1CEST,M3.5.0,M10.5.0/3"
#define TIME_UPDATE_INT       INT_1_SEC     ///< Częstotliwość odświeżania zegara na ekranie

// =================================================================================
// KONFIGURACJA KARTY SD i LOGOWANIA
// =================================================================================
#define SD_CS_PIN             5             ///< Pin Chip Select dla karty SD w ESP32 CYD
#define LOG_INTERVAL          INT_5_MIN     ///< Interwał zapisu danych na kartę SD

// =================================================================================
// KONFIGURACJA ESP-NOW (Komunikacja bezpośrednia między ESP32)
// =================================================================================
#define EN_SEND_INTERVAL      INT_30_SEC    ///< Interwał wysyłania danych przez ESP-NOW

// Adres MAC drugiego ESP32 (odbiornika) - WPISZ TUTAJ ADRES MAC SWOJEGO DRUGIEGO UKŁADU!
#define ESP_NOW_PEER_MAC      {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF}

// Unikalny identyfikator tego urządzenia w systemie eHome
#define DEVICE_ID             "POKOJ_1"     ///< Maksymalnie 15 znaków

// =================================================================================
// KONFIGURACJA INTELIGENTNEGO PODŚWIETLENIA EKRANU (EKO / TRYB NOCNY)
// =================================================================================
#define BRIGHTNESS_DAY        255           ///< Jasność w dzień (maksymalna: 255)
#define BRIGHTNESS_NIGHT      20            ///< Jasność w nocy (minimalna: 0-255)

#define HOUR_START_DAY        8             ///< Godzina rozpoczęcia dnia (np. 06:00)
#define HOUR_START_NIGHT      20            ///< Godzina rozpoczęcia nocy (np. 22:00)

#define BACKLIGHT_CHANNEL     0             ///< Kanał LEDC dla ESP32
#define BACKLIGHT_FREQ        5000          ///< Częstotliwość PWM w Hz
#define BACKLIGHT_RES         8             ///< Rozdzielczość PWM (8 bitów = 0-255)

// =================================================================================
// KONFIGURACJA WBUDOWANEGO FOTOREZYSTORA (LDR)
// =================================================================================
#define CYD_LDR_PIN           34            // Twój działający pin fotorezystora
#define LDR_DARK_THRESHOLD    900           // PRÓG: dzień < 900 < noc

// =================================================================================
// KONFIGURACJA WBUDOWANEJ DIODY RGB LED
// =================================================================================
#define CYD_LED_R             4             // Pin koloru czerwonego
#define CYD_LED_G             16            // Pin koloru zielonego
#define CYD_LED_B             17            // Pin koloru niebieskiego

// =================================================================================
// SYSTEMOWA OCHRONA TERMICZNA CPU
// =================================================================================
#define CPU_HOT_THRESHOLD     75.0f         ///< Temperatura ostrzegawcza (°C)
#define CPU_MAX_THRESHOLD     85.0f         ///< Temperatura krytyczna - awaryjne wyłączenie (°C)

// =================================================================================
// SEKCJA ODŚWIEŻANIA KALENDARZA IMIENIN NA SERIAL
// =================================================================================
#define CALENDAR_SERIAL_INT   INT_10_MIN    ///< Interwał rzutu imienin na Serial Monitor



#endif // CONFIG_H
