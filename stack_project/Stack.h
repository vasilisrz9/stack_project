

#ifndef __STACK__ 
#define __STACK__

#define PLITHOS 100 /*megisto epitrepto plh8os stoixeiwn ana stoiva*/
#include "TStoixeioyStoivas.h"


/*dhlwseis typwn*/

typedef struct 
{   int korifi;        /*8esh toy prwtoy stoixeioy ths stoivas*/
	TStoixeioyStoivas pinakas[PLITHOS];  /* pinakas  stoixeiwn*/
} TStoivas;


/*dhlwseis synarthsewn*/


void Stoiva_dimiourgia(TStoivas *stoiva);
int  Stoiva_keni(TStoivas stoiva);
/* void Stoiva_exagogi(TStoivas *stoiva,TStoixeioyStoivas *stoixeio,int *ypoxeilisi);
antikatastash me */
void Stoiva_PopValue(TStoivas stoiva, TStoixeioyStoivas *stoixeio,int *ypoxeilisi);
void Stoiva_PopState(TStoivas *stoiva,int *ypoxeilisi);
void Stoiva_othisi(TStoivas *stoiva,TStoixeioyStoivas stoixeio,int *yperxeilisi);


#endif /*#ifndef __STACK__ */
