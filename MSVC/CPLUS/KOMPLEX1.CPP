// Überladen des Operators +
#include <stdio.h>

struct KomplexeZahl {
	float Re, Im;
	};

KomplexeZahl Ergebnis, Summand1, Summand2, Summand3;

KomplexeZahl Addiere(KomplexeZahl S1,KomplexeZahl S2) {
	KomplexeZahl z;
	z.Re=S1.Re+S2.Re;
	z.Im=S1.Im+=S2.Im;
	return z;
	}

int main(void) {
	Summand1.Re=3.0;
	Summand1.Im=1.5;
	Summand2.Re=4.0;
	Summand2.Im=-1.0;
	Summand3.Re=1;
    Summand3.Im=0.5;
	Ergebnis=Addiere(Summand1,Addiere(Summand2,Summand3));
	printf("Ergebis: Re: %f Im: %f\n",Ergebnis.Re,Ergebnis.Im);
	return 0;
	}