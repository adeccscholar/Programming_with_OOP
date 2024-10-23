// Testprogramme im Verzeichnis DBASE als eigenständige Methoden implementiert
// Originale Quellen von 1994 (pre Standard)
// Überarbeitung für den Stream, minimale notwendige Anpassungen 
// für aktuelle Compiler, hier Visual Studio 2022
// Volker Hillmann, 24.10.2024
// MIT License

#define _CRT_SECURE_NO_WARNINGS

// error C4996: 'strncpy': This function or variable may be unsafe. 
// Consider using strncpy_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. 
// See online help for details.

#include <iostream>
#include <iomanip>
#include <string.h>

#include "DBDatum.HPP"
#include "DBZahl.HPP"
#include "DBString.HPP"
#include "DBLogic.HPP"

#include "DBHeader.HPP"
#include "DBObjekt.HPP"

using namespace std;

void DatumTest(void) {
	DBDatum Datum1(1, 3, 1993);
	DBDatum Datum2(1, 3, 1992);
	DBDatum Datum3;
	long tage;
	cout << "Binaeres - und unaeres --, Schaltjahr beachten" << endl;
	cout << "--" << Datum1 << "   = ";
	cout << --Datum1 << endl;
	cout << Datum2 << " - 1 = " << (Datum2 - 1) << endl;
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
	cout << "binaeres + und Verbundene Zuweisung +=" << endl;
	cout << Datum2 << " + " << tage << " = ";
	Datum3 = Datum2 + (int)tage;
	cout << Datum3 << endl;
	cout << Datum2 << " += " << tage << " Datum2 = ";
	Datum2 += (int)tage;
	cout << Datum2 << endl;
	cout << endl << "Test der Vergleichsoperatoren" << endl;
	cout << Datum2 << " == " << Datum3 << " = " << (Datum2 == Datum3) << endl;
	cout << Datum2 << " != " << Datum3 << " = " << (Datum2 != Datum3) << endl;
	cout << Datum2 << " <  " << Datum3 << " = " << (Datum2 < Datum3) << endl;
	cout << Datum2 << " <= " << Datum3 << " = " << (Datum2 <= Datum3) << endl;
	cout << Datum2 << " >  " << Datum3 << " = " << (Datum2 > Datum3) << endl;
	cout << Datum2 << " >= " << Datum3 << " = " << (Datum2 >= Datum3) << endl;
   }

void ZahlTest(void) {
	DBZahl Z1(0.0, 7, 2);
	DBZahl Z2(6, 10);
	DBZahl Z3(0, 10);
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
	cout << "++" << Z2;
	++Z2;
	cout << "   Z2 = " << Z2 << endl;
	cout << endl;
	cout << "arithmetische Operatoren mit float und int" << endl;
	cout << Z1 << " + 6.2 = " << (Z1 + 6.2) << endl;
	cout << Z3 << " + 5 =   " << (Z3 + 5) << endl;
	cout << Z2 << " - 3 =   " << (Z2 - 3) << endl << endl;
	Z3 = Z1;
	cout << "Vergleiche" << endl;
	cout << "Z1 == Z3  " << (Z1 == Z3) << endl;
	cout << "Z3 < 15   " << (Z3 < 15) << endl;
	cout << "16 < Z3   " << (16 < Z3) << endl << endl;
	cout << "Verbundene Zuweisungen" << endl;
	cout << Z1 << " *= 5 ";
	Z1 *= 5;
	cout << Z1 << endl;
	cout << Z1 << " /= 3 ";
	Z1 /= 3;
	cout << Z1 << endl;
	Z1 = 14;
	cout << Z1 << " %= 5 ";
	Z1 %= 5;
	cout << Z1 << endl;
   }

