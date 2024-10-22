// Definition der Klasse DBObjekt
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

#ifndef __DBOBJEKT_HPP
#define __DBOBJEKT_HPP

#include <iostream.h>

enum DBObjTyp { dbdatum = 100, dbstring, dblogical, dbzahl };

class DBObjekt {
	protected:
		char *puffer;
		int laenge;
        int Dynamisch;
	public:
		DBObjekt(int = 256);
		DBObjekt(char* p,int);
		virtual ~DBObjekt(void);
		virtual char* Zuordnen(char* p,int l=256,int = 0);
		virtual const int DBObjektTyp(void) = 0;
		virtual void Display(ostream&) = 0;
		int Laenge(void) const { return laenge; };
	};

typedef DBObjekt* PTDBObjekt;

#endif
