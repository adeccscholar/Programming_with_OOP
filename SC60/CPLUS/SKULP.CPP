// Der Gueltigkeits- Zugriffsoperator
#include <iostream.h>
#include <iomanip.h>

// Globale Vereinbarung von Index
int Index=0;

int MyFunction(void) {
	int Index;  // lokales Index
	// Wiederhole, bis lokales Index kleiner als globsles Index
	cout << "Ausgabe von " << ::Index << " Werten" << endl;
	for(Index=0;Index<::Index;Index++) 
		cout << setw(3) << (Index+1) << ". Index" << endl;
	return Index;
	}

int main(void) {
	int RetVal;
	cout << "Demonstration des Gueltigkeits- Zugriffsoperator\n";
	while((Index<1) || (Index>10)) {
	   cout << "Geben Sie einen Index ein (1...10): ";
	   cin >> Index;
       }
	RetVal=MyFunction();
	if(RetVal==Index) return 0;
	else return 1;
	}