int Angest_1(void) {
	DBFile* dbf;
	char name[81];
	int i, Anz = 5;
	PTField AttrField;
	PTField* FieldPt;
	// Anzahl der Felder ist 5
	AttrField = new Field[5];
	FieldPt = new PTField[5];
	FieldPt[0] = new Field("NAME",    'C', 15, 0);
	FieldPt[1] = new Field("VORNAME", 'C', 15, 0);
	FieldPt[2] = new Field("GEBURT",  'D',  8, 0);
	FieldPt[3] = new Field("ANGEST",  'L',  1, 0);
	FieldPt[4] = new Field("GEHALT",  'N',  9, 2);
	for (i = 0; i < Anz; i++) AttrField[i] = *FieldPt[i];
	delete[] FieldPt;
	cerr << "Testprogramm: dBase - Datei erzeugen" << endl << endl;
	strcpy(name, "angest.dbf");
	dbf = new DBFile;
	if (!dbf->DBCreate(name, AttrField, 5)) {
		cerr << endl << "Datei " << name << " laesst sich nicht anlegen"
			<< endl;
		cerr << "Fehler: " << dbf->DOSError() << endl;
		delete dbf;
		delete[] AttrField;
		return 1;
	}
	cerr << "Datei " << dbf->DBName() << " erzeugt" << endl;
	delete[] AttrField;
	dbf->DBClose();
	// Schließen der Datei, anschließend wieder öffnen
	cerr << "Datei " << dbf->DBName() << " geschlossen" << endl;
	cerr << endl;
	dbf->DBOpen(name);
	if (!dbf->DBIsOpen()) {
		cerr << "Datei " << dbf->DBName() << " nicht geoeffnet" << endl;
		cerr << "Fehler: " << dbf->DOSError() << endl;
		delete dbf;
		return 1;
	}
	// Ausgeben der Dateiinformationen
	dbf->DBInfo();
	dbf->DBClose();
	delete dbf;
	return 0;
   }

enum Boolean { FALSCH = 0, WAHR = 1 };

struct Angestellter {
	char Name[16];
	char Vorname[16];
	char Geburt[11];
	Boolean Angestellt;
	float Gehalt;
};

Angestellter Feld[] = {
	{ "Meyer",      "Paul",      "03.04.1958", FALSCH,    0.00 },
	{ "Lehmann",    "Fritz",     "01.12.1962", WAHR,   3550.50 },
	{ "Wegner",     "Werner",    "14.04.1966", WAHR,   3990.00 },
	{ "Nachtigall", "Ingrid",    "12.12.1967", WAHR,   3850.50 },
	{ "Degenhardt", "Hans",      "12.09.1964", FALSCH, 4300.00 },
	{ "Bauer",      "Holger",    "23.02.1966", FALSCH,    0.00 },
	{ "Lau",        "Heidi",     "13.08.1968", WAHR,   4120.50 },
	{ "Stein",      "Georg",     "27.07.1959", WAHR,   5100.00 },
	{ "Krause",     "Anke",      "07.09.1966", FALSCH,    0.00 },
	{ "Friedrich",  "Peter",     "15.10.1958", WAHR,   4123.45 },
	{ "Sanders",    "Ines",      "11.06.1961", FALSCH,    0.00 },
	{ "Wagner",     "Pauline",   "07.08.1941", WAHR,   4200.10 },
	{ "Heinrichs",  "Klaus",     "03.04.1956", WAHR,   5800.20 }
  };

