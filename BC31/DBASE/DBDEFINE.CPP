// Implementierung der Klasse Header und Fields
// Beschreibung der Komponenten eines dBase- Datei- Kopfes
// Autor: Volker Hillmann, 19. Mai 1994
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>
#include <strstrea.h>
#include <string.h>
#include <stdlib.h>
#include <dos.h>

#include "dbdefine.hpp"


// Implementation der Klasse Header
// Standardkonstruktor
Header::Header(void) {
	aVersion    = dBaseVersion;
	aRecordCnt  = 0;
	aHeaderSize = sizeof(Header);
	aRecordSize = 0;
	SystemDate();
	memset(reserve,'\0',20);
	};   

// Kopierkonstruktor
Header::Header(Header& aHeader) {
	aVersion    = aHeader.aVersion;
	aRecordCnt  = aHeader.aRecordCnt;
	aHeaderSize = aHeader.aHeaderSize;
	aRecordSize = aHeader.aRecordSize ;
	SystemDate();
	memcpy(reserve,aHeader.reserve,20);
	};   


// Konstruktor mit Vorbelegungen
Header::Header(char aVers, unsigned int aHSize, unsigned int aRSize) {
	aVersion = aVers;
	aRecordCnt = 0;
	aHeaderSize = aHSize;
	aRecordSize = aRSize;
	SystemDate();
	memset(reserve,'\0',20);
	} 

// Destruktor: er muß in diesem Fall nichts tun
Header::~Header(void) {	}


short Header::Day(void) {
	return (int)aDatum[2];
    };

short Header::Day(int dd) {
	return (int)(aDatum[2]=(unsigned char)dd);
	}

short Header::Month(void) {
	return (int)aDatum[1];
    };

short Header::Month(int mm) {
	return (int)(aDatum[1]=(unsigned char)mm);
	}

short Header::Year(void) {
	return (int)aDatum[0];
	};

short Header::Year(int jj) {
	return (int)(aDatum[0] = (unsigned char)jj);
	}


int Header::ReadHeader(istream& ins) {
	ins.seekg(0L,ios::beg);
    if(ins.fail()) return 0;
	ins.read((char *)this,sizeof(Header));
    if(ins.fail() || ins.eof()) return 0;
	return 1;
	}


int Header::WriteHeader(ostream& out) {
	out.seekp(0L,ios::beg);
    if(out.fail()) return 0;
	out.write((char *)this,sizeof(Header));
	if(out.fail()) return 0;
	return 1;
	}


// Diese Funktion ist abhängig vom Compiler !!!
int Header::SystemDate(void) {
	#if defined __BCPLUSPLUS__
		struct dosdate_t heute;
	#else
		struct _dosdate_t heute;
    #endif
	_dos_getdate(&heute);
	Day(heute.day);
	Month(heute.month);
	Year(heute.year-1900);
	return 1;
    }

int Header::FieldCnt(void) {
   int RetVal = (aHeaderSize - 1 - sizeof(*this)) / 32;
   return RetVal;
   } 


// Implementation der Klasse Fields
Field::Field(void) {
	memset(aFName,'\0',11);
	aFType = ' ';
	aLaenge   = 0;
	aKomma    = 0;
	aSetField = 0;
	}

Field::Field(Field& Feld) {
	strncpy(aFName,Feld.aFName,11);
	aFName[10] = '\0';
	aFType     = Feld.aFType;
	aLaenge    = Feld.aLaenge;
	aKomma     = Feld.aKomma;
	aSetField  = Feld.aSetField;
	}

Field& Field::operator = (Field& aField) {
	strncpy(aFName,aField.aFName,11);
	aFName[10] = '\0';
	aFType     = aField.aFType;
	aLaenge    = aField.aLaenge;
	aKomma     = aField.aKomma;
	aSetField  = aField.aSetField;
	return *this;
	}


Field::Field(Field* Feld) {
	strncpy(aFName,Feld->aFName,11);
	aFName[10] = '\0';
	aFType     = Feld->aFType;
	aLaenge    = Feld->aLaenge;
	aKomma     = Feld->aKomma;
	aSetField  = Feld->aSetField;
	}

Field::Field(char *FeldName,char FeldTyp,unsigned char Lang,char Nachk) {
	strncpy(aFName,FeldName,11);
	aFName[10] = '\0';
	aFType     = FeldTyp;
	aLaenge    = Lang;
	aKomma     = Nachk;
	aSetField  = 0;
	}



Field::~Field(void) { }

char *Field::FName(void) { return aFName; };
char *Field::FName(char* FeldName) {
	strncpy(aFName,FeldName,11);
	aFName[10] = '\0';
	return aFName;
	}

char Field::FType(void) { return aFType; }
char Field::FType(char t) { return aFType=t; }
int Field::Laenge(void) { return aLaenge; }
int Field::Laenge(unsigned char l) { return aLaenge=l; }
int Field::Komma(void) { return aKomma; }
int Field::Komma(char k) { return aKomma=k; }

int Field::ReadField(istream& ins) {
   // spaeter positionieren ueber Parameter !!!
   ins.read((char *)&this->aFName[0],sizeof(Field));
   if(ins.fail()) return 0;
   return 1;
   }

int Field::WriteField(ostream& out) {
	// lseek(out,0L,SEEK_SET); spaeter positionieren mit Parameter
	out.write((char *)this,sizeof(Field));
    if(out.fail()) return 0;
	return 1;
	}
