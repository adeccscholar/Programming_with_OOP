// Streamtest 1. Versuch
// Ausgabe mit Funktionen aus ostream mit Formatierungen aus ios
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

#include <iostream.h>

float Wert[7]= { 102.3, 123.151, 99.991, 105.1, 145.45, 123.55, 10.1 };
char *Tage[7]= 	{	"Montag", "Dienstag", "Mittwoch", "Donnerstag",
							"Freitag", "Sonnabend", "Sonntag" };

int main(void) {
	int i;
	cout << "Ausgaben mit cout und Funktionen aus »ios«" << endl;
	cout.setf(ios::fixed,ios::floatfield);
	cout.setf(ios::showpoint);
	for(i=0;i<7;i++) {
		cout.setf(ios::right,ios::adjustfield);
		cout.width(4);
		cout << (i+1) << "  - ";
		cout.width(10);
		cout.setf(ios::left,ios::adjustfield);
		cout << Tage[i] << " - ";
		cout.width(8);
		cout.setf(ios::right,ios::adjustfield);
		cout.precision(2);
		cout << Wert[i] << endl;
		}
	cout.width();
	return 0;
}