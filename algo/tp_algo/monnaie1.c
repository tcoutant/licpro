# include <stdio.h>

/*choisir un pays dans une liste et donner ensuite sa monnaie*/
int pays;
void main(int argc, char*argv[]) {
printf ("MONNAIE DE CERTAINS PAYS\nChoisissez un pays : 1 France, 2 états-unis, 3 mexique, 4 chine :\n");
scanf ("%d", &pays );
switch (pays) 
{
case 1 :
printf ("En France, c'est l'euro.\n");
break;
case 2 :
printf ("Aux Etats-Unis, c'est le dollar.\n");
break;
case 3 :
printf ("Au Mexique, c'est le peso.\n");
break;
case 4 :
printf ("En Chine, c'est le yen.\n");
break;
default:
printf ("mauvais choix FIN !!!\n");
break;
}
}