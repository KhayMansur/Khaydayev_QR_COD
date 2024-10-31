#include <stdio.h>
#include <string.h>
                                             
//Konstante
#define maxKontakte 20                     
#define maxNamenl�nge 50                   
#define maxTelefonl�nge 15                  

struct Kontakt {
    char name[maxNamenl�nge];
    char grade[maxTelefonl�nge];
};

//Funtionsprototypen die hier deklariert und sp�ter definiert werden
void kontaktHinzufuegen(struct Kontakt kontakte[], int* anzahl);
void kontakteAnzeigen(const struct Kontakt kontakte[], int anzahl);

void main() {
    struct Kontakt kontakte[maxKontakte];   //Array von Kontakt um Kontakte zu speichern, Struktur wird deklaliert
    int anzahl = 0;                         //aktuelle Kontakte werden gespeichert
    int auswahl;                            //die Auswahl des Benutzers im Men� wird gespeichert

    do {                                    //einfache do-while Schleife
        printf_s("--- Kontaktliste--- \n");
        printf_s("1. Kontakt hinzufuegen!\n");
        printf_s("2. Kontakte anzeigen:\n");
        printf_s("3. Programm beenden:\n");
        printf_s("Bitte waehlen Sie eine Option: ");
        scanf_s("%d", &auswahl);

        switch (auswahl) {
        case 1:
            kontaktHinzufuegen(kontakte, &anzahl);
            break;
        case 2:
            kontakteAnzeigen(kontakte, anzahl);
            break;
        case 3:
            printf("Programm beendet!\n");
            break;
        default:
            printf("Falsche Zahl! (1) f�r Kontakt hinzufuegen. (2) f�r Kontakte anzeigen. (3) f�r Programm beende.\n");
            break;
        }
    } while (auswahl != 3);

    
}


void kontaktHinzufuegen(struct Kontakt kontakte[], int* anzahl) {     //wird gepr�ft ob die Kontaktliste voll ist
    if (*anzahl >= maxKontakte) {
        printf("Die Kontaktliste ist voll.\n");                         
        return;
    }

    printf_s("Den Namen eingeben: ");                                 
    getchar();                                                      //Leert den Eingabepuffer
    fgets(kontakte[*anzahl].name, maxNamenl�nge, stdin);                        //der eingegeben Name wird gespeichert
    kontakte[*anzahl].name[strcspn(kontakte[*anzahl].name, "\n")] = 0;              //"strcspn entfernt den Zeilenumbruch

    printf_s("Telefonnummer eingeben: ");                                       //alles das selbe bis auf das hier die Nummer gespeichert wird
    fgets(kontakte[*anzahl].telefon, maxTelefonl�nge, stdin);
    kontakte[*anzahl].telefon[strcspn(kontakte[*anzahl].telefon, "\n")] = 0; 

    (*anzahl)++;                                                                   //Kontaktz�hler wird immer um 1 erh�ht 
    printf_s("Kontakt wurde hinzugefuegt.\n");
}


void kontakteAnzeigen(const struct Kontakt kontakte[], int anzahl) {                //pr�ft ob Kontaktliste == 0 ist wenn true dann wird die Benachrichtigung ausgegeben
    if (anzahl == 0) {
        printf("Die Kontaktliste ist leer.\n");
        return;
    }

    printf_s("\n--- Kontaktliste ---\n");                   
    for (int i = 0; i < anzahl; i++) {                                          //eine for schleife die die gespeicherten Kontakte anzeigt.
        printf_s("%d. Name: %s, Telefon: %s\n", i + 1, kontakte[i].name, kontakte[i].grade);          //hier werden die gespeicherten Daten des Kontakt angezeigt 
    }
}
