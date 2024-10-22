/* Beispielprogramm: Ausgaben mit printf() */
#include <stdio.h>

int Breite = 8, Genauigkeit = 2;
int Tag = 2, Monat = 3, Jahr = 1994;
char *string      = "Dieses ist eine Zeichenkette";
float GleitZahl   = 10.2432;
double DGleitZahl = 10.54612;
int GanzZahl      = 12;

int main(void) {
	/* Ein Formatstring ohne Platzhalter */
	printf("Demonstrationsprogramm fuer die Standardausgabe\n");
	/* Eine Zeichenkette ausgeben */
	printf("Einen Satz: \"%s\" \n", string);
	/* Ausgabe auf Breite, mit vorgestellten Nullen */
	printf("Ein Datum %02d.%02d.%d\n", Tag, Monat, Jahr);
	/* Ganzzahl in Dezimaldarstellung */
	printf("Dezimalzahl:     %d\n", GanzZahl);
	/* Ganzzahl in Oktaldarstellung */
	printf("Oktalzahl:       %o\n", GanzZahl);
	/* Ganzzahl in Hexadezimaldarstellung */
	printf("Hexadezimalzahl: %x\n", GanzZahl);
	/* Ganzzahl in alternativer Hexadezimaldarstellung */
	printf("Hexadezimalzahl: %#x\n", GanzZahl);
	/* Eine Gleitzahl mit 8 Stellen, und 2 Nachkommastellen ausgeben */
	printf("Eine Gleitzahl:  %8.2f\n", GleitZahl);
	/* Ausgabe einer Gleitzahl mit variabler Laenge und Genauigkeit */
	printf("Eine Gleitzahl   %*.*f\n", Breite, Genauigkeit, GleitZahl);
	/* Eine Gleitzahl in Exponential- Darstellung */
	printf("Eine Gleitzahl:  %e\n", GleitZahl);
	/* Eine double- Gleitzahl ausgeben */
	printf("Double- Zahl:   %10.2lf\n", DGleitZahl);
	return(0);
	}