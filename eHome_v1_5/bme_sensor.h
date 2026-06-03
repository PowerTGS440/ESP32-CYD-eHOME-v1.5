/**
 * @file        bme_sensor.h
 * @brief       Obsługa czujnika BME280 ze strukturą danych dla projektu eHome
 * @date        2026-06-03
 * @author      Tomasz Majcher
 */

#ifndef BME_SENSOR_H
#define BME_SENSOR_H

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "config.h"

// =================================================================================
// STRUKTURY I ZMIENNE GLOBALNE
// =================================================================================

/**
 * @brief Struktura przechowująca najświeższe odczyty parametrów środowiskowych.
 */
struct BmeData {
    float temperature = 0.0f;  ///< Temperatura w stopniach Celsjusza (*C)
    float pressure = 0.0f;     ///< Ciśnienie atmosferyczne w hPa
    float altitude = 0.0f;     ///< Przybliżona wysokość nad poziomem morza (m)
    float humidity = 0.0f;     ///< Wilgotność względna (%)
};

// Inicjalizacja obiektów sprzętowych oraz globalnej struktury danych
inline TwoWire I2CBME = TwoWire(0);
inline Adafruit_BME280 bme;
inline BmeData currentBmeData;

// =================================================================================
// DEKLARACJE FUNKCJI (Interfejs dla programisty / Dokumentacja)
// =================================================================================

/**
 * @brief Inicjalizuje magistralę I2C oraz fizyczny czujnik BME280.
 * @return true jeśli wykryto czujnik i inicjalizacja przebiegła pomyślnie, false w przeciwnym wypadku.
 */
bool initBMESensor();

/**
 * @brief Pobiera fizyczne dane z czujnika i zapisuje je do wewnętrznej struktury currentBmeData.
 */
void updateBmeData();

/**
 * @brief Pobiera świeże dane, a następnie formatuje je i wysyła na port szeregowy (jeśli włączono DEBUG).
 */
void printValues();

/**
 * @brief Pobiera i zwraca ostatnio zapisaną temperaturę z pamięci RAM (ze struktury).
 * @return float Temperatura w stopniach Celsjusza (*C).
 */
float getTemperature();

/**
 * @brief Pobiera i zwraca ostatnio zapisane ciśnienie z pamięci RAM (ze struktury).
 * @return float Ciśnienie atmosferyczne w hPa.
 */
float getPressure();

/**
 * @brief Pobiera i zwraca ostatnio obliczoną wysokość n.p.m. z pamięci RAM (ze struktury).
 * @return float Wysokość w metrach (m).
 */
float getAltitude();

/**
 * @brief Pobiera i zwraca ostatnio zapisaną wilgotność z pamięci RAM (ze struktury).
 * @return float Wilgotność względna (%).
 */
float getHumidity();


// =================================================================================
// DEFINICJE FUNKCJI (Implementacja / Czysty kod)
// =================================================================================

// =============================================================================
// initBMESensor()
// =============================================================================
bool initBMESensor() 
{
    I2CBME.begin(I2C_SDA, I2C_SCL, 100000); 
    return bme.begin(BME_ADDRESS, &I2CBME);
}

// =============================================================================
// updateBmeData()
// =============================================================================
void updateBmeData() 
{
    currentBmeData.temperature = bme.readTemperature();
    currentBmeData.pressure = bme.readPressure() / 100.0F;
    currentBmeData.altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);
    currentBmeData.humidity = bme.readHumidity();
}

// =============================================================================
// printValues()
// =============================================================================
void printValues() 
{
    updateBmeData();

    DEBUG_PRINT("Temperature = ");
    DEBUG_PRINT_VAR(currentBmeData.temperature);
    DEBUG_PRINTLN(" *C");
  
    DEBUG_PRINT("Pressure = ");
    DEBUG_PRINT_VAR(currentBmeData.pressure);
    DEBUG_PRINTLN(" hPa");

    DEBUG_PRINT("Approx. Altitude = ");
    DEBUG_PRINT_VAR(currentBmeData.altitude);
    DEBUG_PRINTLN(" m");

    DEBUG_PRINT("Humidity = ");
    DEBUG_PRINT_VAR(currentBmeData.humidity);
    DEBUG_PRINTLN(" %");

    DEBUG_PRINTLN("");
}

// =============================================================================
// getTemperature()
// =============================================================================
float getTemperature() 
{
    return currentBmeData.temperature;
}

// =============================================================================
// getPressure()
// =============================================================================
float getPressure() 
{
    return currentBmeData.pressure;
}

// =============================================================================
// getAltitude()
// =============================================================================
float getAltitude() 
{
    return currentBmeData.altitude;
}

// =============================================================================
// getHumidity()
// =============================================================================
float getHumidity() 
{
    return currentBmeData.humidity;
}

#endif // BME_SENSOR_H
