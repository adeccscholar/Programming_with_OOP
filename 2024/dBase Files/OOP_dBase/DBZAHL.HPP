// Definition der Klasse DBZahl
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

// Originale Quellen von 1994 (pre Standard)
// Überarbeitung für den Stream, minimale notwendige Anpassungen 
// für aktuelle Compiler, hier Visual Studio 2022
// Volker Hillmann, 24.10.2024
// MIT License

#ifndef __DBZAHL_HPP
#define __DBZAHL_HPP

#include <iostream> // !2024! Anpassung für modernes C++, Wegfall von .h für Standardheader
#include "dbobjekt.hpp"

using namespace std;  // !2024! Anpassung für modernes C++, provisorisches Öffnen der Namesräume


class DBZahl : public DBObjekt {
	friend ostream& operator << (ostream&, DBZahl&);
	protected:
		int aKomma;
	public:
		DBZahl(void);
		DBZahl(DBZahl&);
		DBZahl(char*, int, int = 0);
		DBZahl(int,int = 15);
		DBZahl(float,int = 12,int = 2);

		virtual char* Zuordnen(char*, int = 15,int = 0);
		virtual const int DBObjektTyp(void) { return dbzahl; };
		virtual void Display(ostream&);

		int NachKomma(void)  { return aKomma; };
        int NachKomma(int i) { return aKomma = i; };

		DBZahl operator = (DBZahl);
		DBZahl operator = (float);
		operator float();

		DBZahl operator ++();
		DBZahl operator +=(int);
		DBZahl operator --();
		DBZahl operator -=(int);
		DBZahl operator *=(float);
		DBZahl operator /=(float);
		DBZahl operator %=(int);

	};

#endif
