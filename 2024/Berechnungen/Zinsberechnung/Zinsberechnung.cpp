// Zinsberechnung.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#define _CRT_SECURE_NO_WARNINGS


#include "ZINS2.H"

#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;


#define MAX1    5
#define MAX2    9

long double RatenBestimmung(void) {
	char tmp[25];
	long double S0, i, n, A;
	printf("\nBestimmen einer Annuitaet\n\n");
	printf("Geben Sie die folgenden Werte ein: \n");
	printf("Anfangsschuld S0:           ");
	scanf("%s", tmp);
	S0 = Lese(tmp);
	printf("Zinssatz i (7,5%% = 0,075) : ");
	scanf("%s", tmp);
	i = Lese(tmp);
	printf("Laufzeit in Jahren:         ");
	scanf("%s", tmp);
	n = Lese(tmp);
	n *= 12;
	printf("\n");
	A = Rate(S0, i / 12, n);
	printf("Die monatliche Rate betraegt %12.2f DM\n", (float)A);
	printf("Gesamtrueckzahlung betraegt  %12.2f DM\n", (float)(A * n));
	return(A);
   }


long double LaufZeitBestimmung(void) {
	char tmp[25];
	long double S0, i, n, A, t, Z1, T1, A1, A2, n1, n2;
	printf("\nBestimmen der Laufzeit einer Annuitaet\n\n");
	printf("Geben Sie die folgenden Werte ein: \n");
	printf("Anfangsschuld S0:            ");
	scanf("%s", tmp);
	S0 = Lese(tmp);
	printf("Zinssatz i (7,5%% = 0,075) :  ");
	scanf("%s", tmp);
	i = Lese(tmp);
	Z1 = S0 * i / 12;
	printf("Zinsanteil der 1. Rate:      %10.2f DM\n", (float)Z1);
	do {
		printf("Rate eingeben (>Zinsanteil): ");
		scanf("%s", tmp);
		A = Lese(tmp);
	} while (A <= Z1);
	printf("Die Angabe der Raten ist nur ein Richtwert zur "
		"Berechnung der Tilgung\n");
	T1 = A - Z1;
	t = T1 * 12 * 100 / S0;		/* Tilgung bestimmen			   */
	t /= 100;							/* t in Prozentschreibw. 1% = 0,01 */
	n = LaufZeit(S0, i / 12, t / 12);
	n1 = floorl(n / 12) * 12;
	n2 = ceill(n / 12) * 12;
	A1 = Rate(S0, i / 12, n1);
	A2 = Rate(S0, i / 12, n2);
	printf("\n");
	A = Rate(S0, i / 12, n);
	T1 = A - Z1;
	printf("Für die Anfangsschuld S0           %12.2f DM\n", (float)S0);
	printf("und eine anfaengliche Tilgung von  %12.5f %%\n", (float)t);
	printf("betraegt der anteilige Zinsteil    %12.2f DM\n", (float)Z1);
	printf("und der 1. Tilgungsanteil          %12.2f DM\n", (float)T1);
	printf("Daraus folgt eine Rate von         %12.2f DM\n", (float)A);
	printf("und die Laufzeit in Monaten        %12.2f\n", (float)n);
	printf("                 in Jahren         %12.2f\n", (float)(n / 12));
	printf("\nAlternativen:\n");
	printf("Laufzeit: %3d  Raten: %4d  Annuitaet: %12.2f  Tilgung: %12.2f\n",
		(int)(n1 / 12), (int)n1, (float)A1, (float)(12 * 100 * (A1 - Z1) / S0));
	printf("Laufzeit: %3d  Raten: %4d  Annuitaet: %12.2f  Tilgung: %12.2f\n",
		(int)(n2 / 12), (int)n2, (float)A2, (float)(12 * 100 * (A2 - Z1) / S0));
	return(n);
}

