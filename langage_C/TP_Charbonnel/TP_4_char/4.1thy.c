# include <stdio.h>
# include <string.h>
# define const 10 		/*declaration des constantes*/

/*commentaire*/
int i=12;
int *ptr;
int main()
{
ptr =&i;
*ptr = 21;
/*commentaire*/
printf(" ptr=%p *ptr=%d i=%d \n",ptr,*ptr,i);
scanf("%d",ptr);
printf(" ptr=%p *ptr=%d i=%d \n",ptr,*ptr,i);

/*commentaire*/

/*programme principal*/			

return 0;
}
