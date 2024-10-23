// Beispielprogramm, Implementierung einer Klasse (letzter Teil)
// Definition einer Klasse für die Arbeit mit Strings
// Volker Hillmann: Objektorientierte Programmierung mit C++

// Originale Quellen von 1994 (pre Standard)
// Überarbeitung für den Stream, minimale notwendige Anpassungen 
// für aktuelle Compiler, hier Visual Studio 2022
// Volker Hillmann, 24.10.2024
// MIT License

#define _CRT_SECURE_NO_WARNINGS

// error C4996: 'strncpy': This function or variable may be unsafe. 
// Consider using strncpy_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. 
// See online help for details.


#include <stdlib.h>
#include <iostream>   // !2024! Anpassung für modernes C++, Wegfall von .h für Standardheader
#include <iomanip>    // !2024! Anpassung für modernes C++, Wegfall von .h für Standardheader
#include <strstream>  // !2024! Anpassung für modernes C++, Änderung des alten Headernames (8.3)

#include "mystring.hpp"

using namespace std;  // !2024! Anpassung für modernes C++, provisorisches Öffnen der Namesräume

String::String(void) {
	PtStr = 0;
	Len = 0;
	}

String::String(char *PtChar) {
	Len = strlen(PtChar);   // !2024! warning C4267: "=": Konvertierung von "size_t" nach "unsigned int", Datenverlust möglich
	PtStr = new char[Len + 1];
	strncpy(PtStr, PtChar, Len);
	PtStr[Len] = '\0';
    }
	 
String::String(int GanzZahl) {
	ostrstream os;
	char *pt;
	os << GanzZahl << ends;
	pt = os.str();
	Len = strlen(pt); // !2024! warning C4267: "=": Konvertierung von "size_t" nach "unsigned int", Datenverlust möglich
	PtStr = new char[Len + 1];
	strncpy(PtStr, pt, Len);
	PtStr[Len] = '\0';
	delete [] pt;
	}

String::String(double GleitZahl, unsigned l,unsigned k) {
	ostrstream os;
	char *pt;
	os.setf(ios::fixed, ios::floatfield);
	os.setf(ios::showpoint);
	os << setw(l) << setprecision(k) << GleitZahl << ends;
	pt = os.str();
	Len = strlen(pt); // !2024! warning C4267: "=": Konvertierung von "size_t" nach "unsigned int", Datenverlust möglich
	PtStr = new char[Len + 1];
	strncpy(PtStr, pt, Len);
	PtStr[Len] = '\0';
	delete [] pt;
	}

String::String(String const& aStr) {
	Len = aStr.Len;
	PtStr = new char[Len + 1];
	strncpy(PtStr, aStr.PtStr, Len);
	PtStr[Len] = '\0';
    }

String::~String(void) {
	if(PtStr!=NULL) delete [] PtStr;
    }



char* String::SetString(char* aPtChar) {
	Len=strlen(aPtChar); // !2024! warning C4267: "=": Konvertierung von "size_t" nach "unsigned int", Datenverlust möglich
	if(PtStr!=NULL) delete [] PtStr;
	PtStr = new char [Len+1];
	strncpy(PtStr, aPtChar, Len);
	PtStr[Len] = '\0';
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


String& String::operator = (const char* aPtChar) { // !2024! const
	Len = strlen(aPtChar); // !2024! warning C4267: "=": Konvertierung von "size_t" nach "unsigned int", Datenverlust möglich
	if(PtStr != NULL) delete [] PtStr;
	PtStr = new char [Len+1];
	strncpy(PtStr, aPtChar, Len);
	PtStr[Len] = '\0';
	return *this;
	}

String& String::operator = (String aString) {
	Len=aString.Len;
	if(PtStr != NULL) delete [] PtStr;
	PtStr = new char [Len+1];
	strncpy(PtStr, aString.PtStr, Len);
	PtStr[Len] = '\0';
	return *this;
	}

String& String::operator += (char* aPtChar) {
	String tmp = aPtChar;
	return *this = *this + tmp;  // error C2593 : „Operator + “ ist mehrdeutig
	}

String& String::operator += (String aString) {
	return *this = *this + aString;
	}

String::operator int() const {
	int i;
	istrstream in(PtStr);
	in >> i;
	return i;
	}

String::operator float() const {
    float f;
	istrstream in(PtStr);
	in >> f;
	return f;
	}


int String::operator < (String& aStr) {
	if(strcmp(PtStr,aStr.PtStr) < 0) return 1;
	else return 0;
    }

int String::operator <= (String& aStr) {
	if(strcmp(PtStr,aStr.PtStr) <= 0) return 1;
	else return 0;
    }

int String::operator > (String& aStr) {
	if(*this <= aStr) return 0;
	else return 1;
    }

int String::operator >= (String& aStr) {
	if(*this < aStr) return 0;
	else return 1;
	}

int String::operator == (String& aStr) {
	if(strcmp(PtStr,aStr.PtStr)==0) return 1;
	else return 0;
    }

int String::operator != (String& aStr) {
	if(*this == aStr) return 0;
	else return 1;
    }


ostream& operator << (ostream& out, String& aStr) {
	return out << aStr.PtStr;
	}

istream& operator >> (istream& in, String& aStr) {
	int l = in.width(); // !2024! warning C4244: "Initialisierung": Konvertierung von "std::streamsize" in "int", möglicher Datenverlust
	char *PtBuffer;
	if(l==0) l = 256;
	PtBuffer = new char[l];
	in >> setw(l) >> PtBuffer;
	aStr = PtBuffer;
	return in;
	}

String operator + (String& aStr1, String& aStr2) {
	String aString;
	aString.Len = aStr1.GetLen()+aStr2.GetLen();
	aString.PtStr = new char[aString.GetLen()+1];
	strcpy(aString.PtStr, aStr1.PtStr);
	strcat(aString.PtStr, aStr2.PtStr);
	aString.PtStr[aString.Len] = '\0';
	return String(aString);
    }

String operator + (char *aPtChar, String& aStr) {
	String aString;
	aString.Len = strlen(aPtChar) +aStr.GetLen(); // !2024! warning C4267: "=": Konvertierung von "size_t" nach "unsigned int", Datenverlust möglich
	aString.PtStr = new char[aString.GetLen()+1];
	strcpy(aString.PtStr, aPtChar);
	strcat(aString.PtStr, aStr.PtStr);
	aString.PtStr[aString.Len] = '\0';
	return String(aString);
    }

String operator + (String& aStr, char *aPtChar) {
	String aString;
	aString.Len = strlen(aPtChar)+aStr.GetLen(); // !2024! warning C4267: "=": Konvertierung von "size_t" nach "unsigned int", Datenverlust möglich
	aString.PtStr = new char[aString.GetLen()+1];
	strcpy(aString.PtStr, aStr.PtStr);
	strcat(aString.PtStr, aPtChar);
	aString.PtStr[aString.Len] = '\0';
	return String(aString); // !2024!  error C2440: "return": "String" kann nicht in "String" konvertiert werden
    }