long double RestSchuldBestimmung(void) {
	char tmp[25];
	long double S0, i, n, k, A, Sk;
	printf("\nBestimmen einer Restschuld zu einem Kredit\n\n");
	printf("Geben Sie die folgenden Werte ein: \n");
	printf("Anfangsschuld S0:            ");
	scanf("%s", tmp);
	S0 = Lese(tmp);
	printf("Zinssatz i (7,5%% = 0,075) :  ");
	scanf("%s", tmp);
	i = Lese(tmp);
	printf("Laufzeit in n Jahren:        ");
	scanf("%s", tmp);
	n = Lese(tmp);
	n *= 12;
	printf("Restschuld Sk nach k Jahren: ");
	scanf("%s", tmp);
	k = Lese(tmp);
	k *= 12;
	A = Rate(S0, i / 12, n);
	Sk = RestSchuld(S0, i / 12, k, n);
	printf("\n");
	printf("Die monatliche Rate betraegt                 %12.2f DM\n",
		(float)A);
	printf("Die Restschuld nach %4d Zahlungen betraegt: %12.2f DM\n",
		(int)k, (float)Sk);
	printf("Bisher getilgte Schuld betraegt              %12.2f DM\n",
		(float)(S0 - Sk));
	printf("Das entspricht                               %12.4f %%\n",
		(float)((S0 - Sk) / (S0 / 100)));
	return(Sk);
}


long double EZins(void) {
	long double nz, ez;
	char tmp[25];
	printf("\nBestimmen des effektiven Zinssatz bei monatlicher "
		"Verzinsung\n");
	printf("Geben Sie die folgenden Werte ein: \n");
	printf("Nomineller Jahreszins (7,5%% = 0,075) :  ");
	scanf("%s", tmp);
	nz = Lese(tmp);
	printf("\n");
	ez = Runde(EffektivZins(nz, 12), 5);
	printf("Der effektiver Zinssatz betraegt %8.5f\n", (float)ez);
	return(ez);
}

long double NZins(void) {
	long double nz, ez;
	char tmp[25];
	printf("\nBestimmen des nominellen Zinssatz bei unterjaehrigen "
		"Verzinsung");
	printf("\nGeben Sie die folgenden Werte ein: \n");
	printf("Nomineller Jahreszins (7,5%% = 0,075) :  ");
	scanf("%s", tmp);
	ez = Lese(tmp);
	printf("\n");
	nz = Runde(NominalZins(ez, 12), 5);
	printf("Der aequivalente Zinssatz betraegt %8.5f %%\n", (float)nz);
	printf("Der monatliche Zinsteil betraegt:  %8.5f %%\n", (float)(nz / 12));
	return(nz);
}


void Vergleich1(void) {
	long double Werte[MAX1][MAX2];
	long double ZinsSatz[MAX1];
	long double LaufZeit[MAX2];
	int Dim1, Dim2, l1, l2;
	char tmp[25];
	long double S0;
	printf("\nVergleich: Zinssaetzen und Laufzeiten, Anfangsschuld fest");
	printf("\n");
	printf("Anfangsschuld S0 eingeben:    ");
	scanf("%s", tmp);
	S0 = Lese(tmp);
	do {
		printf("Anzahl von Zinssaetzen (1..%d): ", MAX1);
		scanf("%d", &Dim1);
	} while ((Dim1 < 1) || (Dim1 > MAX1));
	do {
		printf("Anzahl von Laufzeiten  (1..%d): ", MAX2);
		scanf("%d", &Dim2);
	} while ((Dim2 < 1) || (Dim2 > MAX2));
	printf("\nZinssaetze einlesen: \n");
	for (l1 = 0; l1 < Dim1; l1++) {
		printf("%d. Zinssatz (7,5%% = 0,075):  ", l1 + 1);
		scanf("%s", tmp);
		ZinsSatz[l1] = Lese(tmp);
	}
	printf("\nLaufzeiten einlesen: \n");
	for (l2 = 0; l2 < Dim2; l2++) {
		printf("%d. Laufzeit:                ", l2 + 1);
		scanf("%s", tmp);
		LaufZeit[l2] = Lese(tmp);
	}
	printf("\n\nBerechnungen fuer S0 = %12.2f\n\n", (float)S0);
	printf("        ");
	for (l1 = 0; l1 < Dim1; l1++) printf("%12.5f", (float)ZinsSatz[l1]);
	printf("\n");
	for (l2 = 0; l2 < Dim2; l2++) {
		printf("%6d  ", (int)LaufZeit[l2]);
		for (l1 = 0; l1 < Dim1; l1++) {
			Werte[l1][l2] = Rate(S0, ZinsSatz[l1] / 12, LaufZeit[l2] * 12);
			printf("%12.2f", (float)Werte[l1][l2]);
		}
		printf("\n");
	}
	return;
}


