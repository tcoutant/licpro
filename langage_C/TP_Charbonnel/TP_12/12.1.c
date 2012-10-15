# include <stdio.h>
# include <string.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
	/*declaration des constantes*/

/*commentaire*/
struct passwd *ptr;
struct group *ptr1;


/*commentaire*/

/*commentaire*/

/*programme principal*/			
int main ()			
{
ptr =getpwent();
ptr1=getgrgid(ptr->pw_gid);
while ((ptr=getpwent())!=NULL)
printf("%s %s \n",ptr->pw_name,ptr1->gr_name);
endpwent();
return 0;
}
