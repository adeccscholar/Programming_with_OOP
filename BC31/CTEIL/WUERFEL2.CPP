	#include <stdio.h>
	#include <stdlib.h>

	#define VOLL

	#if defined TEST
		#define MAXSIZE     20
		#define SATZ "Demoversion des Programms\n"
	#elif defined LEVEL1
   		#define MAXSIZE    500
		#define SATZ "Lightversion des Programms\n"
		int Ergebnis[6];
	#else
   		#define MAXSIZE  10000
		#define SATZ "Vollversion des Programms\n"
		int Ergebnis[6];
	#endif

	int Feld[MAXSIZE], i;

	int main(void) {
		printf(SATZ);
		randomize();
		for(i=0;i<MAXSIZE;i++) Feld[i] = random(6) + 1;
		#ifdef TEST
			printf("Ergebnisse in Testversion auszugeben: \n");
			for(i=0;i<MAXSIZE;i++) printf("Feld[%4d] = %d\n",i+1,Feld[i]);
		#else
			for(i=0;i<6;i++) Ergebnis[i]=0;
			for(i=0;i<MAXSIZE;i++) Ergebnis[Feld[i]-1]+=1;
			printf("Auswertung der Ergebnisse: \n");
			for(i=0;i<6;i++) printf("%d ist %3d mal gewürfelt\n",i+1,Ergebnis[i]);
		#endif
		return(0);
		}