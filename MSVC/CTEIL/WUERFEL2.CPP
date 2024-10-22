#include <stdio.h>
#include <stdlib.h>

#define voll

#if defined test
	#define maxsize     20
	#define satz "demoversion des programms\n"
#elif defined level1
	#define maxsize    500
	#define satz "lightversion des programms\n"
	int ergebnis[6];
#else
   	#define maxsize  10000
	#define satz "vollversion des programms\n"
	int ergebnis[6];
#endif
    
#if defined _MSC_VER 
        
	#include <math.h>
	#include <time.h>

	void randomize(void) {
   		srand( (unsigned)time( NULL ) );
		return;
		}
	

	int random(int x) {
		return (int)floor(((float)rand()/(float)RAND_MAX) * x);
		// return (int)floor(rand());
		}

#endif
    
int feld[maxsize], i;

int main(void) {
	printf(satz);
	randomize();
	for(i=0;i<maxsize;i++) feld[i] = random(6) + 1;
	#ifdef test
		printf("ergebnisse in testversion auszugeben: \n");
		for(i=0;i<maxsize;i++) printf("feld[%4d] = %d\n",i+1,feld[i]);
	#else
		for(i=0;i<6;i++) ergebnis[i]=0;
		for(i=0;i<maxsize;i++) ergebnis[feld[i]-1]+=1;
		printf("auswertung der ergebnisse: \n");
		for(i=0;i<6;i++) printf("%d ist %3d mal gewürfelt\n",i+1,ergebnis[i]);
	#endif
	return(0);
	}
	