// Definition der Klasse DBLogical
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

#ifndef __DBLOGIC_HPP
#define __DBLOGIC_HPP

#include <iostream.h>
#include "dbobjekt.hpp"


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
