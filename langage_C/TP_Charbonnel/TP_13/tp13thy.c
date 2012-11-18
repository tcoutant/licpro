# include <stdio.h>
# include <sys/types.h>
# include <dirent.h>
# include <stdlib.h>

int main(int nb_args, char *arg[])
{
    DIR* rep = NULL;

	struct dirent* fichierlu = NULL;

	if(nb_args==2)
{

    rep = opendir(arg[1]); /* Ouverture du dossier qui est passe en argument,
l'argument 0 est la commande passee */

    if (rep == NULL) /* Si le dossier ne peut pas etre ouvert */
        exit(1); /* (mauvais chemin par exemple) */
      printf("Le dosssier a ete ouvert avec succes\n");

	while((fichierlu=readdir(rep))!=NULL)
	printf("nom du fichier lu : %s\n",fichierlu->d_name);

	   

    if (closedir(rep) == -1) /* S'il y a eu un souci avec la fermeture */
        exit(-1);

    printf("Le dossier a ete ferme avec succes");

    return 0;
}
}