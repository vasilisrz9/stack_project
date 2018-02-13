


#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


/*orismos synarthsewn*/

void Stoiva_dimiourgia(TStoivas *stoiva)
{/*	Pro: 		Kamia
  *	Meta: 		Dhmioyrgia kenhs stoivas */
	stoiva->korifi = -1;
}


int  Stoiva_keni(TStoivas stoiva)
{/*	Pro: 	    Dhmioyrgia ths stoiva
 *	Meta: 		Epistrefei 1 an h stoiva einai kenh alliws 0 */
	return (stoiva.korifi == -1);
}


/* void Stoiva_exagogi(TStoivas *stoiva,TStoixeioyStoivas *stoixeio,int *ypoxeilisi)
{	Pro: 		Mh kenh stoiva
  	Meta: 		Eksagetai to stoixeio apo th stoiva 
	if (Stoiva_keni(*stoiva))
	 	*ypoxeilisi = 1; 
	else
	{   *ypoxeilisi = 0;
		TSstoiva_setValue(stoixeio, stoiva->pinakas[stoiva->korifi]);
		stoiva->korifi--;
	}
}
ALLAGH ME TIS PopValue KAI PopState
*/

void Stoiva_PopValue(TStoivas stoiva, TStoixeioyStoivas *stoixeio, int *ypoxeilisi)
{
	/* Pro: Mh kenh stoiva
	 Meta: Exoume th timh ths korifis sto stoixeio, xoris na allazei kati */
	 
	if (Stoiva_keni(stoiva))
	   *ypoxeilisi = 1;
	 else
	   {
			*ypoxeilisi = 0;
			TSstoiva_setValue(stoixeio, stoiva.pinakas[stoiva.korifi]);
		}
}

void Stoiva_PopState(TStoivas *stoiva,int *ypoxeilisi)
{
	/* Pro: Mh kenh stoiva
	   Meta: Meiwthike h korifi kata 1 */
	   
	 if (Stoiva_keni(*stoiva))
		 *ypoxeilisi = 1;
		else
		{
			*ypoxeilisi = 0;
			stoiva->korifi--;
		}
}


void Stoiva_othisi(TStoivas *stoiva,TStoixeioyStoivas stoixeio,int *yperxeilisi)
{/*	Pro: 		Dhmioyrgia ths stoiva
  *	Meta: 		Wtheitai to stoixeio sth stoiva */  
	if (stoiva->korifi == PLITHOS -1)
    	*yperxeilisi = 1;
	else
	{   *yperxeilisi = 0;
		stoiva->korifi++;
		TSstoiva_setValue(&(stoiva->pinakas[stoiva->korifi]), stoixeio);
	}
}

