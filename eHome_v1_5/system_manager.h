/**
 * @file        system_manager.h
 * @brief       Narzędzia diagnostyki sprzętowej i ochrony termicznej procesora ESP32
 * @date        2026-06-03
 * @author      Tomasz Majcher
 */

#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include <Arduino.h>
#include "config.h"

// =================================================================================
// DEKLARACJE FUNKCJI (Interfejs dla programisty / Dokumentacja)
// =================================================================================

/**
 * @brief Pobiera aktualną temperaturę rdzenia krzemowego procesora ESP32.
 * @return float Temperatura w stopniach Celsjusza (°C).
 */
float getCpuTemperature();

/**
 * @brief Monitoruje temperaturę krzemu w tle. W razie potrzeby uruchamia alarm RGB lub procedurę ochronną.
 */
void handleSystemProtection();


// =================================================================================
// DEFINICJE FUNKCJI (Implementacja / Czysty kod)
// =================================================================================

// =============================================================================
// getCpuTemperature()
// =============================================================================
float getCpuTemperature() 
{
    // Wbudowana w rdzeń Espressif funkcja odczytu wewnętrznego sensora struktury
    return temperatureRead();
}

// =============================================================================
// handleSystemProtection()
// =============================================================================
void handleSystemProtection() 
{
    float currentCpuTemp = getCpuTemperature();
    
    // 1. POZIOM KRYTYCZNY (Awaryjne odłączenie obciążeń)
    if (currentCpuTemp >= CPU_MAX_THRESHOLD) 
    {
        // Wyłączenie podświetlenia ekranu (PWM na 0) - redukcja wydzielania ciepła o ok. 30%
        ledcWrite(TFT_BL, 0); 
        
        // Alarm wizualny: Tylko czerwona dioda (Zielona/Niebieska gasną)
        digitalWrite(CYD_LED_G, HIGH);
        digitalWrite(CYD_LED_B, HIGH);
        digitalWrite(CYD_LED_R, LOW);
        
        DEBUG_PRINT("[KRYTYCZNY] CPU OVERHEAT! Temp: ");
        DEBUG_PRINT_VAR(currentCpuTemp);
        DEBUG_PRINTLN(" *C. Wygaszono ekran w celu schłodzenia!");
        return;
    }
    
    // 2. POZIOM OSTRZEGAWCZY (Modyfikacja koloru diody RGB)
    if (currentCpuTemp >= CPU_HOT_THRESHOLD) 
    {
        // Zapalenie koloru ŻÓŁTEGO (Mieszamy Czerwony + Zielony, logika odwrócona LOW)
        digitalWrite(CYD_LED_R, LOW);
        digitalWrite(CYD_LED_G, LOW);
        digitalWrite(CYD_LED_B, HIGH);
        
        DEBUG_PRINT("[OSTRZEŻENIE] Wysoka temperatura rdzenia: ");
        DEBUG_PRINT_VAR(currentCpuTemp);
        DEBUG_PRINTLN(" *C");
    }
}

#endif // SYSTEM_MANAGER_H
