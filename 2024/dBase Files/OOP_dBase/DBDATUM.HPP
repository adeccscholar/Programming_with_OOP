// Definition der Klasse DBDatum
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

// Originale Quellen von 1994 (pre Standard)
// Überarbeitung für den Stream, minimale notwendige Anpassungen 
// für aktuelle Compiler, hier Visual Studio 2022
// Volker Hillmann, 24.10.2024
// MIT License

#ifndef __DBDATUM_HPP
#define __DBDATUM_HPP

#include <iostream>     // !2024! Anpassung für modernes C++, Wegfall von .h für Standardheader
#include "dbobjekt.hpp"

using namespace std;  // !2024! Anpassung für modernes C++, provisorisches Öffnen der Namesräume

class DBDatum : public DBObjekt {
	friend ostream& operator << (ostream&, DBDatum&);
	friend istream& operator >> (istream&, DBDatum&);

	friend DBDatum operator + (DBDatum, int);
	friend DBDatum operator + (int, DBDatum);
	friend DBDatum operator - (DBDatum, int);
	friend long    operator - (DBDatum, DBDatum);

	public:
		DBDatum(void);
		DBDatum(DBDatum const&); // !2024! copy constructor muss zwingend const& sein
		DBDatum(char*);
		DBDatum(int, int, int);

		virtual char* Zuordnen(char*,int = 10,int=0);
		virtual const int DBObjektTyp(void) { return dbdatum; };
		virtual void Display(ostream&);

		virtual ~DBDatum(void);
		virtual int Tag(void) const;   // !2024! selector as const, otherwise problems with copy constructor
		virtual int Tag(int t);
		virtual int Monat(void) const; // !2024! selector as const, otherwise problems with copy constructor
		virtual int Monat(int m);
		virtual int Jahr(void) const;  // !2024! selector as const, otherwise problems with copy constructor
		virtual int Jahr(int j);

		DBDatum& operator = (DBDatum&);
		DBDatum& operator = (const char*);
		DBDatum operator += (int);
		DBDatum operator -= (int);
		DBDatum operator ++ () { return DBDatum(*this+=1); };
		DBDatum operator -- () { return DBDatum(*this-=1); };
		operator char*();

		int Wochentag(void);
		int IstSchaltjahr(void);
		int TageImMonat(void);
		void SystemDatum(void);

		int operator == (DBDatum);
		int operator != (DBDatum);
		int operator <  (DBDatum);
		int operator <= (DBDatum);
		int operator >  (DBDatum);
		int operator >= (DBDatum);
	private:
		int Ueberpruefe(void);
	};

extern const char *TagesNamen[];   // !2024! const jetzt zwingend für Initialisierung
extern const char *MonatsNamen[];  // !2024! const jetzt zwingend für Initialisierung


#endif
