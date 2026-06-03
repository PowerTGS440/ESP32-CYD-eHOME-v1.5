/**
 * @file        calendar_manager.h
 * @brief       Menedżer jednoczesnego rzutu imienin i świąt z pamięci FLASH na Serial
 * @date        2026-06-03
 * @author      Tomasz Majcher
 */

#ifndef CALENDAR_MANAGER_H
#define CALENDAR_MANAGER_H

#include <time.h>
#include "config.h"
#include "calendar_data.h"
#include "holidays_data.h" // Dołączenie nowej bazy świąt z PROGMEM
#include "time_manager.h"

// =================================================================================
// ZMIENNE GLOBALNE RAM (Dostępne dla portu Serial i serwera WWW)
// =================================================================================

inline String todayNames = "Brak danych";   ///< Zmienna przechowująca dzisiejsze imieniny
inline String todayHoliday = "Brak świąt";  ///< Zmienna przechowująca dzisiejsze święta

// =================================================================================
// DEKLARACJE FUNKCJI (Interfejs dla programisty)
// =================================================================================

/**
 * @brief Przeszukuje obie bazy PROGMEM, aktualizuje RAM i cyklicznie loguje dane na Serial.
 */
void handleCalendarSerial();


// =================================================================================
// DEFINICJE FUNKCJI (Implementacja / Czysty kod)
// =================================================================================

// =============================================================================
// handleCalendarSerial()
// =============================================================================
void handleCalendarSerial() 
{
    struct tm timeinfo;
    // Jeśli wbudowany zegar RTC nie ma jeszcze zsynchronizowanego czasu z NTP, pomijamy krok
    if (!getLocalTime(&timeinfo)) 
    {
        return;
    }

    int currentDay = timeinfo.tm_mday;
    int currentMonth = timeinfo.tm_mon + 1;

    // -------------------------------------------------------------------------
    // 1. PRZESZUKIWANIE BAZY IMIENIN (calendar_data.h)
    // -------------------------------------------------------------------------
    int i = 0;
    todayNames = "Brak wpisu";
    while (true) 
    {
        uint8_t m = pgm_read_byte(&(eHomeCalendar[i].month));
        uint8_t d = pgm_read_byte(&(eHomeCalendar[i].day));

        if (m == 0 && d == 0) break; // Strażnik końca tablicy imienin

        if (m == currentMonth && d == currentDay) 
        {
            const char* nPtr = (const char*)pgm_read_ptr(&(eHomeCalendar[i].names));
            if (nPtr) todayNames = String(nPtr);
            break; 
        }
        i++;
    }

    // -------------------------------------------------------------------------
    // 2. PRZESZUKIWANIE BAZY ŚWIĄT NIETYPOWYCH (holidays_data.h)
    // -------------------------------------------------------------------------
    int j = 0;
    todayHoliday = "Brak święta nietypowego";
    while (true) 
    {
        uint8_t m = pgm_read_byte(&(eHomeHolidays[j].month));
        uint8_t d = pgm_read_byte(&(eHomeHolidays[j].day));

        if (m == 0 && d == 0) break; // Strażnik końca tablicy świąt

        if (m == currentMonth && d == currentDay) 
        {
            const char* hPtr = (const char*)pgm_read_ptr(&(eHomeHolidays[j].holiday));
            if (hPtr) todayHoliday = String(hPtr);
            break; 
        }
        j++;
    }

    // -------------------------------------------------------------------------
    // 3. WSPÓLNY, CYKLICZNY ZRZUT LOGÓW NA SERIAL MONITOR
    // -------------------------------------------------------------------------
    DEBUG_PRINTLN("\n==================================================");
    DEBUG_PRINT("[INFO] Aktualny czas stacji: ");
    DEBUG_PRINTLN_VAR(getFormattedDate() + " " + getFormattedTime());
    DEBUG_PRINT("[IMIENINY] Dzisiaj świętują: ");
    DEBUG_PRINTLN_VAR(todayNames);
    DEBUG_PRINT("[KALENDARZ] Dzisiejsze święta: ");
    DEBUG_PRINTLN_VAR(todayHoliday);
    DEBUG_PRINTLN("==================================================");
}

#endif // CALENDAR_MANAGER_H
