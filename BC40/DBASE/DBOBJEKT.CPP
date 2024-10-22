// Definition der Klasse DBObjekt
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

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



DBObjekt::DBObjekt(char* p, int l) {
	if(p == 0) {
		puffer = new char[l];
		if(puffer==0) Dynamisch = -1;
		else {
			Dynamisch = 1;
			laenge = l;
			}
		}
	else {
		Dynamisch = 0;
		puffer = p;
		laenge = l;
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

