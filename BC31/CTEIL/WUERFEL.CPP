/* Ein Würfelprogramm, dynamischer Speicher und der Feldindex- Operator */
/* Volker Hillmann */

#include <stdio.h>
#include <stdlib.h>

int *ZeigerAufInt, i, max;

int main(void) {
	printf("Wie oft wollen Sie würfeln: ");
	scanf("%d",&max);
	/* Speicherplatz anfordern */
	ZeigerAufInt = (int *)malloc(sizeof(int)*max);
	if(ZeigerAufInt == NULL) {
		printf("kein Speicher für %d Feldelemente\n",max);
		return(1);
		}
	else {
		/* Initialiseren des Zufallszahlengenerators mit Systemzeit */
		randomize();
		for(i=0;i<max;i++)
			ZeigerAufInt[i] = 1 + random(6);
		/* Ausgabe der zufälligen Werte */
		printf("Sie haben gewürfelt: \n");
		for(i=0;i<max;i++)
			printf("%3d. Versuch: %d\n",i+1,ZeigerAufInt[i]);
		/* Freigeben des Speicherplatz (!!! nicht vergessen !!!) */
		free(ZeigerAufInt);
		};
	return 0;
	}