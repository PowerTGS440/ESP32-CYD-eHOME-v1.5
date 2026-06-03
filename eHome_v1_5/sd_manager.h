/**
 * @file        sd_manager.h
 * @brief       Obsługa karty SD z rotacją plików miesięcznych dla projektu eHome
 * @date        2026-06-03
 * @author      Tomasz Majcher
 */

#ifndef SD_MANAGER_H
#define SD_MANAGER_H

#include <FS.h>
#include <SD.h>
#include <time.h>
#include "config.h"
#include "bme_sensor.h"
#include "time_manager.h"

// =================================================================================
// DEKLARACJE FUNKCJI
// =================================================================================
void mountSDCard();
String getMonthlyLogPath();
void logDataToSD();

// =================================================================================
// DEFINICJE FUNKCJI
// =================================================================================

void mountSDCard() 
{
    DEBUG_PRINTLN("\n--- Inicjalizacja Karty SD ---");
    if (!SD.begin(SD_CS_PIN)) 
    {
        DEBUG_PRINTLN("[SD] Nie udało się zamontować karty SD! Sprawdź czy jest włożona.");
        return;
    }
    DEBUG_PRINTLN("[SD] Karta SD zamontowana pomyślnie.");
}

String getMonthlyLogPath() 
{
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo)) 
    {
        return String("/log_fallback.csv");
    }
    char pathBuf[32];
    snprintf(pathBuf, sizeof(pathBuf), "/log_%04d_%02d.csv", timeinfo.tm_year + 1900, timeinfo.tm_mon + 1);
    return String(pathBuf);
}

void logDataToSD() 
{
    String currentLogPath = getMonthlyLogPath();
    
    if (!SD.exists(currentLogPath)) 
    {
        DEBUG_PRINT("[SD] Tworzenie nowego pliku miesięcznego: ");
        DEBUG_PRINTLN_VAR(currentLogPath);
        
        File newFile = SD.open(currentLogPath, FILE_WRITE);
        if (newFile) 
        {
            newFile.println("Data;Godzina;Temperatura_C;Cisnienie_hPa;Wilgotnosc_proc;Wysokosc_m");
            newFile.close();
        }
        else 
        {
            DEBUG_PRINTLN("[SD] Blad tworzenia nagłówka w nowym pliku!");
            return;
        }
    }
    
    File logFile = SD.open(currentLogPath, FILE_APPEND);
    if (logFile) 
    {
        logFile.print(getFormattedDate());
        logFile.print(";");
        logFile.print(getFormattedTime());
        logFile.print(";");
        logFile.print(getTemperature(), 1);
        logFile.print(";");
        logFile.print(getPressure(), 1);
        logFile.print(";");
        logFile.print(getHumidity(), 1);
        logFile.print(";");
        logFile.print(getAltitude(), 0);
        logFile.println(); 
        
        logFile.close();
        DEBUG_PRINT("[SD] Zapisano rekord do pliku: ");
        DEBUG_PRINTLN_VAR(currentLogPath);
    } 
    else 
    {
        DEBUG_PRINTLN("[SD] Błąd otwarcia pliku do zapisu danych!");
    }
}

#endif // SD_MANAGER_H
