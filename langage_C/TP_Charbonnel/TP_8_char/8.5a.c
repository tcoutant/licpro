#include <stdio.h>
#include "8.5.h"

struct contact liste[] =
{
  { { "Dupont", "" }, fr, { .fraddr={10, "bd Lavoisier", 49000, "Angers"}} },
  { { "Wilson", "" }, uk, { .ukaddr={2, "Wall Street", "Oxford", "Oxfordshire", "04010"}} },
  { { "Carter", "" }, us, { .usaddr={1123, "New Montgomery St.", "East", "San Francisco", "Californie", "94105" }}}
} ;


int main()
{
        FILE *out ;

        out = fopen("myfile","w") ;
        if (out==NULL) { perror("myfile") ; return 1 ; }
        fwrite(liste,sizeof(struct contact),3,out) ;
        fclose(out) ;

        return 0 ;
}

