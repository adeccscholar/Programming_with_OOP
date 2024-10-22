// Implementierung der Klasse DBFile
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0


#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>

#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "dbheader.hpp"


const char IsDele  = 0x2a;	// regulärer Eintrag
const char NoDele  = 0x20;	// gelöschter Eintrag
const char EndDat  = 0x1a;	// Endemarke dBase
const char EndDef  = 0x0d;	// Endemarke für Header

// Fehlermeldungen aus DOS, Index entspricht errno

char *DBFile::DOSErrorMsg[36]= {
   /*  0 */ "Kein Fehler",
   /*  1 */ "ungueltige Funktionsnummer",
   /*  2 */ "Datei oder Suchweg nicht gefunden",
   /*  3 */ "Suchweg nicht gefunden",
   /*  4 */ "Maximalzahl von Dateien bereits offen",
   /*  5 */ "Zugriff nicht gestattet",
   /*  6 */ "Handle nicht definiert",
   /*  7 */ "Speicherkontrollblock zerstoert",
   /*  8 */ "nicht genuegend Speicher",
   /*  9 */ "ungueltige Speicherblockadresse",
   /* 10 */ "ungueltige Umgebung",
   /* 11 */ "ungueltiges Format",
   /* 12 */ "ungueltiger Zugriffscode",
   /* 13 */ "ungueltige Daten",
   /* 14 */ "unbekannter Fehler",
   /* 15 */ "Laufwerk/Geraet existiert nicht",
   /* 16 */ "Versuch, das aktuelle Verzeichnis zu loeschen",
   /* 17 */ "Ziel- und Quell-Laufwerk sind nicht identisch",
   /* 18 */ "keine weiteren Dateien",
   /* 19 */ "ungueltiges Argument",
   /* 20 */ "DOS- Kommandozeile zu lang",
   /* 21 */ "EXEC- Formatfehler",
   /* 22 */ "RENAME mit verschiedenen Laufwerken",
   /* 23 */ NULL,
   /* 24 */ NULL,
   /* 25 */ NULL,
   /* 26 */ NULL,
   /* 27 */ NULL,
   /* 28 */ NULL,
   /* 29 */ NULL,
   /* 30 */ NULL,
   /* 31 */ NULL,
   /* 32 */ NULL,
   /* 33 */ "Mathematischer Parameter",
   /* 34 */ "Ergebnis zu groß",
   /* 35 */ "Datei existiert bereits"
   };


DBFile::DBFile(void) : Header() {
	memset(DateiName,'\0',PATHLEN);
	Buffer = NULL;
	Fields = NULL;
	dbStatus.eof=dbStatus.fail=dbStatus.open=0;
	CurrentTupel = 0;
	}

DBFile::DBFile(DBFile& aDBFile) : Header((Header)(*(&aDBFile))) {
	memset(DateiName,'\0',PATHLEN);
	strncpy(DateiName,aDBFile.DateiName,PATHLEN);
	DateiName[PATHLEN-1] = '\0';
	Buffer = NULL;
	Fields = NULL;
	dbStatus.eof=dbStatus.fail=dbStatus.open=0;
	CurrentTupel = 0;
	}

DBFile::DBFile(char* aName) : Header() {
	memset(DateiName,'\0',PATHLEN);
	strncpy(DateiName,aName,PATHLEN);
	DateiName[PATHLEN-1] = '\0';
	Buffer = NULL;
	Fields = NULL;
	CurrentTupel = 0;
	dbStatus.eof=dbStatus.fail=dbStatus.open=0;
	}


DBFile::DBFile(char* aName,char aVers, unsigned int aHSize,
					unsigned int aRSize) : Header(aVers,aHSize,aRSize) {
	memset(DateiName,'\0',PATHLEN);
	strncpy(DateiName,aName,PATHLEN);
	DateiName[PATHLEN-1] = '\0';
	Buffer = NULL;
	Fields = NULL;
	CurrentTupel = 0;
	dbStatus.eof=dbStatus.fail=dbStatus.open=0;
	 }

DBFile::DBFile(char* aName,Header& aHeader) : Header(aHeader) {
	memset(DateiName,'\0',PATHLEN);
	strncpy(DateiName,aName,PATHLEN);
	DateiName[PATHLEN-1] = '\0';
	Buffer = NULL;
	Fields = NULL;
	CurrentTupel = 0;
	dbStatus.eof=dbStatus.fail=dbStatus.open=0;
	 }

