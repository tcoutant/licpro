#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
	char firstname[20], lastname[20];
	int age;
};

int main ()
{
struct person moi = {"Jacques","Dupont",20};
struct person toi, *lui;

strcpy(toi.firstname,"Anne");
strcpy(toi.lastname,"Dubois");
toi.age = 25;

lui= malloc(sizeof(struct person));
if(lui==NULL) perror("lui");
scanf("%s %s %d", lui->firstname, lui->lastname, &lui->age);

printf("%s %s %d ans \n", moi.firstname, moi.lastname, moi.age);
printf("%s %s %d ans \n", toi.firstname, toi.lastname, toi.age);
printf("%s %s %d ans \n", lui->firstname, lui->lastname, lui->age);

free(lui);
return 0;
}