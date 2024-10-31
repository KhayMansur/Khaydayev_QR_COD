#include <stdio.h>
#include <string.h>

//Konstante
#define maxArtikel 20
#define maxArtikelnamelänge 50


struct Artikel {
    char name[maxArtikelnamelänge];
    int menge;
};
//Funtionsprototypen die hier deklariert und später definiert werden
void artikelHinzufügen(struct Artikel artikelListe[maxArtikel], int* anzahl);
void artikelAnzeigen(struct Artikel artikelListe[maxArtikel], int anzahl);

void main() {
    struct Artikel artikelListe[maxArtikel];                //Array von Kontakt um Kontakte zu speichern, Struktur wird deklaliert
    int anzahl = 0;                                         //aktuelle Kontakte werden gespeichert
    int auswahl;                                            //die Auswahl des Benutzers im Menü wird gespeichert

    do {
        printf("Einkaufsliste\n");
        printf("1. Artikel hinzufuegen!\n");
        printf("2. Alle Artikel anzeigen!\n");
        printf("3. Programm beenden!\n");
        printf("Eine Option waehlen:\n");
        scanf_s("%d", &auswahl);

        switch (auswahl) {
        case 1:
            artikelHinzufügen(artikelListe, &anzahl);
            break;
        case 2:
            artikelAnzeigen(artikelListe, anzahl);
            break;
        case 3:
            printf("Programm beendet!\n");
            break;
        default:
            printf("Ungueltige Auswahl, bitte versuchen Sie es erneut.\n");
            break;
        }

    } while (auswahl != 3);


}

void artikelHinzufügen(struct Artikel artikelListe[maxArtikel], int* anzahl) {          //wird geprüft ob die Kontaktliste voll ist
    if (*anzahl >= maxArtikel) {
        printf("Die Liste ist voll.\n");
        return;
    }

    printf("Artikelnamen eingeben: ");
    getchar();
    fgets(artikelListe[*anzahl].name, maxArtikelnamelänge, stdin);               //der eingegeben Name wird gespeichert
    artikelListe[*anzahl].name[strcspn(artikelListe[*anzahl].name, "\n")] = '\0';           //"strcspn entfernt den Zeilenumbruch

    if (strlen(artikelListe[*anzahl].name) == 0) {
        printf("Fehler: Artikelname darf nicht leer sein.\n");
        return;
    }

    printf("Die noetige Menge eingeben (max 20): ");
    int menge;
    scanf_s("%d", &menge);

    if (menge < 1 || menge > 20) {
        printf("Fehler: Die Artikelmenge muss zwischen 1 und 20 liegen.\n");
        return;
    }

    artikelListe[*anzahl].menge = menge;
    (*anzahl)++;                                                //Kontaktzähler wird immer um 1 erhöht 
}

void artikelAnzeigen(struct Artikel artikelListe[maxArtikel], int anzahl) {                 //prüft ob Kontaktliste == 0 ist wenn true dann wird die Benachrichtigung ausgegeben
    if (anzahl == 0) {
        printf("Die Liste ist leer!\n");
        return;
    }

    printf("Einkaufsliste:\n");
    for (int i = 0; i < anzahl; i++) {                                          //eine for schleife die die gespeicherten Kontakte anzeigt.
        printf("%d. %s - Menge: %d\n", i + 1, artikelListe[i].name, artikelListe[i].menge);                 //hier werden die gespeicherten Daten des Kontakt angezeigt 
    }
}
