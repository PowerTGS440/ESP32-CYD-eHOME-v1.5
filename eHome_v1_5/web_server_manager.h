/**
 * @file        web_server_manager.h
 * @brief       Obsługa serwera Web HTTP z panelem imienin, świąt i zarządzaniem SD
 * @date        2026-06-03
 * @author      Tomasz Majcher
 */

#ifndef WEB_SERVER_MANAGER_H
#define WEB_SERVER_MANAGER_H

#include <WebServer.h>
#include <SD.h>
#include "config.h"
#include "bme_sensor.h"
#include "wifi_manager.h"
#include "calendar_manager.h" // Serwer pobiera zmienne todayNames oraz todayHoliday

inline WebServer server(80);

void initWebServer();
void handleWebServer();
void handleLogList();
void handleFileDownload();
void handleFileDelete();

void initWebServer() {
    server.on("/logs", handleLogList);             
    server.on("/download", handleFileDownload);     
    server.on("/delete", handleFileDelete);         
    server.onNotFound([](){ server.sendHeader("Location","/logs"); server.send(303); });
    server.begin();
    DEBUG_PRINTLN("[HTTP] Oficjalny Serwer Web ruszył w tle na porcie 80.");
}

void handleWebServer() {
    if (WiFi.status() == WL_CONNECTED) server.handleClient(); 
}

void handleLogList() {
    String html = "<!DOCTYPE html><html><head><meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1.0'>";
    html += "<title>eHome Panel</title>";
    html += "<style>body{font-family:Arial,sans-serif;margin:20px;background:#f4f4f9;color:#333;}h2{color:#002147;border-bottom:2px solid #002147;padding-bottom:5px;}h3{color:#003366;margin-top:20px;}table{width:100%;max-width:750px;border-collapse:collapse;background:#fff;box-shadow:0 2px 5px rgba(0,0,0,0.1);margin-bottom:20px;}th,td{padding:10px;text-align:left;border-bottom:1px solid #ddd;}th{background:#002147;color:#fff;}a{color:#0066cc;text-decoration:none;font-weight:bold;margin-right:15px;}.btn-del{color:#cc0000;}.info-box{max-width:720px;background:#fff;padding:15px;border-left:5px solid #002147;box-shadow:0 2px 5px rgba(0,0,0,0.1);border-radius:0 5px 5px 0;margin-bottom:20px;}</style></head><body>";
    
    html += "<h2>System eHome - Panel Zarządzania i Kalendarza</h2>";
    
    // --- ZINTEGROWANY PANEL KALENDARZA (Imieniny + Święta nietypowe z PROGMEM) ---
    html += "<div class='info-box'>";
    html += "<p style='margin:0 0 8px 0;font-size:14px;color:#666;'>Dzisiaj jest: <b>" + getFormattedDate() + " | " + getFormattedTime() + "</b></p>";
    html += "<p style='margin:0 0 8px 0;'>🎉 <b>Imieniny obchodzą:</b> <span style='color:#002147;font-weight:bold;'>" + todayNames + "</span></p>";
    html += "<p style='margin:0;'>🎈 <b>Dzisiejsze święto:</b> <span style='color:#cc0000;font-weight:bold;'>" + todayHoliday + "</span></p>";
    html += "</div>";
    
    html += "<h3>Archiwum pomiarów lokalnych (Karta SD)</h3>";
    html += "<table><tr><th>Nazwa pliku</th><th>Rozmiar</th><th>Akcja</th></tr>";

    File root = SD.open("/");
    if (root) {
        File file = root.openNextFile();
        while (file) {
            String fileName = String(file.name());
            if (fileName.endsWith(".csv") || fileName.indexOf(".csv") != -1) {
                String linkName = fileName.startsWith("/") ? fileName : "/" + fileName;
                String displayName = fileName.startsWith("/") ? fileName.substring(1) : fileName;
                html += "<tr><td>" + displayName + "</td><td>" + String(file.size() / 1024.0, 1) + " KB</td><td>";
                html += "<a href='/download?file=" + linkName + "'>Pobierz</a>";
                html += "<a class='btn-del' href='/delete?file=" + linkName + "' onclick=\"return confirm('Usunąć?')\">Usuń</a></td></tr>";
            }
            file = root.openNextFile();
        }
        root.close();
    } else {
        html += "<tr><td colspan='3'>Błąd karty SD.</td></tr>";
    }
    html += "</table></body></html>";
    server.send(200, "text/html", html);
}

void handleFileDownload() {
    if (!server.hasArg("file")) { server.send(400, "text/plain", "Brak pliku"); return; }
    String path = server.arg("file");
    if (!SD.exists(path)) { server.send(404, "text/plain", "Brak pliku"); return; }
    File file = SD.open(path, FILE_READ);
    server.sendHeader("Content-Disposition", "attachment; filename=" + path.substring(path.lastIndexOf("/") + 1));
    server.streamFile(file, "text/csv");
    file.close();
}

void handleFileDelete() {
    if (!server.hasArg("file")) { server.send(400, "text/plain", "Brak argumentu"); return; }
    String path = server.arg("file");
    if (SD.exists(path)) { SD.remove(path); server.sendHeader("Location", "/logs"); server.send(303); } 
    else { server.send(404, "text/plain", "Brak pliku"); }
}

#endif // WEB_SERVER_MANAGER_H
