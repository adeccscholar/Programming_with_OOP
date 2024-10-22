// Definition der Klassen Bekannter und Person
// Bestandteil der Klasse Bekannter
// Autor: Volker Hillmann
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

#ifndef __BEKANNT_HPP
#define __BEKANNT_HPP

#include "person.hpp"
#include "mystring.hpp"
#include "adresse.hpp"
#include "datum.hpp"



// Die Klasse Bekannter wird von Person abgeleitet
class Bekannter : public Person {
	friend ostream& operator << (ostream&, Bekannter&);
	public:
		Datum Geburtstag;
		Adresse Anschrift;
	public:
		Bekannter(void);
		Bekannter(char*, char*,int, int, int, char*, char*, char*);
		Bekannter(Person&,Datum&,Adresse&);
		Bekannter(Bekannter&);
		~Bekannter(void);
	};

#endif