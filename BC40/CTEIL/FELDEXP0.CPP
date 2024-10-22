/* Beispiel für die Arbeit mit einem Feld */
/* Anlegen eines Feldes mit 10 Elementen */
#include <stdio.h>

#define MAX 10

int Feld[MAX];

int main(void) {
	int i;
	/* Alle Feldelemente mit aufsteigenden Zahlen von 1..50 belegen */
	for(i=0;i<MAX;i+=1)  /* Wertebereich läuft von 0 bis 49 */
		Feld[i]=i+1;
	/* Diese Zahlen auf die Standardausgabe schreiben */
	for(i=0;i<MAX;i+=1)
		printf("Feld[%2d] = %2d\n",i,Feld[i]) ;
	return 0;
	}