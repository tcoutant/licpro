/* Fonctions de choix des menu (Jouer, quitter, règles), du mode de jeu (HvsH, HvsO, OvsO), et choix du niveau (en cas de choix d'un mode de jeu avec ordinateur)*/



//Choix entre Jouer, Règles, Auteurs, Quitter
int proposeEtChoixMenu();

//Si "Jouer" est choisi, choix entre "Humain vs Humain",  "Humain vs Ordi" et "Ordi vs Ordi"
int proposeEtChoixModeDeJeu();

//Si "Humain vs Ordi" ou "Ordi vs Ordi" est choisi, choix entre différents niveaux
int proposeEtChoixNiveauDeJeu();


