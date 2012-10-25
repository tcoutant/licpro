/*	Libère une liste chainée */
void free_Maillons(Maillon * teteMaillon);

/*	Compte le nombre de pions pour chacun des joueurs étant donné un plateau p */
int ecartPions(plateau p);

/*
	On initialise la variable ecart à -70 (valeur impossible)
	On alloue une liste chainée qui contient la liste des coups valides sur le plateau passé en paramètre.
	On teste chaque coup possible, et on compte le nombre de pions que l'on prendra à l'adversaire si l'on joue ce coup (avec la fonction ecartPions ), que l'on stocke dans ecart_tmp.
	Si ce nombre est supérieur au nombre stocké dans la variable ecart, on change la valeur.
	A la fin de la liste chainée, on retourne ecart.
*/
int trouveCoupMaxPions(plateau p, StrCoup * Coup,int joueur);

/*	Si l'ordinateur a la possibilité de jouer, on appelle la fonction qui cherche le coup prenant le plus de pions à son adversaire, puis on joue ce coup.	*/
void tourCPUMaxPions(plateau p, int joueur);
