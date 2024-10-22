/* Sichtbarkeit von Bezeichnern */
/* Volker Hillmann, Objektorientiertes Programmieren mit C++ */

#include <stdio.h>
	
int i;				/* die globale Variable i */

int Funktion1(void) {    
	float i;			/* ein lokales i vom Typ float wird definiert */
	i=2.5;				/* dem lokalen i Wert 2.5 zuweisen */
	// lokales i wird ausgegeben
	printf("Das lokale i hat den Wert %f\n",i); 		
	return 1;
	}						/* Funktionsaustritt, lokales i wird gelöscht */

void main(void) {
	int RetVal; 	/* eine lokale Variable in main */
	i=5;				/* dem globalen i wird der Wert 5 zugewiesen */
	printf("Das globale i hat den Wert %d\n",i);	/* globales i ausgeben */
	printf("Aufruf der Funktion\n");
	RetVal = Funktion1();	 /* Aufruf Funktion1 globales i wird verdeckt */
	printf("Rueckkehr aus der Funktion\n");
	printf("Das globale i hat den Wert %d\n",i);	/* globales i ausgeben */
	return;
	}					/* Programmaustritt, globales i wird gelöscht */