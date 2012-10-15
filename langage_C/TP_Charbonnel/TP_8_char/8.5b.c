#include <stdio.h>
#include "8.5.h"

int main()
{
	FILE *in ;
	struct contact p ;

	in = fopen("myfile","r") ;
	if (in==NULL) { perror("myfile") ; return 1 ; }
	while (fread(&p,sizeof(struct contact),1,in)==1)
	{
		printf("%s ",p.this_person.firstname) ;
		switch (p.his_country)
		{
			case fr : printf("%d %s %d %s\n",p.his_address.fraddr.numero,p.his_address.fraddr.rue,p.his_address.fraddr.postal_code,p.his_address.fraddr.ville) ;
			          break ;
			case us : printf("%d %s %s %s %s\n",p.his_address.usaddr.house_number, p.his_address.usaddr.street, p.his_address.usaddr.direction, p.his_address.usaddr.locality, p.his_address.usaddr.postal_code) ;
			          break ;
			case uk : printf("%d %s %s %s %s\n",p.his_address.usaddr.house_number, p.his_address.usaddr.street, p.his_address.usaddr.locality, p.his_address.usaddr.province, p.his_address.usaddr.postal_code) ;
			          break ;
		}		
	}
	fclose(in) ;

	return 0 ;
}
