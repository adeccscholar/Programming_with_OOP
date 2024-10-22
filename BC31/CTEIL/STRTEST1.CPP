/* Beispiel: Arbeiten mit nullterminierten Zeichenfolgen    */
/* Datei: strtest1.cpp                                      */
/* eigene Implementierung der Standard- Stringfunktionen    */
/* Volker Hillmann: Objektorientiertes Programmieren in C++ */

#include <stdio.h>
#include "mystring.h"

/* Sie dürfen auf keinen Fall string.h einbinden */

/* Einsatz der Stringfunktionen */
void main(void) {
	char Satz[81], Satz1[25], Satz2[25], *PosPt;
	int Position, Comp;
	strcpy(Satz,"Stringfunktionen in C");
	printf("Satz1: %s\n\n",Satz);
	strcpy(Satz1," selbst programmiert!");
	printf("Satz2: %s\n",Satz1);
	strcpy(Satz2," selbst");
	strcat(Satz2," programmiert!");
	printf("Satz3: %s\n",Satz2);
	Comp = strcmp(Satz1, Satz2);
	printf("Comp = %d\n\n",Comp);
	strcat(Satz, Satz1);
	printf("%s\n", Satz);
	PosPt = strchr(Satz, 'C');
	if(PosPt!=NULL)
		Position = PosPt-Satz +1; /* Diff. von Treffer und Satzbeginn+1 */
	else
		Position = 0;
	printf("Das \'C\' steht an der %d. Position\n",Position);
	return;
	}
