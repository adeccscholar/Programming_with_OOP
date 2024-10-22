// Definition der Klassen Bekannter und Person
// Bestandteil der Klasse Bekannter
// Autor: Volker Hillmann
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

#ifndef __PERSON_HPP
#define __PERSON_HPP

#include "mystring.hpp"
#include "adresse.hpp"
#include "datum.hpp"

// Die Klasse Person
class Person {
	friend BaumKnoten;
	friend ostream& operator << (ostream& os, Person& p);
	protected:
		String aName;
		String aVorname;
	public:
		Person(void);					// Defaultkonstruktor
		Person(char*,char*);			// Konstruktor mit Initialisierung
		Person(Person&);				// Kopierkonstruktor
		~Person(void);					// Der Destruktor
		inline char *Name(char*);				// Namen setzen
		inline char *Name(void);				// Namen abfragen
		inline char *VorName(char*);			// Vornamen setzen
		inline char *VorName(void);			// Vornamen abfragen
		void ZeigePerson(ostream&);	// Ausgabe der Person
	};

#endif
