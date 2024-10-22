// Definition der Klassen: Baum und BaumKnoten
// Volker Hillmann
// Objektorientierte Programmierung mit C++
// Compiler: Borland C++ 3.1, 4.0, Symantec C++ 6.0, Visual C++ 1.0


#ifndef __BAUM_HPP
#define __BAUM_HPP

#ifndef NULL
  #include <_null.h>
#endif

class BaumKnoten {
	friend class Baum;
	private:
		BaumKnoten *Links;
		BaumKnoten *Rechts;
	public:
		BaumKnoten(void) { Links = NULL; Rechts = NULL; };
		virtual ~BaumKnoten(void) { };
		virtual int operator < (BaumKnoten&) = 0;
		virtual int operator > (BaumKnoten&) = 0;
		virtual void Gleichheit(BaumKnoten*) = 0;
		virtual void Verarbeite(void) = 0;
	};


class Baum {
	private:
		BaumKnoten *Wurzel;
		int near Einfuegen(BaumKnoten*, BaumKnoten*&);
		int near Entfernen(BaumKnoten*, BaumKnoten*&);
		int near Durchlaufe(BaumKnoten*);
		void near Loesche(BaumKnoten*&);
	public:
		Baum(void) { Wurzel = NULL; };
		~Baum(void);
		int Einfuegen(BaumKnoten*);
		int Entfernen(BaumKnoten*);
		int Durchlaufe(void);
		BaumKnoten* Suche(BaumKnoten*);
		void Loesche(void);
	};

#endif