void Vergleich2(void) {
	long double Werte[MAX1][MAX2];
	long double S0[MAX1];
	long double LaufZeit[MAX2];
	int Dim1, Dim2, l1, l2;
	char tmp[25];
	long double i;
	printf("\nVergleich: Anfangsschuld und Laufzeit, Zinssatz fest");
	printf("\n");
	printf("Zinssatz i eingeben (7,5%% = 0,075):  ");
	scanf("%s", tmp);
	i = Lese(tmp);
	do {
		printf("Anzahl von Kreditbetraegen (1..%d): ", MAX1);
		scanf("%d", &Dim1);
	} while ((Dim1 < 1) || (Dim1 > MAX1));
	do {
		printf("Anzahl von Laufzeiten      (1..%d): ", MAX2);
		scanf("%d", &Dim2);
	} while ((Dim2 < 1) || (Dim2 > MAX2));
	printf("\nAnfangsschuld S0 einlesen: \n");
	for (l1 = 0; l1 < Dim1; l1++) {
		printf("%d. Anfangsschuld:  ", l1 + 1);
		scanf("%s", tmp);
		S0[l1] = Lese(tmp);
	}
	printf("\nLaufzeiten einlesen: \n");
	for (l2 = 0; l2 < Dim2; l2++) {
		printf("%d. Laufzeit:       ", l2 + 1);
		scanf("%s", tmp);
		LaufZeit[l2] = Lese(tmp);
	}
	printf("\n\nBerechnungen fuer i = %12.5f\n\n", (float)i);
	printf("        ");
	for (l1 = 0; l1 < Dim1; l1++) printf("%12.2f", (float)S0[l1]);
	printf("\n");
	for (l2 = 0; l2 < Dim2; l2++) {
		printf("%6d  ", (int)LaufZeit[l2]);
		for (l1 = 0; l1 < Dim1; l1++) {
			Werte[l1][l2] = Rate(S0[l1], i / 12, LaufZeit[l2] * 12);
			printf("%12.2f", (float)Werte[l1][l2]);
		}
		printf("\n");
	}
	return;
}