DBFile::~DBFile(void) {
	if(DBIsOpen()) aStream.close();
	if(Buffer!=NULL) {
		delete [] Buffer;
		Buffer=NULL;
		}
	if(Fields!=NULL) {
		delete [] Fields;
		Fields=NULL;
		}
	}

int DBFile::DBIsDeleted(unsigned long RecordNumber) {
	dbStatus.fail=1;
	if(RecordNumber==0) RecordNumber=CurrentTupel;
	if(Buffer==NULL) return 0;
	if(dbStatus.open == 0) return 0;
	if(GotoTupel(RecordNumber)) {
		dbStatus.fail = 0;
		DBRead();
		if(Buffer[0]==IsDele) return 1;
		else return 0;
		}
	return(0);
	}

int DBFile::OpenStream(char *Name,int neu) {
	if(Name[0]=='\0') return 1;
	if(!neu)
	  #if defined __BCPLUSPLUS__
	  aStream.open(Name,ios::binary | ios::in | ios::out | ios::nocreate);
	  #elif defined _MSC_VER
	  aStream.open(Name,ios::binary | ios::in | ios::out | ios::nocreate);
	  #else
	  aStream.open(Name,ios::translated | ios::in | ios::out | ios::nocreate);
	  #endif
	else
	  #if defined __BCPLUSPLUS__
	  aStream.open(Name,ios::binary | ios::in | ios::out | ios::noreplace);
	  #elif defined _MSC_VER
	  aStream.open(Name,ios::binary | ios::in | ios::out | ios::noreplace);
	  #else
	  aStream.open(Name,ios::translated|ios::in|ios::out | ios::noreplace);
	  #endif
	dbStatus.open=0;
	if(aStream.bad()) return 2;
	if(aStream.fail()) return 3;
	dbStatus.open=1;
	return 0;
	}

int DBFile::GotoTupel(unsigned long RecNumber) {
	long aOffSet;
	if(RecNumber > TupelCnt()) return 0;
	if(RecNumber==0) RecNumber = CurrentTupel;
	aOffSet = HeaderSize() + (RecNumber-1) * TupelSize();
	CurrentTupel=RecNumber;
	dbStatus.fail = 1;
	if(dbStatus.open==0) return 0;
	dbStatus.fail=0;
	dbStatus.eof=0;
	if(TupelCnt()<RecNumber) {
		dbStatus.eof=1;
		dbStatus.fail=1;
		return 0;
		}
	aStream.seekg(aOffSet,ios::beg);
	aStream.seekp(aOffSet,ios::beg);
	if(aStream.fail()) {
		dbStatus.fail=1;
		return 0;
		}
	if(aStream.eof()) {
		dbStatus.eof=1;
		dbStatus.fail=1;
		return 0;
		}
	return 1;
	}

int DBFile::GotoNext(void) {
	if(CurrentTupel < TupelCnt()) return GotoTupel(CurrentTupel + 1);
	else return 0;
	}

int DBFile::GotoPrev(void) {
	if(CurrentTupel > 1)  return GotoTupel(CurrentTupel - 1);
	else return 0;
	}


int DBFile::DBCreate(char* aName,PTField felder,int Anz) {
	int i,RecSize=1;
	Buffer = new char[TupelSize()+1];
	if(Buffer==NULL) return 0;
	if(DBIsOpen()) DBClose();
	strncpy(DateiName,aName,PATHLEN);
	DateiName[PATHLEN-1] = '\0';
	if(OpenStream(DateiName,1)) return 0;
	SystemDate();
	SetVersion();
	for(i=0;i<Anz;i++) RecSize+=(felder[i].Laenge());
	TupelSize(RecSize);
	HeaderSize((sizeof(Header)+Anz*sizeof(Field))+1);
	TupelCnt(0);
	WriteHeader(aStream);
	Fields = new Field[Anz];
	FieldsCounter = Anz;
	for(i=0;i<FieldsCounter;i++) {
		Fields[i] = felder[i];
		Fields[i].WriteField(aStream);
		}
	aStream.write(&EndDef,1);
	aStream.write(&EndDat,1);
	aStream.close();
	if(OpenStream(DateiName)) return 0;
	dbStatus.open = 1;
	dbStatus.fail = 0;
	return 1;
	}


