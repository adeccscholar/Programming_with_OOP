// Einsatz von Referenzen auf Variablen
// Volker Hillmann


#include <stdio.h>

const float Pi = 3.1416;	// Eine Konstante in C++

float x1, x2,Durchmesser;
const float &Umfang = x1;   // x ist eine Referenz auf die Variable Umfang
const float &Inhalt = x2;

// Funktion, um Kreisumfang U zu berechnen

float BerechneUmfang(float d) {
	return Pi * d; 			// U = Pi * d
	}

// Funktion, um Flächeninhalt A zu berechnen

float BerechneInhalt(float d) {
	return Pi * d * d / 4; 	// A = Pi * d² / 4
    }

int main(void) {
	//Inhalt = 0;
	printf("Berechnungen am Kreis: \n\n");
	printf("Geben Sie bitte den Durchmesser ein. \n");
	scanf("%f",&Durchmesser);
	x1 = BerechneUmfang(Durchmesser);
    x2 = BerechneInhalt(Durchmesser);
	printf("Der Umfang ist %10.2f\n", Umfang);
	printf("Der Inhalt ist %10.2f\n", Inhalt);
	return 0;
	}