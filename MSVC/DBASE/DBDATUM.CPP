// Implementierung der Klasse DBDatum
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

#include <iostream.h>
#include <iomanip.h>
#include <strstrea.h>

#include "dos.h"

#include "DBDatum.HPP"

int TagesAnzahl[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31 };

char *TagesNamen[] = {  "Sonntag", "Montag", "Dienstag", "Mittwoch",
									"Donnerstag", "Freitag", "Sonnabend" };

char *MonatsNamen[] = { "", "Januar", "Februar", "März", "April", "Mai",
						"Juni", "Juli", "August", "September",
						"Oktober", "November", "Dezember" };

// Implementierung der datenabhängigen Methoden

int DBDatum::Tag(void) {
	int tmp;
	if(puffer == 0) return 1;
	istrstream ins(puffer+6,2);
	ins >> dec >> tmp;
	return tmp;
	}

int DBDatum::Tag(int t) {
	ostrstream outs(puffer+6,2);
	if(puffer == 0) return 1;
	outs << setw(2) << setfill('0') << t;
	return t;
	}

int DBDatum::Monat(void) {
	int tmp;
	if(puffer == 0) return 1;
	istrstream ins(puffer+4,2);
	ins >> dec >> tmp;
	return tmp;
	}

int DBDatum::Monat(int m) {
	ostrstream outs(puffer+4,2);
	if(puffer == 0) return 1;
	outs << setw(2) << setfill('0') << m;
	return m;
	}

int DBDatum::Jahr(void) {
	int tmp;
	if(puffer == 0) return 1901;
	istrstream ins(puffer,4);
	ins >> dec >> tmp;
	return tmp;
	}

int DBDatum::Jahr(int j) {
	ostrstream outs(puffer,4);
	if(puffer == 0) return 1901;
	outs << setw(4) << j;
	return j;
	}

// Konstruktoren und Destruktoren

DBDatum::DBDatum(void) : DBObjekt(10) {
	}


DBDatum::DBDatum(DBDatum& dat) : DBObjekt(10) {
	Tag(dat.Tag());
	Monat(dat.Monat());
	Jahr(dat.Jahr());
    }

DBDatum::DBDatum(char *p) : DBObjekt(p,10) { };

DBDatum::DBDatum(int tt, int mm, int jjjj)  : DBObjekt(10) {
	if(jjjj < 100) {
		SystemDatum();
		Jahr((Jahr() / 100) * 100 + jjjj);
		}
	else Jahr(jjjj);
	Tag(tt);
	Monat(mm);

	if(!Ueberpruefe()) {
		Tag(1);
		Monat(1);
		Jahr(1901);
		}
	}

DBDatum::~DBDatum(void) { };

char* DBDatum::Zuordnen(char *p, int l,int) {
	return DBObjekt::Zuordnen(p,l);
    }

void DBDatum::Display(ostream& out) {
	out << *this;
	}

// Zuweisungsoperatoren

DBDatum& DBDatum::operator = (DBDatum& dat) {
	Tag(dat.Tag());
	Monat(dat.Monat());
	Jahr(dat.Jahr());
	return DBDatum(*this);
	}

DBDatum& DBDatum::operator = (char* strdat) {
	istrstream ins(strdat);
	ins >> *this;
	return DBDatum(*this);
	}

// verbundende Zuweisungen

DBDatum DBDatum::operator += (int tage) {
	int zwtage;
	if(tage == 0) return DBDatum(*this);
	if(tage < 0)  {
		*this -= (-tage);
		return DBDatum(*this);
        }
	while(tage > 366) {
		zwtage = 365;
		if(IstSchaltjahr() && (Monat() <=2 )) zwtage += 1;
		Jahr(Jahr()+1);
		if(IstSchaltjahr() && (Monat() > 2 )) zwtage += 1;
		tage -= zwtage;
		}
	while(tage > (zwtage=TageImMonat())) {
		tage -= zwtage;
		if(Monat()==12) {
			Jahr(Jahr()+1);
			Monat(1);
			}
		else Monat(Monat()+1);
		}
	if(Tag()+tage > TageImMonat()) {
		tage = tage - (TageImMonat() - Tag());
		Monat(Monat()+1);
		Tag(tage);
		}
	else Tag(Tag()+tage);
	return DBDatum(*this);
	}

DBDatum DBDatum::operator -= (int tage) {
	int zwtage;
	if(tage == 0) return *this;
	if(tage < 0)  return *this += (-tage);
	if(Tag() > 28)
		if(tage > 3) Tag(Tag()-3);
		else {
			Tag(Tag()-tage);
			return *this;
			}
	while( tage > 366) {
		zwtage = 365;
		if(IstSchaltjahr() && (Monat() >  2)) zwtage+=1;
		Jahr(Jahr()-1);
		if(IstSchaltjahr() && (Monat() <= 2)) zwtage+=1;
		tage -= zwtage;
		}
	while(tage > 0) {
		if(Monat()==1) {
			Jahr(Jahr()-1);
			Monat(12);
			}
		else Monat(Monat()-1);
		tage-=TageImMonat();
		}
	if(tage < 0) {
		*this += (-tage);
        }
	return DBDatum(*this);
	}

