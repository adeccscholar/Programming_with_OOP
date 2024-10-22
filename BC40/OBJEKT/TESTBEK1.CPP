// Testprogramm: Einsatz der Klasse Bekannter
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

#include <iostream.h>
#include "datum.hpp"
#include "adresse.hpp"
#include "bekannt.hpp"

int main(void) {
	Person  p1("Meyer","Johannes");
	Datum   d1(12,3,1954);
	Person  p2("Meyer","Friedrich");
	Datum   d2(7,1,1983);
	Adresse a1("Moorweg 5","Berlin","12524");
	Bekannter b1(p1,d1,a1);
	Bekannter b2(p2,d2,a1);
	Bekannter b3("Werner","Karl- Heinz",1,4,1958,
				"Salbeiweg 1","Berlin","12555");
	cout << "Testprogramm Bekannter" << endl;
	cout << "нннннннннннннннннннннн" << endl;
	cout << b1 << endl;
	cout << b2 << endl;
	cout << b3 << endl;
	return 0;
	}
