// Definition der Klasse für den Zugriff auf eine dBase- Datei
// Zentrale Klasse für den Zugriff
// Autor: Volker Hillmann, 20. März 1994
// Compiler: Borland C++ 3.1, 4.0, Symantex C++ 6.0, Visual C++ 1.0

#ifndef __DBHEADER_HPP
#define __DBHEADER_HPP

#include <fstream.h>
#include "dbdefine.hpp"

#define PATHLEN  81

const char dbVersionString[] = "DBF-View Version 1.0";
const int dbVersion = 1;

struct Status {
	unsigned fail  :  1;
	unsigned open  :  1;
	unsigned eof   :  1;
	unsigned dummy : 13;
	};


// Klasse DBHeader, abgeleitet von Header, Zugriff auf die Datei

class DBFile : public Header {
	friend int main(void);
	private:
		PTField Fields;		 		  // Feld mit Attributbeschreibungen
		int FieldsCounter;			  // Anzahl von Attributen in der Datei
		char DateiName[PATHLEN];	  // Name der dBase- Datei
		static char *DOSErrorMsg[36]; // Feld mit DOS- Fehlermeldung
	protected:
		fstream aStream;			// Dateistream fuer den Zugriff
		char *Buffer;				// Ein- und Ausgabepuffer
		unsigned long CurrentTupel;	// aktuelles Tupel
		Status dbStatus;			// Statusinformationen
	public:
		DBFile(void);
		DBFile(DBFile&);
		DBFile(char*);
		DBFile(char*,char, unsigned int, unsigned int);
		DBFile(char*,Header&);
		~DBFile(void);
		PTField const DBFields(void) { return Fields; };
		char* PTBuffer(void)   { return Buffer; };
		char* DBName(void)     { return DateiName; };
		int DBFieldCnt(void) { return FieldsCounter; };
		char *DBFieldPos(int);
		char *DBFieldPos(char*);
		int FieldNumber(char*);

		int DBOpen(void);
		int DBOpen(char *aName);
		int DBCreate(char*,PTField,int);
		int DBClose(void);
		int DBInfo(void);
		int DBBlank(void);
		int DBAppend(void);
		int DBReplace(unsigned long = 0);
		int DBUpdate(unsigned long = 0);
		int DBDelete(unsigned long = 0);
		unsigned int DBDeleteAll(void);
		int DBRecall(unsigned long = 0);
		unsigned int DBRecallAll(void);
		int DBIsDeleted(unsigned long = 0);
		unsigned int DBPack(void);
		unsigned int DBFastPack(void);
		int DBIsOpen(void)    { return dbStatus.open; };
		int DBIsFail(void)    { return dbStatus.fail; };
		int DBIsEOF(void)     { return dbStatus.eof;  };
		char *DOSError(void);
		int GotoTupel(unsigned long);   // In Datei auf Tupel positionieren
		int GotoFirst(void) { return GotoTupel(1); };
		int GotoLast(void) { return GotoTupel(TupelCnt()); };
		int GotoNext(void);
		int GotoPrev(void);
		unsigned long TupelNumber(void) { return CurrentTupel; };
		int DBRead(unsigned long = 0);
	protected:
		int CopyBuffer(char *NeuInhalt);
		int OpenStream(char*,int=0);	// Filestream öffnen
		int DBWrite(unsigned long = 0);
	 };

#endif
