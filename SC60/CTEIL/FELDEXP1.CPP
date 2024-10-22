#include <stdio.h>

char Feld[4][4];

void main(void) {
	int i,j;
	char k;
	char (*PtInt1)[4];	   	/* eine Zeiger auf char[4] Variable */
	char *PtInt2;		   	/* ein Zeiger auf char */
	PtInt1 = Feld;		 	/* FeldVariable zuweisen */
	PtInt2 = &Feld[0][0];	/* Zeiger aufs erste Element des Feldes setzen */

    /* Füllen des Feldes mit Werten von 1 bis 16 */
	for(i=0,k='A';i<4;i++)
		for(j=0;j<4;j++,k++)
		   Feld[i][j] = k;	/* Zugriff über Indexoperator */

	printf("Ausgabe mit Indexoperator\n");
	for(i=0;i<4;i++) {
		for(j=0;j<4;j++)
			printf(" %c  ",Feld[i][j]);
		printf("\n");
        }
	printf("Ausgabe mit übers Feld \"laufenden\" Zeiger\n");
	for(i=0;i<4;i++) {
		for(j=0;j<4;j++,PtInt2++)
			printf(" %c  ",*(PtInt2));
        printf("\n");
        }
	printf("Ausgabe mit Zeigerarithmetik\n");
	for(i=0;i<4;i++) {
		for(j=0;j<4;j++)
		   printf(" %c  ",*(*(PtInt1+i)+j));
		printf("\n");
        }
	printf("Ausgabe mit Mischen von Indexoperator und Zeigerarithmetik\n");
	for(i=0;i<4;i++) {
		for(j=0;j<4;j++)
		   printf(" %c  ",*(Feld[i]+j));
		printf("\n");
        }
	return;
	}