/*
   { "Roth",       "Christian",  "17.04.1953", FALSCH,     0.00 },
	{ "Hoenow",     "Harald",     "05.12.1961", WAHR,    4325.20 },
	{ "Brandt",     "Marlene",    "18.10.1965", WAHR,    5126.50 },
	{ "Krause",     "Gerd",       "06.02.1951", FALSCH,     0.00 },
	{ "Winkler"     "Mia",        "16.12.1959", WAHR,    5480.25 },
	{ "Eckhardt",   "Matthias",   "27.05.1960", FALSCH,  6250.50 },
	{ "Kaspar",     "Maria",      "14.06.1952", FALSCH,     0.00 },
   { "Hardt",      "Franz",      "15.02.1962", WAHR,    4920.00 },
   { "Fuchs"       "Lisa",       "31.10.1956", FALSCH,     0.00 },
   { "Bergmann",   "Andreas",    "26.09.1962", WAHR,    5520.75 },
   { "Wolf",       "Roland",     "01.04.1968", WAHR,    4750.20 },
   { "Mayer",      "Hans",       "20.10.1977", WAHR,    4250.00 },
   { "Schmidt",    "Julia",      "01.11.1978", WAHR,    6320.90 },
	{ "Braun",      "Simon",      "12.03.1954", FALSCH,     0.00 },
	{ "Frey",       "Linda",      "09.03.1962", WAHR,    4125.50 },
	{ "Meierhoff",  "Harald",     "02.04.1960", WAHR,    3928.20 },
	{ "Sommer",     "Elke",       "07.12.1951", FALSCH,  4620.00 },
	{ "Sommer",     "Gabriele",   "28.09.1963", WAHR,    4550.00 },
	{ "Peters",     "Hugo",       "10.01.1961", WAHR,    5625.50 },
	{ "Engel",      "Gerd",       "04.11.1961", FALSCH,     0.00 },
   { "Meier",      "Clara",      "27.12.1972", WAHR,    5295.00 },
   { "Lehmann"     "Susanne",    "24.04.1951", FALSCH,     0.00 },
	{ "Thaika",     "Klaus",      "06.04.1959", WAHR,    4200.00 },
   { "Schwarzer",  "Dominique",  "23.01.1968", WAHR,    6215.40 },
   { "Pohl",       "Gerda",      "01.05.1959", WAHR,    5895.75 },
	{ "Sebastian",  "Friedrich",  "01.07.1981", WAHR,    4222.20 },
   { "Michalski",  "Ingrid",     "12.05.1963", WAHR,    5100.50 },
   { "Theuss",     "Katrin",     "17.06.1980", FALSCH,  5796.90 },
   { "Golzow",     "Ludwig",     "28.10.1979", WAHR,    5100.00 },
   { "Hoffmann",   "Marvin",     "09.05.1987", WAHR,    4975.50 },
   { "Klein",      "Maik",       "24.11.1966", FALSCH,     0.00 },
   { "Dunker",     "Sonja",      "18.06.1978", WAHR,    5650.50 },   
   { "Cianfarini", "Cornelia",   "10.07.1970", WAHR,    5841.40 },
   { "Berger",     "Theresa",    "10.04.1967", FALSCH,     0.00 },
   { "Koch",       "Richard",    "24.03.1960", FALSCH,  4950.00 },
   { "Lindner",    "Peter",      "19.04.1973", WAHR,    5120.00 },
   { "Hoppe",      "Norbert",    "20.07.1981", WAHR,    5240.50 },
   { "Behlert",    "Grit",       "16.12.1975", WAHR,    5555.55 },
   { "Reichstein", "Grete",      "17.11.1979", WAHR,    5820.45 }

*/

const int TestCnt = sizeof(Feld) / sizeof(Feld[0]);

