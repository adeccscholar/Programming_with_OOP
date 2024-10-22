// Definition der Klasse DBDatum
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

#ifndef __DBDATUM_HPP
#define __DBDATUM_HPP

#include <iostream.h>
#include "dbobjekt.hpp"

class DBDatum : public DBObjekt {
	friend ostream& operator << (ostream&, DBDatum&);
	friend istream& operator >> (istream&, DBDatum&);

	friend DBDatum operator + (DBDatum, int);
	friend DBDatum operator + (int, DBDatum);
	friend DBDatum operator - (DBDatum, int);
	friend long    operator - (DBDatum, DBDatum);

	public:
		DBDatum(void);
		DBDatum(DBDatum&);
		DBDatum(char*);
		DBDatum(int, int, int);

		virtual char* Zuordnen(char*,int = 10,int=0);
		virtual const int DBObjektTyp(void) { return dbdatum; };
		virtual void Display(ostream&);

		virtual ~DBDatum(void);
		virtual int Tag(void);
		virtual int Tag(int t);
		virtual int Monat(void);
		virtual int Monat(int m);
		virtual int Jahr(void);
		virtual int Jahr(int j);

		DBDatum& operator = (DBDatum&);
		DBDatum& operator = (char*);
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

extern char *TagesNamen[];
extern char *MonatsNamen[];


#endif
