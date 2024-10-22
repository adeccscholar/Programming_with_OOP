// Definition der Klasse Bekannter (Nutzung der Mehrfachen Vererbung)
// Autor: Volker Hillmann
// Objektorientiertes Programmieren mit C++

#ifndef __BEKANNT2_HPP
#define __BEKANNT2_HPP

#include "person.hpp"
#include "adresse.hpp"
#include "datum.hpp"
#include "mystring.hpp"

class Bekannter_2 : public Person, public Adresse, public Datum {
	friend ostream& operator << (ostream&, Bekannter_2&);
	public:
		Bekannter_2(void);
		Bekannter_2(char*, char*, int, int, int, char*, char*, char*);
		Bekannter_2(Person&,Datum&,Adresse&);
		Bekannter_2(Bekannter_2&);
	};

#endif
