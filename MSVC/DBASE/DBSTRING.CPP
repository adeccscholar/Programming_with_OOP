// Implementierung der Klasse DBString
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

#include <iostream.h>
#include <iomanip.h>

#include "dbstring.hpp"
#include "mystring.hpp"

DBString::DBString(void) : DBObjekt() { };

DBString::DBString(DBString& ds) : DBObjekt(ds.laenge) {
	strncpy(puffer,ds.puffer,ds.laenge);
	}

DBString::DBString(char* p) : DBObjekt(p,strlen(p)+1) {
	strncpy(puffer,p,strlen(p));
	puffer[strlen(p)]='\0';
	};

DBString::DBString(char* p, int l) : DBObjekt(p,l) { };


DBString::DBString(String str) : DBObjekt(str.GetLen()) {
	*this = str;
	}

DBString DBString::operator = (String str) {
	register int i;
	char *pt = str.GetString();
	int max = (laenge < str.GetLen() ? str.GetLen() : laenge);
	for(i=0;i<max;i++) puffer[i]= pt[i];
	for(;i<laenge;i++) puffer[i]= ' ';
	return *this;
	}

DBString DBString::operator = (char* str) {
	register int i;
	char *pt = str;                
	int stl = strlen(str);
	int max = (laenge < stl ? stl : laenge);
	for(i=0;i<max;i++) puffer[i]= pt[i];
	for(;i<laenge;i++) puffer[i]= ' ';
	return *this;
	}

DBString::operator String () {
	String str;
	char *ptl, *pt = new char[laenge+1];
	strncpy(pt,puffer,laenge);
	pt[laenge] = '\0';
	ptl = pt + strlen(pt);
	while((ptl>pt) && (*(ptl-1)==' ')) ptl--;
	*ptl = '\0';
	str = pt;
	return String(str);
	}

void DBString::Display(ostream& out) {
	ostrstream os;
	char *pt;
	os.setf(ios::fixed, ios::floatfield);
	os.setf(ios::showpoint);
	os << setiosflags(ios::left) << setw(laenge) << (String)*this << ends;
	pt = os.str();
	out << setw(laenge) << pt;
	delete [] pt;
	return;
	}


int DBString::operator <  (DBString st) {
	return ((String)*this < (String)st);
	}

int DBString::operator <= (DBString st) {
	return ((String)*this <= (String)st);
	}

int DBString::operator >  (DBString st) {
	return ((String)*this > (String)st);
	}

int DBString::operator >= (DBString st) {
	return ((String)*this >= (String)st);
	}

int DBString::operator == (DBString st) {
	return (String)*this == (String)st;
	}

int DBString::operator != (DBString st) {
	return (String)*this != (String)st;
	}


DBString DBString::operator += (DBString st) {
	String str = (String)*this;
	str += String(st);
	*this = str;
	return DBString(*this);
	}