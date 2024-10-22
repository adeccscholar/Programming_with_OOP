#include <stdio.h>

/*Feld mit drei Elementen, die Felder mit 3 int- Elementen sind */
int Feld[3][3] = { { 3, 2, 4 }, { 5, 1, 6 }, { 6, 2, 4 } };

void main(void) {
	int i, j;
	for(i=0;i<3;i++) {
		for(j=0;j<3;j++) printf("%3d",Feld[i][j]);
		printf("\n");
		}
	return;
	}
