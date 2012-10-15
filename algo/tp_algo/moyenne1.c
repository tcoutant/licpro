# include <stdio.h>
float n1, n2, n3, moy;
float c1, c2, c3;

void main() {
c1=3, c2=3, c3=2;
printf ("donner la note de math, d'informatique et d'anglais :\n");
scanf ("%f %f %f", &n1,&n2, &n3);
 moy=((c1*n1)+(c2*n2)+(c3*n3))/(c1+c2+c3);
printf ("la moyenne coefficientée est: %f \n",moy) ;
}
