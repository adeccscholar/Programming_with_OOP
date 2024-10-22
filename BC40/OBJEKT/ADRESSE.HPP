// Definition der Klasse Adresse
// Bestandteil der Klasse Bekannter
// Autor: Volker Hillmann
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

#ifndef __ADRESSE_HPP
#define __ADRESSE_HPP

#include <iostream.h>
#include "mystring.hpp"

// Die Klasse Adresse modelliert die Eigenschaften einer Anschrift
class Adresse {
	friend ostream& operator << (ostream&,Adresse&);
		String aStrasse;
		String aOrt;
		String aPLZ;
	public:
		Adresse(void);							// Standardkonstruktor
		Adresse(char*, char *, char*);		// Konstruktor mit Initialisierung
		Adresse(Adresse&);						// Kopierkonstruktor
		char* Strasse(void);
		char* Strasse(char*);
		char* Ort(void);
		char* Ort(char*);
		char* PLZ(void);
		char* PLZ(char*);
		void ZeigeAdresse(ostream&);
	};

#endif
