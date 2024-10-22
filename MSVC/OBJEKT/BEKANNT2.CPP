// Definition der Klasse Bekannter (Nutzung der Mehrfachen Vererbung)
// Autor: Volker Hillmann
// Objektorientiertes Programmieren mit C++


#include "bekannt2.hpp"

Bekannter_2::Bekannter_2(void) : Person(), Adresse(), Datum() { };

Bekannter_2::Bekannter_2(char* name, char* vorname,
						 int tag, int monat, int jahr,
						 char* strasse, char* ort, char* plz) :
						 Person(name, vorname), Adresse(strasse, ort, plz),
						 Datum(tag, monat, jahr) { }

Bekannter_2::Bekannter_2(Person& p, Datum& d, Adresse& a) :
						 Person(p), Datum(d), Adresse(a) { }

Bekannter_2::Bekannter_2(Bekannter_2& b) : Person(*(Person*)&b),
										 Adresse(*(Adresse*)&b),
										 Datum(*(Datum*)&b) { }


ostream& operator << (ostream& os, Bekannter_2& b) {
	return os << *(Person*)&b << endl
			  << *(Datum*)&b << endl
			  << *(Adresse*)&b << endl;
	}
