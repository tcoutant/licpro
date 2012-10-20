#include <SDL/SDL.h>
#define klCase 64
#define khCase 64
#define kblanche 0
#define knoire 1
#define kneutre 2
#define kcorrect 1
void copie(int table[8][8], int copieTable[8][8]);
int positionnement(int table[8][8], int couleur, int i, int j);
int main(int argc, char* argv[]) {
int passerTour(int table[8][8], int couleur);
void ordinateur(int table[8][8]);
void initialisation(int table[8][8]) ;
void dessin(int table[8][8], SDL_Surface* spiece[3], SDL_Surface* sfenetre);
int fin=0, n;
int table[8][8];
SDL_Surface* sfenetre;
SDL_Surface* spiece[3];
SDL_Event evenement;
SDL_Init(SDL_INIT_VIDEO);
SDL_WM_SetCaption("Reversi", NULL);
sfenetre=SDL_SetVideoMode(8*klCase, 8*khCase, 32, SDL_HWSURFACE);
spiece[kblanche]=SDL_LoadBMP("Images/blanche.bmp");
spiece[knoire]=SDL_LoadBMP("Images/noire.bmp");
spiece[kneutre]=SDL_LoadBMP("Images/neutre.bmp");
initialisation(table);
dessin(table, spiece, sfenetre);
SDL_Flip(sfenetre);
while ( !fin ) {
SDL_WaitEvent(&evenement);
switch ( evenement.type ) {
case SDL_QUIT:
fin=1;
break;
case SDL_KEYDOWN:
if ( evenement.key.keysym.sym==SDLK_ESCAPE )
fin=1;
break;
case SDL_MOUSEBUTTONDOWN:
if ( !passerTour(table, kblanche) ) {
if ( positionnement(table, kblanche, evenement.button.y/khCase,
evenement.button.x/klCase)==kcorrect ) {
dessin(table, spiece, sfenetre);
SDL_Flip(sfenetre);
SDL_Delay(1000);
if ( !passerTour(table, knoire) )
ordinateur(table);
}
}
else if ( !passerTour(table, knoire) )
ordinateur(table);
dessin(table, spiece, sfenetre);
SDL_Flip(sfenetre);
break;
}
}
for ( n=0; n<3; n++ )
SDL_FreeSurface(spiece[n]);
SDL_Quit();
return 0;
}
int passerTour(int table[8][8], int couleur) {
int i, j;
int copieTable[8][8];
for ( i=0; i<8; i++ ) {
for ( j=0; j<8; j++ ) {
copie(table, copieTable);
if ( positionnement(copieTable, couleur, i, j)==kcorrect )
return 0;
}
}
return 1;
}
void ordinateur(int table[8][8]) {
int arbre(int table[8][8], int couleur, int x);
int i, j, n, m, x=0;
int copieTable[8][8], tableDefinitive[8][8];
for ( i=0; i<8; i++ ) {
for ( j=0; j<8; j++ ) {
copie(table, copieTable);
if ( positionnement(copieTable, knoire, i, j)==kcorrect ) {
x++;
n=arbre(copieTable, knoire, 0);
if ( x==1 || n>m ) {
m=n;
copie(copieTable, tableDefinitive);
}
}
}
}
copie(tableDefinitive, table);
return;
}
int arbre(int table[8][8], int couleur, int x) {
int total(int table[8][8]);
int i, j, n=0;
int copieTable[8][8];
if ( x<4 ) {
x++;
for ( i=0; i<8; i++ ) {
for ( j=0; j<8; j++ ) {
copie(table, copieTable);
if ( positionnement(copieTable, couleur, i, j)==kcorrect )
n+=arbre(copieTable, !couleur, x);
}
}
}
else
return total(table);
return n/4;
}
int total(int table[8][8]) {
int i, j, n=0;
for ( i=0; i<8; i++ )
for ( j=0; j<8; j++ )
if ( table[i][j]==knoire )
n++;
else if ( table[i][j]==kblanche )
n--;
return n;
}
void copie(int table[8][8], int copieTable[8][8]) {
int i, j;
for ( i=0; i<8; i++ )
for ( j=0; j<8; j++ )
copieTable[i][j]=table[i][j];
return;
}
int encadrement(int table[8][8], int couleur, int i, int j, int dir[2]) {
while ( 0<=i && i<=7 && 0<=j && j<=7 && table[i][j]==!couleur )
i+=dir[0], j+=dir[1];
if ( 0<=i && i<=7 && 0<=j && j<=7 &&
table[i][j]==couleur && table[i-dir[0]][j-dir[1]]==!couleur )
return kcorrect;
return !kcorrect;
}
int inversionPions(int table[8][8], int couleur, int i, int j) {
int encadrement(int table[8][8], int couleur, int i, int j, int dir[2]) ;
int n, ci, cj, x=0;
int dir[8][2]={{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
for ( n=0; n<8; n++ ) {
ci=i, cj=j;
if ( encadrement(table, couleur, ci+dir[n][0], cj+dir[n][1], dir[n])==kcorrect ) {
while ( table[ci+dir[n][0]][cj+dir[n][1]]==!couleur ) {
table[ci+dir[n][0]][cj+dir[n][1]]=couleur;
ci+=dir[n][0], cj+=dir[n][1];
x++;
}
}
}
return x;
}
int positionnement(int table[8][8], int couleur, int i, int j) {
int inversionPions(int table[8][8], int couleur, int i, int j);
if ( table[i][j]==kneutre ) {
if ( inversionPions(table, couleur, i, j)!=0 ) {
table[i][j]=couleur;
return kcorrect;
}
}
return !kcorrect;
}
void dessin(int table[8][8], SDL_Surface* spiece[3], SDL_Surface* sfenetre) {
int i, j;
SDL_Rect position;
for ( i=0; i<8; i++ ) {
position.y=i*khCase;
for ( j=0; j<8; j++ ) {
position.x=j*klCase;
SDL_BlitSurface(spiece[table[i][j]], NULL, sfenetre, &position);
}
}
return;
}
void initialisation(int table[8][8]) {
int i, j;
for ( i=0; i<8; i++ )
for ( j=0; j<8; j++ )
table[i][j]=kneutre;
table[3][3]=kblanche, table[3][4]=knoire,
table[4][3]=knoire, table[4][4]=kblanche;
return;
}