void Vergleich3(int modus) {
	long double Werte[MAX1][MAX2];
	long double LaufZeit[MAX1];
	long double AbLaufZt[MAX2];
	int Dim1, Dim2, l1, l2;
	char tmp[25];
	long double i, S0, MaxZt;
	printf("\nVergleich: Laufzeit und Restschuld, Anfangsschuld und "
		"Zins fest");
	printf("\n");
	printf("\nAnfangsschuld S0 einlesen:         ");
	scanf("%s", tmp);
	S0 = Lese(tmp);
	printf("Zinssatz i eingeben (7,5%% = 0,075):  ");
	scanf("%s", tmp);
	i = Lese(tmp);
	do {
		printf("Anzahl von Laufzeiten   (1..%d): ", MAX1);
		scanf("%d", &Dim1);
	} while ((Dim1 < 1) || (Dim1 > MAX1));
	do {
		printf("Anzahl von Ablaufzeiten (1..%d): ", MAX2);
		scanf("%d", &Dim2);
	} while ((Dim2 < 1) || (Dim2 > MAX2));
	printf("\nLaufzeiten einlesen: \n");
	MaxZt = 0;
	for (l1 = 0; l1 < Dim1; l1++) {
		printf("%d. Laufzeit:   ", l1 + 1);
		scanf("%s", tmp);
		LaufZeit[l1] = Lese(tmp);
		if (MaxZt < LaufZeit[l1]) MaxZt = LaufZeit[l1];
	}
	printf("\nAblaufzeiten einlesen: \n");
	for (l2 = 0; l2 < Dim2; l2++) {
		printf("%d. Ablaufzeit: ", l2 + 1);
		scanf("%s", tmp);
		AbLaufZt[l2] = Lese(tmp);
	}
	printf("\n\nBerechnungen fuer S0 = %12.2f DM", (float)S0);
	printf("\n                  i  = %12.5f %%\n\n", (float)i);
	printf("        ");
	for (l1 = 0; l1 < Dim1; l1++) printf("%12.0f", (float)LaufZeit[l1]);
	printf("\n");
	for (l2 = 0; l2 < Dim2; l2++) {
		printf("%6d  ", (int)AbLaufZt[l2]);
		for (l1 = 0; l1 < Dim1; l1++) {
			if (AbLaufZt[l2] > LaufZeit[l1])
				if (modus == 1) Werte[l1][l2] = 100;
				else		 Werte[l1][l2] = 0;

			else {
				Werte[l1][l2] = RestSchuld(S0, i / 12, AbLaufZt[l2] * 12,
					LaufZeit[l1] * 12);
				if (modus == 1)
					Werte[l1][l2] = Runde((S0 - Werte[l1][l2]) /
						(S0 / 100), 2);
			}
			printf("%12.2f", (float)Werte[l1][l2]);
		}
		printf("\n");
	}
	return;
}


int Auswahl(void) {
	char cmd;
	printf("\nEinfacher Kreditratgeber\n\n");
	printf("Auswahlmenue:\n\n");
	printf("Einfache Berechnungen:\n");
	printf("[A]nnuitaet\n");
	printf("[D]auer eines Darlehens\n");
	printf("[R]estschuld\n");
	printf("[E]ffektiven Zinssatz\n");
	printf("[N]ominellen Zinssatz\n");
	printf("\nVergleichsrechnungen:\n");
	printf("[Z]inssaetze und Laufzeiten\n");
	printf("[S]chuld und Laufzeiten\n");
	printf("[L]aufzeiten und Restschuld\n");
	printf("[P]rozentualer Vergleich Laufzeit - Restschuld\n");
	printf("\n");
	printf("[B]eenden des Programmes\n\n");
	printf("Ihre Wahl -> ");
	cmd = getchar();
	if (cmd == 10) cmd = getchar();
	cmd &= 223;
	switch (cmd) {
	case 'A': return(1);
	case 'R': return(2);
	case 'E': return(3);
	case 'N': return(4);
	case 'Z': return(5);
	case 'S': return(6);
	case 'L': return(7);
	case 'P': return(8);
	case 'D': return(9);
	case 'B': return(0);
	}
	return(-1);
}

int Weiter(void) {
	char cmd;
	printf("\n");
	do {
		printf("Neue Berechnung ([j]a / [n]ein) ? -> ");
		cmd = getchar();
		if (cmd == 10) cmd = getchar();
		cmd &= 223;
	} while ((cmd != 'J') && (cmd != 'N'));
	if (cmd == 'J') return(1);
	else return(0);
}

int Run(void) {
	int Wahl;
	do {
		Wahl = Auswahl();
		switch (Wahl) {
		case 1: RatenBestimmung(); break;
		case 2:	RestSchuldBestimmung(); break;
		case 3: EZins(); break;
		case 4: NZins(); break;
		case 5: Vergleich1(); break;
		case 6: Vergleich2(); break;
		case 7: Vergleich3(0); break;
		case 8: Vergleich3(1); break;
		case 9: LaufZeitBestimmung(); break;
		}
		if ((Wahl > 0) && !Weiter()) break;
		printf("\n\n");
	} while (Wahl != 0);
	return(0);
}


int main()
{
	printf("Kleines Demoprogramm: Kreditberechnungen:\n");
	printf("Volker Hillmann, Version 27. April 1994\n");
	return Run();
}

