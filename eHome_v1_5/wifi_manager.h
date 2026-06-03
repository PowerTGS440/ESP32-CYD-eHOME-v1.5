/**
 * @file        wifi_manager.h
 * @brief       Obsługa połączenia WiFi z auto-reconnect i sygnalizacją RGB LED
 * @date        2026-06-03
 * @author      Tomasz Majcher
 */

#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <WiFi.h>
#include "config.h"

// =================================================================================
// ZMIENNE GLOBALNE
// =================================================================================

inline String deviceMac = "";           
inline unsigned long lastWiFiCheck = 0; 
inline bool ledStateToggle = false;     ///< Zmienna pomocnicza do migania diodą

// =================================================================================
// DEKLARACJE FUNKCJI (Interfejs dla programisty / Dokumentacja)
// =================================================================================

void initWiFi();
void handleWiFi();
void updateMacAddress();
String getMacAddress();


// =================================================================================
// DEFINICJE FUNKCJI (Implementacja / Czysty kod)
// =================================================================================

// =============================================================================
// initWiFi()
// =============================================================================
void initWiFi() 
{
    // Konfiguracja pinów diody RGB jako wyjścia
    pinMode(CYD_LED_R, OUTPUT);
    pinMode(CYD_LED_G, OUTPUT);
    pinMode(CYD_LED_B, OUTPUT);
    
    // Gaszenie wszystkich kolorów na starcie (Stan HIGH = zgaszona)
    digitalWrite(CYD_LED_R, HIGH);
    digitalWrite(CYD_LED_G, HIGH);
    digitalWrite(CYD_LED_B, HIGH);

    DEBUG_PRINTLN("\n--- Inicjalizacja WiFi ---");
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    DEBUG_PRINT("Łączenie z siecią: ");
    DEBUG_PRINTLN(WIFI_SSID);

    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 20) {
        delay(500);
        // Podświetlenie na czerwono podczas próby łączenia
        digitalWrite(CYD_LED_R, LOW); 
        delay(50);
        digitalWrite(CYD_LED_R, HIGH);
        DEBUG_PRINT_VAR(".");
        attempts++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        DEBUG_PRINTLN("\n[WiFi] Połączono pomyślnie!");
        DEBUG_PRINT("[WiFi] Adres IP: ");
        DEBUG_PRINTLN_VAR(WiFi.localIP());
        
        // Sukces: Zapalenie koloru zielonego na stałe (G = LOW, R/B = HIGH)
        digitalWrite(CYD_LED_G, LOW);
        digitalWrite(CYD_LED_R, HIGH);
        digitalWrite(CYD_LED_B, HIGH);
    } else {
        DEBUG_PRINTLN("\n[WiFi] Nie udało się połączyć przy starcie. Reconnect działa w tle.");
    }
}

// =============================================================================
// handleWiFi()
// =============================================================================
void handleWiFi() 
{
    unsigned long currentMillis = millis();
    
    if (currentMillis - lastWiFiCheck >= WIFI_CHECK_INT) 
    {
        lastWiFiCheck = currentMillis;
        
        if (WiFi.status() != WL_CONNECTED) 
        {
            DEBUG_PRINTLN("[WiFi] Połączenie utracone! Próba ponownego łączenia...");
            WiFi.disconnect();
            WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
            
            // Brak połączenia: gasimy zielony, przechodzimy w stan awarii
            digitalWrite(CYD_LED_G, HIGH);
        }
        else
        {
            // Połączenie poprawne: pilnujemy stałego zielonego koloru
            digitalWrite(CYD_LED_G, LOW);
            digitalWrite(CYD_LED_R, HIGH);
            digitalWrite(CYD_LED_B, HIGH);
        }
    }
    
    // NIEBLOKUJĄCE MIGANIA NA CZERWONO: Wykonuje się tylko, gdy sieć jest zerwana
    if (WiFi.status() != WL_CONNECTED)
    {
        // Sprawdzamy czas szybciej (miganie co 500 ms) za pomocą prostej aritmetiki czasu
        if ((currentMillis / 500) % 2 == 0) {
            digitalWrite(CYD_LED_R, LOW); // Zapal czerwony
        } else {
            digitalWrite(CYD_LED_R, HIGH); // Zgaś czerwony
        }
    }
}

// =============================================================================
// updateMacAddress()
// =============================================================================
void updateMacAddress() 
{
    deviceMac = WiFi.macAddress();
    DEBUG_PRINT("[SYSTEM] Adres MAC urządzenia: ");
    DEBUG_PRINT_VAR(deviceMac);
    DEBUG_PRINTLN("");
}

// =============================================================================
// getMacAddress()
// =============================================================================
String getMacAddress() 
{
    deviceMac = WiFi.macAddress();
    DEBUG_PRINT("[SYSTEM] Pobrano adres MAC: ");
    DEBUG_PRINT_VAR(deviceMac);
    DEBUG_PRINTLN("");
    return deviceMac;
}

#endif // WIFI_MANAGER_H
