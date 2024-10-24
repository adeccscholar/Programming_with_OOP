/* Beispielprogramm: Zinsberechnungen                            */
/* Headerdatei mit Prototypen der finazmathematischen Funktionen */
/* Volker Hillmann, Objektorientierte Programmierung in C++      */

#ifndef __ZINS2_H
#define __ZINS2_H

long double Runde(long double, int);
long double Lese(const char*); // !2024!
long double EffektivZins(long double j, long double m);
long double NominalZins(long double i, long double m);
long double ZeitWertFaktor(int n,long double i);
long double Rate(long double S0, long double i,long double n);
long double LaufZeit(long double S0, long double i, long double t);
long double RestSchuld(long double S0, long double i, long double k,
								   long double n);

#endif
