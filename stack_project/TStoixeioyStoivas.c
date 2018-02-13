

#include "TStoixeioyStoivas.h"



void TSstoiva_setValue (TStoixeioyStoivas *target, TStoixeioyStoivas source)
{

	*target=source;

}


/* int TSstoiva_readValue (FILE *from, TStoixeioyStoivas * Elem)
{   int fd;
     fd=fscanf(from, "%5.2f", Elem);
     return fd;
}

int TSstoiva_writeValue (FILE *to, TStoixeioyStoivas  Elem)
{   int fd;
	fd=fprintf(to, "%5.2f",Elem);
	return fd;
}
*/
