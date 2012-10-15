#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define N 10

struct person
{
	char firstname[20], lastname[20];
	int age;
};
typedef struct person person;
int main ()
{


FILE *out;
person *ami[N];	char prenom[20];
char nom[20];
char s[20];
int i,age;

/* initialiser ami[] à partir des valeurs lues au clavier */

for (i=0;i<N;i++)
{
printf ("rentrer le prenom nom et age de votre %deme ami : ",i+1);
	scanf("%19s %19s %d",prenom, nom, &age);

	struct person (*ami)[i]=malloc(sizeof(struct person));

	//person ami[i]=malloc(((strlen(prenom)+strlen(nom)+3)*sizeof(char))+strlen(age));
	if (&ami[i]==NULL) {perror("malloc") ; exit(1);}
	strcpy((*ami)[i].firstname,prenom);
	strcpy((*ami)[i].lastname,nom);
	(*ami)[i].age=age;
}
out = fopen("myfile","w");
if (out==NULL) { perror("myfile") ; return 1 ;}

/* ecrire le contenu de ami dans out avec fwrite */

fwrite(ami,N*sizeof(person),1,out);
fclose(out);

for(i=0;i<N;i++) free(ami[i]);
free(*ami);
return 0;
}