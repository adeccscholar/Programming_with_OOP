// Beispielprogramm, Definition einer Klasse (2. Teil)
// Definition einer Klasse für die Arbeit mit Strings
// Volker Hillmann: Objektorientierte Programmierung mit C++

#include <iostream.h>
#include <string.h>
#include <strstrea.h>

#ifndef __STRING2_H
#define __STRING2_H

// Definition einer Klasse fuer die Stringverarbeitung
class String {
	friend ostream& operator << (ostream&, String);
	private: 		// Diese Daten sind nur innerhalb der Klasse nutzbar
		char *PtStr;
		unsigned int Len;
	public:		// Ab hier folgt das öffentliche Protokoll
		String(void);			// Standardkonstruktor
		String(String&);		// Kopierkonstruktor
		String(char *);	// Konstruktor erwartet Parameter vom Typ char*
		String(int);
		String(double, unsigned =-1,unsigned =-1);
		~String(void);		// der Destruktor
		char* SetString(char* aPtChar);
		char* SetString(String& aString);
		char* GetString(void) { return PtStr; };	// eine inline - Funktion
		unsigned int GetLen(void) { return Len; };	// eine inline - Funktion
	};

#endif
