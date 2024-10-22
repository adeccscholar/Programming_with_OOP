/* Beispiel scanf()- Einlesen von Daten von der Standardeingabe */
/* Volker Hillmann */

#include <stdio.h>

int GanzZahl;
float GleitZahl;
char aString[81];

int main(void) {
	char cmd;
	printf("Einlesen mit scanf()\n");
	printf("Geben Sie bitte Ihren Namen ein: ");
	scanf("%80s", aString);
	printf("Wie alt sind Sie: ");
	scanf("%d", &GanzZahl);
	printf("Geben Sie eine Gleitzahl ein: ");
	scanf("%f", &GleitZahl);
	printf("Ihre Eingaben:\n");
	printf("Sie heissen %s und sind %d Jahre alt!\n", aString, GanzZahl);
	printf("Sie haben die Zahl %f eingegeben.\n", GleitZahl);
	printf("Bitte <Enter> druecken");
	scanf("%c",&cmd);
	return(0);
	}