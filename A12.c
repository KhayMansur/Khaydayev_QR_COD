#include <stdio.h>
#include <string.h>

//Konstante 
#define maxStudente 30
#define maxNote 5
#define maxNamenlänge 50

struct Student {
	char name[maxStudente];
	int marticulationNumber; 
	float grade[maxNote];
	float average; 
};

void studentHinzufügen(struct Student studente[], int* anzahl);
void showStudent(const struct Student studente[], int anzahl);
void seekStudent(const struct Student studente[], int anzahl);
void calculateAverageOffAllStudents(const struct Student studente[], int anzahl);

void main() {
    struct Student studente[maxNamenlänge];
    int anzahl = 0;
    int auswahl; 

    do {                                    
        printf_s("--STUDIERENDENVERWALTUNGSSYSTEM--\n");
        printf_s("1. Studierende hinzufuegen:\n");
        printf_s("2. Alle Studierenden anzeigen:\n");
        printf_s("3. Nach einem Studierenden suchen:\n");
        printf_s("4. Durchschnittsnote aller Studierenden berechnen:\n");
        printf_s("5. Programm beenden!\n");
        printf_s("Bitte waehlen Sie eine Option: ");
        scanf_s("%d", &auswahl);

        switch (auswahl) {
        case 1:
            studentHinzufügen(studente, &anzahl);
            break;
        case 2:
            showStudent(studente, anzahl);
            break;
        case 3:
            seekStudent(studente,anzahl);
            break;
        case 4:
            calculateAverageOffAllStudents(studente, anzahl);
            break;
        case 5:
            printf("Programm beendet!\n");
            break;

        
        
        default:
            printf("Falsche Zahl! (1) Studierende hinzufügen. (2) Alle Studierenden anzeigen. (3) nach einem Studierenden suchen. (4) Durchschnittnote aller Studierenden berechnen. (5) Programm beenden.\n");
            break;
        }
    } while (auswahl != 5);


}


void studentHinzufügen(struct Student studente[], int* anzahl) {
    if  (*anzahl >= maxStudente) {
        printf_s("Die Liste ist voll.\n");
        return;
    }
    printf_s("Den Namen eingeben: ");
    getchar();                                                      
    fgets(studente[*anzahl].name, maxNamenlänge, stdin);                        
    studente[*anzahl].name[strcspn(studente[*anzahl].name, "\n")] = 0;              

    printf_s("Martikelnummer hinzufuegen: ");                                       
    scanf_s("%d", &studente[*anzahl].marticulationNumber);

    printf_s("Noten eigeben:\n");
    for (int i = 0; i < maxNote; i++) {
        printf_s("Note %d: ", i + 1);
        scanf_s("%f", &studente[*anzahl].grade[i]);
    }
    (*anzahl)++;                                                                   
    printf_s("Student wurde hinzugefuegt.\n");


}


void showStudent(const struct Student studente[], int anzahl) {
    if (anzahl == 0) {
        printf_s("Die Liste ist leer!\n");
        return;
    }

    for (int i = 0; i < anzahl; i++) {
        printf_s("Name: %s, Matrikelnummer: %d, Noten: ", studente[i].name, studente[i].marticulationNumber);
        for (int j = 0; j < maxNote; j++) {
            printf_s("%.2f", studente[i].grade[j]);
        }
        printf_s("\n");
    }
}

void seekStudent(const struct Student studente[], int anzahl) {
       int martikelNumber;
       printf_s("Gebe die Martikelnummer von der Person ein, die du suchst:");
       scanf_s("%d", &martikelNumber);
 

    for (int i = 0; i < anzahl; i++) {
        if (studente[i].marticulationNumber == martikelNumber) {
        printf_s("Name: %s, Martikelnummer: %d\n", studente[i].name, studente[i].marticulationNumber);
        printf_s("Noten: ");
        for (int j = 0; j < maxNote; j++) {
            printf_s("%.2f", studente[i].grade[j]);
        }
        return;
       }
    }
    printf_s("%d wurde nicht gefunden!\n", martikelNumber);
}

void calculateAverageOffAllStudents(struct Student studente[], int anzahl) {
    int totalGrades = 0;
    float sum = 0;
    for (int i = 0; i < anzahl; i++) {
        for (int j = 0; j < maxNote; j++) {
            sum += studente[i].grade[j];
            totalGrades++;

        }
    }

    float average = totalGrades > 0 ? sum / totalGrades : 0;
    printf_s("Die Durchschnittsnote aller Studenten ist: %.2f\n", average);

}