// Methoden für Arbeit mit Datum 
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0


#ifndef __DBDATEN_HPP
#define __DBDATEN_HPP

#include <iostream.h>

#include "dbheader.hpp"

#include "dbobjekt.hpp"
#include "dbdatum.hpp"
#include "dbstring.hpp"
#include "dblogic.hpp"
#include "dbzahl.hpp"

#include "mystring.hpp"

DBObjekt *ErzeugeDBDaten(DBFile *dbf,char *Name);
void Display(DBFile *dbf, ostream& out = cout, int para = 0);
void Display(DBFile *dbf, char *Wunsch, ostream& out = cout, int para = 0);

#endif
