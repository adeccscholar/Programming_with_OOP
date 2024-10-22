// Methoden für Arbeit mit Datum
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0


#include <iostream.h>
#include <iomanip.h>
#include <strstrea.h>

#include "dbdaten.hpp"


DBObjekt *ErzeugeDBDaten(DBFile *dbf,char *Name) {
	int pos, size, komma;
	char typ, *adresse;
	pos   = dbf->FieldNumber(Name);
	if(pos==0) return NULL;
	pos-=1;
	typ     = (dbf->DBFields()+pos)->FType();
	size    = (dbf->DBFields()+pos)->Laenge();
	komma   = (dbf->DBFields()+pos)->Komma();
	adresse = dbf->DBFieldPos(pos+1);
	switch(typ) {
		case 'C': return new DBString(adresse,size);
		case 'D': return new DBDatum(adresse);
		case 'N': if(komma > 0)
					  return new DBZahl(adresse,size-1-komma,komma);
				  else
					  return new DBZahl(adresse,size,0);
		case 'L': return new DBLogical(adresse);
		}
	return NULL;
	}

void Display(DBFile *dbf,ostream& out,int para) {
	int lauf,i,anz;
	PTDBObjekt *Feld;

	anz = dbf->DBFieldCnt();
    Feld = new PTDBObjekt[anz];
	for(lauf = 0; lauf < anz; lauf++)
		Feld[lauf] = ErzeugeDBDaten(dbf,(dbf->DBFields()+lauf)->FName());
	for(i=1;i<=dbf->TupelCnt();i++) {
		dbf->DBRead(i);
		if((para==0) || (para==1)) out <<  *dbf->PTBuffer();
		else if(*(dbf->PTBuffer())=='*') continue;
        if((para==0) || (para==2)) out << setw(4) << i << ": ";
		for(lauf=0;lauf < anz; lauf++) {
		   Feld[lauf]->Display(cout);
		   out << " ";
		   }
		out << endl;
		}
	for(lauf = 0; lauf < anz; lauf++)
		delete Feld[lauf];

	return;
	}

void Display(DBFile *dbf,char *Wunsch,ostream& out,int para) {
	int lauf,i,anz;
	PTDBObjekt *Feld;
	char Name[12];
	istrstream ins(Wunsch,strlen(Wunsch));
	istrstream ins2(Wunsch,strlen(Wunsch));
	for(anz=0;(!ins.eof() && !ins.bad());
		anz++,ins >> setw(12) >> Name);
	Feld = new PTDBObjekt[anz];
	for(lauf = 0; lauf < anz; lauf++) {
		ins2 >> setw(12) >> Name;
		Feld[lauf] = ErzeugeDBDaten(dbf,Name);
		}
	for(i=1;i<=dbf->TupelCnt();i++) {
		dbf->DBRead(i);
		if((para==0) || (para==1)) out <<  *dbf->PTBuffer();
		else if(*(dbf->PTBuffer())=='*') continue;
		if((para==0) || (para==2)) out << setw(4) << i << ": ";
		for(lauf=0;lauf < anz; lauf++) {
		   Feld[lauf]->Display(cout);
		   out << " ";
		   }
		out << endl;
		}
	for(lauf = 0; lauf < anz; lauf++)
		delete Feld[lauf];

	return;
	}