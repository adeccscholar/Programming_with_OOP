// Implementierung der Klassen: Baum und BaumKnoten
// Volker Hillmann
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

#include "baum.hpp"

int near Baum::Einfuegen(BaumKnoten* knoten, BaumKnoten*& wurzel) {
	if(knoten == NULL)
		return 0;
	if(wurzel == NULL)
		wurzel = knoten;
	else if (*knoten < *wurzel) 
		 	Einfuegen(knoten, wurzel->Links);
		 else if(*knoten > *wurzel)
			  	Einfuegen(knoten, wurzel->Rechts);
			  else {
				wurzel->Gleichheit(knoten);
				return 2;
				}
	return 1;
	}

int near Baum::Entfernen(BaumKnoten *knoten, BaumKnoten*& wurzel) {
	if(knoten == NULL) 
		return 0;
	if(wurzel == NULL)
		return 0;
	else if(*knoten < *wurzel)
		 	return Entfernen(knoten, wurzel->Links);
		 else if(*knoten > *wurzel)
			  	return Entfernen(knoten, wurzel->Rechts);
			  else {
			  	BaumKnoten *temp = wurzel;
				if(wurzel->Links == NULL)
					wurzel = wurzel->Rechts;
				else if(wurzel->Rechts == NULL)
					 	wurzel = wurzel->Links;
					 else {
                     	BaumKnoten *temp2;
						for( temp2 = wurzel->Links;
							 temp2->Rechts != NULL;
							 temp2 = temp2->Rechts );
						temp2->Rechts = wurzel->Rechts;
						wurzel = wurzel->Links;
						}
				delete temp;
				return 1;
				}
		}

int near Baum::Durchlaufe(BaumKnoten *knoten) {
	register int Zaehler = 0;
	if(knoten == NULL) 
		return 0;
	Zaehler += Durchlaufe(knoten->Links);
	knoten->Verarbeite();
	Zaehler += 1;
	Zaehler += Durchlaufe(knoten->Rechts);
	return Zaehler;
	}
		
void near Baum::Loesche(BaumKnoten*& knoten) {
	if(knoten == NULL) 
		return;
	if(knoten->Links != NULL)
		Loesche(knoten->Links);
	if(knoten->Rechts != NULL)
		Loesche(knoten->Rechts);
	delete knoten;
	knoten = NULL;
	return;
	}

// die oeffentliche Methoden von Baum

Baum::~Baum(void) {
	if(Wurzel != NULL)
	Loesche(Wurzel);
	}

int Baum::Einfuegen(BaumKnoten* knoten) { 
	return Einfuegen(knoten, Wurzel);
	}

int Baum::Entfernen(BaumKnoten* knoten) {
	return Entfernen(knoten, Wurzel);
	}
	
int Baum::Durchlaufe(void) {
	return Durchlaufe(Wurzel);
	}

BaumKnoten* Baum::Suche(BaumKnoten* knoten) {
	BaumKnoten *temp = Wurzel;
	while(temp != NULL) {
		if((*knoten) < (*temp))
			temp = temp->Links;
		else if((*knoten) > (*temp))
			 	temp = temp->Rechts;
		     else						// GEFUNDEN
			 	break;
		}
	return temp;
	}

void Baum::Loesche(void) {
	if(Wurzel == NULL) 
		return;
	Loesche(Wurzel);
	return;
	}