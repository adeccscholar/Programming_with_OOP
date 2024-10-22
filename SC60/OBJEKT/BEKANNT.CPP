
#include <iostream.h>
#include "bekannt.hpp"


// Bekannter
Bekannter::Bekannter(void) : Person() { }

Bekannter::Bekannter(char* name, char* vorname,
					 int tag, int monat, int jahr,
					 char* strasse, char* ort, char* plz) :
		   Person(name,vorname),Geburtstag(tag,monat,jahr),
		   Anschrift(strasse,ort,plz) { }

Bekannter::Bekannter(Person& p,Datum& d,Adresse& a) :
		   Person(p),Geburtstag(d),Anschrift(a) { }

Bekannter::Bekannter(Bekannter& b) :
		   Person(b.Name(),b.VorName()),
		   Geburtstag(b.Geburtstag),Anschrift(b.Anschrift) { }

Bekannter::~Bekannter(void) { }

ostream& operator << (ostream& os, Bekannter& b) {
   	os << *(Person*)&b << endl;
	return os << b.Geburtstag << endl << b.Anschrift;
	}
