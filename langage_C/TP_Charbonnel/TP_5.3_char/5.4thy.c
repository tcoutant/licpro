# include <stdio.h>
# include <string.h>
# define const 10 		/*declaration des constantes*/


void tri(char t[])
{
	int N=strlen(t);
	int i,permut ;
	char x ;

	do {
	  permut = 0 ;
	  for (i=0 ; i<N-1 ; i++)
	    if (t[i]>t[i+1])
	    {
	      x = t[i] ;
	      t[i] = t[i+1] ;
	      t[i+1] = x ;
	      permut = 1 ;
	    }
	} while (permut==1) ;
}

int identique(char T1[],char T2[])
{
int i;
int N=strlen(T1);
int test=1;
do
	{
	test=1;
	if(T1[i]!=T2[i]) test=0;
	i++;
	}
while (i<N && test==1);
 return test;
}

/*programme principal*/
int main()
{
char s1[const], s2[const];
/* saisie des 2 chaines de caracteres s1 et s2*/
printf("donnner la 1ere chaine : \n");
scanf("%9s",s1);
printf("donnner la 2eme chaine : \n");
scanf("%9s",s2);
tri(s1);
tri(s2);
if (identique(s1,s2)==1)
printf("Ce sont des anagrammes. \n");
else
printf("Ce ne sont pas des anagrammes. \n");
return 0;
}
