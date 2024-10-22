
// Die Klasse Adresse

#include "adresse.hpp"

Adresse::Adresse(void) { };

Adresse::Adresse(char* s, char *o, char* p) {
   aStrasse = s;
   aOrt     = o;
   aPLZ     = p;
   }

Adresse::Adresse(Adresse& a) {
   aStrasse = a.aStrasse;
   aOrt     = a.aOrt;
   aPLZ     = a.aPLZ;
   }

char* Adresse::Strasse(void)    { return aStrasse.GetString(); }
char* Adresse::Strasse(char* s) { return aStrasse.SetString(s); }
char* Adresse::Ort(void)        { return aOrt.GetString(); }
char* Adresse::Ort(char* s)     { return aOrt.SetString(s); }
char* Adresse::PLZ(void)        { return aPLZ.GetString(); }
char* Adresse::PLZ(char* s)     { return aPLZ.SetString(s); }

void Adresse::ZeigeAdresse(ostream& os) {
	os << aStrasse << endl;
	os << aOrt << endl;
	os << aPLZ << endl;
	return;
	}


ostream& operator << (ostream& os,Adresse& a) {
	return os << a.aStrasse << endl
			  <<  a.aPLZ << " " << a.aOrt << endl;
   }
