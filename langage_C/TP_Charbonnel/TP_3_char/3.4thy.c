// triangle de Pascal

#include <stdio.h>

#define N 10

/* fonction qui calcule le nombre se situant sur la ligne n et la colonne P dans le triangle de pascal*/
int C(int n,int p)
{

if ((n==p)||(p==0)) return 1;
else return C(n-1,p)+C(n-1,p-1);
}
int main()
{
int lig, col;
printf("donner une ligne du tableau de pascal: ");
scanf("%d",&lig);
printf("donner un numero de colonne < ou = au numero de ligne: ");
scanf("%d",&col);
if (col>lig)
printf("Vous etes sorti du tableau\n");
printf("le nombre correspondant dans le tableau de pascal est : %d \n",C(lig,col));
return 0;
}
