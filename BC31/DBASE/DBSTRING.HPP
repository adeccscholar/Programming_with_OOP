// Definition der Klasse DBString
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

#ifndef __DBSTRING_HPP
#define __DBSTRING_HPP

#include <iostream.h>
#include "dbobjekt.hpp"

#include "mystring.hpp"

class DBString : public DBObjekt {
	public:
		DBString(void);
		DBString(DBString&);
		DBString(char*, int);
		DBString(char*);
		DBString(String);

		virtual const int DBObjektTyp(void) { return dbstring; };
		virtual void Display(ostream&);

		DBString operator = (String);
		DBString operator = (char*);
		
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
