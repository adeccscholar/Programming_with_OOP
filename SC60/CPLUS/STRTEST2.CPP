 // Streamtest 2. Versuch
// Ausgabe mit Manipulatoren

#include <iostream.h>
#include <iomanip.h>

float Wert[7]	= { 	102.3, 123.15, 99.991, 105.1, 145.45, 123.55, 10.1 };
char *Tage[7]	= { 	"Montag", "Dienstag", "Mittwoch", "Donnerstag",
							"Freitag", "Sonnabend", "Sonntag" };

// Manipulator, um Abstand einzufügen
ostream& di(ostream& output) {
	return output << " - ";
	}

ostream& right(ostream& output) {
	output.setf(ios::right, ios::adjustfield);
	return output;
	}

ostream& left(ostream& output) {
	output.setf(ios::left, ios::adjustfield);
	return output;
	}

int main(void) {
	int i;
	cout << "Ausgaben mit cout und den Manipulatoren" << endl;
	cout.setf(ios::fixed,ios::floatfield);
	cout.setf(ios::showpoint, ios::adjustfield);
	for(i=0;i<7;i++) {
		cout	<< right << setw(4) << (i+1);
		cout	<< di << left  << setw(10) << Tage[i];
		cout	<< di << right << setw(8) << setprecision(2)
				<< Wert[i] << endl;
		}
	return 0;
	}