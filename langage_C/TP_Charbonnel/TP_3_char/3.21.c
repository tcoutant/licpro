# include <stdio.h>
# include <string.h>
# define const 10 		/*declaration des constantes*/

/*commentaire*/
int main()
{
int mat [3] [3]={{1,0,0},{0,1,0},{0,0,1}};
/*commentaire*/
int i,j;
for (i=0;i<3;i++)
{
	for(j=0;j<3;j++)
	printf("%3d",mat[i][j]); // 3 devant le d, c'est l'espacement apres l'écriture
printf(" \n");
}

}