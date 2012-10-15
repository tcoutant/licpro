#include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdlib.h>
#define N 10

void f(int t[N], int n)
{
int i;int *ptr;
printf("ligne %d: %d\n", __LINE__,sizeof(t));
ptr=t;
while(ptr<t+N)
	{printf("%d ",*ptr);
	ptr=ptr+1;}
}

int main()
{
int t[N]={0,1,2,3,4,5,6,7,8,9};
printf("ligne %d: %d\n", __LINE__,sizeof(t));
f(t,N);
printf("\n");

return 0;
}
