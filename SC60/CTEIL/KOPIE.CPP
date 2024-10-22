/* Auswerten der Befehlszeilenparameter */
#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[]) {
	char name[9],*pt,ch;
	FILE *in,*out;
	pt=strrchr(argv[0],'\\');	/* Suche letztes Zeichen \ im Programmnamen */
	strcpy(name,pt,8);				/* Kopiere Programmnamen in Variable name */
	name[8]='\0';
	pt=strchr(name,'.');	/* Suche erstes Zeichen . */
	if(pt!=NULL) *pt='\0';
	if(argc!=3) {
		printf("Aufruf des Programms: %s Quelle Ziel\n",name);
		return(1);
		};
	in=fopen(argv[1],"r");	/* Datei zum Lesen öffnen */
	if(in==NULL) {
		printf("Quelle %s kann nicht geöffnet werden!\n",argv[1]);
		return(2);
		}
	else printf("Quelldatei %s ist geöffnet!\n",argv[1]);
	out=fopen(argv[2],"w");
	if(out==NULL) {
		printf("Ziel %s kann nicht geöffnet werden\n",argv[2]);
		fclose(in);
		return(3);
		}
	else printf("Zieldatei %s ist geöffnet\n",argv[2]);
	for(;;) {							/* eine Endlosschleife */
		ch=fgetc(in);					/* einlesen eines Zeichens aus in */
		if(feof(in)==0) break;	/* Dateiende, Schleife abbrechen */
		else fputc(ch, out);		/* schreiben eines Zeichens nach out */
		};
	fclose(in);
	fclose(out);
	return(0);
	}
