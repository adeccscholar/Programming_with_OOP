// Einsatz von Referenzen auf Variablen
// Volker Hillmann

// Version fuer Symantec unter MS- DOS
#if defined _WINDOWS
#error Symantec- Version muss unter DOS laufen
#endif

#include <stdio.h>

const float Pi = 3.1416;	// Eine Konstante in C++

float x1, x2,Durchmesser;
float &Umfang = x1;   // x ist eine Referenz auf die Variable Umfang
float &Inhalt = x2;

// Funktion, um Kreisumfang U zu berechnen

float BerechneUmfang(float d) {
	return Pi * d; 			// U = Pi * d
	}

// Funktion, um Flaecheninhalt A zu berechnen

float BerechneInhalt(float d) {
	return Pi * d * d / 4; 	// A = Pi * d^2 / 4
    }

int main(void) {
	char cmd;
	//Inhalt = 0;
	
	printf("Berechnungen am Kreis: \n\n");
	printf("Geben Sie bitte den Durchmesser ein. \n");
	scanf("%f",&Durchmesser);
	x1 = BerechneUmfang(Durchmesser);
    x2 = BerechneInhalt(Durchmesser);
	printf("Der Umfang ist %10.2f\n", x1); //Umfang);
    printf("Der Inhalt ist %10.2f\n", x2); //Inhalt);
    printf("\n\nDruecken Sie bitte <Enter>");
    scanf("%c",&cmd);
	return 0;
	}