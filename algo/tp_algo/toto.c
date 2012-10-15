# include <stdio.h>
# include <string.h>
		
int i, j;
float x, y;
char c;
		
int main ()			
{

printf( "Donner un entier, un reel et un carctere : " );
scanf("%d %f %c",&i, &x,&c);
printf("%d, %c, %c \n", c, c+1, c-1);
i++; c--;
x=i/11; y=i/11; 
/*printf("%d %f %.2f \n",i,y,y);*/
printf(" %d %f \n",j/i,j/(float)i);
}
