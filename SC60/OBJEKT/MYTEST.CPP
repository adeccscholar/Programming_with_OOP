// Beispielprogramm, Test der Stringklasse (letzter Teil)
// Arbeit mit Strings
// Volker Hillmann: Objektorientierte Programmierung mit C++

#include <iostream.h>
#include <iomanip.h>

#include "mystring.hpp"


int main(void) {
	String s1("Dieses ist ein Beispiel"),
		   s2(10),
		   s3(12.336,8,2),
		   s4(s1),
		   s5, s6, s7;
	char Satz[] = " fuer die C++ Programmierung";
	int i1,i2;
	float f1,f2;
	s5 = s1 + Satz;
    s4 += Satz;
	cout << "s4 = " << s4 << endl;
	cout << "s5 = " << s5 << endl << endl;
	cout << "Test der Konvertierungen: " << endl;
	i1 = s2;
    i2 = s3;
	f1 = s2;
	f2 = s3;
	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint, ios::adjustfield);
	cout << setw(19) << "s2" << setw(10) << "s3"
		 <<  endl;
	cout << "Ganzzahlen:  " << setw(10) << i1 << setw(10) << i2 << endl;
	cout << "Gleitzahlen: " << setw(10) << setprecision(2) << f1
		 << setw(10) << setprecision(2) << f2 << endl;
	s7 = (float)s2 + (float)s3;
	cout << "(float)s2 + (float)s3 = " << setw(10)
		 << setprecision(2) << (float)s7 << endl << endl;
	cout << "Test der Vergleichsoperatoren" << endl;
	cout << "1.String: ";
	cin >> setw(21) >> s6;
	cout << "2.String: ";
	cin >> setw(21) >> s7;
	cout << "s6 = " << s6 << "   s7 = " << s7 << endl;
	cout << "s6 == s7  " << (s6 == s7) << endl;
	cout << "s6 != s7  " << (s6 != s7) << endl;
	cout << "s6 <  s7  " << (s6 <  s7) << endl;
	cout << "s6 >  s7  " << (s6 >  s7) << endl;
	return 0;
	}
