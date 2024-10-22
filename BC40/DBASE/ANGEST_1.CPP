// Beispielprogramm fuer den Einsatz der dBase- Datei- Klassen (1. Stufe)
// Volker Hillmann, Objektorientiertes Programmieren mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

#include <iostream.h>
#include <iomanip.h>

#include <string.h>

#include "dbheader.hpp"

int main(void) {
	DBFile *dbf;
	char name [81];
	int i,Anz = 5;
	PTField AttrField;
	PTField *FieldPt;
	// Anzahl der Felder ist 5
	AttrField = new Field[5];
	FieldPt = new PTField[5];
	FieldPt[0] = new Field("NAME",    'C', 15, 0);
	FieldPt[1] = new Field("VORNAME", 'C', 15, 0);
	FieldPt[2] = new Field("GEBURT",  'D',  8, 0);
	FieldPt[3] = new Field("ANGEST",  'L',  1, 0);
	FieldPt[4] = new Field("GEHALT",  'N',  9, 2);
	for(i=0;i<Anz;i++) AttrField[i] = *FieldPt[i];
	delete [] FieldPt;
	cerr << "Testprogramm: dBase - Datei erzeugen" << endl << endl;
	strcpy(name,"angest.dbf");
	dbf = new DBFile;
	if(!dbf->DBCreate(name,AttrField,5)) {
		cerr << endl << "Datei " << name << " laesst sich nicht anlegen"
			 << endl;
		cerr << "Fehler: " << (dbf->DOSError()) << endl;
		delete dbf;
		delete [] AttrField;
		return 1;
		}
	//cerr << "Datei " << (dbf->DBName()) << " erzeugt" << endl;
	cerr << dbf->DBName()<< endl;
	delete [] AttrField;
	dbf->DBClose();
	// Schließen der Datei, anschließend wieder öffnen
	cerr << "Datei " << (dbf->DBName()) << " geschlossen" << endl;
	cerr << endl;
	dbf->DBOpen(name);
	if(!dbf->DBIsOpen()) {
		cerr << "Datei " << (dbf->DBName()) << " nicht geoeffnet" << endl;
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