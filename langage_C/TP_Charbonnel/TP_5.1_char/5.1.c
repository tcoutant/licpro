# include <stdio.h>
# include <string.h>
# define const 10 		/*declaration des constantes*/

/*p*/
void main()
{
char s1[10], s2[10], x[10];
/* saisie des 2 chaines de caracteres s1 et s2*/
printf("donnner la 1ere chaine : \n");
scanf("%9s",s1);
printf("donnner la 2eme chaine : \n");
scanf("%9s",s2);

int i;

/*commentaire*/
if (strcmp(s1,s2)>0)
{
strcpy(x,s1);
strcpy(s1,s2);
strcpy(s2,x);
}

/*programme principal*/
printf("%s",s1);
printf("\t");

printf("%s",s2);
printf("\n");
			
}