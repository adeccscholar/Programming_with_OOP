// Demoprogramm: Daten einlesen und ausgeben
#include <iostream.h>

// allgemeines Datenobjekt als Basis fuer spezielle Datenklassen
class ClDObject {
	public:
	  virtual int Input(void) { return 0; };
	  virtual int Display(void) {return 0; };
	};

// Klasse fuer Strings mit variabler Laenge
class ClVarString : public ClDObject {
	private:
	  char *aString;
	  unsigned int lenght;
	public:
	  ClVarString(void);
	  ~ClVarString(void);
	  virtual int Input(void);
	  virtual int Display(void);
	};

// Klasse, um Datum zu speichern
class ClDate : public ClDObject {
	private:
	  unsigned int day;
	  unsigned int month;
	  unsigned int year;
	public:
	  ClDate(void);
	  ~ClDate(void);
	  virtual int Input(void);
	  virtual int Display(void);
	};

// Implementierung der Klasse ClVarString
ClVarString::ClVarString(void) {
	aString=0;
	lenght=0;
	};

ClVarString::~ClVarString(void) {
	if(lenght!=0) delete [] aString;
	};

int ClVarString::Input(void) {
	char TmpString[256];
	char *pt;
	char i;
	cout << "Geben Sie bitte einen Satz ein: ";
	//cin.getline(TmpString,256,'\n');
	cin >> TmpString;
	pt=TmpString;
	lenght=0;
	while(*pt++!='\0') lenght++;
	aString = new char[lenght+1];
	if(aString==0) lenght=0;
	else for(i=0;i<=lenght;i++) aString[i]=TmpString[i];
	return lenght;
	}

int ClVarString::Display(void) {
	cout << "VarString: " << aString << endl;
	return lenght;
	}

// Implementierung der Klasse ClDate
ClDate::ClDate(void) {
   day=month=1;
   year=1980;
   }

ClDate::~ClDate(void) { };

int ClDate::Input(void) {
	char P;
	cout << "Datum (dd.mm.yyyy) eingeben: ";
	cin >> day >> P >> month >> P >> year;
	return 1;
	}

int ClDate::Display(void) {
	cout << "Date:      " << day << '.' << month << '.' << year << endl;
	return 1;
	}

int main(void) {
	ClDate *ob2;
	ClVarString *ob1;
	ob1= new ClVarString;
	ob1->Input();
	ob1->Display();
	delete ob1;
	ob2 = new ClDate;
	ob2->Input();
	ob2->Display();
	delete ob2;
	return 0;
	}