// Konvertierungsoperatoren

DBDatum::operator char*() {
	ostrstream outs;
	outs << *this << ends;
	return outs.str();
	}


// vergleichende Operatoren

int DBDatum::operator == (DBDatum dat) {
	if(Tag()   != dat.Tag())   return 0;
	if(Monat() != dat.Monat()) return 0;
	if(Jahr()  != dat.Jahr())  return 0;
	return 1;
	}

int DBDatum::operator != (DBDatum dat) {
	return (*this == dat ? 0 : 1);
	}

int DBDatum::operator <  (DBDatum dat) {
	if(Jahr()  < dat.Jahr())  return 1;
	if(Jahr()  > dat.Jahr())  return 0;
	if(Monat() < dat.Monat()) return 1;
	if(Monat() > dat.Monat()) return 0;
	if(Tag()   < dat.Tag())   return 1;
	if(Tag()   > dat.Tag())   return 0;
	return 0;
	}

int DBDatum::operator <= (DBDatum dat) {
	if(Jahr()  < dat.Jahr())  return 1;
	if(Jahr()  > dat.Jahr())  return 0;
	if(Monat() < dat.Monat()) return 1;
	if(Monat() > dat.Monat()) return 0;
	if(Tag()   < dat.Tag())   return 1;
	if(Tag()   > dat.Tag())   return 0;
	return 1;
	}

int DBDatum::operator >  (DBDatum dat) {
	return ( *this <= dat ? 0 : 1);
	}

int DBDatum::operator >= (DBDatum dat) {
	return ( *this < dat ? 0 : 1);
	};

// Hilffunktionen

int DBDatum::IstSchaltjahr(void) {
	return (Jahr()%4==0 ? 1 : 0);
	}

int DBDatum::TageImMonat(void) {
	if(Monat()==2) return ( IstSchaltjahr()==1 ? 29 : 28 );
	else return TagesAnzahl[Monat()];
	}

int DBDatum::Wochentag(void) {
	int Jahrhundert, JahrImJH, Wochentag;
	int derTag   = Tag(),
		derMonat = Monat(),
		dasJahr  = Jahr();
	if(derMonat < 3) {
		derMonat += 10;
		dasJahr  -= 1;
		}
	else
		derMonat -= 2;

	Jahrhundert = dasJahr / 100;
	JahrImJH = dasJahr % 100;

	Wochentag = ( ( (26 * derMonat - 2) / 10 ) +
				  derTag + JahrImJH + (JahrImJH / 4) +
				  (Jahrhundert / 4) - (2 * Jahrhundert) ) % 7;

	return (Wochentag < 0 ? Wochentag + 7 : Wochentag);
	}

int DBDatum::Ueberpruefe(void) {
	if((( Monat() < 1) || (Monat() > 12   )  ||
		( Jahr() > 99) && ( Jahr() < 1000 )) ||
		( Tag() < 1) || (Tag() > TageImMonat())) return 0;
	else return 1;
	}


void DBDatum::SystemDatum(void) {
	#if defined __BCPLUSPLUS__
	  struct dosdate_t dd;
	#else
	  struct _dosdate_t dd;
	#endif
	_dos_getdate(&dd);
	Tag(dd.day);
	Monat(dd.month);
	Jahr(dd.year);
	return;
	}

// befreundete arithmetische Operatoren

DBDatum operator + (DBDatum dat, int tage) {
	return dat += tage;
	}

DBDatum operator + (int tage, DBDatum dat) {
	return dat += tage;
	}


DBDatum operator - (DBDatum dat, int tage) {
	return dat -= tage;
	}

long operator - (DBDatum dat1, DBDatum dat2) {
	long zw = 0;
	while(dat2.Jahr() < dat1.Jahr()) {
		zw += 365;
		if(dat2.IstSchaltjahr() && (dat2.Monat() <=2)) zw++;
		dat2.Jahr(dat2.Jahr()+1);
		if(dat2.IstSchaltjahr() && (dat2.Monat() >2 )) zw++;
		}
	if(dat1 < dat2) return zw - (dat2 - dat1);
	while( dat2.Monat() < dat1.Monat()  ) {
		zw += dat2.TageImMonat();
		dat2.Monat(dat2.Monat()+1);
		}
	if(dat1 < dat2) zw -= (dat2.Tag() - dat1.Tag());
	else zw += (dat1.Tag() - dat2.Tag());
	return zw;
	}

// Übergabe- und Übernahmeoperator

ostream& operator << (ostream& out, DBDatum& dat) {
	long alt = out.setf(ios::right,ios::adjustfield);
	out << setw(2) << setfill('0') << dat.Tag() << '.'
	    << setw(2) << setfill('0') << dat.Monat() << '.'
	    << setw(4) << setfill(' ') << dat.Jahr();
	out.setf(alt);
	return out;
	}

istream& operator >> (istream& in, DBDatum& dat) {
	char pkt;
	int  tt, mm, jjjj;
	in >> dec >> tt >> pkt >> dec >> mm >> pkt >> dec >> jjjj;
	dat = DBDatum(tt, mm, jjjj);
	return in;
	}

