// Beispielprogramm, Definition einer Klasse (2. Teil)
// Definition einer Klasse f�r die Arbeit mit Strings
// Volker Hillmann: Objektorientierte Programmierung mit C++

#include <iostream.h>
#include "string2.h"

int main(void) {
	String *aString;
	aString = new String;
	aString->SetString("Arbeit mit Zeichenfolgen variabler Laenge in C++");
	cout << "Stringtest" << endl;
	cout << "Der Teststring ist:        " << (String)(*aString) << endl;
	cout << "Laenge des Teststrings ist: " << aString->GetLen() << endl;
	return 0;
	}
