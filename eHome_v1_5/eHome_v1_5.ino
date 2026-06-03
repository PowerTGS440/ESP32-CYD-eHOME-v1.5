/**
 * @file        eHome_v1_1.ino
 * @brief       Główny plik systemu automatyki domowej eHome
 * @details     ESP32-2432S028R + bme/bmp280 + WiFi Reconnect (RAM Optimized)
 *              Time + RTC + SD Card + TFT + FileWebServer
 *
 * 
 * @author      Tomasz Majcher (tomasz.majcher@gmail.com)
 * @company     eHome
 * @version     1.5 STABLE

- * @date        2026-06-03
 
 * @copyright   Copyright (c) 2026 Tomasz Majcher. Wszelkie prawa zastrzeżone.
 *              Licencja: MIT
 * 
 * @note        4MB FLASH, CPU 240Mhz, Partycja HugeAPP, PSRam Disabled
 * @warning     Czujnik BME/BMP280 podpięty do GPIO22 GPIO27 TwoWire
 *
 * =================================================================================
 * HISTORIA ZMIAN (Zarządzanie wersjami / Changelog)
 * =================================================================================
 * Data       | Wersja | Autor           | Opis zmian
 * -----------|--------|-----------------|------------------------------------------
 * 2026-06-01 |  0.1   | Tomasz Majcher  | obsługa czujnika BME/BMP280, struktura danych
 *            |        |                 | gettery, WiFi reconnect oraz plik config.h
 * -----------|--------|-----------------|------------------------------------------
 * 2026-06-01 |  0.2   | Tomasz Majcher  | optymalizacja kodu
 * -----------|--------|-----------------|------------------------------------------
 * 2026-06-01 |  0.3   | Tomasz Majcher  | dodana obsługa wyświetlacza CYD
 *            |        |                 | wyswietlanie danych z czujnika BMP280
 * -----------|--------|-----------------|------------------------------------------
 * 2026-06-01 |  0.4   | Tomasz Majcher  | dodana time_manager, dodano pasek górny
 *            |        |                 | z aktualna datą i czasem
 * -----------|--------|-----------------|------------------------------------------
 * 2026-06-02 |  0.5   | Tomasz Majcher  | dodana obsługę czytnika kart SD
 *            |        |                 | i logowanie z BMP280 do pliku csv
 *            |        |                 | oraz obsługa protokołu ESPNOW
 * -----------|--------|-----------------|------------------------------------------
 * 2026-06-02 |  0.6   | Tomasz Majcher  | dodano przyciemnianie ekranu nocą
 *            |        |                 | oraz wskaźnik sygnału WiFi na pasku górnym
 * -----------|--------|-----------------|------------------------------------------
 * 2026-06-02 |  0.7   | Tomasz Majcher  | optymalizacja zapisu danych na kartę SD
 *            |        |                 | z podziałem na pliki miesiaca
 * -----------|--------|-----------------|------------------------------------------
 * 2026-06-02 |  0.8   | Tomasz Majcher  | dodanie obsługę SD File Web Server 
 *            |        |                 | pod adresem 192.168.xxx.xxx sieci lokalnej
 * -----------|--------|-----------------|------------------------------------------
 * 2026-06-03 |  0.9   | Tomasz Majcher  | dodanie obsługi diody RBG dla WIFI
 *            |        |                 | dodanie obsługi czujnika LDR 
 * -----------|--------|-----------------|------------------------------------------
 * 2026-06-03 |  1.0   | Tomasz Majcher  | dodanie obsługi czujnika temp. CPU
 *            |        |                 | z ostrzezeniem o przegrzaniu
 * -----------|--------|-----------------|------------------------------------------
 * 2026-06-03 |  1.1   | Tomasz Majcher  | dodanie calendar_data z dniami imienin
 *            |        |                 | i wyświetlanie na Serial Monitor
 * -----------|--------|-----------------|------------------------------------------
 * 2026-06-03 |  1.2   | Tomasz Majcher  | aktualizacja calendar_manager 
 *            |        |                 | wyświetlanie na stronie WWW imienin
 * -----------|--------|-----------------|------------------------------------------
 * 2026-06-03 |  1.3   | Tomasz Majcher  | dodanie holidays_data 
 *            |        |                 | i wyświetlanie na Serial Monitor
 * -----------|--------|-----------------|------------------------------------------
 * 2026-06-03 |  1.4   | Tomasz Majcher  | aktualizacja calendar_manager 
 *            |        |                 | wyświetlanie na stronie WWW świąt
 * -----------|--------|-----------------|------------------------------------------
 * 2026-06-03 |  1.5   | Tomasz Majcher  | testowanie stabilności
 * =================================================================================
 *
 *
 * =================================================================================
 * UŻYTE BIBLIOTEKI (SPIS I DOKUMENTACJA)
 * =================================================================================
 * 1. Wire (Wbudowana w rdzeń ESP32)
 *    - Opis: Obsługa sprzętowej magistrali I2C do komunikacji z czujnikiem.
 * 
 * 2. WiFi (Wbudowana w rdzeń ESP32)
 *    - Opis: Zarządzanie połączeniem sieciowym, pobieranie MAC oraz RSSI.
 * 
 * 3. WebServer (Wbudowana w rdzeń ESP32)
 *    - Opis: Oficjalny serwer HTTP do bezprzewodowego pobierania logów.
 * 
 * 4. FS & SD (Wbudowane w rdzeń ESP32)
 *    - Opis: Obsługa systemu plików i fizyczny zapis na kartę pamięci SD.
 * 
 * 5. Adafruit BME280 Library (Zewnętrzna)
 *    - Opis: Odczyt parametrów środowiskowych z czujnika Bosch BME280.
 *    - Link: https://github.com
 * 
 * 6. Adafruit Unified Sensor (Zewnętrzna - Wymagana przez BME280)
 *    - Opis: Wspólna warstwa abstrakcji dla czujników firmy Adafruit.
 *    - Link: https://github.com
 * 
 * 7. TFT_eSPI (Zewnętrzna)
 *    - Opis: Szybki, zoptymalizowany pod ESP32 sterownik ekranu ILI9341.
 *    - Link: https://github.com
 * 
 */

