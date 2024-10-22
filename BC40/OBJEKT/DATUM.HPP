// Definition der Klasse Datum
// Bestandteil der Klasse Bekannter
// Autor: Volker Hillmann
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

#ifndef __DATUM_HPP
#define __DATUM_HPP

#include <iostream.h>

// Die Klasse Datum stellt die Eigenschaften eines Datums bereit
class Datum {
		friend ostream& operator << (ostream&,Datum&);
		int aTag, aMonat, aJahr;
	public:
		Datum(void);								// Standardkonstruktor
		Datum(int, int, int);					// Konstruktor mit Initialisierung
		Datum(Datum&);							// Kopierkonstruktor
		int Tag(void);
		int Tag(int);
		int Monat(void);
		int Monat(int);
		int Jahr(void);
		int Jahr(int);
		void ZeigeDatum(ostream&);
	};

#endif