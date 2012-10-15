# include <stdio.h>



# define const 10 		/*declaration des constantes*/

/*commentaire*/
int swap(int *A,int *B)
{
int temp;
temp=*A;
*A=*B;
*B=temp;
}

int main()
{
int C=4, D=9;
printf("valeur A: %d  valeur B: %d \n",C, D);
swap(&C,&D);
printf("valeur A: %d  valeur B: %d \n",C, D);
return 0;
}		
