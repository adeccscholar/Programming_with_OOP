// Ausgabebeispiel mit ostream::write()
// Objektorientiertes Programmieren mit C++

#include <iostream.h>
#include <string.h>

struct Person {
	char Name[21];
	char Vorname[21];
	};

int main(void) {
	Person aPerson;
	strcpy(aPerson.Name,"Hillmann");
	strcpy(aPerson.Vorname,"Volker");
	cout.write((char*)&aPerson,sizeof(Person));
	return 0;
	}