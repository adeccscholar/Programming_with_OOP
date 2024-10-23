// Implementierung der Klasse DBZahl
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

#include <iostream>    // !2024! Anpassung für modernes C++, Wegfall von .h für Standardheader
#include <strstream>   // !2024! Anpassung für modernes C++, Änderung des alten Headernames (8.3)
#include <iomanip>     // !2024! Anpassung für modernes C++, Wegfall von .h für Standardheader
#include <string.h>
#include "dbzahl.hpp"

using namespace std;  // !2024! Anpassung für modernes C++, provisorisches Öffnen der Namesräume


DBZahl::DBZahl(void) : DBObjekt(15) { };

DBZahl::DBZahl(DBZahl& dat) : DBObjekt(dat.laenge) {
	strncpy(puffer,dat.puffer,dat.laenge);
	aKomma = dat.aKomma;
	};

DBZahl::DBZahl(char* p, int l,int k) : DBObjekt(p,l), aKomma(k) { };

DBZahl::DBZahl(int z,int l) : DBObjekt(l) {
	ostrstream os(puffer,laenge);
	aKomma = 0;
	os.setf(ios::fixed, ios::floatfield);
	os.setf(ios::showpoint);
	os << setw(laenge) << setprecision(aKomma) << z;
	}

DBZahl::DBZahl(float z,int l,int k) : DBObjekt(l+k+1) {
	ostrstream os(puffer,laenge);
	aKomma = k;
	os.setf(ios::fixed, ios::floatfield);
	os.setf(ios::showpoint);
	os << setw(laenge) << setprecision(aKomma) << z;
	}

char* DBZahl::Zuordnen(char* p, int l,int k) {
	aKomma = k;
	return DBObjekt::Zuordnen(p,l);
	}

 void DBZahl::Display(ostream& out) {
	ostrstream os;
	char *pt;
	os.setf(ios::fixed, ios::floatfield);
	os.setf(ios::showpoint);
	os << setw(laenge) << setprecision(aKomma) << (float)*this << ends;
	pt=os.str();
	out << pt;
	delete [] pt;
	return;
	}


DBZahl DBZahl::operator = (DBZahl dat) {
	float zw = dat;
	return *this = zw;
	}

DBZahl DBZahl::operator = (float zw) {
	ostrstream os(puffer,laenge);
	os.setf(ios::fixed, ios::floatfield);
	os.setf(ios::showpoint);
	os << setw(laenge) << setprecision(aKomma) << zw;
	return *this;
	}


DBZahl::operator float() {
	istrstream ins(puffer, laenge);
	float tmp;
	ins.setf(ios::fixed, ios::floatfield);
	ins.setf(ios::showpoint);
	ins >> tmp;
	return tmp;
	}


DBZahl DBZahl::operator ++(void) {
	float Zahl = (float)*this;
	Zahl++;
	return *this = Zahl;
	}

DBZahl DBZahl::operator +=(int z) {
	float Zahl = (float)*this;
	Zahl += z;
	return *this = Zahl;
	}

DBZahl DBZahl::operator --(void) {
	float Zahl = (float)*this;
	Zahl--;
	return *this = Zahl;
	}

DBZahl DBZahl::operator -=(int z) {
	float Zahl = (float)*this;
	Zahl -= z;
	return *this = Zahl;
	}

DBZahl DBZahl::operator *=(float z) {
	float Zahl = (float)*this;
	Zahl *= z;
	return *this = Zahl;
	}

DBZahl DBZahl::operator /=(float z) {
	float Zahl = (float)*this;
	Zahl /= z;
	return *this = Zahl;
	}

DBZahl DBZahl::operator %=(int z) {
	int Zahl = (float)*this;  // !2024!  warning C4244: "Initialisierung": Konvertierung von "float" in "int", möglicher Datenverlust
	Zahl %= z;
	*this = DBZahl(Zahl);
	return *this;
	}

ostream& operator << (ostream& out, DBZahl& z) {
	float zahl = z;
	out.setf(ios::fixed, ios::floatfield);
	out.setf(ios::showpoint);
	return out << setw(z.Laenge()) << setprecision(z.NachKomma()) << zahl;
    }