int DBFile::DBOpen(void) {
	register int i,RetVal=1;
	if(OpenStream(DateiName)) return 0;
	if(!ReadHeader(aStream)) return 0;
	FieldsCounter =  FieldCnt();
	Fields = new Field[FieldsCounter];
	for(i=0;(i<FieldsCounter)&&RetVal;i++) {
		RetVal=Fields[i].ReadField(aStream);
		}
	if(!RetVal) return 0;
	Buffer = new char[TupelSize()+1];
	if(Buffer==NULL) {
	   dbStatus.open=0;
	   aStream.close();
	   return 0;
	   }
	CurrentTupel = 1;
	dbStatus.open=1;
	GotoTupel(1);
	return 1;
	}

int DBFile::DBOpen(char *aName) {
	strncpy(DateiName,aName,PATHLEN);
	DateiName[PATHLEN-1] = '\0';
	return DBOpen();
	}

int DBFile::DBClose(void) {
	if(DBIsOpen()) {
		WriteHeader(aStream);
		aStream.close();
		dbStatus.open=0;
		}
	if(Buffer!=NULL) {
		delete [] Buffer;
		Buffer = NULL;
		}
	if(Fields!=NULL) {
		delete [] Fields;
		Fields = NULL;
		}
	FieldsCounter = 0;
	return 1;
	}


char* DBFile::DBFieldPos(int pos) {
	register int i, adr;
	if((pos<1) || (pos > FieldsCounter)) return NULL;
	pos-=1;
	for(i=0, adr=1;i < pos;i++)
		adr += Fields[i].Laenge();
	return Buffer + adr;
	}

char* DBFile::DBFieldPos(char* name) {
	register int i, adr;
	strupr(name);
	for(i=0, adr=1;i < FieldsCounter;i++) {
		if(strcmp(Fields[i].FName(),name)==0) return Buffer + adr;
		adr += Fields[i].Laenge();
		}
	return NULL;
	}

int DBFile::FieldNumber(char* name) {
	register int i;
	strupr(name);
	for(i=0;i < FieldsCounter;i++) {
		if(strcmp(Fields[i].FName(),name)==0) return i+1;
		}
	return 0;
	}


char* DBFile::DOSError(void) {
	return DOSErrorMsg[errno];
	}

int DBFile::DBDelete(unsigned long RecordNumber) {
	if(RecordNumber==0) RecordNumber=CurrentTupel;
	if(!DBRead(RecordNumber)) return 0;
	Buffer[0] = IsDele;
	return DBUpdate(RecordNumber);
	}

unsigned int DBFile::DBDeleteAll(void) {
	unsigned int anz=0;
	for(int i=1;i<=TupelCnt();i++) {
		if(!DBIsDeleted(i)) {
			if(!DBDelete(i)) return 0;
			anz+=1;
			}
		}
	return anz;
	}

int DBFile::DBRecall(unsigned long RecordNumber) {
	if(RecordNumber==0) RecordNumber=CurrentTupel;
	if(!DBRead(RecordNumber)) return 0;
	Buffer[0] = NoDele;
	return DBUpdate(RecordNumber);
	}


unsigned int DBFile::DBRecallAll(void) {
	unsigned int anz = 0;
	for(int i=1;i<=TupelCnt();i++) {
		if(DBIsDeleted(i)) {
			if(!DBRecall(i)) return 0;
			anz+=1;
			}
		}
	return anz;
	}

unsigned int DBFile::DBFastPack(void) {
	unsigned int lese = 0, schreibe = 0;
	while(lese < TupelCnt()) {
		if(!DBRead(++lese)) return 0;
		if(Buffer[0]!=IsDele) if(!DBWrite(++schreibe)) return 0;
		}
	DBBlank();
	for(lese = schreibe+1;lese <= TupelCnt();lese++) {
		DBWrite(lese);
		}
	GotoTupel(schreibe+1);
	aStream.write(&EndDat,1);
	TupelCnt(schreibe);
	WriteHeader(aStream);
	return schreibe;
	}

