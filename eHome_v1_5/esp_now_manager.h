/**
 * @file        esp_now_manager.h
 * @brief       Obsługa bezprzewodowej komunikacji ESP-NOW dla projektu eHome
 * @date        2026-06-03
 * @author      Tomasz Majcher
 */

#ifndef ESP_NOW_MANAGER_H
#define ESP_NOW_MANAGER_H

#include <esp_now.h>
#include <WiFi.h>
#include "config.h"
#include "bme_sensor.h"

// =================================================================================
// STRUKTURY I ZMIENNE GLOBALNE
// =================================================================================

/**
 * @brief Struktura pakietu danych przesyłanego przez ESP-NOW.
 *        Musi być dokładnie taka sama w kodzie urządzenia odbierającego!
 */
struct EspNowMessage {
    char deviceID[16]; ///< Identyfikator urządzenia (np. "POKOJ_1"), maks 15 znaków + \0
    float temperature;
    float pressure;
    float humidity;
    uint32_t msgId;    ///< Unikalny identyfikator wiadomości (licznik)
};

inline esp_now_peer_info_t peerInfo;
inline uint32_t espNowMsgCounter = 0;
inline String espNowStatusStr = "Brak wysylki";

// =================================================================================
// DEKLARACJE FUNKCJI (Interfejs dla programisty / Dokumentacja)
// =================================================================================

/**
 * @brief Callback wywoływany automatycznie po zakończeniu transmisji pakietu.
 *        Dostosowany do nowej sygnatury Arduino-ESP32 v3.x.
 */
void onDataSent(const wifi_tx_info_t *tx_info, esp_now_send_status_t status);

/**
 * @brief Inicjalizuje protokół ESP-NOW i rejestruje urządzenie odbiorcze (peer).
 */
void initEspNow();

/**
 * @brief Pobiera dane z geterów BME280, pakuje je do struktury i wysyła przez ESP-NOW.
 */
void sendDataViaEspNow();


// =================================================================================
// DEFINICJE FUNKCJI (Implementacja / Czysty kod)
// =================================================================================

// =============================================================================
// onDataSent() - POPRAWIONA SYGNATURA DLA NOWEGO RDZENIA ESP32
// =============================================================================
void onDataSent(const wifi_tx_info_t *tx_info, esp_now_send_status_t status) 
{
    if (status == ESP_NOW_SEND_SUCCESS) {
        espNowStatusStr = "Wysrano: OK";
        DEBUG_PRINTLN("[ESP-NOW] Dostarczono pakiet pomyślnie.");
    } else {
        espNowStatusStr = "Wysrano: BLAD";
        DEBUG_PRINTLN("[ESP-NOW] Blad dostarczenia pakietu!");
    }
}

// =============================================================================
// initEspNow()
// =============================================================================
void initEspNow() 
{
    DEBUG_PRINTLN("\n--- Inicjalizacja ESP-NOW ---");
    
    if (esp_now_init() != ESP_OK) 
    {
        DEBUG_PRINTLN("[ESP-NOW] Blad inicjalizacji protokołu!");
        return;
    }
    
    esp_now_register_send_cb(onDataSent);
    
    uint8_t peerMac[] = ESP_NOW_PEER_MAC;
    memcpy(peerInfo.peer_addr, peerMac, 6);
    peerInfo.channel = WiFi.channel(); 
    peerInfo.encrypt = false;          
    
    if (esp_now_add_peer(&peerInfo) != ESP_OK) 
    {
        DEBUG_PRINTLN("[ESP-NOW] Nie udalo sie dodac urzadzenia odbiorczego!");
        return;
    }
    
    DEBUG_PRINTLN("[ESP-NOW] Protokół gotowy do pracy.");
}

// =============================================================================
// sendDataViaEspNow()
// =============================================================================
void sendDataViaEspNow() 
{
    EspNowMessage msg;
    
    // Bezpieczne skopiowanie tekstu DEVICE_ID do tablicy char (zapobiega przepełnieniu bufora)
    strncpy(msg.deviceID, DEVICE_ID, sizeof(msg.deviceID) - 1);
    msg.deviceID[sizeof(msg.deviceID) - 1] = '\0'; // Wymuszenie znaku końca stringu
    
    // Pakowanie danych telemetrycznych
    msg.temperature = getTemperature();
    msg.pressure    = getPressure();
    msg.humidity    = getHumidity();
    msg.msgId       = espNowMsgCounter++;
    
    uint8_t peerMac[] = ESP_NOW_PEER_MAC;
    
    // Wysłanie struktury jako surowego bloku bajtów
    esp_err_t result = esp_now_send(peerMac, (uint8_t *) &msg, sizeof(msg));
    
    if (result == ESP_OK) {
        DEBUG_PRINT("[ESP-NOW] Wysłano pakiet z ID: ");
        DEBUG_PRINT_VAR(msg.deviceID);
        DEBUG_PRINTLN(" do kolejki.");
    } else {
        espNowStatusStr = "Blad kolejki";
        DEBUG_PRINTLN("[ESP-NOW] Blad podczas uruchamiania wysylki!");
    }
}

#endif // ESP_NOW_MANAGER_H
