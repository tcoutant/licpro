# include <math.h>
# include <stdio.h>

int main()
{
int i;
double (*tab[5])(double) = { sin,cos,tan,exp,log };
for (i=0;i<5;i++) printf("%f\n",tab[i](3.14));
} 
