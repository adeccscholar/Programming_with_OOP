// Implementierung der Klasse DBZahl
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0


#include <iostream.h>
#include <strstrea.h>
#include <iomanip.h>
#include <string.h>
#include "dbzahl.hpp"

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
	int Zahl = (float)*this;
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

