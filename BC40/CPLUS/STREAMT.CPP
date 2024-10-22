// Einlesen mit Streams
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

#include <iostream.h>

char Name[21];
char VorName[16];

int main(void) {
	cout << "Beispiel, einlesen von Werten aus der Standardeingabe: " << endl;
	cout << "Name: 		";
	cin.width(sizeof(Name));			// Begrenzen der Eingabe auf 20 Zeichen
	cin >> Name;
	cout << "Vorname: 	";
	cin.width(sizeof(VorName)); 		//Begrenzen der Eingabe auf  15 Zeichen
	cin >> VorName;
	cout << endl << "Sie haben eingegeben: " << endl;
	cout << "\t" << VorName << " " << Name << endl;
	return 0;
	}