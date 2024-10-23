// Definition der Klasse DBObjekt
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

// Originale Quellen von 1994 (pre Standard)
// Überarbeitung für den Stream, minimale notwendige Anpassungen 
// für aktuelle Compiler, hier Visual Studio 2022
// Volker Hillmann, 24.10.2024
// MIT License

#define _CRT_SECURE_NO_WARNINGS

// error C4996: 'strncpy': This function or variable may be unsafe. 
// Consider using strncpy_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. 
// See online help for details.

#include "dbobjekt.hpp"

DBObjekt::DBObjekt(int l) {
	puffer = new char[l];
	if(puffer==0) {
		Dynamisch = -1;
		laenge = 0;
		}
	else {
		Dynamisch = 1;
		laenge = l;
		}
	}



DBObjekt::DBObjekt(const char* p, int l) {
	puffer = new char[l];
	if (puffer == 0) Dynamisch = -1;
	else {
	   if(p == 0) {
   		Dynamisch = 1;
	   	laenge = l;
		   }
    	else {
		   Dynamisch = 1;
			strncpy(puffer, p, l);
		   laenge = l;
		   }
	    }
   }

DBObjekt::~DBObjekt(void) {
	if(Dynamisch == 1) delete [] puffer;
	}

char* DBObjekt::Zuordnen(char* p, int l,int) {
	if(Dynamisch == 1) delete [] puffer;
	if(p!=0) {
		Dynamisch = 0;
		laenge = l;
		puffer = p;
		return p;
		}
	puffer = new char[l];
	if(puffer != 0) {
		Dynamisch = 1;
		laenge = l;
		return puffer;
		}
	Dynamisch = -1;
	return 0;
	}

