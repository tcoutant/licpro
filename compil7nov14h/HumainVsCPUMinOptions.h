/*	Compte, à partir d'un plateau et d'un joueur passé en paramètre, le nombre de coups possible pour ce joueur sur le plateau */
int nbCoupsValides(plateau p, int joueur);

/*
	On initialise la variable minOptions à 65 (supérieur aux possibilités maximum, car il n'y a que 64 cases)
	On alloue une liste chainée qui contient la liste des coups valides sur le plateau passé en paramètre.
	On teste chaque coup possible, et on compte le nombre de possibilités qu'aura l'adversaire si l'on joue ce coup (avec la fonction nbCoupsValides), ue l'on stocke dans minOptions_tmp.
	Si ce nombre est inférieur au nombre stocké dans la variable minOptions, on change la valeur.
	A la fin de la liste chainée, on retourne minOptions.
*/
int trouveCoupMinOptions(plateau p, StrCoup * Coup,int joueur);


/*	Si l'ordinateur a la possibilité de jouer, on appelle la fonction qui cherche le coup laissant le moins de possibilités à son adversaire, puis on joue ce coup.	*/
void tourCPUMinOptions(plateau p, int joueur);
