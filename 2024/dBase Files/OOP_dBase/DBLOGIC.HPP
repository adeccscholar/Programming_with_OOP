// Definition der Klasse DBLogical
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

// Originale Quellen von 1994 (pre Standard)
// Überarbeitung für den Stream, minimale notwendige Anpassungen 
// für aktuelle Compiler, hier Visual Studio 2022
// Volker Hillmann, 24.10.2024
// MIT License

#ifndef __DBLOGIC_HPP
#define __DBLOGIC_HPP

#include <iostream>  // !2024! Anpassung für modernes C++, Wegfall von .h für Standardheader
#include "dbobjekt.hpp"

using namespace std;  // !2024! Anpassung für modernes C++, provisorisches Öffnen der Namesräume


class DBLogical : public DBObjekt {
	public:
		DBLogical(void);
		DBLogical(DBLogical&);
		DBLogical(char*);
		DBLogical(int);

		virtual char* Zuordnen(char*, int = 1,int = 0);
		virtual const int DBObjektTyp(void) { return dblogical; };
		virtual void Display(ostream&);


		DBLogical operator = (DBLogical);
		DBLogical operator = (int);
		operator int();
	};

#endif