unsigned int DBFile::DBPack(void) {
	unsigned int lese = 0, schreibe = 0;
	char OldName[PATHLEN];
	DBFile *dbf2 = new DBFile;
	if(unlink("TMPFILE.DBF")==-1) {
		if(errno==EACCES) return 0;
		}
	strcpy(OldName,DBName());
	DBClose();
	rename(OldName,"TMPFILE.DBF");
	DBOpen("TMPFILE.DBF");
	dbf2->DBCreate(OldName,DBFields(),DBFieldCnt());
	while(lese < TupelCnt()) {
		if(!DBRead(++lese)) return 0;
		if(Buffer[0]!=IsDele) {
			dbf2->CopyBuffer(Buffer);
			schreibe+=1;
			if(!dbf2->DBAppend()) return 0;
			}
		}
	DBClose();
	dbf2->DBClose();
	DBOpen(OldName);
	unlink("TMPFILE.DBF");
	return schreibe;
	}

int DBFile::DBRead(unsigned long RecordNumber) {
	if(RecordNumber==0) RecordNumber = CurrentTupel;
	if(!GotoTupel(RecordNumber)) return 0;
	aStream.read(Buffer,TupelSize());
	Buffer[TupelSize()]='\0';
	if(Buffer[0]==IsDele) return -1;
	return 1;
	}

int DBFile::DBBlank(void) {
	memset(Buffer,' ',TupelSize());
	return 1;
	}

int DBFile::DBAppend(void) {
	return DBWrite(TupelCnt()+1);
	}

int DBFile::DBReplace(unsigned long RecNumber) {
	return DBWrite(RecNumber);
	}

int DBFile::DBUpdate(unsigned long RecNumber) {
	return DBWrite(RecNumber);
	}


int DBFile::DBWrite(unsigned long RecordNumber) {

	int islast = 0;
	if(RecordNumber==0) RecordNumber = CurrentTupel;
	if(!GotoTupel(RecordNumber)) {  // Anhängen
		islast = 1;
		TupelCnt(TupelCnt()+1);
		RecordNumber =TupelCnt();
		CurrentTupel = RecordNumber;
		if(!GotoTupel(RecordNumber)) return 0;
		}
	SystemDate();
	WriteHeader(aStream);
	GotoTupel(RecordNumber);
	aStream.write(Buffer,TupelSize());
	if(islast) aStream.write(&EndDat,1);
	GotoNext();
	return 1;
	}


int DBFile::CopyBuffer(char *NeuInhalt) {
	int i;
	strcpy(Buffer,NeuInhalt);
	for(i=strlen(Buffer);i<TupelSize();i++) Buffer[i] = ' ';
	Buffer[TupelSize()]='\0';
	return 1;
	}

int DBFile::DBInfo(void) {
	register int i;
	ReadHeader(aStream);
	for(i=0;i<FieldCnt();i++) Fields[i].ReadField(aStream);
	cout << dbVersionString << endl;
	cout << "Information fuer dBase- Datei:  " << DateiName << endl;
	cout << "letzte Aenderung:   " << setw(2) << setfill('0') << Day()
		 << '.' << setw(2) << Month() << '.' << setw(2) << Year()
		 << setfill(' ') << endl;
	cout << "Headergroesse:      " << setw(5) << HeaderSize() << endl;
	cout << "Attribute           " << setw(5) << FieldCnt()   << endl;
	cout << "Datensatzlaenge:    " << setw(5) << TupelSize()  << endl;
	cout << "Datensaetze:        " << setw(5) << TupelCnt()   << endl
		 << endl;
	cout.setf(ios::left,ios::adjustfield);
	cout << setw(12) << setiosflags(ios::left) << "Feldname"
		 << setw( 4) << " Typ" << setw( 7) << " Laenge"
		 << setw( 6) << " Komma" << endl
		 << "-----------------------------" << endl;
	for(i=0;i<FieldsCounter;i++) {
		cout.setf(ios::left,ios::adjustfield);
		cout << setw(12) << Fields[i].FName();
		cout.setf(ios::right,ios::adjustfield);
		cout << setw( 4) << Fields[i].FType()
			 << setw( 7) << Fields[i].Laenge()
			 << setw( 5) << Fields[i].Komma() << endl;
		}
	return 1;
	}