int Angest_2(void) {
	int i, j;
	DBFile* dbf;
	DBString  DBName, DBVorname;
	DBDatum   DBGeburt;
	DBLogical DBAngestellt;
	DBZahl    DBGehalt;
	dbf = new DBFile;
	cerr << "Testprogramm: Anfuegen von Datensaetzen" << endl;
	cout << dbVersionString << endl << endl;
	dbf->DBOpen("angest.dbf");
	if (!dbf->DBIsOpen()) {
		cerr << "Datei " << dbf->DBName() << " nicht geoeffnet" << endl;
		cerr << "Fehler: " << dbf->DOSError() << endl;
		delete dbf;
		return 1;
	}
	cout << "Datei " << dbf->DBName() << " geoeffnet" << endl;
	DBName.Zuordnen(dbf->DBFieldPos("NAME"), 15);
	DBVorname.Zuordnen(dbf->DBFieldPos("VORNAME"), 15);
	DBGeburt.Zuordnen(dbf->DBFieldPos("GEBURT"));
	DBAngestellt.Zuordnen(dbf->DBFieldPos("ANGEST"));
	DBGehalt.Zuordnen(dbf->DBFieldPos("GEHALT"), 9, 2);
	for (i = 0, j = 0; i < TestCnt; i++) {
		dbf->DBBlank();
		DBName = Feld[i].Name;
		DBVorname = Feld[i].Vorname;
		DBGeburt = Feld[i].Geburt;
		DBAngestellt = Feld[i].Angestellt;
		DBGehalt = Feld[i].Gehalt;
		if (dbf->DBAppend()) j++;
	}
	cout << j << " Saetze in Datei "
		<< dbf->DBName() << " angefuegt" << endl << endl;
	dbf->DBClose();
	cout << "Datei " << dbf->DBName() << " geschlossen" << endl;
	dbf->DBOpen("angest.dbf");
	dbf->DBInfo();
	dbf->DBClose();
	delete dbf;
	return 0;
   }


int Angest_3(void) {
	int i, j;
	DBFile* dbf;
	DBString  DBaName, DBaVorname;
	DBDatum   DBGeburt;
	DBLogical DBAngestellt;
	DBZahl    DBGehalt;
	float Summe = 0.0;
	dbf = new DBFile;
	cerr << "Testprogramm: Lesen von Datensaetzen" << endl;
	cout << dbVersionString << endl << endl;
	dbf->DBOpen("angest.dbf");
	if (!dbf->DBIsOpen()) {
		cerr << "Datei " << dbf->DBName() << " nicht geoeffnet" << endl;
		cerr << "Fehler: " << dbf->DOSError() << endl;
		delete dbf;
		return 1;
	   }
	cout << "Datei " << dbf->DBName() << " geoeffnet" << endl;

	DBaName.Zuordnen(dbf->DBFieldPos("NAME"), 15);
	DBaVorname.Zuordnen(dbf->DBFieldPos("VORNAME"), 15);
	DBGeburt.Zuordnen(dbf->DBFieldPos("GEBURT"));
	DBAngestellt.Zuordnen(dbf->DBFieldPos("ANGEST"));
	DBGehalt.Zuordnen(dbf->DBFieldPos("GEHALT"), 9, 2);
	for (i = 1, j = 0; i <= dbf->TupelCnt(); i++) {
		dbf->DBRead(i);
		if ((DBaName == "Degenhardt") || (DBaName == "Stein"))
			if (dbf->DBDelete(i)) j += 1;
	}
	cout << j << " Saetze in Datei "
		<< dbf->DBName() << " geloescht" << endl << endl;
	cout << setiosflags(ios::left);
	cout << setw(8) << "Satz"
		<< setw(16) << "Name"
		<< setw(16) << "Vorname"
		<< setw(11) << "Datum"
		<< setw(3) << "AG"
		<< setw(12) << "Gehalt" << endl;
	for (i = 1, j = 0; i <= dbf->TupelCnt(); i++) {
		dbf->DBRead(i);

		if (*dbf->PTBuffer() == '*') cout << setw(4) << i << ": * ";
		else {
			cout << setw(4) << i << ":   ";
			if (DBAngestellt) Summe += DBGehalt;
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

int main() {
    std::cout << "Hello World!\n";
	 std::cout << "\nDatum Test!\n";
	 DatumTest();
	 std::cout << "\nZahl Test!\n";
	 ZahlTest();

	 std::cout << "\n\nAngest_1 Test!\n";
	 int ret = Angest_1();
	 std::cout << "result = " << ret << "\n";

	 std::cout << "\n\nAngest_2 Test!\n";
	 ret = Angest_2();
	 std::cout << "result = " << ret << "\n";

	 std::cout << "\n\nAngest_3 Test!\n";
	 ret = Angest_3();
	 std::cout << "result = " << ret << "\n";

   }

