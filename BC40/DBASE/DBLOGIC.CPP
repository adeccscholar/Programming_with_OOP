// Implemtierung der Klasse DBLogical
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0


#include <iostream.h>
#include "dblogic.hpp"


DBLogical::DBLogical(void) : DBObjekt(1) { };

DBLogical::DBLogical(DBLogical& loc) : DBObjekt(1) {
	*puffer = *loc.puffer;
	}


DBLogical::DBLogical(char* p) : DBObjekt(p,1) { }

DBLogical::DBLogical(int i) {
	*this = i;
	}


char* DBLogical::Zuordnen(char* p, int l,int) {
	return DBObjekt::Zuordnen(p,l);
	}

void DBLogical::Display(ostream& out) {
	if((int)*this == 1) out << 'J';
	else out << 'N';
	return;
	}

DBLogical DBLogical::operator = (DBLogical loc) {
	*puffer = *loc.puffer;
	return *this;
	}

DBLogical DBLogical::operator = (int w) {
	switch(w) {
		case 'T':
		case 'Y':
		case 'J':
		case  1 :
		case 't':
		case 'y':
		case 'j': *puffer='T'; break;
		case 'F':
		case 'N':
		case  0 :
		case 'f':
		case 'n': *puffer='F'; break;
		default: *puffer=' ';
		}
	return *this;
	}


DBLogical::operator int() {
	switch(*puffer) {
		case 'T':
		case 't':
		case 'J':
		case 'j': return 1;
		case 'F':
		case 'f':
		case 'N':
		case 'n': return 0;
		}
	return 0;
	}

