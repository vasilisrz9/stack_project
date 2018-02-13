
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "TStoixeioyStoivas.h"

/*orismos synarthsewn*/

TStoixeioyStoivas upologismos (char,TStoixeioyStoivas ,TStoixeioyStoivas);
int factor(int);     /* synarthsh gia tous paragontikous */
int einai_telestis (char);
void print_options(void);

int main(void)
{
	FILE *fop;
	int sfalma;
	TStoivas stoiva; /*stoiva twn orwn*/
	TStoixeioyStoivas oros1,oros2,apotelesma;
	char metathematiki[256];
	int i,symbolo,t,o,option,created;
	sfalma=created=0;
	
	do
	{
		print_options();
		scanf("%d", &option);
		switch(option)
		{case 1:
			Stoiva_dimiourgia(&stoiva);
			created=1;
			printf("\nH stoiva dhmiourghthike!\n");
			break;
		case 2:
	
	if ((fop=fopen("input.txt","r")) == NULL) /* Open text file */
	{
		printf("Problem with the text file\n");
	}
		 if(!created)
		 {
				printf("\nDen uparxei stoiva gia na eisaxthoun stoixeia!\n");
				break;
		 }
	
	do
	{
		metathematiki[0]='\0';
		i=0;
		t=0;
		o=0;
		
		while ( (symbolo = fgetc(fop))!= '\n') /* diavazei tis metathematikes parastaseis */
		{
			metathematiki[i]=symbolo;
			i++;
			if (symbolo >= '0' && symbolo <= '9') /*bre8hke oros*/
			{
				o++;    /* afkhsh tou metrhth orwn kata 1 */
				TSstoiva_setValue(&apotelesma, (float)(symbolo-'0'));
				Stoiva_othisi(&stoiva,apotelesma,&sfalma);
				if(sfalma){
					printf("\nYperxeilhsh stoivas");
				}
			}
			else  if ( einai_telestis(symbolo) ) /*bre8hke telesths*/
			{
				t++; /* afkhsh tou metrhth telestwn kata 1 */
				if (symbolo == '!')   /* ean einai paragontikos */
				{
					t--;; /* meiwsh tou metrhth telestwn kata 1 */
					Stoiva_PopValue(stoiva,&oros1,&sfalma);
					Stoiva_PopState(&stoiva,&sfalma);
					TSstoiva_setValue(&apotelesma,factor((int)oros1));
					Stoiva_othisi(&stoiva,apotelesma,&sfalma);
					if(sfalma){
                        printf("\nYperxeilhsh stoivas");
				    }
				}
				else /* den einai paragontikos */
				{
                    Stoiva_PopValue(stoiva,&oros2,&sfalma);
					Stoiva_PopState(&stoiva,&sfalma);
					Stoiva_PopValue(stoiva,&oros1,&sfalma);
					Stoiva_PopState(&stoiva,&sfalma);
				/* Stoiva_exagogi(&stoiva,&oros1,&sfalma);
				   Stoiva_exagogi(&stoiva,&oros2,&sfalma); */
				   TSstoiva_setValue(&apotelesma, upologismos(symbolo,oros1,oros2));
				   Stoiva_othisi(&stoiva,apotelesma,&sfalma);
				   if(sfalma){
                        printf("\nYperxeilhsh stoivas");
				   }
			    }
			}
        }
		metathematiki[i]='\0';
		Stoiva_PopValue(stoiva,&apotelesma,&sfalma);
		Stoiva_PopState(&stoiva,&sfalma);
	 /* Stoiva_exagogi(&stoiva,&apotelesma,&sfalma); */
	 
		if ((t>=o ) || t<o-1)   /* Ean yparxei lathos. Elegxos gia thn orthothta
		                 tis metathematikhs parastashs */
		{
		   printf("%s=", metathematiki);
		   printf("error\n");
		}
		else /* Ean einai orth */
		{
           printf("%s=", metathematiki);
		   fprintf(stdout, "%d\n",(int) apotelesma); /* Ektyposh tou apotelesmatos
														ths metathematikhs parastashs */
		}
		if(sfalma){
            printf("\nYperxeilhsh stoivas. Ta stoixeia DEN eishx8hsan!\n");
		    }
   }
   while((symbolo=fgetc(fop)) !=EOF && ungetc(symbolo,fop));
   fclose(fop);
   break;
   
	  case 3:
			if(!created)
			{
				printf("\nDen uparxei stoiva  gia na elexthei an einai kenh!\n");
				break;
			}
			if(Stoiva_keni(stoiva))
               printf("\nH stoiva einai kenh!\n");
            else
	           printf("\nH stoiva DEN einai kenh!\n");
            break;

      case 4:
            if(!created)
             {
				printf("\nDen uparxei stoiva  gia na eksaxthoun stoixeia!\n");
                break;
              }
            Stoiva_PopValue(stoiva,&apotelesma,&sfalma);
		    Stoiva_PopState(&stoiva,&sfalma);
	     /* Stoiva_exagogi(&stoiva,&apotelesma,&sfalma); */
            if(sfalma)
               printf("\nKeni stoiva!\n");
            else
             {
					 printf("\nEkshx8hsan merika apo ta stoixeia, synexiste gia na adeiasei");
             }
            break;
  }
}while(option);
 return 0;
}

TStoixeioyStoivas upologismos (char symbolo, TStoixeioyStoivas oros1, TStoixeioyStoivas oros2)
{
    TStoixeioyStoivas apotelesma = 0;
	switch (symbolo)
	{
	case '+' :	TSstoiva_setValue(&apotelesma,oros1 + oros2);
				break;
	case '-' :	TSstoiva_setValue(&apotelesma, oros1 - oros2);
				break;
	case '*' :	TSstoiva_setValue(&apotelesma, oros1 * oros2);
				break;
	case '/' :	TSstoiva_setValue(&apotelesma, oros1 / oros2);
				break;
	case '%' :  TSstoiva_setValue(&apotelesma, oros1 % oros2);
				break;
	case '!' :  TSstoiva_setValue(&apotelesma, factor(oros1));
				break;
	default :	printf("%c: mh egkyros telesths!\n", symbolo);
				break;
	}

	return apotelesma;
}

int factor(int p)  /* synarthsh ypologismou paragontikou */
{
	int i,s=1;
	for (i=1; i<=p; i++)
	{
		s=s*i;
	}
	return s;
}


int einai_telestis (char c)
{
	return c == '+' || c == '-'
		|| c == '*' || c == '/' || c == '%' || c == '!';
}

void print_options(void)
{   printf("\n\n1. Dhmioyrgia stoivas\n\
2. Na ginoun oi prakseis\n\
3. Elegxos kenhs stoivas\n\
4. Eksagwgh stoixeiou apo th stoiva\n\
Dwste thn epilogh sas(1-4, 0 gia eksodo):");
}
