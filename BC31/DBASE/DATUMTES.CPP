// Test der Klasse DBDatum
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

#include <iostream.h>
#include <iomanip.h>

#include "dbdatum.hpp"

int main(void) {
	DBDatum Datum1( 1, 3, 1993);
	DBDatum Datum2( 1, 3, 1992);
    DBDatum Datum3;
	long tage;
    cout << "Binäres - und unäres --, Schaltjahr beachten" << endl; 
	cout << "--" << Datum1 << "   = ";
	cout << --Datum1 << endl;
	cout << Datum2 << " - 1 = " << (Datum2-1) << endl;
	Datum2 = "07.07.1965";
	Datum1.SystemDatum();
	cout << endl;
	cout << "Nutzen der Zeichenfelder für Monats- und Tagesnamen" << endl;
	cout << TagesNamen[Datum1.Wochentag()] << ", der "
		 << Datum1.Tag() << ". " << MonatsNamen[Datum1.Monat()] << " "
		 << Datum1.Jahr() << endl;
	cout << endl;
	tage = Datum1 - Datum2;
    cout << "Abstand zwischen zwei Datumswerten in Tagen" << endl;
	cout << Datum1 << " - " << Datum2 << " = " << tage << endl << endl;
	cout << "binäres + und Verbundene Zuweisung +=" << endl;
	cout << Datum2 << " + " << tage << " = ";
	Datum3 = Datum2 + (int)tage;
    cout << Datum3 << endl;
	cout << Datum2 << " += " << tage << " Datum2 = ";
    Datum2 += (int)tage;
	cout << Datum2 << endl;
	cout << endl << "Test der Vergleichsoperatoren" << endl;
	cout << Datum2  << " == " << Datum3 << " = " << (Datum2==Datum3) << endl;
	cout << Datum2  << " != " << Datum3 << " = " << (Datum2!=Datum3) << endl;
	cout << Datum2  << " <  " << Datum3 << " = " << (Datum2< Datum3) << endl;
	cout << Datum2  << " <= " << Datum3 << " = " << (Datum2<=Datum3) << endl;
	cout << Datum2  << " >  " << Datum3 << " = " << (Datum2> Datum3) << endl;
	cout << Datum2  << " >= " << Datum3 << " = " << (Datum2>=Datum3) << endl;
	return 0;
	}
