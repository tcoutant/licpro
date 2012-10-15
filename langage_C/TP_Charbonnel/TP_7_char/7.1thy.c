# include <stdio.h>
# include <stdlib.h>
#include <readline/readline.h>
# define N 40

void tri(char ** tab, int n)
{
  int i;
  int ordre = 0;
  int taille = n;
  char tmp[N];
  while(ordre==0)
    {
      ordre = 1;
      for( i=0 ; i < taille-1 ; i++)
        {
	  if(strcmp(tab[i],tab[i+1])>0)
            {
	      strcpy(tmp,tab[i]);
	      strcpy(tab[i],tab[i+1]);
	      strcpy(tab[i+1],tmp);
	      ordre = 0;
            }
        }
    	taille--;
    }
}

int main()
{
int i,n;
char**tab;
char buffer[N];

printf("combien y a t'il de chaines de caracteres à trier ? ");
scanf("%d", &n);
tab = malloc(n*sizeof(char));
if (tab==NULL) {perror("malloc") ; exit;}
for (i=0; i<n;i++)
	{
	printf ("rentrer la %dème chaine de caractere : ",i+1);
	scanf("%39s",buffer);
	tab[i]=malloc((strlen(buffer)+1)*sizeof(char));
		if (tab[i]==NULL){perror("malloc") ; exit(1);}
	strcpy(tab[i],buffer);
	}
tri (tab,n);
for(i=0;i<n;i++)
{
printf("%s \n",tab[i]);
}
for(i=0;i<n;i++) free(tab[i]);
free (tab);

return 0;
}


