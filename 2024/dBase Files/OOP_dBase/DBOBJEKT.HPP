// Definition der Klasse DBObjekt
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

// Originale Quellen von 1994 (pre Standard)
// Überarbeitung für den Stream, minimale notwendige Anpassungen 
// für aktuelle Compiler, hier Visual Studio 2022
// Volker Hillmann, 24.10.2024
// MIT License

#ifndef __DBOBJEKT_HPP
#define __DBOBJEKT_HPP

#include <iostream> // !2024! Anpassung für modernes C++, Wegfall von .h für Standardheader

using namespace std;  // !2024! Anpassung für modernes C++, provisorisches Öffnen der Namesräume

enum DBObjTyp { dbdatum = 100, dbstring, dblogical, dbzahl };

class DBObjekt {
	protected:
		char *puffer;
		int laenge;
        int Dynamisch;
	public:
		DBObjekt(int = 256);
		DBObjekt(const char* p,int);
		virtual ~DBObjekt(void);
		virtual char* Zuordnen(char* p,int l=256,int = 0);
		virtual const int DBObjektTyp(void) = 0;
		virtual void Display(ostream&) = 0;
		int Laenge(void) const { return laenge; };
	};

typedef DBObjekt* PTDBObjekt;

#endif
