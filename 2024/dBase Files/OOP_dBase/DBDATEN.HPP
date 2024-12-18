// Methoden f�r Arbeit mit Datum 
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

// Originale Quellen von 1994 (pre Standard)
// �berarbeitung f�r den Stream, minimale notwendige Anpassungen 
// f�r aktuelle Compiler, hier Visual Studio 2022
// Volker Hillmann, 24.10.2024
// MIT License


#ifndef __DBDATEN_HPP
#define __DBDATEN_HPP

#include <iostream>      // !2024! Anpassung f�r modernes C++, Wegfall von .h f�r Standardheader

#include "dbheader.hpp"

#include "dbobjekt.hpp"
#include "dbdatum.hpp"
#include "dbstring.hpp"
#include "dblogic.hpp"
#include "dbzahl.hpp"

#include "mystring.hpp"

using namespace std;  // !2024! Anpassung f�r modernes C++, provisorisches �ffnen der Namesr�ume

DBObjekt *ErzeugeDBDaten(DBFile *dbf,char *Name);
void Display(DBFile *dbf, ostream& out = cout, int para = 0);
void Display(DBFile *dbf, char *Wunsch, ostream& out = cout, int para = 0);

#endif
