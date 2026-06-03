/**
 * @file        holidays_data.h
 * @brief       Pełna roczna baza danych świąt nietypowych w PROGMEM (Część 1)
 * @date        2026-06-03
 * @author      Tomasz Majcher
 */

#ifndef HOLIDAYS_DATA_H
#define HOLIDAYS_DATA_H

#include <Arduino.h>

struct HolidayEntry {
    uint8_t month;
    uint8_t day;
    const char* holiday;
};

const HolidayEntry eHomeHolidays[] PROGMEM = {
    // STYCZEŃ (01)
    {1, 1, "Nowy Rok, Światowy Dzień Pokoju"}, {1, 2, "Światowy Dzień Introwertyka"}, {1, 3, "Dzień Słomki do Picia"},
    {1, 4, "Światowy Dzień Braille'a"}, {1, 5, "Dzień Bitej Śmietany"}, {1, 6, "Trzech Króli, Dzień Filatelisty"},
    {1, 7, "Dzień Dziwaka"}, {1, 8, "Dzień Sprzątania Biurka"}, {1, 9, "Dzień Ligi Ochrony Przyrody"},
    {1, 10, "Dzień Obniżania Kosztów Energii"}, {1, 11, "Międzynarodowy Dzień Dziękuję"}, {1, 12, "Dzień Całowania w Czoło"},
    {1, 13, "Dzień Koszuli"}, {1, 14, "Dzień Ukrytej Miłości"}, {1, 15, "Dzień i Noc Składanki Muzycznej"},
    {1, 16, "Dzień Pikantnych Potraw"}, {1, 17, "Dzień Wszystkich Świętych Leonów"}, {1, 18, "Dzień Kubusia Puchatka"},
    {1, 19, "Dzień Popcornu"}, {1, 20, "Dzień Wiedzy o Pingwinach"}, {1, 21, "Dzień Babci, Dzień Przytulania"},
    {1, 22, "Dzień Dziadka"}, {1, 23, "Dzień Pisma Ręcznego"}, {1, 24, "Światowy Dzień Środków Masowego Przekazu"},
    {1, 25, "Dzień Sekretarki i Asystentki"}, {1, 26, "Dzień Transplantacji"}, {1, 27, "Międzynarodowy Dzień Pamięci o Ofiarach Holokaustu"},
    {1, 28, "Dzień Ochrony Danych Osobowych"}, {1, 29, "Dzień Składanki Przewodnikowej"}, {1, 30, "Dzień Rogalika"},
    {1, 31, "Międzynarodowy Dzień Przytulania"},

    // LUTY (02)
    {2, 1, "Międzynarodowy Dzień Puszystych"}, {2, 2, "Dzień Świstaka, Dzień Handlowca"}, {2, 3, "Dzień Ciasta Marchewkowego"},
    {2, 4, "Światowy Dzień Walki z Rakiem"}, {2, 5, "Światowy Dzień Nutelli"}, {2, 6, "Międzynarodowy Dzień Barmana"},
    {2, 7, "Dzień Najlepszego Przyjaciela"}, {2, 8, "Dzień Bezpiecznego Internetu"}, {2, 9, "Międzynarodowy Dzień Pizzy"},
    {2, 10, "Dzień Singla"}, {2, 11, "Ogólnopolski Dzień Dokarmiania Zwierzyny Leśnej"}, {2, 12, "Międzynarodowy Dzień Darwina"},
    {2, 13, "Światowy Dzień Radia"}, {2, 14, "Walentynki, Dzień Chorych na Padaczkę"}, {2, 15, "Dzień Singla (Wielka Brytania)"},
    {2, 16, "Międzynarodowy Dzień Listonosza"}, {2, 17, "Międzynarodowy Dzień Kota"}, {2, 18, "Dzień Baterii"},
    {2, 19, "Dzień Nauki Polskiej"}, {2, 20, "Międzynarodowy Dzień Palących Fajkę"}, {2, 21, "Międzynarodowy Dzień Języka Ojczystego"},
    {2, 22, "Dzień Myśli Braterskiej"}, {2, 23, "Ogólnopolski Dzień Walki z Depresją"}, {2, 24, "Dzień Niespodziewanego Całusa"},
    {2, 25, "Dzień Mastodontów"}, {2, 26, "Dzień Dinozaura"}, {2, 27, "Dzień Niedźwiedzia Polarnego"},
    {2, 28, "Dzień Spania w Miejscach Publicznych"}, {2, 29, "Dzień Kroków Przestępnych"},

    // MARZEC (03)
    {3, 1, "Dzień Puszystych, Dzień Piegów"}, {3, 2, "Dzień Staroci"}, {3, 3, "Międzynarodowy Dzień Pisarza"},
    {3, 4, "Święto Kazimierza"}, {3, 5, "Dzień Teściowej, Dzień Dentysty"}, {3, 6, "Europejski Dzień Logopedy"},
    {3, 7, "Dzień Płatków Owsianych"}, {3, 8, "Dzień Kobiet"}, {3, 9, "Polski Dzień Statystyki"},
    {3, 10, "Dzień Mężczyzn"}, {3, 11, "Dzień Sołtysa"}, {3, 12, "Światowy Dzień Drzewa"},
    {3, 13, "Światowy Dzień Snu"}, {3, 14, "Liczby Pi, Dzień Białych Butów"}, {3, 15, "Światowy Dzień Konsumenta"},
    {3, 16, "Dzień Pandy"}, {3, 17, "Dzień Świętego Patryka"}, {3, 18, "Europejski Dzień Mózgu"},
    {3, 19, "Dzień Wędkarza"}, {3, 20, "Międzynarodowy Dzień Szczęścia, Dzień bez Mięsa"}, {3, 21, "Pierwszy Dzień Wiosny, Dzień Wagarowicza"},
    {3, 22, "Światowy Dzień Wody"}, {3, 23, "Światowy Dzień Meteorologii"}, {3, 24, "Narodowy Dzień Życia"},
    {3, 25, "Dzień Gofra"}, {3, 26, "Dzień Modlitw za Więźniów"}, {3, 27, "Międzynarodowy Dzień Teatru"},
    {3, 28, "Dzień Żelków"}, {3, 29, "Dzień Metalowca"}, {3, 30, "Dzień Śrubokręta"},
    {3, 31, "Światowy Dzień Backupów"},

    // KWIECIEŃ (04)
    {4, 1, "Prima Aprilis, Międzynarodowy Dzień Ptaków"}, {4, 2, "Światowy Dzień Świadomości Autyzmu"}, {4, 3, "Dzień Tęczy"},
    {4, 4, "Dzień Marchewki"}, {4, 5, "Dzień Leśnika i Drzewiarza"}, {4, 6, "Światowy Dzień Sportu"},
    {4, 7, "Światowy Dzień Zdrowia"}, {4, 8, "Międzynarodowy Dzień Romański"}, {4, 9, "Dzień Wszystkich Antków"},
    {4, 10, "Dzień Rodzeństwa"}, {4, 11, "Dzień Radia"}, {4, 12, "Dzień Czekolady, Dzień Ludzi Kosmosu"},
    {4, 13, "Dzień Pamięci Ofiar Katynia"}, {4, 14, "Dzień Ludzi Bezdomnych"}, {4, 15, "Światowy Dzień Sztuki"},
    {4, 16, "Dzień Sapera"}, {4, 17, "Światowy Dzień Hemofilii"}, {4, 18, "Międzynarodowy Dzień Ochrony Zabytków"},
    {4, 19, "Dzień czosnku"}, {4, 20, "Międzynarodowy Dzień Wolnej Prasy"}, {4, 21, "Światowy Dzień Kreatywności"},
    {4, 22, "Międzynarodowy Dzień Ziemi"}, {4, 23, "Światowy Dzień Książki i Praw Autorskich"}, {4, 24, "Międzynarodowy Dzień Solidarności Młodzieży"},
    {4, 25, "Dzień Sekretarki, Światowy Dzień Pingwina"}, {4, 26, "Światowy Dzień Własności Intelektualnej"}, {4, 27, "Dzień Grafika"},
    {4, 28, "Światowy Dzień Bezpieczeństwa w Pracy"}, {4, 29, "Międzynarodowy Dzień Tańca"}, {4, 30, "Dzień Koni"},
    // MAJ (05)
    {5, 1, "Święto Pracy, Ogólnopolski Dzień Święta Kaszanki"}, {5, 2, "Dzień Flagi RP, Dzień Polonii"}, {5, 3, "Święto Konstytucji 3 Maja"},
    {5, 4, "Dzień Strażaka, Dzień Gwiezdnych Wojen"}, {5, 5, "Dzień Godności Osoby z Niepełnosprawnością"}, {5, 6, "Międzynarodowy Dzień bez Diety"},
    {5, 7, "Dzień Kosmosu"}, {5, 8, "Dzień Bibliotekarza i Bibliotek"}, {5, 9, "Dzień Unii Europejskiej"},
    {5, 10, "Dzień Chemika"}, {5, 11, "Dzień bez Śmiecenia"}, {5, 12, "Międzynarodowy Dzień Pielęgniarek"},
    {5, 13, "Światowy Dzień Sokw"}, {5, 14, "Dzień Farmaceuty"}, {5, 15, "Międzynarodowy Dzień Rodziny, Dzień Niezapominajki"},
    {5, 16, "Dzień Straży Granicznej"}, {5, 17, "Światowy Dzień Telekomunikacji"}, {5, 18, "Międzynarodowy Dzień Muzeów"},
    {5, 19, "Dzień Dobrych Uczynków"}, {5, 20, "Światowy Dzień Pszczół"}, {5, 21, "Światowy Dzień Kosmosu i Rozwoju Kultury"},
    {5, 22, "Dzień Paczki"}, {5, 23, "Światowy Dzień Żółwia"}, {5, 24, "Europejski Dzień Parków Narodowych"},
    {5, 25, "Dzień Piwowara, Dzień Ręcznika"}, {5, 26, "Dzień Matki"}, {5, 27, "Dzień Samorządu Terytorialnego"},
    {5, 28, "Dzień Bez Poprawek"}, {5, 29, "Dzień Działacza Kultury"}, {5, 30, "Dzień Sieroty"},
    {5, 31, "Dzień bez Papierosa"},

    // CZERWIEC (06) - Dzień po dniu
    {6, 1, "Dzień Dziecka, Światowy Dzień Mleka, Dzień Bułki"},
    {6, 2, "Dzień bez Krawata, Dzień Gąsienicy"},
    {6, 3, "Międzynarodowy Dzień Roweru, Dzień Ślimaka"},
    {6, 4, "Dzień Drukarza, Dzień Wolności i Praw Obywatelskich"},
    {6, 5, "Światowy Dzień Ochrony Środowiska, Dzień Szwagra"},
    {6, 6, "Dzień Jojo, Dzień bez Samochodu, Dzień Pocałunku"},
    {6, 7, "Dzień Seksu, Dzień Chemika, Telemanii"},
    {6, 8, "Dzień Przyjaciela, Światowy Dzień Oceanów"},
    {6, 9, "Dzień Księgowego, Dzień Przytulania"},
    {6, 10, "Dzień Straży Granicznej"},
    {6, 11, "Dzień Drwala, Międzynarodowy Dzień Lalek"},
    {6, 12, "Światowy Dzień Falafela, Dzień Stylisty Fryzur"},
    {6, 13, "Dzień Dobrych Rad"},
    {6, 14, "Światowy Dzień Krwiodawstwa, Dzień Mycia Rąk"},
    {6, 15, "Światowy Dzień Wiatru, Ogólnopolski Dzień Dogadzania"},
    {6, 16, "Dzień Dziecka Afrykańskiego, Dzień Pomocy Refleksyjnej"},
    {6, 17, "Światowy Dzień Walki z Pustynnieniem i Suszą"},
    {6, 18, "Dzień Ewakuacji, Międzynarodowy Dzień Sushi"},
    {6, 19, "Dzień Spaceru, Dzień Kota Garfielda"},
    {6, 20, "Światowy Dzień Uchodźcy"},
    {6, 21, "Dzień Muzyki, Światowy Dzień Deskrolki"},
    {6, 22, "Dzień Kultury Fizycznej"},
    {6, 23, "Dzień Ojca, Dzień Wędkarza"},
    {6, 24, "Światowy Dzień Przytulania Psa, Dzień Chrupek"},
    {6, 25, "Dzień Stoczniowca, Ogólnopolski Dzień Smerfa"},
    {6, 26, "Międzynarodowy Dzień Solidarności z Ofiarami Tortur"},
    {6, 27, "Światowy Dzień Rybołówstwa, Walki z Cukrzycą"},
    {6, 28, "Narodowy Dzień Pamięci Poznańskiego Czerwca 1956"},
    {6, 29, "Dzień Ratownika WOPR, Dzień Rybaka"},
    {6, 30, "Dzień Motyla Kapustnika, Międzynarodowy Dzień Asteroid"},

    // LIPIEC (07)
    {7, 1, "Dzień Psa, Światowy Dzień Architektury"}, {7, 2, "Międzynarodowy Dzień UFO"}, {7, 3, "Dzień Czerwonej Opaski"},
    {7, 4, "Święto Hot-doga"}, {7, 5, "Dzień Łapania za Biust"}, {7, 6, "Światowy Dzień Pocałunku"},
    {7, 7, "Dzień Czekolady (Meteo)"}, {7, 8, "Dzień Odlewnika"}, {7, 9, "Dzień Chodzenia do Pracy Inną Drogą"},
    {7, 10, "Dzień Energii"}, {7, 11, "Światowy Dzień Ludności"}, {7, 12, "Światowy Dzień Kebabu"},
    {7, 13, "Dzień Frytek"}, {7, 14, "Dzień Łapania za Pupę"}, {7, 15, "Dzień Bez Telefonu Komórkowego"},
    {7, 16, "Dzień Księgowego"}, {7, 17, "Międzynarodowy Dzień Sprawiedliwości"}, {7, 18, "Międzynarodowy Dzień Nelsona Mandeli"},
    {7, 19, "Dzień Czerwonego Kapturka"}, {7, 20, "Międzynarodowy Dzień Szachów"}, {7, 21, "Dzień bezpiecznego kierowcy"},
    {7, 22, "Światowy Dzień Mózgu"}, {7, 23, "Dzień Włóczykija"}, {7, 24, "Święto Policji"},
    {7, 25, "Dzień Bezpiecznego Kierowcy, Dzień Tkacza"}, {7, 26, "Dzień Administratora"}, {7, 27, "Dzień Samotnych"},
    {7, 28, "Światowy Dzień Walki z Zapaleniem Wątroby"}, {7, 29, "Międzynarodowy Dzień Tygrysa"}, {7, 30, "Międzynarodowy Dzień Przyjaźni"},
    {7, 31, "Dzień Skarbnika"},

    // SIERPIEŃ (08)
    {8, 1, "Pamięci Powstania Warszawskiego"}, {8, 2, "Światowy Dzień Karmienia Piersią"}, {8, 3, "Dzień Arbuza"},
    {8, 4, "Światowy Dzień Piwa i Piwowara"}, {8, 5, "Międzynarodowy Dzień Ostryg"}, {8, 6, "Dzień Musztardy"},
    {8, 7, "Dzień Latarni Morskiej"}, {8, 8, "Wielki Dzień Pszczół"}, {8, 9, "Międzynarodowy Dzień Ludności Tubylczej"},
    {8, 10, "Dzień Przewodnika i Ratownika Górskiego"}, {8, 11, "Dzień Konserwatora Zabytków"}, {8, 12, "Międzynarodowy Dzień Młodzieży"},
    {8, 13, "Międzynarodowy Dzień Leworęcznych"}, {8, 14, "Dzień Energetyka"}, {8, 15, "Święto Wojska Polskiego"},
    {8, 16, "Dzień Żonglerki"}, {8, 17, "Dzień Pozytywnie Zakręconych"}, {8, 18, "Dzień Latarni Morskiej"},
    {8, 19, "Światowy Dzień Fotografii"}, {8, 20, "Dzień Komara"}, {8, 21, "Dzień Optymisty"},
    {8, 22, "Dzień Pracownika Ochrony"}, {8, 23, "Europejski Dzień Pamięci Ofiar Stalinizmu"}, {8, 24, "Dzień Systemu Windows"},
    {8, 25, "Dzień Zupy Pomidorowej"}, {8, 26, "Dzień Psa (USA)"}, {8, 27, "Dzień Tira"},
    {8, 28, "Dzień Lotnictwa Polskiego"}, {8, 29, "Dzień Straży Miejskiej"}, {8, 30, "Dzień Taksówkarza"},
    {8, 31, "Dzień Solidarności i Wolności"},
    // WRZESIEŃ (09)
    {9, 1, "Dzień Kombatanta, Wybuch II Wojny Światowej"}, {9, 2, "Dzień Dużego Rozmiaru"}, {9, 3, "Dzień Wieżowca"},
    {9, 4, "Dzień Świeżaka"}, {9, 5, "Międzynarodowy Dzień Dobroczynności"}, {9, 6, "Dzień Czytania Książek"},
    {9, 7, "Dzień Brody"}, {9, 8, "Dzień Dobrej Wiadomości"}, {9, 9, "Światowy Dzień Alkoholowego Zespołu Płodowego"},
    {9, 10, "Dzień Piłkarza"}, {9, 11, "Dzień Ofiar Terroryzmu"}, {9, 12, "Dzień Programisty"},
    {9, 13, "Dzień Programisty (Lata Przestępne)"}, {9, 14, "Dzień Alternatywnego Paliwa"}, {9, 15, "Europejski Dzień Prostaty"},
    {9, 16, "Dzień Dzikiej Fauny i Flory"}, {9, 17, "Dzień Sybiraka, Dzień Głuchego"}, {9, 18, "Międzynarodowy Dzień Monitorowania Wód"},
    {9, 19, "Dzień Emotikona"}, {9, 20, "Ogólnopolski Dzień Przedszkolaka"}, {9, 21, "Międzynarodowy Dzień Pokoju"},
    {9, 22, "Europejski Dzień bez Samochodu"}, {9, 23, "Pierwszy Dzień Jesieni"}, {9, 24, "Dzień Grzyba"},
    {9, 25, "Dzień Budowlańca"}, {9, 26, "Europejski Dzień Języków"}, {9, 27, "Światowy Dzień Turystyki"},
    {9, 28, "Dzień Jabłka"}, {9, 29, "Dzień Kawy"}, {9, 30, "Dzień Chłopaka"},

    // PAŹDZIERNIK (10)
    {10, 1, "Międzynarodowy Dzień Wegetarianizmu, Dzień Lekarza"}, {10, 2, "Światowy Dzień Tabliczki Mnożenia"}, {10, 3, "Dzień Noszenia Glanów"},
    {10, 4, "Światowy Dzień Zwierząt"}, {10, 5, "Światowy Dzień Nauczycieli"}, {10, 6, "Światowy Dzień Uśmiechu"},
    {10, 7, "Mędzynarodowy Dzień Pracy Godnej"}, {10, 8, "Dzień Pierogów"}, {10, 9, "Światowy Dzień Poczty"},
    {10, 10, "Światowy Dzień Zdrowia Psychicznego"}, {10, 11, "Dzień Dziewczynek"}, {10, 12, "Dzień Bezpiecznego Komputera"},
    {10, 13, "Dzień Ratownika Medycznego"}, {10, 14, "Dzień Edukacji Narodowej (Nauczyciela)"}, {10, 15, "Światowy Dzień Mycia Rąk"},
    {10, 16, "Światowy Dzień Żywności, Dzień Szefa"}, {10, 17, "Międzynarodowy Dzień Walki z Ubóstwem"}, {10, 18, "Dzień Poczty Polskiej"},
    {10, 19, "Dzień Normalnego Faceat"}, {10, 20, "Międzynarodowy Dzień Szefa Kuchni"}, {10, 21, "Dzień bez Skarpetek"},
    {10, 22, "Dzień Caps Locka"}, {10, 23, "Dzień kreta"}, {10, 24, "Dzień Origami, Dzień Walki z Otyłością"},
    {10, 25, "Dzień Kundelka, Dzień Ustawy o Ochronie Zwierząt"}, {10, 26, "Dzień Chorych na Niewydolność Serca"}, {10, 27, "Światowy Dzień Dziedzictwa Audiowizualnego"},
    {10, 28, "Dzień Odpoczynku dla Świata"}, {10, 29, "Światowy Dzień Udaru Mózgu"}, {10, 30, "Dzień Spódnicy"},
    {10, 31, "Światowy Dzień Oszczędności, Halloween"},

    // LISTOPAD (11)
    {11, 1, "Wszystkich Świętych"}, {11, 2, "Dzień Zaduszny"}, {11, 3, "Dzień Myśliwego (Hubertus)"},
    {11, 4, "Dzień Taniego Wina"}, {11, 5, "Dzień Postaci z Bajek"}, {11, 6, "Międzynarodowy Dzień Zapobiegania Eksploatacji Środowiska"},
    {11, 7, "Dzień Kotleta Schabowego"}, {11, 8, "Europejski Dzień Zdrowego Jedzenia"}, {11, 9, "Światowy Dzień Gry i Zabawy"},
    {11, 10, "Dzień Jeża"}, {11, 11, "Narodowe Święto Niepodległości"}, {11, 12, "Światowy Dzień Zapalenia Płuc"},
    {11, 13, "Światowy Dzień Dobroci"}, {11, 14, "Światowy Dzień Cukrzycy, Seniora"}, {11, 15, "Dzień Uwięzionego Pisarza"},
    {11, 16, "Międzynarodowy Dzień Tolerancji"}, {11, 17, "Ogólnopolski Dzień bez Długów"}, {11, 18, "Dzień Antybiotyków"},
    {11, 19, "Międzynarodowy Dzień Mężczyzn (ONZ)"}, {11, 20, "Praw Dziecka, Dzień Systemów Informacji Geograficznej"}, {11, 21, "Dzień Pracownika Socjalnego, Życzliwości"},
    {11, 22, "Dzień Kredki"}, {11, 23, "Dzień Fibonacciego"}, {11, 24, "Katarzynki"},
    {11, 25, "Dzień Pluszowego Misia, Dzień bez Futra"}, {11, 26, "Dzień Ciasta"}, {11, 27, "Dzień Gorsetu"},
    {11, 28, "Dzień Pocałunku w Usta"}, {11, 29, "Dzień Kina Polskiego, Andrzejki"}, {11, 30, "Dzień Białych Rękawiczek"},

    // GRUDZIEŃ (12)
    {12, 1, "Światowy Dzień Walki z AIDS"}, {12, 2, "Dzień bez Przekleństw"}, {12, 3, "Międzynarodowy Dzień Osób z Niepełnosprawnościami"},
    {12, 4, "Barbórka (Dzień Górnika)"}, {12, 5, "Międzynarodowy Dzień Wolontariusza"}, {12, 6, "Mikołajki"},
    {12, 7, "Międzynarodowy Dzień Lotnictwa Cywilnego"}, {12, 8, "Dzień Kupca"}, {12, 9, "Międzynarodowy Dzień Walki z Korupcją"},
    {12, 10, "Dzień Praw Człowieka"}, {12, 11, "Międzynarodowy Dzień Terenów Górskich"}, {12, 12, "Dzień Guzika"},
    {12, 13, "Dzień Pamięci Ofiar Stanu Wojennego"}, {12, 14, "Dzień Księgowego"}, {12, 15, "Dzień Herbaty"},
    {12, 16, "Dzień Pokrycia Wszystkiego Czekoladą"}, {12, 17, "Dzień bez Przekleństw"}, {12, 18, "Międzynarodowy Dzień Migrantów"},
    {12, 19, "Dzień Współpracy Południe-Południe"}, {12, 20, "Dzień Ryby"}, {12, 21, "Dzień Pierwszego Dnia Zimy"},
    {12, 22, "Dzień Krotkich Nocy"}, {12, 23, "Światowy Dzień Snowboardu"}, {12, 24, "Wigilia Bożego Narodzenia"},
    {12, 25, "Boże Narodzenie (Pierwszy Dzień)"}, {12, 26, "Drugi Dzień Świąt (Szczepana)"}, {12, 27, "Dzień Filatelisty"},
    {12, 28, "Dzień Gry w Karty"}, {12, 29, "Międzynarodowy Dzień Różnorodności Biologicznej"}, {12, 30, "Dzień Serka Wiejskiego"},
    {12, 31, "Sylwester"},

    // Strażnik końca pętli
    {0, 0, nullptr}
};

#endif // HOLIDAYS_DATA_H
