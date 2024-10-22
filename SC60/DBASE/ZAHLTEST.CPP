// Test für die Klasse DBZahl
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

#include <iostream.h>
#include <iomanip.h>

#include "dbzahl.hpp"

int main(void) {
	DBZahl Z1(0.0f,7,2);
	DBZahl Z2(6,10);
	DBZahl Z3(0,10);
	Z2.NachKomma(2);
	Z3.NachKomma(2);
	cout << "Zuweisungen und DBZahl + DBZahl" << endl;
	cout << "Z1 = 12.2     -> " << (Z1 = 12.2) << endl;
	cout << "Z2 = 16       -> " << (Z2 = 16) << endl;
	Z3 = Z1 + Z2;
	cout << Z1 << " + " << Z2 << " = " << Z3 << endl << endl;
	cout << "In- und Dekrementierung" << endl;
	cout << "--" << Z1;
	--Z1;
	cout << "   Z1 = " << Z1 << endl;
	cout << "++" << Z2 ;
	++Z2;
	cout<< "   Z2 = " << Z2 << endl;
	cout << endl;
	cout << "arithmetische Operatoren mit float und int" << endl;
	cout << Z1 << " + 6.2 = " << (Z1 +6.2) << endl;
	cout << Z3 << " + 5 =   " << (Z3 + 5) << endl;
	cout << Z2 << " - 3 =   " << (Z2 - 3) << endl << endl;
	Z3 = Z1;
	cout << "Vergleiche" << endl;
	cout << "Z1 = " << Z1 << "    Z3 = " << Z3 << endl;
	cout << "Z1 == Z3  " << (Z1==Z3) << endl;
	cout << "Z3 < 15   " << (Z3 < 15) << endl;
	cout << "16 < Z3   " << (16 < Z3) << endl << endl;
	cout << "Verbundene Zuweisungen" << endl;
	cout << Z1 << " *= 5 ";
	Z1*=5;
	cout << Z1 << endl;
	cout << Z1 << " /= 3 ";
	Z1/=3;
	cout << Z1 << endl;
	Z1 = 14;
	cout << Z1 << " %= 5 ";
	Z1%=5;
	cout << Z1 << endl;
	return 0;
	}
