// Beispielprogramm, Definition einer Klasse (1. Teil)
// Definition einer Klasse für die Arbeit mit Strings
// Volker Hillmann: Objektorientierte Programmierung mit C++

#include <iostream.h>
#include "string1.h"

int main(void) {
	String *aString;
	aString = new String;
	aString->SetString("Arbeit mit Zeichenfolgen variabler Länge in C++");
	cout << "Stringtest" << endl;
	cout << "Der Teststring ist:        " << aString->GetString() << endl;
	cout << "Länge des Teststrings ist: " << aString->GetLen() << endl;
	aString->Kill();
	return 0;
	}
