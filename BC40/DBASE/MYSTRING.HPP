// Beispielprogramm, Definition einer Klasse (letzter Teil)
// Definition einer Klasse für die Arbeit mit Strings
// Volker Hillmann: Objektorientierte Programmierung mit C++

#include <iostream.h>
#include <string.h>
#include <strstrea.h>

#ifndef __MYSTRING_HPP
#define __MYSTRING_HPP

// Definition einer Klasse fuer die Stringverarbeitung
class String {
	friend ostream& operator << (ostream& out, String& aStr);
	friend istream& operator >> (istream& in, String& aStr);
	friend String operator + (String&, String&);
	friend String operator + (char*, String&);
	friend String operator + (String&, char*);
	private:
		char *PtStr;
		unsigned int Len;
	public:		
		// Konstruktoren
		String(void);		
		String(char *);	
		String(int);		
		String(double, unsigned =-1,unsigned =-1);
		String(String&);
		// Destruktor
		~String(void);
		// Methoden und Operatoren, um Inhalt zu setzen
		char* SetString(char* aPtChar);
		char* SetString(String& aString);
		String& operator = (String);
		String& operator = (char*);
		String& operator += (String);
		String& operator += (char*);
		// Methoden und Operatoren, um Inhalt zu holen
		char* GetString(void) { return PtStr; };	
		operator int() const;
		operator float()  const;
		unsigned int GetLen(void) { return Len; };	
		// Vergleichende Operatoren
		int operator < (String&);
		int operator <= (String&);
		int operator > (String&);
		int operator >= (String&);
		int operator == (String&);
		int operator != (String&);
	};

#endif   
