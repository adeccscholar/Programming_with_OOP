// Beispielprogramm fuer den Einsatz der dBase- Datei- Klassen (2. Stufe)
// Volker Hillmann, Objektorientiertes Programmieren mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

#include <iostream.h>
#include <iomanip.h>

#include "DBHeader.HPP"

#include "DBObjekt.HPP"
#include "DBDatum.HPP"
#include "DBString.HPP"
#include "DBLogic.HPP"
#include "DBZahl.HPP"

int main(void) {
	int i,j;
	DBFile *dbf;
	DBString  DBaName, DBaVorname;
	DBDatum   DBGeburt;
	DBLogical DBAngestellt;
	DBZahl    DBGehalt;
	float Summe = 0.0;
	dbf = new DBFile;
	cerr << "Testprogramm: Lesen von Datensaetzen" << endl;
	cout << dbVersionString << endl << endl;
	dbf->DBOpen("angest.dbf");
	if(!dbf->DBIsOpen()) {
		cerr << "Datei " << dbf->DBName() << " nicht geoeffnet" << endl;
		cerr << "Fehler: " << dbf->DOSError() << endl;
		delete dbf;
		return 1;
		}
	cout << "Datei " << dbf->DBName() << " geoeffnet" << endl;

	//DBaName.Zuordnen(dbf->DBFieldPos(1), 15);
	DBaName.Zuordnen(dbf->DBFieldPos("NAME"), 15);
	DBaVorname.Zuordnen(dbf->DBFieldPos("VORNAME"), 15);
	DBGeburt.Zuordnen(dbf->DBFieldPos("GEBURT"));
	DBAngestellt.Zuordnen(dbf->DBFieldPos("ANGEST"));
	DBGehalt.Zuordnen(dbf->DBFieldPos("GEHALT"),9,2);
	for(i = 1, j = 0; i <= dbf->TupelCnt(); i++) {
		dbf->DBRead(i);
		if((DBaName=="Degenhardt") || (DBaName=="Stein"))
		   if(dbf->DBDelete(i)) j+=1;
		}
	cout << j << " Saetze in Datei "
		 << dbf->DBName() << " geloescht" << endl << endl;
	cout.setf(ios::left, ios::adjustfield);
	cout << setw( 8) << "Satz"
		 << setw(16) << "Name"
		 << setw(16) << "Vorname"
		 << setw(11) << "Datum"
		 << setw( 3) << "AG"
		 << setw(12) << "Gehalt" << endl;
	for(i = 1, j = 0; i <= dbf->TupelCnt(); i++) {
		dbf->DBRead(i);
		cout.setf(ios::right, ios::adjustfield);
		if(*dbf->PTBuffer()=='*') cout << setw(4) << i << ": * ";
		else {
			cout << setw(4) << i << ":   ";
			if(DBAngestellt) Summe += DBGehalt;
			}
		DBaName.Display(cout);
		cout << " ";
		DBaVorname.Display(cout);
		cout << " ";
		DBGeburt.Display(cout);
		cout << " ";
		DBAngestellt.Display(cout);
		cout << " ";
		DBGehalt.Display(cout);
		cout << endl;
		}

	cout << endl;                          
	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint);	
	cout << "Summe der Gehaelter der Angestellten = "
		 << setw(12) << setprecision(2) << Summe << " DM" << endl;
	dbf->DBClose();
	cout << endl;
	cout << "Datei " << dbf->DBName() << " geschlossen" << endl;
	delete dbf;
	return 0;
	}

