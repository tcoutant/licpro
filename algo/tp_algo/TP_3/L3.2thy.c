# include <stdlib.h>
#include <stdio.h>
# define nmax 50
//sructure d'une image non compresse
struct maillon_ligne
{
int pixel;
struct maillon_ligne *suivant;
};

/*creation d'un pointeur vers la liste de maillon_ligne*/
typedef struct maillon_ligne *ptr_ligne;
/*creation d'un tableau image de pointeurs maillon_ligne*/
typedef ptr_ligne T_image[nmax];

//stucture d'une image compressée
struct maillon_ligne_compressee
{
int val; int nb;
struct maillon_ligne_compressee *suivant;
};
typedef struct maillon_ligne_compressee *ptr_ligne_compressee;
typedef ptr_ligne_compressee T_image_compressee[nmax];

/*declaration de variables et pointeurs*/
T_image im,ima;
int nbligne;
T_image_compressee imc;
ptr_ligne_compressee ligne;

// fonction ajout sur une image non compressée
void ajout(ptr_ligne *L, int e)
{
/*declaration du pointeur de l'element ajouté*/
ptr_ligne p;
/* on lui assigne de l'espace*/
p= malloc(sizeof(struct maillon_ligne));
/*attribution des valeurs*/
p->pixel =e;
p-> suivant = *L;
*L= p;
}

// fonction ajout sur une image compressée
void ajoutc (ptr_ligne_compressee *L,int valeur, int nombre)
{
ptr_ligne_compressee p;
p= malloc(sizeof(struct maillon_ligne_compressee));
(p->val)=valeur;
(p->nb)=nombre;
p->suivant = *L;
*L = p;
}

/*affiche ligne non compressee*/
void afficheligne(ptr_ligne L)
{
while (L!=NULL)
	{
	printf("%d ", L->pixel);
	L=L->suivant;
	}
printf("\n");
}

/*affiche ligne compressee*/
void affichelignecompressee(ptr_ligne_compressee L)
{
while (L!=NULL)
	{
	printf("(%d,%d) ",L->val,L->nb);
	L=L->suivant;
	}
printf("\n");
}
/*affiche image non compressee*/
void afficheimage(T_image xx,int nbligne)
{
ptr_ligne p;
int i;
for (i=0;i<nbligne;i++)
	{
	p=xx[i];
	while(p!=NULL)
		{
		printf("%d ",p->pixel);
		p=p->suivant;
		}
	
printf("\n");
	}
}

/*affiche imagecompressee*/
void afficheimageC(T_image_compressee xx, int nbligne)
{
ptr_ligne_compressee p;
int i;
for(i=0;i<nbligne;i++)
	{
	p=xx[i];
	while(p!=NULL)
		{
		printf("(%d,%d) ",p->val,p->nb);
		p=p->suivant;
		}
	}
printf("\n");
}
/*procedure qui compresse une image*/
void compresseimage (T_image xx,int nbligne, T_image_compressee *yy)
{
int valeur, nombre;
ptr_ligne p;
yy=NULL;
p=xx[nbligne];
while (p!=NULL)
{
valeur=p->pixel;
nombre=0;
while(p!=NULL&&(p->pixel==valeur))
	{
	nombre=nombre+1;
	p->suivant;
	}
	ajoutc(*yy,valeur,nombre);
}
}

int main()
{
/*creation d'une ligne*/
ptr_ligne ptr_ligne1=NULL;

ajout(&ptr_ligne1,5);
ajout(&ptr_ligne1,5);
ajout(&ptr_ligne1,5);
ajout(&ptr_ligne1,5);
ajout(&ptr_ligne1,5);
ajout(&ptr_ligne1,2);
ajout(&ptr_ligne1,2);
ajout(&ptr_ligne1,2);
ajout(&ptr_ligne1,2);
ajout(&ptr_ligne1,2);
ajout(&ptr_ligne1,2);
ajout(&ptr_ligne1,2);
ajout(&ptr_ligne1,2);
ajout(&ptr_ligne1,2);
ajout(&ptr_ligne1,2);
ajout(&ptr_ligne1,7);
ajout(&ptr_ligne1,7);
ajout(&ptr_ligne1,7);
ajout(&ptr_ligne1,7);
ajout(&ptr_ligne1,7);
ajout(&ptr_ligne1,7);
ajout(&ptr_ligne1,7);
ajout(&ptr_ligne1,7);
ajout(&ptr_ligne1,7);

ptr_ligne ptr_ligne2=NULL;

ajout(&ptr_ligne2,4);
ajout(&ptr_ligne2,4);
ajout(&ptr_ligne2,4);
ajout(&ptr_ligne2,4);
ajout(&ptr_ligne2,4);
ajout(&ptr_ligne2,8);
ajout(&ptr_ligne2,8);
ajout(&ptr_ligne2,8);
ajout(&ptr_ligne2,8);
ajout(&ptr_ligne2,8);
ajout(&ptr_ligne2,8);
ajout(&ptr_ligne2,8);
ajout(&ptr_ligne2,8);
ajout(&ptr_ligne2,8);
ajout(&ptr_ligne2,6);
ajout(&ptr_ligne2,6);
ajout(&ptr_ligne2,6);
ajout(&ptr_ligne2,6);
ajout(&ptr_ligne2,6);
ajout(&ptr_ligne2,6);
ajout(&ptr_ligne2,6);
ajout(&ptr_ligne2,6);
ajout(&ptr_ligne2,6);
ajout(&ptr_ligne2,7);

ptr_ligne ptr_ligne3=NULL;

ajout(&ptr_ligne3,4);
ajout(&ptr_ligne3,4);
ajout(&ptr_ligne3,4);
ajout(&ptr_ligne3,4);
ajout(&ptr_ligne3,3);
ajout(&ptr_ligne3,3);
ajout(&ptr_ligne3,3);
ajout(&ptr_ligne3,3);
ajout(&ptr_ligne3,3);
ajout(&ptr_ligne3,3);
ajout(&ptr_ligne3,3);
ajout(&ptr_ligne3,3);
ajout(&ptr_ligne3,9);
ajout(&ptr_ligne3,9);
ajout(&ptr_ligne3,9);
ajout(&ptr_ligne3,9);
ajout(&ptr_ligne3,9);
ajout(&ptr_ligne3,9);
ajout(&ptr_ligne3,9);
ajout(&ptr_ligne3,9);
ajout(&ptr_ligne3,9);
ajout(&ptr_ligne3,9);
ajout(&ptr_ligne3,9);
ajout(&ptr_ligne3,2);
im[0]=ptr_ligne1;
im[1]=ptr_ligne2;
im[2]=ptr_ligne3;
//afficheligne(ptr_ligne1);
//afficheligne(ptr_ligne2);
//afficheligne(ptr_ligne3);
afficheimage(im,3);
T_image_compressee *ima;
compresseimage(im,3,&(*ima));
afficheimageC(*ima,3);
return 0;
}
