# include <stdio.h>
# include <string.h>

/*quelque soit la valeur de *j la fonction retounera  a l'adresse j la valeur *j= 2*i */
int i, *j;
void f(int i, int *j)
{
*j= 2*i;
}

int main()
{
i=1;
int *k;
for(i=0;i<10;i++)
{
f(i,k);
printf(" %d %d  ",i,*k);
}
printf("  \n");
return 0;

}
