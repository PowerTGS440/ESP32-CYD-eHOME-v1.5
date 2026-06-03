/**
 * @file        time_manager.h
 * @brief       Narzędzie synchronizacji czasu NTP oraz obsługi wbudowanego RTC ESP32
 * @date        2026-06-03
 * @author      Tomasz Majcher
 */

#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include <time.h>
#include "config.h"

// =================================================================================
// ZMIENNE GLOBALNE
// =================================================================================

inline String currentFormattedTime = "00:00";     ///< Globalny bufor na godzinę i minuty
inline String currentFormattedDate = "01.01.2026"; ///< Globalny bufor na datę

// =================================================================================
// DEKLARACJE FUNKCJI (Interfejs dla programisty / Dokumentacja)
// =================================================================================

/**
 * @brief Inicjalizuje synchronizację NTP i ustawia strefę czasową dla wbudowanego RTC.
 */
void initTimeEngine();

/**
 * @brief Pobiera aktualny czas z wewnętrznego RTC i aktualizuje zmienne globalne tekstu.
 */
void updateTimeAndDateStrings();

/**
 * @brief Zwraca aktualnie przetworzoną godzinę z minutami.
 * @return String Tekst w formacie HH:MM.
 */
String getFormattedTime();

/**
 * @brief Zwraca aktualnie przetworzoną datę.
 * @return String Tekst w formacie DD.MM.YYYY.
 */
String getFormattedDate();


// =================================================================================
// DEFINICJE FUNKCJI (Implementacja / Czysty kod)
// =================================================================================

// =============================================================================
// initTimeEngine()
// =============================================================================
void initTimeEngine() 
{
    DEBUG_PRINTLN("\n--- Inicjalizacja Czasu NTP/RTC ---");
    
    // Konfiguracja strefy czasowej i serwerów NTP dla wbudowanego RTC ESP32
    configTzTime(TZ_WARSAW, NTP_SERVER_1, NTP_SERVER_2);
    
    DEBUG_PRINTLN("[RTC] Oczekiwanie na synchronizację czasu z serwerem NTP...");
    
    // Krótkie oczekiwanie na pobranie pierwszej prawidłowej struktury czasu (max 5 sek)
    struct tm timeinfo;
    int attempts = 0;
    while (!getLocalTime(&timeinfo) && attempts < 10) {
        delay(500);
        DEBUG_PRINT_VAR(".");
        attempts++;
    }
    
    if (getLocalTime(&timeinfo)) {
        DEBUG_PRINTLN("\n[RTC] Czas zsynchronizowany pomyślnie!");
    } else {
        DEBUG_PRINTLN("\n[RTC] Błąd NTP. Zegar sprzętowy wystartuje od daty domyślnej.");
    }
    
    // Pierwsza generacja ciągów znaków
    updateTimeAndDateStrings();
}

// =============================================================================
// updateTimeAndDateStrings()
// =============================================================================
void updateTimeAndDateStrings() 
{
    struct tm timeinfo;
    
    // Pobranie czasu bezpośrednio ze sprzętowego, wewnętrznego RTC procesora
    if (!getLocalTime(&timeinfo)) {
        return; 
    }
    
    char bufTime[6];  // "HH:MM\0"
    char bufDate[11]; // "DD.MM.YYYY\0"
    
    // Formatowanie niskopoziomowe zgodne ze specyfikacją języka C
    strftime(bufTime, sizeof(bufTime), "%H:%M", &timeinfo);
    strftime(bufDate, sizeof(bufDate), "%d.%m.%Y", &timeinfo);
    
    currentFormattedTime = String(bufTime);
    currentFormattedDate = String(bufDate);
}

// =============================================================================
// getFormattedTime()
// =============================================================================
String getFormattedTime() 
{
    return currentFormattedTime;
}

// =============================================================================
// getFormattedDate()
// =============================================================================
String getFormattedDate() 
{
    return currentFormattedDate;
}

#endif // TIME_MANAGER_H
