// Beispielprogramm, Definition einer Klasse (letzter Teil)
// Definition einer Klasse für die Arbeit mit Strings
// Volker Hillmann: Objektorientierte Programmierung mit C++

// Originale Quellen von 1994 (pre Standard)
// Überarbeitung für den Stream, minimale notwendige Anpassungen 
// für aktuelle Compiler, hier Visual Studio 2022
// Volker Hillmann, 24.10.2024
// MIT License

#ifndef __MYSTRING_HPP
#define __MYSTRING_HPP

#include <iostream>  // !2024! Anpassung für modernes C++, Wegfall von .h für Standardheader
#include <string>    // !2024! Anpassung für modernes C++, Wegfall von .h für Standardheader
#include <strstream> // !2024! Anpassung für modernes C++, Änderung des alten Headernames (8.3)

using namespace std;  // !2024! Anpassung für modernes C++, provisorisches Öffnen der Namesräume


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
		String(String const&);  // !2024! copy constructor muss zwingend const& sein
		// Destruktor
		~String(void);
		// Methoden und Operatoren, um Inhalt zu setzen
		char* SetString(char* aPtChar);
		char* SetString(String& aString);
		String& operator = (String);
		String& operator = (const char*); // !2024! 
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
