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


enum Boolean { FALSCH = 0, WAHR = 1 };

struct Angestellter {
	char Name[16];
	char Vorname[16];
	char Geburt[11];
	Boolean Angestellt;
	float Gehalt;
	};

Angestellter Feld[] = {
	{ "Meyer",      "Paul",     "03.04.1958", FALSCH,    0.00 },
	{ "Lehmann",    "Fritz",    "01.12.1962", WAHR,   3550.50 },
	{ "Wegner",     "Werner",   "14.04.1966", WAHR,   3990.00 },
    { "Nachtigall", "Ingrid",   "12.12.1967", WAHR,   3850.50 },
	{ "Degenhardt", "Hans",     "12.09.1964", FALSCH, 4300.00 },
	{ "Bauer",      "Holger",   "23.02.1966", FALSCH,    0.00 },
    { "Lau",        "Heidi",    "13.08.1968", WAHR,   4120.50 },
	{ "Stein",      "Georg",    "27.07.1959", WAHR,   5100.00 },
	{ "Krause",     "Anke",     "07.09.1966", FALSCH,    0.00 },
	{ "Friedrich",  "Peter",    "15.10.1958", WAHR,   4123.45 },
	{ "Sanders",    "Ines",     "11.06.1961", FALSCH,    0.00 },
	{ "Wagner",     "Pauline",  "07.08.1941", WAHR,   4200.10 },
    { "Heinrichs",  "Klaus",    "03.04.1956", WAHR,   5800.20 }
	};

int main(void) {
	int i,j;
	DBFile *dbf;
	DBString  DBName, DBVorname;
	DBDatum   DBGeburt;
	DBLogical DBAngestellt;
	DBZahl    DBGehalt;
	dbf = new DBFile;
	cerr << "Testprogramm: Anfuegen von Datensätzen" << endl;
	cout << dbVersionString << endl << endl;
	dbf->DBOpen("angest.dbf");
	if(!dbf->DBIsOpen()) {
		cerr << "Datei " << dbf->DBName() << " nicht geoeffnet" << endl;
		cerr << "Fehler: " << dbf->DOSError() << endl;
		delete dbf;
		return 1;
		}
    cout << "Datei " << dbf->DBName() << " geöffnet" << endl;
	DBName.Zuordnen(dbf->DBFieldPos("NAME"), 15);
	DBVorname.Zuordnen(dbf->DBFieldPos("VORNAME"), 15);
	DBGeburt.Zuordnen(dbf->DBFieldPos("GEBURT"));
	DBAngestellt.Zuordnen(dbf->DBFieldPos("ANGEST"));
	DBGehalt.Zuordnen(dbf->DBFieldPos("GEHALT"),9,2);
	for(i = 0, j= 0; i < 13; i++) {
    	dbf->DBBlank();
		DBName       = Feld[i].Name;
		DBVorname    = Feld[i].Vorname;
		DBGeburt     = Feld[i].Geburt;
		DBAngestellt = Feld[i].Angestellt;
		DBGehalt     = Feld[i].Gehalt;
		if(dbf->DBAppend()) j++;
		}
	cout << j << " Sätze in Datei "
		 << dbf->DBName() << " angefügt" << endl << endl;
	dbf->DBClose();
	cout << "Datei " << dbf->DBName() << " geschlossen" << endl;
	dbf->DBOpen("angest.dbf");
	dbf->DBInfo();
	dbf->DBClose();
	delete dbf;
	return 0;
	}


    	

