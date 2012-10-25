int caseVide(plateau p, int NumLigne, int NumColonne)
{
	if(p[NumLigne][NumColonne]== 0) 
		return 1
	else 
		return 0;
}


int adversaire(int joueur)//Retourne l'adversaire du joueur passé en parametre
{   
   if(joueur==1)
      return 2; 
   else 
      return 1;
}


int renvoieContenuCase(plateau p, int NumLigne, int NumColonne)
{
  
  return p[NumLigne][NumColonne];
}


void comptePions(plateau p, int *NbPions1, int *NbPions2)//Compte le nombre de pions pour chaque joueurs
{
   int i,j;

   for(i=0;i<DIM_MAX;i++)
   {
      for(j=0;j<DIM_MAX;j++)
      {
         if(p[i][j]==1)
			*NbPions1++;
		else
			*NbPions2++;
      }
   }
}


int existeCoupPourJoueur(plateau p,int joueur)
{
   int i,j;  
 
   for(i=0;i<DIM_MAX;i++)
   {
      for(j=0;j<DIM_MAX;j++)
      {
         if(coupValide(joueur,p,i,j))
             return 1;
      }
   }
   return 0;
}


void joueLeCoup(plateau p, int NumLigne, int NumColonne, int joueur)//Joue un coup
{
      p[NumLigne][NumColonne]=joueur;								//Retourne le pion avec la couleur du joueur

      retournePions(joueur,p,NumLigne,NumColonne);					//Appel de la fonction retournePions

      affichePlateau(p);											//Affichage du plateau
}


int valeurQuantitative(plateau p) 
{
	int pion1,pion2;
	pion2=0;
	pion1=0;

	comptePions(p,&pion1,&pion2);

	printf("Nombre Pions Joueur1:%d - Joueur2:%d\n",pion1,pion2);
	
	return (pion1-pion2);  
}


float evalue(plateau p)
{
	return (float)valeurQuantitative(p);
}


int partieTerminee(plateau p) //La partie est terminée si les deux joueurs ne peuvent plus jouer
{
   return !existeCoupPourJoueur(p,1) && !existeCoupPourCamp(p,1); 
}

