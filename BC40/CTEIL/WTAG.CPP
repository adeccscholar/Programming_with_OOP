/* Beispielsprogramm zur Anwendung von Aufz�hlungstypen */
#include <stdio.h>

enum Wochentag {	Montag, Dienstag, Mittwoch,
							Donnerstag, Freitag, Sonnabend, Sonntag };

void main(void) {
	enum Wochentag  Lauf;
	for(Lauf=Montag;Lauf<=Sonntag;Lauf+=1)
		if((Lauf==Sonntag) || (Lauf==Sonnabend))
			printf("Heute ist ein freier Tag, Sie sollten sich ausruhen!\n");
		else
			printf("Heute gehen Sie arbeiten, viel Spa�.\n");
	return;
	}
