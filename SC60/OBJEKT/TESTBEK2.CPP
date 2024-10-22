#include <iostream.h>
#include "bekannt.hpp"
#include "bekannt2.hpp"

int main(void) {
    Bekannter bek1;
	Bekannter_2 bek2;

	bek1.Name("Meier");
	bek1.VorName("Ingrid");
	bek1.Anschrift.Ort("Guestrow");
	bek1.Anschrift.PLZ("18273");
	bek1.Anschrift.Strasse("Hafengasse 5");
	bek1.Geburtstag.Tag(6);
	bek1.Geburtstag.Monat(4);
	bek1.Geburtstag.Jahr(1968);

	bek2.Name("Meier");
	bek2.VorName("Ingrid");
	bek2.Ort("Guestrow");
	bek2.Strasse("Hafengasse 5");
	bek2.PLZ("18273");
	bek2.Tag(6);
	bek2.Monat(4);
	bek2.Jahr(1968);

	cout << bek1 << endl;
	cout << bek2 << endl;

	return 0;
    }