// Auswahl der Funktionen über Bezeichner und Parameterliste
// Objektorientiertes Programmieren mit C++

#include <stdio.h>

int Input(int &IntVar) {				// Parameter Wert vom Typ int
	printf("Ganzzahl eingeben:	");
	return scanf("%d",&IntVar);
	}

int Input(float &FloatVar) {		// Parameter Wert vom Typ float
	printf("Gleitzahl eingeben:	");
	return scanf("%f",&FloatVar);
	}

int Input(char* StringVar) {		// Parameter Zeiger auf char
	printf("String eingeben:	");
	return scanf("%s",StringVar);
	}

int main(void) {
	char Feld[21];
	int GanzeZahl;
	float GleitZahl;
	printf("Beispiel für die Funktionsauswahl durch den Compiler\n\n");
	Input(GleitZahl);
	Input(GanzeZahl);
	Input(Feld);
	printf("\Ihre Eingabe waren:\n");
	printf("Ganzzahl:\t%d\n",GanzeZahl);
	printf("Gleitzahl:\t%f\n",GleitZahl);
	printf("Satz:    \t%s\n",Feld);
	return 0;
	}