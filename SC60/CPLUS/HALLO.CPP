// Mein erstes objektorientiertes Programm
// Neue Ausgaben in C++
#include <iostream.h>

// Klassenbeschreibung
class TApplication {
	private:
		char Text[36];
	int Status;
	public:
		TApplication(void) {
			char Satz[]="Hallo, jetzt geht es los!";
			char *pt;
			int i;
			for(i=0,pt=Satz;*pt!='\0';i++,pt++) Text[i]=*pt;
			Text[i]='\0';
			Status=i;
			};

		void Print(void) {
			cout << Text << endl;
			cout << (Status-1) << " Buchstaben geschrieben" << endl;
			return;
			};

		int GetStatus(void) {
			return Status;
			};
		};

int main(void) {
	// Eine Instanz bilden, Konstruktor wird aufgerufen
	TApplication MyApplication;
	// Botschaft an Instanz senden
	MyApplication.Print();
	return MyApplication.GetStatus();
	}