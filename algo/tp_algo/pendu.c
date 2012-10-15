#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char lirecaractere ();
void remplaceLettre (char motSecret[], char motAffiche[], char lettreSaisie);

char lireCaractere ()
{
    char caractere = 0;

    caractere = getchar ();// On lit le premier caractère
    caractere = toupper (caractere);//On met la lettre en majuscule si elle ne l'ets pas déjà

    while (getchar() != '\n'); //On lit les autres caractères un à un jusqu'au \n pour les effacer

    return caractere;
}

void remplaceLettre (char motSecret[], char motAffiche[], char lettreSaisie)
{
    int i=0;

    do
    {
        if (lettreSaisie == motSecret[i])
        {
            motAffiche[i] = motSecret[i];
        }

        i++;
    }
    while (motSecret[i] != '\0' && motAffiche[i] != '\0');
}

int main()
{
    char motSecret[] = "MARRON", *motAffiche = NULL, *resultat = NULL;
    char lettreSaisie = 0;
    int essais = 0, longueurMot = 0, i = 0;

    printf ("Bienvenue au jeu du Pendu ! \n Le but du jeu est de trouver un mot cache en moins de 10 essais (rates)!\n Vous devez proposer UNE lettre (en majuscule) et l'ordinateur verifie si cette lettre fait partie du mot ou pas. Si c'est le cas, le jeu continue -vous devez chercher les autres lettres du mot - et vous gardez votre nombre d'essais restants. Sinon, votre nombre d'essais restants diminue a chaque nouvel essai rate jusqu'a ce que vous trouviez a nouveau une lettre correcte. :D \n");


    longueurMot = strlen (motSecret);
    printf ("%d \n", longueurMot);
    printf ("%d \n", sizeof (char));
    motAffiche = malloc(longueurMot * sizeof (char));//allocation du tableau de char motAffiche
    if (motAffiche == NULL)//Vérification de l'allocation
    {
        exit (0);
    }

    printf ("%s \n", motAffiche); //Affichage du contenu de l'espace alloué : 3 caractères sans sens particulier (normal me direz vous ! :D)

    while (motAffiche[i] != '\0' && motSecret[i] != '\0') //ou bien while (i<longueurMot)
    {
       motAffiche[i] = '*'; //Initialisation de la chaîne nouvellement créée
       i++;
    }
    motAffiche[longueurMot] = '\0'; //Insertion du caractère de fin de chaîne 
    printf ("%d \n", sizeof (motAffiche)); //EDIT : Affichage de la place prise en mémoire par la chaîne motAffiche : 4
    printf ("%s \n", motAffiche); //Affichage de la chaîne tout juste initialisée avec des astérisques : résultat = 3 '*'

    essais = 10;
    do
    {
        lettreSaisie  = lireCaractere ();
        printf ("Vous avez saisi la lettre %c !", lettreSaisie);
        resultat = strchr (motSecret, lettreSaisie);

        if (resultat == NULL)
        {
            essais --;
            printf ("Rate : la lettre que vous avez saisie n'est pas contenue dans le mot secret ! Il ne vous reste plus que %d essais", essais);
        }
        else
        {
            printf ("Bravo ! Vous avez trouvé une des lettres du mot secret !");
            remplaceLettre (motSecret, motAffiche, lettreSaisie);
            printf ("%s", motAffiche);

        }
    }
    while(essais > 0);

    free (motAffiche);
    return 0;
}
