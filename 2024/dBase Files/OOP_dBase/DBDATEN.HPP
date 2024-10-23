// Methoden für Arbeit mit Datum 
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0

// Originale Quellen von 1994 (pre Standard)
// Überarbeitung für den Stream, minimale notwendige Anpassungen 
// für aktuelle Compiler, hier Visual Studio 2022
// Volker Hillmann, 24.10.2024
// MIT License


#ifndef __DBDATEN_HPP
#define __DBDATEN_HPP

#include <iostream>      // !2024! Anpassung für modernes C++, Wegfall von .h für Standardheader

#include "dbheader.hpp"

#include "dbobjekt.hpp"
#include "dbdatum.hpp"
#include "dbstring.hpp"
#include "dblogic.hpp"
#include "dbzahl.hpp"

#include "mystring.hpp"

using namespace std;  // !2024! Anpassung für modernes C++, provisorisches Öffnen der Namesräume

DBObjekt *ErzeugeDBDaten(DBFile *dbf,char *Name);
void Display(DBFile *dbf, ostream& out = cout, int para = 0);
void Display(DBFile *dbf, char *Wunsch, ostream& out = cout, int para = 0);

#endif
