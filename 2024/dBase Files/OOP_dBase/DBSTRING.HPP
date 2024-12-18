// Definition der Klasse DBString
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

// Originale Quellen von 1994 (pre Standard)
// �berarbeitung f�r den Stream, minimale notwendige Anpassungen 
// f�r aktuelle Compiler, hier Visual Studio 2022
// Volker Hillmann, 24.10.2024
// MIT License

#ifndef __DBSTRING_HPP
#define __DBSTRING_HPP

#include <iostream>     // !2024! Anpassung f�r modernes C++, Wegfall von .h f�r Standardheader
#include "dbobjekt.hpp"

#include "mystring.hpp"

using namespace std;  // !2024! Anpassung f�r modernes C++, provisorisches �ffnen der Namesr�ume

class DBString : public DBObjekt {
	public:
		DBString(void);
		DBString(DBString&);
		DBString(const char*, int);
		DBString(const char*);
		DBString(String);

		virtual const int DBObjektTyp(void) { return dbstring; };
		virtual void Display(ostream&);

		DBString operator = (String);
		DBString operator = (const char*); // !2024!
		
		operator String();
		int operator <  (DBString);
		int operator <= (DBString);
		int operator >  (DBString);
		int operator >= (DBString);
		int operator == (DBString);
		int operator != (DBString);
		DBString operator += (DBString);
	};

#endif
