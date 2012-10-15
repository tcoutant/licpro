#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nmax 10
struct maillon_ligne
{
	int pix;
	struct maillon_ligne * suiv;
};

typedef struct maillon_ligne * ptr_ligne;

typedef ptr_ligne T_image[nmax];


struct couple
{
	int val,nb;
};

struct maillon_ligne_compressee
{
	struct couple pix;
	struct maillon_ligne_compressee * suiv;
};

typedef struct maillon_ligne_compressee * ptr_ligne_compressee;

typedef ptr_ligne_compressee T_image_compressee[nmax];

T_image im,ima;
int nbligne;
T_image_compressee imc;
ptr_ligne_compressee ligne;


void ajout (int e, ptr_ligne *L)
{
	ptr_ligne p;
	p = malloc(sizeof(struct maillon_ligne));
	p->pix=e;
	p->suiv=*L;
	*L=p;
}

void ajouter (struct couple c, ptr_ligne_compressee *L)
{
	ptr_ligne_compressee p;
	p = malloc(sizeof(struct maillon_ligne_compressee));
	p->pix=c;
	p->suiv=*L;
	*L=p;
}

void afficheLigne(ptr_ligne L)
{
	while (L!=NULL)
		{
		printf("%d ",L->pix);
		L=L->suiv;
		}
	printf("\n");
}

void afficheLigneCompressee(ptr_ligne_compressee L)
{
	while (L!=NULL)
		{
		printf("(%d,%d) ",(L->pix).val,(L->pix).nb);
		L=L->suiv;
		}
	printf("\n");
}

void ajouterbis (int val, int nb, ptr_ligne_compressee *L)
{
	ptr_ligne_compressee p;
	p = malloc(sizeof(struct maillon_ligne_compressee));
	(p->pix).val = val;
	(p->pix).nb = nb;
	p->suiv=*L;
	*L=p;
}


void creer_image (T_image *im, int * nbligne)
{
	FILE *fp;
	int x,i;
	  if ((fp = fopen("image.txt", "r")) == NULL){
	    fprintf(stderr, "Cannot open image.txt\n");
	    exit(1);
	  }
	fscanf(fp,"%d",&(*nbligne));    
  for(i=0;i<*nbligne;i++)
		(*im)[i]=NULL;
  i=0;
  while (i != *nbligne)
    {
		do
			{
				fscanf(fp,"%i ",&x);
				if (x != -1)
					ajout(x,&(*im)[i]);
			}
		while (x != -1);
		i++;
		}
  fclose(fp);
}


void affiche(T_image im, int nbligne)
{
	ptr_ligne p;
	int i;
  for(i=0;i<nbligne;i++)
		{
      p=im[i];
      while (p != NULL)
				{
          printf("%d ",p->pix);
          p=p->suiv;
        }
        printf("\n");
    }
}

void affichecompressee (T_image_compressee im,int nbligne)
{
	ptr_ligne_compressee p;
	int i;
  for(i=0;i<nbligne;i++)
    {
      p=im[i];
      while(p != NULL)
        {
          printf("(%d,%d)",p->pix.val,p->pix.nb);
          p=p->suiv;
        }
        printf("\n");;
    }
}


void compresse_ligne (T_image im, int l, ptr_ligne_compressee *ligne)
{
	int val,nb;
	struct couple c;
	ptr_ligne p;

  *ligne=NULL;
  p=im[l];
  while (p != NULL)
    {
      val=p->pix;
      nb=0;
      while ((p != NULL) && (p->pix == val))
        {
          nb=nb+1;
          p=p->suiv;
        }
        c.val=val;
        c.nb=nb;
	ajouter(c,&(*ligne));
    }
}

void decompresse_ligne (T_image_compressee im, int l, ptr_ligne *ligne)
{
	ptr_ligne_compressee p;
	int i;
  *ligne=NULL;
  p=im[l];
  while (p!=NULL)
    {
      for(i=0;i<p->pix.nb;i++)
        ajout(p->pix.val,&(*ligne));
      p=p->suiv;
    }
}

void compresse_image(T_image im, int nbligne, T_image_compressee *imc)
{
	int i;
	for(i=0;i<nbligne;i++)
		compresse_ligne(im,i,&(*imc)[i]);
}

int main()
{
	creer_image(&im,&nbligne);
	printf("Image saisie\n");
  affiche(im,nbligne);
  compresse_image(im,nbligne,&imc);
	printf("\nImage compressee\n");
	affichecompressee(imc,nbligne);
  decompresse_ligne(imc,0,&ima[0]);
	printf("\nLigne 1 decompressee\n");
  affiche(ima,1);
	return 0;
}
