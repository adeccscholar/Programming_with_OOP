// Definition der Klasse DBZahl
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

#ifndef __DBZAHL_HPP
#define __DBZAHL_HPP

#include <iostream.h>
#include "dbobjekt.hpp"


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
