// Beispielprogramm, Definition einer Klasse (1. Teil)
// Definition einer Klasse für die Arbeit mit Strings
// Volker Hillmann: Objektorientierte Programmierung mit C++

#include <iostream.h>
#include <iomanip.h>
#include <strstrea.h>
#include <string.h>

#include "string2.h"

// Implementierung der Methoden von String

String::String(void) {
	PtStr = 0;
	Len   = 0;
	}

String::String(char* aPtChar) {
	Len = strlen(aPtChar);
	PtStr = new char[Len + 1];
	strncpy(PtStr, aPtChar, Len);
	PtStr[Len] = '\0';
	}

String::String(String& aString) {		// Kopierkonstruktor
	Len=aString.Len;
	PtStr = new char[Len + 1];
	strncpy(PtStr, aString.GetString(), Len);
	PtStr[Len] = '\0';
	}

String::String(int IWert) {
	char *pt;
	ostrstream os;
	os << IWert;
	pt = os.str();
	Len = strlen(pt);
	PtStr = new char[Len + 1];
	strncpy(PtStr, pt, Len);
	PtStr[Len] = '\0';
	delete [] pt;
	}

String::String(double GWert, unsigned l, unsigned k) {
	char *pt;
   ostrstream os;
	os.setf(ios::fixed,ios::floatfield);
   os.setf(ios::showpoint);
	os << setw(l) << setprecision(k) << GWert << ends;
	pt = os.str();
	Len = strlen(pt);
	PtStr = new char[Len + 1];
	strncpy(PtStr, pt, Len);
	PtStr[Len] = '\0';
	delete [] pt;
	}

String::~String(void) {
	delete [] PtStr;
	return;
	}

char* String::SetString(char* aPtChar) {
	Len=strlen(aPtChar);
	if(PtStr!=NULL) delete [] PtStr;
	PtStr = new char [Len+1];
	strncpy(PtStr, aPtChar, Len);
	return PtStr;
	}

char* String::SetString(String& aString) {
	Len=aString.Len;
	if(PtStr!=NULL) delete [] PtStr;
	PtStr = new char [Len+1];
	strncpy(PtStr, aString.PtStr, Len);
	PtStr[Len] = '\0';
	return PtStr;
	}

ostream& operator << (ostream& out, String aString) {
	//return out <<  (char*)aString.PtStr;	// PtStr ist privat
	return out <<  (char*)aString.GetString();	// PtStr ist privat
	}