/* Beispielprogramm: Zeiger auf Funktionen */
/* Volker Hillmann */

#include <stdio.h>

int (*funcPt)(int, int);

int Funk1(int a, int b) {
	return(a * b);
	}

int Funk2(int a, int b) {
	return(a + b);
	}

int main(void) {
	int a = 5, b = 3;
	funcPt = Funk1;
	printf("Funktion 1: %d * %d = %d\n", a, b, (*funcPt)(a,b));
	funcPt = Funk2;
	printf("Funktion 2: %d + %d = %d\n", a, b, (*funcPt)(a,b));
	return 0;
	}
