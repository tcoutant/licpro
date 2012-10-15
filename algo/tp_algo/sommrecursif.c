# include <stdio.h>

int somm(int n)
{
if (n==0)
return 0;
else
return n+somm(n-1);
}
void main (int argc, char * argv[])
{
printf("%d\n",somm(5));
}
