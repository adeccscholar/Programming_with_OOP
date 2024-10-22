/* Beispiel: Arbeiten mit nullterminierten Zeichenfolgen    */
/* Datei: string1.cpp                                          */
/* eigene Implementierung der Standard- Stringfunktionen    */
/* Volker Hillmann: Objektorientiertes Programmieren in C++ */

#include <stdio.h>		/* Für NULL */


/* Kopieren des Inhalts einer Zeichenkette in eine andere Zeichenkette */

char *strcpy(char *Ziel, char *Quelle) {
   char *ptc1, *ptc2;
   for(ptc1=Ziel, ptc2=Quelle;*ptc2!='\0';ptc1++,ptc2++)
	   *ptc1 = *ptc2;
   *ptc1 = '\0';	/* abschließende 0 an Ziel anhängen */
   return(Ziel);
   }


/* Anhängen des Inhalts einer Zeichenkette an eine andere Zeichenkette */

char *strcat(char *Ziel, char *Quelle) {
   char *ptc1, *ptc2;
   /* Suche Ende der Zeichenkette in Ziel */
   for(ptc1=Ziel;*ptc1!='\0';ptc1++); /* leere Anweisung, mache nichts! */
   /* Anhängen, möglich wäre auch Aufruf: strcpy(pt1, Quelle); */
   for(ptc2=Quelle;*ptc2!='\0';ptc1++,ptc2++)
	   *ptc1 = *ptc2;
   *ptc1 = '\0';	/* abschließende 0 an Ziel anhängen */
   return(Ziel);
   }


/* Suchen eines Zeichens in einer Zeichenfolge */

char* strchr(char *satz,const char chr) {
   char *ptc;
   /* Durchlaufe Zeichenfolge, bis Endemarkierung gefunden */
   for(ptc=satz;*ptc!='\0';ptc+=1)
	   if(*ptc==chr) return(ptc);		/* Zeichen chr gefunden, Rückspung */
   return(NULL);								/* Zeichen nicht gefunden, Rückgabe 0 */
   }


/* Vergleich von zwei Strings */

int strcmp(char *str1, char *str2) {
   char *pt1, *pt2;
   for(pt1=str1,pt2=str2;(*pt1!='\0')&&(*pt2!='\0');pt1++,pt2++) {
	   if(*pt1 == *pt2) continue;	/* Bei Gleichheit Schleife fortsetzen */
	   if(*pt1 < *pt2)
	   		return(-1);
	   else return(1);
	   }
   if(*pt1 == *pt2)
   		return(0);		/* Zeichenfolgen sind gleich */
   if(*pt1 == '\0')
   		return(-1);
   else
   		return(1);
   }