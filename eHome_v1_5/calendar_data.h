/**
 * @file        calendar_data.h
 * @brief       Pełna roczna baza danych imienin w pamięci PROGMEM
 * @date        2026-06-03
 * @author      Tomasz Majcher
 */

#ifndef CALENDAR_DATA_H
#define CALENDAR_DATA_H

#include <Arduino.h>

struct CalendarEntry {
    uint8_t month;
    uint8_t day;
    const char* names;
};

const CalendarEntry eHomeCalendar[] PROGMEM = {
    // STYCZEŃ (01)
    {1, 1, "Mieszka, Mieczysława"}, {1, 2, "Abelarda, Makarego"}, {1, 3, "Danuty, Genowefy"},
    {1, 4, "Anieli, Tytusa"}, {1, 5, "Edwarda, Szymona"}, {1, 6, "Kacpra, Melchiora, Baltazara"},
    {1, 7, "Lucjana, Juliana"}, {1, 8, "Seweryna, Juliusza"}, {1, 9, "Marcjanny, Marcela"},
    {1, 10, "Danuty, Wilhelma"}, {1, 11, "Honoraty, Matyldy"}, {1, 12, "Arkadiusza, Benedykta"},
    {1, 13, "Weroniki, Bogumiła"}, {1, 14, "Feliksa, Hilarego"}, {1, 15, "Pawła, Maurów"},
    {1, 16, "Marcelego, Włodzimierza"}, {1, 17, "Antoniego, Rościsława"}, {1, 18, "Piotra, Małgorzaty"},
    {1, 19, "Henryka, Marty"}, {1, 20, "Fabiana, Sebastiana"}, {1, 21, "Agnieszki, Agnieszki"},
    {1, 22, "Anastazego, Wincentego"}, {1, 23, "Ildefonsa, Rajmunda"}, {1, 24, "Rafała, Felicjana"},
    {1, 25, "Pawła, Miłosza"}, {1, 26, "Polikarpa, Tymoteusza"}, {1, 27, "Przemysława, Jana"},
    {1, 28, "Walerego, Radomira"}, {1, 29, "Zdzisława, Franciszka"}, {1, 30, "Macieja, Martyny"},
    {1, 31, "Jana, Marceli"},

    // LUTY (02)
    {2, 1, "Brygidy, Ignacego"}, {2, 2, "Marii, Mirosława"}, {2, 3, "Błażeja, Oskara"},
    {2, 4, "Andrzeja, Weroniki"}, {2, 5, "Agaty, Adelajdy"}, {2, 6, "Doroty, Bogdana"},
    {2, 7, "Ryszarda, Romualda"}, {2, 8, "Hieronima, Sebastiana"}, {2, 9, "Apolonii, Cyryla"},
    {2, 10, "Jacka, Scholastyki"}, {2, 11, "Łazarza, Marii"}, {2, 12, "Eulalii, Modesta"},
    {2, 13, "Grzegorza, Katarzyny"}, {2, 14, "Walentego, Cyryla"}, {2, 15, "Jowity, Faustyna"},
    {2, 16, "Danuty, Juliana"}, {2, 17, "Donata, Łukasza"}, {2, 18, "Szymona, Konstancji"},
    {2, 19, "Arnolda, Konrada"}, {2, 20, "Leona, Zenobiusza"}, {2, 21, "Eleonory, Feliksa"},
    {2, 22, "Marty, Małgorzaty"}, {2, 23, "Romany, Damiana"}, {2, 24, "Macieja, Bogusza"},
    {2, 25, "Wiktora, Cezarego"}, {2, 26, "Mirosława, Aleksandra"}, {2, 27, "Anastazego, Gabriela"},
    {2, 28, "Romana, Makarego"}, {2, 29, "Leona, Justyna"},

    // MARZEC (03)
    {3, 1, "Albiny, Antoniego"}, {3, 2, "Heleny, Karola"}, {3, 3, "Kunegundy, Tycjana"},
    {3, 4, "Kazimierza, Łucji"}, {3, 5, "Adriana, Fryderyka"}, {3, 6, "Róży, Wiktora"},
    {3, 7, "Tomasza, Felicyty"}, {3, 8, "Beaty, Wincentego"}, {3, 9, "Franciszki, Brunona"},
    {3, 10, "Cypriana, Aleksandra"}, {3, 11, "Benedykta, Konstantego"}, {3, 12, "Bernarda, Grzegorza"},
    {3, 13, "Krystyny, Bożeny"}, {3, 14, "Matyldy, Leona"}, {3, 15, "Longina, Klemensa"},
    {3, 16, "Izabeli, Oktawiana"}, {3, 17, "Patryka, Zbigniewa"}, {3, 18, "Edwarda, Cyryla"},
    {3, 19, "Józefa, Bogdana"}, {3, 20, "Eufemii, Maurycego"}, {3, 21, "Ludomira, Benedykta"},
    {3, 22, "Katarzyny, Bogusława"}, {3, 23, "Pelagii, Feliksa"}, {3, 24, "Gabriela, Marka"},
    {3, 25, "Marioli, Wieńczysława"}, {3, 26, "Emanuela, Teodora"}, {3, 27, "Lidii, Ernesta"},
    {3, 28, "Anieli, Sykstusa"}, {3, 29, "Heleny, Wiktora"}, {3, 30, "Anatola, Kwiryna"},
    {3, 31, "Balbiny, Kornelii"},
    // KWIECIEŃ (04)
    {4, 1, "Grażyny, Hugona"}, {4, 2, "Władysława, Franciszka"}, {4, 3, "Ryszarda, Pankracego"},
    {4, 4, "Wacława, Izydora"}, {4, 5, "Ireny, Wincentego"}, {4, 6, "Izoldy, Celestyna"},
    {4, 7, "Donata, Rufina"}, {4, 8, "Dionizego, Julii"}, {4, 9, "Mai, Dymitra"},
    {4, 10, "Michała, Makarego"}, {4, 11, "Filipa, Leona"}, {4, 12, "Juliusza, Zenona"},
    {4, 13, "Przemysława, Idy"}, {4, 14, "Bereniki, Waleriana"}, {4, 15, "Anastazji, Wacławy"},
    {4, 16, "Julii, Kseni"}, {4, 17, "Roberta, Patrycego"}, {4, 18, "Bogusława, Apoloniusza"},
    {4, 19, "Adolfa, Tymona"}, {4, 20, "Agnieszki, Czesława"}, {4, 21, "Bartosza, Feliksa"},
    {4, 22, "Łukasza, Kai"}, {4, 23, "Wojciecha, Jerzego"}, {4, 24, "Aleksego, Horacego"},
    {4, 25, "Marka, Jarosława"}, {4, 26, "Marzeny, Klaudiusza"}, {4, 27, "Zyty, Felicjana"},
    {4, 28, "Pawła, Walerii"}, {4, 29, "Piotra, Roberta"}, {4, 30, "Mariana, Donata"},

    // MAJ (05)
    {5, 1, "Filipa, Jeremiego"}, {5, 2, "Anatola, Zygmunta"}, {5, 3, "Marii, Aleksandra"},
    {5, 4, "Moniki, Floriana"}, {5, 5, "Ireny, Waldemara"}, {5, 6, "Judyty, Jakuba"},
    {5, 7, "Gizeli, Ludmiły"}, {5, 8, "Stanisława, Lizy"}, {5, 9, "Grzegorza, Karoliny"},
    {5, 10, "Antoniego, Izydora"}, {5, 11, "Mamerta, Ignacego"}, {5, 12, "Pankracego, Dominika"},
    {5, 13, "Serwacego, Roberta"}, {5, 14, "Bonifacego, Macieja"}, {5, 15, "Zofii, Nadziei"},
    {5, 16, "Andrzeja, Szymona"}, {5, 17, "Brunona, Paschalisa"}, {5, 18, "Eryka, Klaudii"},
    {5, 19, "Piotra, Celestyna"}, {5, 20, "Bazylego, Bernarda"}, {5, 21, "Wiktora, Kryspina"},
    {5, 22, "Heleny, Wiesławy"}, {5, 23, "Iwony, Dezyderiusza"}, {5, 24, "Joanny, Zuzanny"},
    {5, 25, "Grzegorza, Urbana"}, {5, 26, "Eweliny, Filipa"}, {5, 27, "Jana, Juliusza"},
    {5, 28, "Augustyna, Jaromira"}, {5, 29, "Magdaleny, Maksymiliana"}, {5, 30, "Feliksa, Ferdynanda"},
    {5, 31, "Anieli, Petroneli"},

    // CZERWIEC (06)
    {6, 1, "Jakuba, Konrada"}, {6, 2, "Erazma, Marianny"}, {6, 3, "Leszka, Tamary"},
    {6, 4, "Franciszka, Karola"}, {6, 5, "Waltera, Bonifacego"}, {6, 6, "Pauliny, Norberta"},
    {6, 7, "Roberta, Wiesława"}, {6, 8, "Maksyma, Medarda"}, {6, 9, "Alicji, Pelagii"},
    {6, 10, "Bogumiła, Małgorzaty"}, {6, 11, "Barnaby, Radomiła"}, {6, 12, "Jana, Onufrego"},
    {6, 13, "Antoniego, Lucjana"}, {6, 14, "Elwiry, Walerego"}, {6, 15, "Jolanty, Witolda"},
    {6, 16, "Aliny, Benona"}, {6, 17, "Alberta, Marcjana"}, {6, 18, "Elżbiety, Marka"},
    {6, 19, "Gerwazego, Protazego"}, {6, 20, "Bogny, Florentyny"}, {6, 21, "Alicji, Alojzego"},
    {6, 22, "Paulina, Tomasza"}, {6, 23, "Wandy, Zenona"}, {6, 24, "Jana, Danuty"},
    {6, 25, "Łucji, Wilhelma"}, {6, 26, "Jana, Pawła"}, {6, 27, "Władysława, Maryli"},
    {6, 28, "Leona, Ireneusza"}, {6, 29, "Piotra, Pawła"}, {6, 30, "Emilii, Lucyny"},
    // LIPIEC (07)
    {7, 1, "Haliny, Mariana"}, {7, 2, "Jagody, Urbana"}, {7, 3, "Anatola, Jacka"},
    {7, 4, "Ody, Jakuba"}, {7, 5, "Karoliny, Filomeny"}, {7, 6, "Dominiki, Łucji"},
    {7, 7, "Estery, Gotarda"}, {7, 8, "Adriana, Przeclawa"}, {7, 9, "Lukrecji, Weroniki"},
    {7, 10, "Oskara, Filipa"}, {7, 11, "Olgi, Kaliny"}, {7, 12, "Jana, Brunona"},
    {7, 13, "Ernesta, Małgorzaty"}, {7, 14, "Bonawentury, Marcelina"}, {7, 15, "Henryka, Włodzimierza"},
    {7, 16, "Marii, Marwina"}, {7, 17, "Bogdana, Aleksego"}, {7, 18, "Kamila, Szymona"},
    {7, 19, "Wincentego, Wodzisława"}, {7, 20, "Czesława, Hieronima"}, {7, 21, "Daniela, Andrzeja"},
    {7, 22, "Marii, Magdaleny"}, {7, 23, "Bogny, Apolinarego"}, {7, 24, "Kingi, Krystyny"},
    {7, 25, "Krzysztofa, Jakuba"}, {7, 26, "Anny, Mirosławy"}, {7, 27, "Julii, Natalii"},
    {7, 28, "Wiktora, Innocentego"}, {7, 29, "Marty, Olafa"}, {7, 30, "Julity, Ludwika"},
    {7, 31, "Ignacego, Heleny"},

    // SIERPIEŃ (08)
    {8, 1, "Piotra, Juliana"}, {8, 2, "Gustawa, Karoliny"}, {8, 3, "Lidii, Augusta"},
    {8, 4, "Dominika, Jana"}, {8, 5, "Marii, Oswalda"}, {8, 6, "Sławomira, Jakuba"},
    {8, 7, "Doroty, Kajetana"}, {8, 8, "Cypriana, Emiliana"}, {8, 9, "Romana, Ryszarda"},
    {8, 10, "Borysa, Wawrzyńca"}, {8, 11, "Klary, Zuzanny"}, {8, 12, "Lecha, Hilarego"},
    {8, 13, "Diany, Hipolita"}, {8, 14, "Alfreda, Maksymiliana"}, {8, 15, "Marii, Napoleona"},
    {8, 16, "Rocha, Joachima"}, {8, 17, "Jacka, Mirona"}, {8, 18, "Heleny, Ilony"},
    {8, 19, "Bolesława, Juliana"}, {8, 20, "Bernarda, Samuela"}, {8, 21, "Joanny, Kazimiery"},
    {8, 22, "Cezarego, Zygfryda"}, {8, 23, "Apolinarego, Filipa"}, {8, 24, "Bartłomieja, Jerzego"},
    {8, 25, "Luizy, Ludwika"}, {8, 26, "Marii, Zefiryna"}, {8, 27, "Moniki, Cezarego"},
    {8, 28, "Augustyna, Aleksego"}, {8, 29, "Sabiny, Jana"}, {8, 30, "Róży, Szczęsnego"},
    {8, 31, "Bogdana, Rajmunda"},

    // WRZESIEŃ (09)
    {9, 1, "Bronisława, Idziego"}, {9, 2, "Juliana, Stefana"}, {9, 3, "Izabeli, Szymona"},
    {9, 4, "Idy, Rozalii"}, {9, 5, "Doroty, Wawrzyńca"}, {9, 6, "Beaty, Zakarii"},
    {9, 7, "Reginy, Melchiora"}, {9, 8, "Marii, Adrianny"}, {9, 9, "Piotra, Sergiusza"},
    {9, 10, "Łukasza, Mikołaja"}, {9, 11, "Jacka, Prota"}, {9, 12, "Amadeusza, Gwidona"},
    {9, 13, "Eugeniusza, Filipa"}, {9, 14, "Cypriana, Roksany"}, {9, 15, "Albiny, Nikodema"},
    {9, 16, "Edyty, Kornela"}, {9, 17, "Franciszka, Roberta"}, {9, 18, "Ireny, Stanisława"},
    {9, 19, "Janusza, Konstancji"}, {9, 20, "Eustachego, Filipa"}, {9, 21, "Mateusza, Jonasza"},
    {9, 22, "Tomasza, Maurycego"}, {9, 23, "Tekli, Bogusława"}, {9, 24, "Gerarda, Ruperta"},
    {9, 25, "Władysława, Aurelii"}, {9, 26, "Justyny, Cypriana"}, {9, 27, "Damiana, Kosmy"},
    {9, 28, "Wacława, Marka"}, {9, 29, "Michała, Gabriela"}, {9, 30, "Zofii, Hieronima"},
    // PAŹDZIERNIK (10)
    {10, 1, "Danuty, Remigiusza"}, {10, 2, "Teofila, Dionizego"}, {10, 3, "Teresy, Heliodora"},
    {10, 4, "Franciszka, Rozalii"}, {10, 5, "Ireny, Apolinarego"}, {10, 6, "Artura, Brunona"},
    {10, 7, "Marka, Justyny"}, {10, 8, "Pelagii, Brygidy"}, {10, 9, "Ludwika, Dionizego"},
    {10, 10, "Pauliny, Daniela"}, {10, 11, "Emila, Aldony"}, {10, 12, "Eustachego, Maksymiliana"},
    {10, 13, "Edwarda, Teofila"}, {10, 14, "Alana, Kaliksta"}, {10, 15, "Teresy, Jadwigi"},
    {10, 16, "Aurelii, Gawła"}, {10, 17, "Małgorzaty, Wiktora"}, {10, 18, "Łukasza, Juliana"},
    {10, 19, "Piotra, Kleopatry"}, {10, 20, "Ireny, Kleofasa"}, {10, 21, "Urszuli, Hilariona"},
    {10, 22, "Filipa, Korduli"}, {10, 23, "Marleny, Seweryna"}, {10, 24, "Rafała, Marcina"},
    {10, 25, "Darii, Sambora"}, {10, 26, "Lucjana, Ewarysta"}, {10, 27, "Sabiny, Iwony"},
    {10, 28, "Tadeusza, Szymona"}, {10, 29, "Euzebii, Narcyza"}, {10, 30, "Zenobii, Przemysława"},
    {10, 31, "Urbana, Augusta"},

    // LISTOPAD (11)
    {11, 1, "Seweryna, Wiktora"}, {11, 2, "Bohdany, Tobiasza"}, {11, 3, "Sylwii, Huberta"},
    {11, 4, "Karola, Olgierda"}, {11, 5, "Elżbiety, Sławomira"}, {11, 6, "Feliksa, Leonarda"},
    {11, 7, "Antoniego, Melchiora"}, {11, 8, "Seweryna, Bogdana"}, {11, 9, "Ursyna, Teodora"},
    {11, 10, "Ludomira, Leona"}, {11, 11, "Marcina, Bartłomieja"}, {11, 12, "Renaty, Witolda"},
    {11, 13, "Mikołaja, Stanisława"}, {11, 14, "Rogera, Serafina"}, {11, 15, "Alberta, Leopolda"},
    {11, 16, "Gertrudy, Edmunda"}, {11, 17, "Grzegorza, Salomei"}, {11, 18, "Romana, Klaudyny"},
    {11, 19, "Elżbiety, Seweryna"}, {11, 20, "Anatola, Rafała"}, {11, 21, "Janusza, Konrada"},
    {11, 22, "Marka, Cecylii"}, {11, 23, "Adeli, Klemensa"}, {11, 24, "Jana, Chryzogona"},
    {11, 25, "Katarzyny, Erazma"}, {11, 26, "Sylwestra, Konrada"}, {11, 27, "Waleriana, Maksyma"},
    {11, 28, "Zdzisława, Grzegorza"}, {11, 29, "Błażeja, Saturnina"}, {11, 30, "Andrzeja, Maurycego"},

    // GRUDZIEŃ (12)
    {12, 1, "Natalii, Eligiusza"}, {12, 2, "Balbiny, Pauliny"}, {12, 3, "Franciszka, Ksawerego"},
    {12, 4, "Barbary, Krystiana"}, {12, 5, "Saby, Kryspina"}, {12, 6, "Mikołaja, Jasiu"},
    {12, 7, "Marcina, Ambrożego"}, {12, 8, "Marii, Wirginiusza"}, {12, 9, "Wiesława, Leokadii"},
    {12, 10, "Julii, Daniela"}, {12, 11, "Damazego, Waldemara"}, {12, 12, "Aleksandry, Dagmary"},
    {12, 13, "Łucji, Otylii"}, {12, 14, "Alfreda, Izydora"}, {12, 15, "Celiny, Waleriana"},
    {12, 16, "Albiny, Zdzisławy"}, {12, 17, "Łazarza, Olimpii"}, {12, 18, "Bogusława, Gracjana"},
    {12, 19, "Gabrieli, Dariusza"}, {12, 20, "Bogumiła, Dominika"}, {12, 21, "Tomasza, Tomisława"},
    {12, 22, "Zenona, Honoraty"}, {12, 23, "Wiktorii, Sławomira"}, {12, 24, "Adama, Ewy"},
    {12, 25, "Anatola, Anastazji"}, {12, 26, "Dionizego, Szczepana"}, {12, 27, "Jana, Żanety"},
    {12, 28, "Cezarego, Antoniego"}, {12, 29, "Dawida, Tomasza"}, {12, 30, "Eugeniusza, Irminy"},
    {12, 31, "Sylwestra, Sebastiana"},

    // Strażnik pętli
    {0, 0, nullptr}
};

#endif // CALENDAR_DATA_H
