/* Verschiedene Sichten auf Daten ueber Varianten */
#include <stdio.h>
#include <dos.h>

#if defined _WINDOWS
	#error keine Windows- Anwendung
#endif

/* Farben fuer die Textdarstellung unter MS- DOS */
enum Color {
		BLACK,          /* Dunkle Farben (Vordergrund und Hintergrund) */
		BLUE,
		GREEN,
		CYAN,
		RED,
		MAGENTA,
		BROWN,
		LIGHTGRAY,
		DARKGRAY,       /* Helle Farben, nur Vordergrund! */
		LIGHTBLUE,
		LIGHTGREEN,
		LIGHTCYAN,
		LIGHTRED,
		LIGHTMAGENTA,
		YELLOW,
		WHITE
	};

struct ByteStruct {
	unsigned char Lo;
	unsigned char Hi;
	};

union Bildzeichen {
	unsigned int word;
	struct ByteStruct byte;
	};

union Bildzeichen aScreenChar;

/* Bildschirmadresse für VGA- und EGA- Textbildschirme  (normalerweise) */

unsigned int far *screen=(unsigned int far *)MK_FP(0xB800,0x0);

unsigned char Text[]= "Eine Ausgabe direkt in den Bildschirmspeicher";


void main(void) {
	int i;
	/* Farbe für Ausgabe festlegen (weiße Schrift auf blauem Grund ) */
	aScreenChar.byte.Hi=(BLUE<<4)|WHITE;
	i=0;
	while(Text[i]!='\0') {
		aScreenChar.byte.Lo=Text[i];
		screen[i]=aScreenChar.word;
		 i+=1;
		 }
	return;
	}
