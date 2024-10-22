// Beispielprogramm: Definition einer Klasse, bilden von Instanzen
//                   und Zugriff auf die Methoden
// Volker Hillmann, Objektorientierte Programmierung in C++

#include <iostream.h>
#include <iomanip.h>

// Definitionder Klasse Punkt	

class Punkt {
		int x, y;	// Datenelemente
	public:	// Dieses Schlüsselwort steuert die Sichtbarkeit
		int GetX(void) { return x; };
		int GetY(void) { return y; };
		int SetX(int ax);
		int SetY(int ay);
	};

// Implementierung der Methodender Klasse Punkt

int Punkt::SetX(int ax) {
	int temp = x;
	x = ax;
	return temp;
	}

int Punkt::SetY(int ay) {
	int temp = y;
	y = ay;
	return temp;
	}

ostream& operator << (ostream& out,Punkt& aPkt) {
	return out << "X = " << setw(5) << aPkt.GetX() << "  "
			   << "Y = " << setw(5) << aPkt.GetY();
	}

int main(void) {
	Punkt aPunkt1,					// Variable vom Typ Punkt
		  *aPtPunkt;				// Zeiger auf Punkt
	aPunkt1.SetX(5);				// Zugriff auf Variablen vm Typ Punkt
	aPunkt1.SetY(7);
	aPtPunkt = new Punkt;			// dynamischen Speicherplatz anfordern
	aPtPunkt->SetX(10);				// Zugriff ueber Zeigervariable auf Punkt
	aPtPunkt->SetY(15);
	cout << endl << "Beispielprogramm: "
	     << "Definition und Einsatz einer ersten Klasse" << endl << endl;
	cout << " Punkt 1: " << aPunkt1 << endl;
	cout << " Punkt 2: " << *aPtPunkt << endl;
	delete aPtPunkt;
	return 0;
	}