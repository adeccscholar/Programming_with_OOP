// Beispielsprogramm: Das Arbeiten mit Streams
// Einbinden der Streamsklasse
#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>
#include <strstrea.h>

// C- Stringfunktion (fuer strlen)
#include <string.h>

#if defined _Windows
#error Keine Windows- Anwendung
#endif

// Stream fuer die Eingabe
ifstream DatenDatei;
// Stream fuer die Druckerausgabe - DOS- Kanal 4 ist prn zugeordnet
ofstream Drucker(4);

// Struktur fuer Datum
struct Datum {
   int Tag,Monat,Jahr;
   };

// Funktionsprototypen, die mit Datum arbeiten
void SetzeDatum(Datum &aDatum,int tt,int mm,int jj);
char *DatumToString(Datum aDatum,char *ptr);
void StringToDatum(char *ptr,Datum &aDatum);

// Struktur, um Tabelle aufzubauen
struct Tabelle {
	char Name[11];	// Bezeichner der Spalte
	char Typ;		// Typ der Spalte
	int  Laenge;	// Laenge der Tabellenspalte
	int  NachKomma;	// Nachkommastellen
	};

// Funktionen, um mit de Tabelleformat zu arbeiten
void SetzeSpalte(Tabelle &aTabelle,const char *aName,char aTyp,
				 int aLaenge,int aNachKomma);
void DruckerTitel(Tabelle &aTabelle,ofstream &Drucker);
void DruckerTabelle(Tabelle &aTabelle,ofstream &Drucker);
void DruckFormatSpalte(Tabelle *aSpalte,ofstream &Drucker);


// Struktur, um eine Person zu speichern
struct Person {
   char Name[13],VorName[13];
   Datum Beginn;
   char Taetigkeit[16];
   float Gehalt;
   };

// Funktionen, um mit der Struktur Person zu arbeiten
void FormatierePerson(Person &aPerson,istrstream &instr);
int LesePerson(Person &aPerson,ifstream &Datei);
void DruckePerson(Person &aPerson,Tabelle *aTab,ofstream &aDrucker);

// Manipulatoren fuer die Druckerausgabe
// Tabelle Oben

ostream& TabBeginn (ostream& output) { return output <<  "³ "; }
ostream& TabBeginnO(ostream& output) { return output <<  "ÚÄ"; }
ostream& TabBeginnZ(ostream& output) { return output <<  "ÃÄ"; }
ostream& TabBeginnU(ostream& output) { return output <<  "ÀÄ"; }

ostream& TabMitte  (ostream& output) { return output << " ³ "; }
ostream& TabMitteO (ostream& output) { return output << "ÄÂÄ"; }
ostream& TabMitteZ (ostream& output) { return output << "ÄÅÄ"; }
ostream& TabMitteU (ostream& output) { return output << "ÄÁÄ"; }

ostream& TabEnde (ostream& output) { return output << " ³" << "\r\n"; }
ostream& TabEndeO(ostream& output) { return output << "Ä¿" << "\r\n"; }
ostream& TabEndeZ(ostream& output) { return output << "Ä´" << "\r\n"; }
ostream& TabEndeU(ostream& output) { return output << "ÄÙ" << "\r\n"; }

// Implementation der Funktionen fuer Datumsverarbeitung
void SetzeDatum(Datum &aDatum,int tt,int mm,int jj) {
   // aDatum ist Referenzparameter, daher erfolgt kein indirekter Zugriff
   aDatum.Tag   = tt;
   aDatum.Monat = mm;
   aDatum.Jahr  = jj;
   return;
   }

char *DatumToString(Datum aDatum,char *ptr) {
   // ptr muss auf Texfeld mit mindestens 11 Zeichen verweisen
   ostrstream out(ptr,11);
   out << setfill('0') << setiosflags(ios::right) << setw(2) << aDatum.Tag
	   << setw(0) << '.'
	   << setfill('0') << setiosflags(ios::right) << setw(2) << aDatum.Monat
	   << setw(0) << '.'
	   << setfill(' ') << setiosflags(ios::left)  << setw(4) << aDatum.Jahr
	   << ends;
   return out.str();
   }


void StringToDatum(char *ptr,Datum &aDatum) {
   // ptr enthaelt String mit Datum
   istrstream in(ptr);
   char cmd;
   in >> setfill('0') >> dec >> setw(2) >> aDatum.Tag
	  >> setw(0) >> cmd
	  >> setfill('0') >> dec >> setw(2) >> aDatum.Monat
	  >> setw(0) >> cmd
	  >> setfill(' ') >> dec >> setw(4) >> aDatum.Jahr;
   return;
   }

// Funktionen fuer die Verarbeitung von Person
void FormatierePerson(Person &aPerson,istrstream &instr) {
   char Buffer[11];
   instr >> setw(13) >> aPerson.Name >> setw(13) >> aPerson.VorName
		 >> setw(11) >> Buffer >> setw(16) >> aPerson.Taetigkeit
		 >> setw(0) >> aPerson.Gehalt;
   StringToDatum(Buffer,aPerson.Beginn);
   return;
   }

int LesePerson(Person &aPerson,ifstream &Datei) {
   char Buffer[81];
   Datei.getline(Buffer,80);
   // ueberpruefen, ob Datei ok
   if(!Datei) {
	   if(Datei.bad()) cerr << "Fehler beim Lesen" << endl;
	   if(Datei.eof()) cerr << "Dateiende" << endl;
	   return 0;
	   }
   else {
	   istrstream in(Buffer,strlen(Buffer));
	   FormatierePerson(aPerson,in);
	   }
   return 1;
   }

