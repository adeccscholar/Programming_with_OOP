/* Beispielprogramm: Zinsberechnungen                            */
/* Funktionen fuer Bestimmung von Zinssätzen, Raten, Restschuld  */
/* Volker Hillmann, Objektorientierte Programmierung in C++      */

#define _CRT_SECURE_NO_WARNINGS

#include <math.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

/* Rundungsfunktion auf n Stellen nach dem Komma */

long double Runde(long double wert,int stellen) {
	return floor( wert * pow(10,stellen) + 0.50001 ) / pow(10,stellen);
	}


/* Funktion, um Gleitzahl mit Komma einlesen zu können */

long double Lese(const char *tmp) {
	char *pt;
	int len = strlen(tmp);
	char *modifiable = (char*)malloc(len + 1);
	strncpy(modifiable, tmp, len);
	modifiable[len] = '\0';
	if((pt=strchr(modifiable,',')) != NULL) *pt = '.';
	long double retval = atof(modifiable);
	free(modifiable);
	return retval;
	}


/* effektive Zinsrate bei einer unterjaehrigen Verzinsung */

long double EffektivZins(long double j, long double m) {
	return powl(1 + j / m, m) - 1;
	}

/* aequivalente Zinsratebei unterjaehriger Verzinsung */

long double NominalZins(long double i, long double m) {
	return m * (powl(1+i, 1 / m) - 1);
	}


/* Zeitwertfaktor fuer einen vorgebenen Zins und n Zahlungen */

long double ZeitWertFaktor(int n,long double i) {
	long double q = 1 + i;
	long double v = 1.0l / q;
	return  v * (powl(v,n) / (v-1) - 1 / ( v - 1));
	}


/* Rate, bei vorgegebener Schuld, Laufzeit, Zins und ZahlWeise */

long double Rate(long double S0, long double i,long double n) {
return Runde(S0 / ZeitWertFaktor(static_cast<int>(n), i),2);
}


/* Laufzeit eines Kredit bestimmen */

long double LaufZeit(long double S0, long double i, long double t) {
	long double Z1 = S0 * i;	/* Zinsanteil der ersten Rate    */
	long double T1 = S0 * t;	/* gewuenschte Tilgung zu Beginn */
	long double A  = Z1 + T1;
	long double q  = 1 + i;
	long double v  = 1 / q;
	long double an = S0 / A;
	return(logl( ((v-1) * an) / v + 1) / logl(v));
	}


/* Restschuld nach n Zahlungen */

long double RestSchuld(long double S0, long double i,long double k,
							   long double n) {
		long double A  = Rate( S0, i, n);
		long double Z1 = S0 * i;
		long double T1 = A - Z1;
		long double q  = 1 + i;
		long double sk = ( powl( q, k) -1 ) / ( q - 1 );
		long double Sk = S0 - T1 * sk;
		return Sk;
		}