#include "config.h"
#include "bme_sensor.h"
#include "wifi_manager.h"
#include "time_manager.h"
#include "display_manager.h"
#include "sd_manager.h"
#include "esp_now_manager.h"
#include "web_server_manager.h" // Dołączenie odseparowanego modułu serwera Web
#include "system_manager.h"     // Dołączamy nowy odseparowany moduł diagnostyczny
#include "calendar_manager.h"   // Dołączenie kalendarza PROGMEM

unsigned long lastSensorRead  = 0;
unsigned long lastTimeUpdate  = 0;
unsigned long lastSdWrite     = 0;
unsigned long lastEspNowWrite = 0;
unsigned long lastRssiUpdate  = 0;
unsigned long lastCalendarLog = 0; // Licznik cyklicznego rzutu imienin na Serial


// =============================================================================
// setup()
// =============================================================================
void setup() 
{
    // Uruchomienie Seriala z prędkością zdefiniowaną w makrze
    DEBUG_BEGIN(115200);

    DEBUG_PRINTLN("=======================================");
    DEBUG_PRINTLN("eHome System Booting...                ");
    DEBUG_PRINTLN("=======================================");

    // Inicjalizacja czujnika środowiskowego
    if (!initBMESensor()) 
    {
        DEBUG_PRINTLN("[BŁĄD] Nie znaleziono czujnika BME280!");
        while (1);  // Blokada w przypadku awarii krytycznej sprzętu
    }
    DEBUG_PRINTLN("[BME280] Czujnik zainicjalizowany pomyślnie.");

    // Inicjalizacja bezprzewodowej sieci strukturalnej
    initWiFi();

    // Zapisuje w zmiennej inline String deviceMac adres sieciowy urządzenia
    updateMacAddress();

    // Inicjalizacja silnika czasu NTP i wbudowanego RTC
    initTimeEngine();

    // Inicjalizacja i narysowanie interfejsu graficznego na ekranie CYD
    initDisplay();

    // Inicjalizacja karty SD (współdzielącej SPI z wyświetlaczem)
    mountSDCard(); 
    
    // Inicjalizacja bezprzewodowej komunikacji bezpośredniej ESP-NOW
    initEspNow();

    // Uruchomienie wbudowanego serwera sieciowego HTTP (po montażu SD i połączeniu z WiFi)
    initWebServer();

    // Pierwsze pobranie danych i rysowanie interfejsu
    updateBmeData();
    updateDisplayValues();
    drawWiFiIcon(295, 22);

    // Wymuś natychmiastowe pobranie i zrzut imienin przy rozruchu stacji
    handleCalendarSerial(); 

    // Wymuszenie natychmiastowego utworzenia i zapisu pliku miesięcznego
    logDataToSD();

    DEBUG_PRINTLN("\nUruchamianie pętli głównej programu...");
}

// =============================================================================
// loop()
// =============================================================================
void loop() 
{
    handleWebServer();

    unsigned long currentMillis = millis();
    handleWiFi();

    // 1. Pętla czasu (co 1 sekundę)
    if (currentMillis - lastTimeUpdate >= TIME_UPDATE_INT) 
    {
        lastTimeUpdate = currentMillis;
        updateTimeAndDateStrings();
        handleBacklight();
        updateDisplayValues(); 
    }

    // 2. Pętla wskaźnika RSSI WiFi (co 10 sekund)
    if (currentMillis - lastRssiUpdate >= WIFI_RSSI_INT) 
    {
        lastRssiUpdate = currentMillis;
        drawWiFiIcon(295, 22);
    }

    // 3. Pętla odczytu parametrów oraz ochrony termicznej krzemu (co 30 sekund)
    if (currentMillis - lastSensorRead >= SENSOR_INTERVAL) 
    {
        lastSensorRead = currentMillis;
        
        // Pomiar otoczenia
        updateBmeData();
        printValues();
        
        // Nadzór nad zdrowiem procesora ze struktury system_manager.h
        handleSystemProtection();
    }

    // 4. Pętla zapisu na kartę SD (co 5 minut)
    if (currentMillis - lastSdWrite >= LOG_INTERVAL) 
    {
        lastSdWrite = currentMillis;
        logDataToSD();
    }

    // 5. Wysyłka danych przez ESP-NOW (co 30 sekund)
    if (currentMillis - lastEspNowWrite >= EN_SEND_INTERVAL) 
    {
        lastEspNowWrite = currentMillis;
        sendDataViaEspNow();
    }

    // 6. Cykliczna pętla wypisywania solenizantów na Serial Monitor (np. co 10 minut)
    if (currentMillis - lastCalendarLog >= CALENDAR_SERIAL_INT) 
    {
        lastCalendarLog = currentMillis;
        handleCalendarSerial();
    }
}