#include <stdio.h>
#include "8.3.h"

/*struct person
{
	char firstname[20], lastname[20];
	int age;
};*/

int main()
{
	FILE *in ;
	struct person ami ;

	in = fopen("myfile","r") ;
	if (in==NULL) { perror("myfile") ; return 1 ; }
	while (fread(&ami,sizeof(struct person),1,in)==1)
		printf("%s %s %d\n",ami.firstname,ami.lastname,ami.age) ;
	fclose(in) ;

	return 0 ;
}
