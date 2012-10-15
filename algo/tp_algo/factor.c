# include <stdio.h>
int A,B;
void main(int agrc, char*argv[]) {	 

printf ("donner la valeur de A :\n");
scanf ("%d", &A);
printf ("donner la valeur de B :\n");
scanf ("%d", &B);
while(A!=B)
{if (A>B) 
A=A-B;
else
B=B-A;
}

printf ("le PGCD est : %d \n", A);
}
