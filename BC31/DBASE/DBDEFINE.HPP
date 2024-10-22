// Definition der Klassen für den Zugriff auf den Header einer dBase III-Datei
// Informationen aus allgemeinem Header und den Feldbeschreibungen verwalten
// Autor: Volker Hillmann, 19. Mai 1994
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

#ifndef __HEADER_HPP
#define __HEADER_HPP

#include <iostream.h>

const int dBaseVersion = 0x03;

// Klasse Header: allgemeine Informationen zur dBase III - Datei
// Wenn das Zeichenfeld auskommentiert ist, handelt es sich um die 
// Einplatzversion, ansonsten um die Netzwerkversion von dBase III

class Header {
   private:
		unsigned char aVersion; 		// dBase- Versionsnummer
		unsigned char aDatum[3];		// Datum der letzten Aenderung
		unsigned long aRecordCnt;		// Anzahl der Datensaetze in der Datei
		unsigned short aHeaderSize;		// Groesse des Headers in Byte
		unsigned short aRecordSize;		// Groesse eines Records in Byte
		char reserve[20];		       	// Reserviert fuer spaetere Versionen
		// char netz[13];
	public:
		Header(void);
		Header(Header&);	
		Header(char, unsigned int, unsigned int);
		~Header(void);
		short Day(int);
		short Day(void);
		short Month(int);
		short Month(void);
		short Year(int);
		short Year(void);
		unsigned long TupelCnt(void) 			{ return aRecordCnt; };
		unsigned long TupelCnt(unsigned long l)	{ return aRecordCnt = l; };
		unsigned int HeaderSize(void)			{ return aHeaderSize; };
		unsigned int HeaderSize(unsigned int h)	{ return aHeaderSize = h; };
		unsigned int TupelSize(void)			{ return aRecordSize; };
		unsigned int TupelSize(unsigned int r)	{ return aRecordSize = r; };
	protected:
		int ReadHeader(istream&);
		int WriteHeader(ostream&);
		int SystemDate(void);
		int SetVersion(void) { return aVersion = dBaseVersion; };
		int FieldCnt(void);
	};


// Klasse Field: Beschreibung eines Blocks zur Definition eines Attributes
// Die Adresse im Speicher wird von dieser Klassenbibliothek nicht genutzt

class Field {
	private:
		char aFName[11];         	// Name des Feldeintrages
		char aFType;             	// Type des Feldeintrages
		unsigned char Adresse[4];	// Adresse des Feldes im Speicher
		unsigned char aLaenge;		// Laenge des Feldeintrages
		char aKomma;            	// Kommastellen bei numerischen Feldern
		char Ddummy1[2];        	// Ungenutzt, fuer spaetere Erweiterungen
		char aID;               	// Identifik.-symbol fuer Netzwerkfunkt.
		char Dummy2[2];	   			// Ungenutzt fuer spaetere Entwicklungen
		char aSetField;				// Kennzeichen fuer Set Field
		char Dummy3[8];				// Ungenutzt fuer spaetere Entwicklungen
	public:
		Field(void);
		Field(Field&);
		Field(Field*);
		Field(char*,char,unsigned char,char);
		~Field(void);
		char *FName(void);
		char *FName(char*);
		char FType(void);
		char FType(char);
		int Laenge(void);
		int Laenge(unsigned char);
		int Komma(void);
		int Komma(char);
		int ReadField(istream&);
		int WriteField(ostream&);
		Field& operator =(Field&);
	};

// Definition der Typen Zeiger auf Header, Field

typedef Header  *PTHeader;
typedef Field  *PTField;

#endif
