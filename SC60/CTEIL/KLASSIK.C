#include <stdio.h>

	float Flaeche( laenge, breite)
		float laenge, breite;
	{
		return(laenge * breite);
	}

	main()
	{
		float a=5.0;
		float b=6.0;
		char cmd;
		printf("Die Flaeche von %3.1f * %3.1f = %4.1f\n",a,b,Flaeche(a,b));
		printf("Druecken Sie <Enter>");
		scanf("%c",&cmd);
		return(0);
	}