/*
	On regarde dans la direction passée en paramètre, si la case adjacente est vide ou contient une pièce de la même couleur que celle du joueur => pas de prise, retourne 0
	sinon, on se décale dans la direction tant qu'on ne tombe pas sur la fin du tableau, ou sur une case vide ou occupée par une pièce du joueur.
	Si on est en fin de tableau, on renvoie 0
	Si la case est vide, on renvoie 0
	Si la case contient une pièce du joueur, on renvoie 1 => on fait une prise dans la direction.
*/
int faitPriseDansDirection(int direction, int joueur, plateau p, int NumLigne, int NumColonne);




/*
	On regarde dans la direction passée en paramètre si on fait une prise avec la fonction faitPriseDansDirection
	Si non, on retourne 0
	Si oui, on se décale dans la direction jusqu'à rencontrer un pion de la couleur du joueur passé en paramètre, en changeant la couleur des cases que l'on rencontre.
		====> On teste aussi si la case est non nulle et si on est pas au bord ???? utile ? testé dans faitPriseDansDirection
	On incrémente "compte" a chaque fois qu'on change une case.
	On retourne "compte", pour savoir le nombre de pion prit
*/
int retournePionsDansDirection(int direction, int joueur, plateau p, int NumLigne, int NumColonne);




/*
	On compte le nombre de pions retournés dans chacune des 8 directions, et on fait le total dans la boucle.
	On retourne le nombre total de pions prit grâce au coup joué
*/
int retournePions(int joueur, plateau p, int NumLigne, int NumColonne);




/*
	Retourne 1 si le nombre de pions prit est supérieur à 0 ==> on fait une prise
	Retourne 0 si le nombre de pions prit est égal à 0 ==> on ne fait pas de prise 
*/
int faitPrise(int joueur,plateau p, int NumLigne, int NumColonne);



/*
	Renvoie 0 si la case et vide, 1 ou 2 selon la couleur de la pièce présente
*/
int renvoieContenuCase(plateau p, int NumLigne, int NumColonne);
