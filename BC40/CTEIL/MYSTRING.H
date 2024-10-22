/* Beispiel: Arbeiten mit nullterminierten Zeichenfolgen    */
/* Datei: mystring.h                                        */
/* eigene Implementierung der Standard- Stringfunktionen    */
/* Volker Hillmann: Objektorientiertes Programmieren in C++ */

#ifndef __MYSTRING_H
#define __MYSTRING_H

/* Kopieren einer Zeichenfolge in eine andere */
char *strcpy(char *Ziel, char *Quelle);

/* Anfügen einer Zeichenfolge an eine andere */
char *strcat(char *Ziel, char *Quelle);

/* Suchen eines Zeichens in einer Zeichenkette */
char* strchr(char *satz,const char chr);

/* Zwei Zeichenfolgen vergleichen */
int strcmp(char *str1, char *str2);

#endif