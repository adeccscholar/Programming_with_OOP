// Implementierung der Klasse DBString
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

// Originale Quellen von 1994 (pre Standard)
// Überarbeitung für den Stream, minimale notwendige Anpassungen 
// für aktuelle Compiler, hier Visual Studio 2022
// Volker Hillmann, 24.10.2024
// MIT License

#define _CRT_SECURE_NO_WARNINGS

// error C4996: 'strncpy': This function or variable may be unsafe. 
// Consider using strncpy_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. 
// See online help for details.


#include <iostream>   // !2024! Anpassung für modernes C++, Wegfall von .h für Standardheader
#include <iomanip>    // !2024! Anpassung für modernes C++, Wegfall von .h für Standardheader

#include "dbstring.hpp"
#include "mystring.hpp"

using namespace std;  // !2024! Anpassung für modernes C++, provisorisches Öffnen der Namesräume


DBString::DBString(void) : DBObjekt() { };

DBString::DBString(DBString& ds) : DBObjekt(ds.laenge) {
	strncpy(puffer,ds.puffer,ds.laenge);
	}

DBString::DBString(const char* p) : DBObjekt(p,strlen(p)+1) {
	strncpy(puffer,p,strlen(p));
	puffer[strlen(p)]='\0';
	};

DBString::DBString(const char* p, int l) : DBObjekt(p,l) { };


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

DBString DBString::operator = (const char* str) {
	register int i;
	const char *pt = str;                
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
	String tmp(*this);
	os << setiosflags(ios::left) << setw(laenge) << tmp << ends;
	pt = os.str();
	out << setw(laenge) << pt;
	delete [] pt;
	return;
	}


int DBString::operator <  (DBString st) {
	String tmp1(*this), tmp2(st);
	return tmp1 < tmp2;
	}

int DBString::operator <= (DBString st) {
	String tmp1(*this), tmp2(st);
	return tmp1 <= tmp2;
}

int DBString::operator >  (DBString st) {
	String tmp1(*this), tmp2(st);
	return tmp1 > tmp2;
}

int DBString::operator >= (DBString st) {
	String tmp1(*this), tmp2(st);
	return tmp1 >= tmp2;
}

int DBString::operator == (DBString st) {
	String tmp1(*this), tmp2(st);
	return tmp1 == tmp2;
}

int DBString::operator != (DBString st) {
	String tmp1(*this), tmp2(st);
	return tmp1 != tmp2;
   }


DBString DBString::operator += (DBString st) {
	String str = (String)*this;
	str += String(st);
	*this = str;
	return DBString(*this);
	}