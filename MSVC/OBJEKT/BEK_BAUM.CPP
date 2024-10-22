// Beispielprogramm: Bekannte in Bäumen speichern
// Volker Hillmann
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

#include <iostream.h>
#include "bekannt.hpp"
#include "baum.hpp"

class BekannterKnoten : public Bekannter, public BaumKnoten {
	public:
		BekannterKnoten(void);
		BekannterKnoten(Bekannter&);
		BekannterKnoten(char*, char*);
		BekannterKnoten(char*, char*,int, int, int, char*, char*, char*);
		virtual int operator < (BaumKnoten&);
		virtual int operator > (BaumKnoten&);
		virtual void Gleichheit(BaumKnoten*);
		virtual void Verarbeite(void);
	};

BekannterKnoten::BekannterKnoten(void) : 
		BaumKnoten(), Bekannter() { }

BekannterKnoten::BekannterKnoten(Bekannter& b) :
		BaumKnoten(), Bekannter(b) { } 

BekannterKnoten::BekannterKnoten(char* name, char* vorname,
					 			 int tag, int monat, int jahr,
					 			 char* strasse, char* ort, char* plz) :
		   Bekannter(name, vorname, tag, monat, jahr, strasse, ort, plz) { }


BekannterKnoten::BekannterKnoten(char *name, char *vorname) :
		BaumKnoten(), Bekannter() {
	Name(name);
	VorName(vorname);
	} 

int BekannterKnoten::operator < (BaumKnoten& knoten) {
	if( this->aName < ((BekannterKnoten*)&knoten)->aName)
		return 1;
	if( this->aName > ((BekannterKnoten*)&knoten)->aName)
		return 0;
	if( this->aVorname < ((BekannterKnoten*)&knoten)->aVorname)
		return 1;
	if( this->aVorname > ((BekannterKnoten*)&knoten)->aVorname)
		return 0;
	return 0;
	}
		
int BekannterKnoten::operator > (BaumKnoten& knoten) {
	if( this->aName > ((BekannterKnoten*)&knoten)->aName)
		return 1;
	if( this->aName < ((BekannterKnoten*)&knoten)->aName)
		return 0;
	if( this->aVorname > ((BekannterKnoten*)&knoten)->aVorname)
		return 1;
	if( this->aVorname < ((BekannterKnoten*)&knoten)->aVorname)
		return 0;
	return 0;
	}

void BekannterKnoten::Gleichheit(BaumKnoten* knoten) {
	delete knoten;
	return;
	}

void BekannterKnoten::Verarbeite(void) {
	cout << aName << ", " << aVorname << endl;
	return;
	}

int main(void) {
	Baum *BBaum;
	BekannterKnoten *k1;
	BaumKnoten *k2;
    int Anzahl;
	cout << "Testprogramm: Bekannte im binaeren Baum speichern" << endl;
	cout << "­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­" << endl;
	BBaum = new Baum;
	BBaum->Einfuegen(new BekannterKnoten("Meyer","Bernd",7,7,1965,
					 "Saturnring 89","Berlin","12524"));
	BBaum->Einfuegen(new BekannterKnoten("Friedrichs","Frank",3,4,1963,
					 "Wendenschloßstraße 520","Berlin","12557"));
	BBaum->Einfuegen(new BekannterKnoten("Faßbinder","Jürgen",4,9,1930,
					 "Ringstraße 92","Güstrow","18273"));
	BBaum->Einfuegen(new BekannterKnoten("Prochnow","Fred",14,1,1937,
					 "Weinbergstraße 75","Güstrow","18273"));
	BBaum->Einfuegen(new BekannterKnoten("Gerke","Peter",14,1,1957,
					 "Schnellstraße 45","Berlin","12685"));
	BBaum->Einfuegen(new BekannterKnoten("Arnold","Roland",1,1,1949,
					 "Kurt- Schumacher- Platz 45","Berlin","13403"));
	BBaum->Einfuegen(new BekannterKnoten("Becker","Werner",11,12,1941,
					 "Auguste- Viktoria- Allee 145","Berlin","13403"));
	BBaum->Einfuegen(new BekannterKnoten("Lehmann","Heinz",17,2,1970,
					 "Weinbergstraße 75","Bernau","16321"));
	Anzahl = BBaum->Durchlaufe();
	cout << "Anzahl ist: " << Anzahl << endl << endl;
	k1 = new BekannterKnoten("Meyer","Bernd");
	k2 = BBaum->Suche(k1);
	delete k1;
	if(k2!=NULL)
		cout << ((BekannterKnoten*)k2)->VorName() << " "
			 << ((BekannterKnoten*)k2)->Name() << endl;
	else
    	cout << "Nicht gefunden" << endl;
	k2 = NULL;
	k1 = new BekannterKnoten("Faßbinder","Jürgen");
	k2 = BBaum->Suche(k1);
	delete k1;
	if(k2!=NULL)
		cout << ((BekannterKnoten*)k2)->VorName() << " "
			 << ((BekannterKnoten*)k2)->Name() << endl;
	else
    	cout << "Nicht gefunden" << endl;
	k2 = NULL;
	delete BBaum;
	return 0;
    }