void DruckePerson(Person &aPerson,Tabelle *aTab,ofstream &aDrucker) {
   char Buffer[11], *ptr;
   ptr=DatumToString(aPerson.Beginn,Buffer);
   aDrucker << TabBeginn;
   DruckFormatSpalte(&aTab[0],aDrucker);
   aDrucker << aPerson.Name	   << TabMitte;
   DruckFormatSpalte(&aTab[1],aDrucker);
   aDrucker << aPerson.VorName << TabMitte;
   DruckFormatSpalte(&aTab[2],aDrucker);
   aDrucker << ptr << TabMitte;
   DruckFormatSpalte(&aTab[3],aDrucker);
   aDrucker << aPerson.Taetigkeit << TabMitte;
   DruckFormatSpalte(&aTab[4],aDrucker);
   aDrucker << aPerson.Gehalt << TabEnde;
   return;
   }

void SetzeSpalte(Tabelle &aTabelle,const char *aName,char aTyp,
				 int aLaenge,int aNachKomma) {
   strncpy(aTabelle.Name,aName,10);
   aTabelle.Name[10]  ='\0';
   aTyp = aTyp & 223; // Kleinbuchstaben -> Groá
   if((aTyp=='N') || (aTyp=='Z')) aTabelle.Typ = 'N';
   else aTabelle.Typ = 'C';
   aTabelle.Laenge    = aLaenge;
   aTabelle.NachKomma = aNachKomma;
   return;
   }

void DruckerTitel(Tabelle &aTabelle,ofstream &Drucker) {
	register unsigned char l;
	if(strlen(aTabelle.Name) > aTabelle.Laenge)
		l = strlen(aTabelle.Name);
	else
		l = aTabelle.Laenge;
	Drucker << setw(l) << setiosflags(ios::left) << aTabelle.Name;
	// Dezimalpunkt zeigen bei Gleitkommadarstellung
	Drucker.setf(ios::fixed,ios::floatfield);
	return;
	}

void DruckerTabelle(Tabelle &aTabelle,ofstream &Drucker) {
	register unsigned char l;
	if(strlen(aTabelle.Name) > aTabelle.Laenge)
		l = strlen(aTabelle.Name);
	else
		l = aTabelle.Laenge;
	Drucker << setw(l) << setfill('Ä') << 'Ä' << setfill(' ');
	return;
	}

void DruckeLinie(Tabelle *aTabelle,int Anzahl,ofstream &ostr,int typ) {
   register unsigned int i=0;
   switch(typ) {
	  case 0: ostr << TabBeginn;  break;
	  case 1: ostr << TabBeginnO; break;
	  case 2: ostr << TabBeginnZ; break;
	  case 3: ostr << TabBeginnU; break;
	  }
   if(typ==0) DruckerTitel(aTabelle[i++],ostr);
   else       DruckerTabelle(aTabelle[i++],Drucker);
   while(i<Anzahl) {
	   switch(typ) {
		  case 0: ostr << TabMitte;
				  DruckerTitel(aTabelle[i++],ostr);
				  break;
		  case 1: ostr << TabMitteO;
				  DruckerTabelle(aTabelle[i++],ostr);
				  break;
		  case 2: ostr << TabMitteZ;
				  DruckerTabelle(aTabelle[i++],ostr);
				  break;
		  case 3: ostr << TabMitteU;
				  DruckerTabelle(aTabelle[i++],ostr);
				  break;
		  }
	   }
   switch(typ) {
	  case 0: ostr << TabEnde;  break;
	  case 1: ostr << TabEndeO; break;
	  case 2: ostr << TabEndeZ; break;
	  case 3: ostr << TabEndeU; break;
	  }
   return;
   }


void DruckFormatSpalte(Tabelle *aTabelle,ofstream &Drucker) {
	register unsigned char l;
	if(strlen(aTabelle->Name) > aTabelle->Laenge)
		l = strlen(aTabelle->Name);
	else
		l = aTabelle->Laenge;
	Drucker << setw(l);
	if(aTabelle->Typ=='C')
	   Drucker << setiosflags(ios::left);
	else {
	   Drucker << setiosflags(ios::right);
	   if(aTabelle->NachKomma>0)
		  Drucker << setiosflags(ios::showpoint)
				  << setprecision(aTabelle->NachKomma);
	   else
		  Drucker << setprecision(0);
	   }
	return;
	}

int main(void) {
   Person aPerson;
   Tabelle DrTab[5];
   int i=0;
   SetzeSpalte(DrTab[0],"Name",      'C', 12, 0);
   SetzeSpalte(DrTab[1],"Vorname",   'C', 12, 0);
   SetzeSpalte(DrTab[2],"Beginn",    'D', 10, 0);
   SetzeSpalte(DrTab[3],"Taetigkeit", 'C', 15, 0);
   SetzeSpalte(DrTab[4],"Gehalt",    'N',  9, 2);
   DatenDatei.open("personen.dat");
   if(!DatenDatei) {
		cerr << "Datendatei wurde nicht geoeffnet\n";
		return 1;
		}
   DruckeLinie(DrTab,5,Drucker,1);
   DruckeLinie(DrTab,5,Drucker,0);
   DruckeLinie(DrTab,5,Drucker,2);
   while(LesePerson(aPerson,DatenDatei)) {
	   DruckePerson(aPerson,DrTab,Drucker);
	   i++;
	   }
   DruckeLinie(DrTab,5,Drucker,3);
   cout << i << " Personen gedruckt" << endl;
   Drucker << '\f';
   return 0;
   }
