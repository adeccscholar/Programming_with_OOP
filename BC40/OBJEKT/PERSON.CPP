// Die Klasse Person

#include <iostream.h>
#include "person.hpp"

Person::Person(void) : aName(), aVorname() { }

Person::Person(char* n,char* v) : aName(n),aVorname(v) { }

Person::Person(Person& p) : aName(p.aName),aVorname(p.aVorname) { }

Person::~Person(void) { }

char *Person::Name(char* n)		{ return aName.SetString(n); }
char *Person::Name(void)		{ return aName.GetString(); 	}
char *Person::VorName(char* v)	{ return aVorname.SetString(v); }
char *Person::VorName(void)		{ return aVorname.GetString(); 	}

void Person::ZeigePerson(ostream& os) {
   os << aVorname.GetString() << " " << aName.GetString();
   return;
   }

ostream& operator << (ostream& os, Person& p) {
	return os << p.aVorname << " " << p.aName;
	}

