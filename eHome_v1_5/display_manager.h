/**
 * @file        display_manager.h
 * @brief       Obsługa ekranu TFT ILI9341 dla projektu eHome z PWM i czujnikiem LDR
 * @date        2026-06-03
 * @author      Tomasz Majcher
 */

#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <SPI.h>
#include <TFT_eSPI.h>
#include "config.h"
#include "bme_sensor.h"
#include "wifi_manager.h"
#include "time_manager.h"

// =================================================================================
// ZMIENNE GLOBALNE
// =================================================================================

inline TFT_eSPI tft = TFT_eSPI(); ///< Instancja sterownika ekranu TFT
inline int currentBrightness = -1; ///< Aktualny stan jasności ekranu

// =================================================================================
// DEKLARACJE FUNKCJI (Interfejs dla programisty / Dokumentacja)
// =================================================================================

void initDisplay();
void drawInterfaceSkeleton();
void updateDisplayValues();
void handleBacklight();
void drawWiFiIcon(int x, int y);


// =================================================================================
// DEFINICJE FUNKCJI (Implementacja / Czysty kod)
// =================================================================================

// =============================================================================
// initDisplay()
// =============================================================================
void initDisplay() 
{
    tft.init();
    tft.setRotation(1); 
    tft.fillScreen(TFT_BLACK);
    
    // 1. Konfiguracja sprzętowego PWM dla podświetlenia ekranu (GPIO21)
    //    W rdzeniu v3.x ta funkcja sama automatycznie mapuje pin i uruchamia zegar PWM
    ledcAttachChannel(TFT_BL, BACKLIGHT_FREQ, BACKLIGHT_RES, BACKLIGHT_CHANNEL);
    
    // 2. Bezpieczne ustawienie jasności startowej (na pin) bez zawieszania procesora
    ledcWrite(TFT_BL, BRIGHTNESS_DAY);
    currentBrightness = BRIGHTNESS_DAY;
    
    // 3. Konfiguracja pinu fotorezystora
    pinMode(CYD_LDR_PIN, INPUT);
    
    drawInterfaceSkeleton();
}

// =============================================================================
// drawInterfaceSkeleton()
// =============================================================================
void drawInterfaceSkeleton() 
{
    tft.fillScreen(TFT_BLACK);
    
    // Nagłówek Górny (Belka systemowa)
    tft.fillRect(0, 0, 320, 30, TFT_NAVY);
    
    // Separatory i ramki interfejsu (linie podziału)
    tft.drawFastHLine(0, 30, 320, TFT_DARKGREY);
    tft.drawFastHLine(0, 210, 320, TFT_DARKGREY);
    
    // Statyczne opisy dla danych z czujnika BME
    tft.setTextColor(TFT_LIGHTGREY, TFT_BLACK);
    tft.setTextDatum(TL_DATUM); 
    
    tft.drawString("Temperatura:", 15, 50, 4);
    tft.drawString("Cisnienie:", 15, 90, 4);
    tft.drawString("Wilgotnosc:", 15, 130, 4);
    tft.drawString("Wysokosc:", 15, 170, 4);
}

// =============================================================================
// updateDisplayValues()
// =============================================================================
void updateDisplayValues() 
{
    // --- ODŚWIEŻANIE ZEGARA I DATY NA GÓRNYM PASKU ---
    tft.setTextColor(TFT_WHITE, TFT_NAVY);
    
    tft.setTextDatum(TL_DATUM);
    tft.drawString(getFormattedDate(), 10, 7, 2);
    
    tft.setTextDatum(TL_DATUM);
    tft.drawString(getFormattedTime(), 245, 7, 2);
    
    // --- ODŚWIEŻANIE PARAMETRÓW ŚRODOWISKOWYCH BME ---
    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.setTextDatum(TR_DATUM); 
    
    tft.drawFloat(getTemperature(), 1, 260, 50, 4);
    tft.drawString("*C", 300, 50, 4);
    
    tft.drawFloat(getPressure(), 1, 260, 90, 4);
    tft.drawString("hPa", 305, 90, 4);
    
    tft.drawFloat(getHumidity(), 1, 260, 130, 4);
    tft.drawString("%", 295, 130, 4);

    tft.drawFloat(getAltitude(), 0, 260, 170, 4);
    tft.drawString("m", 295, 170, 4);
    
    // Dolny pasek statusowy (MAC)
    tft.setTextDatum(BC_DATUM);
    tft.setTextColor(TFT_ORANGE, TFT_BLACK);
    String footerText = "MAC: " + deviceMac;
    tft.drawString(footerText, 160, 235, 2);
}

// =============================================================================
// handleBacklight()
// =============================================================================
void handleBacklight() 
{
    // Odczyt surowej wartości analogowej z fotorezystora
    int ldrValue = analogRead(CYD_LDR_PIN);
    int targetBrightness = BRIGHTNESS_DAY;

    // DEBUG_PRINT(" | LDR ");
    // DEBUG_PRINTLN_VAR(ldrValue);
    
    // Jeśli wartość przekracza próg (ciemno)
    if (ldrValue >= LDR_DARK_THRESHOLD) 
    {
        targetBrightness = BRIGHTNESS_NIGHT;
    }
    
    // Logowanie wartości pomiarowej do Serial Monitora przy KAŻDEJ zmianie
    if (currentBrightness != targetBrightness) 
    {
        currentBrightness = targetBrightness;
        
        // Wymuszenie zapisu PWM bezpośrednio na fizyczny pin podświetlenia ekranu
        ledcWrite(TFT_BL, currentBrightness);
        
        DEBUG_PRINT("[LDR] Zmiana oswietlenia! RAW: ");
        DEBUG_PRINT_VAR(ldrValue);
        DEBUG_PRINT(" | Ustawiono jasnosc: ");
        DEBUG_PRINTLN_VAR(currentBrightness);
    }
}

// =============================================================================
// drawWiFiIcon()
// =============================================================================
void drawWiFiIcon(int x, int y) 
{
    tft.fillRect(x, y - 15, 22, 17, TFT_NAVY);
    
    if (WiFi.status() != WL_CONNECTED) 
    {
        tft.drawLine(x, y - 12, x + 12, y, TFT_RED);
        tft.drawLine(x + 12, y - 12, x, y, TFT_RED);
        return;
    }
    
    long rssi = WiFi.RSSI();
    int bars = 0;
    
    if (rssi > -60)      bars = 4;
    else if (rssi > -70) bars = 3;
    else if (rssi > -80) bars = 2;
    else if (rssi > -90) bars = 1;
    
    tft.fillRect(x,      y - 3,  3, 3,  (bars >= 1) ? TFT_CYAN : TFT_DARKCYAN);
    tft.fillRect(x + 5,  y - 7,  3, 7,  (bars >= 2) ? TFT_CYAN : TFT_DARKCYAN);
    tft.fillRect(x + 10, y - 11, 3, 11, (bars >= 3) ? TFT_CYAN : TFT_DARKCYAN);
    tft.fillRect(x + 15, y - 15, 3, 15, (bars >= 4) ? TFT_CYAN : TFT_DARKCYAN);
}

#endif // DISPLAY_MANAGER_H
