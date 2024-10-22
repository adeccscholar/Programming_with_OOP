// Die Klasse Datum

#include <iostream.h>
#include <iomanip.h>

#include "datum.hpp"

Datum::Datum(void) {
	aTag   =    1;
	aMonat =    1;
	aJahr  = 1901;
	}

Datum::Datum(int tt, int mm, int jj) {
	aTag   = tt;
	aMonat = mm;
	aJahr  = jj;
	}

Datum::Datum(Datum& dd) {
	aTag   = dd.aTag;
	aMonat = dd.aMonat;
	aJahr  = dd.aJahr;
	}

int Datum::Tag(void) 		{ return aTag; }
int Datum::Tag(int tt)	{ return aTag   = tt; 	}
int Datum::Monat(void)	{ return aMonat; }
int Datum::Monat(int mm)	{ return aMonat = mm; 	}
int Datum::Jahr(void)		{ return aJahr; }
int Datum::Jahr(int jj)	{ return aJahr  = jj; 	}

void Datum::ZeigeDatum(ostream& os) {
	os	<< setfill('0') << setw(2) << aTag << '.' << setw(2) << aMonat
		<< '.' << setfill(' ') << aJahr;
   return;
	}

ostream& operator << (ostream& os,Datum& d) {
	return os << setfill('0') << setw(2) << d.aTag << '.'
			   << setw(2) << d.aMonat << '.' << setfill(' ') << d.aJahr;
	}