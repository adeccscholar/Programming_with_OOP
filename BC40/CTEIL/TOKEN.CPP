/* Demonstrations der Grundsymboleverbindung */
#include <stdio.h>
#define  ZGVAR(para)  printf("Variable%d = %d\n",para,variable ## para)

int variable1 = 5, variable2 = 3, variable3 = variable1 + variable2;

int main(void) {
	ZGVAR(1);
	ZGVAR(2);
	ZGVAR(3);
	return(0);
	}