# include <stdio.h>

int PGCD(int A,int B)
{
if (A==B)
return A;
else
	if (A>B)
	return PGCD(A-B,B);
	else
	return PGCD(A,B-A);
}
void main (int argc, char * argv[])
{
printf("%d\n",PGCD(15,45));
}
