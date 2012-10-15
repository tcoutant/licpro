# include <stdio.h>

/* donner le numero d'un mois et afficher ensuite le nombre de jours dans ce mois*/
int mois;
void main() {
printf ("Donner le numero d'un mois :\n");
scanf ("%d", &mois);
switch(mois)
{
case 1 : case 3: case 5: case 7: case 9: case 11:
printf ("c'est un mois de 31 jours.\n");
break;
case 2 :
printf ("c'est un mois de 28 ou 29 jours.\n");
break;
case 4 : case 6: case 8: case 10: case 12:
printf ("c'est un mois de 30jours.\n");
break;
default :
printf ("mois introuvable,  FIN!!!!\n");
break;
}
}
