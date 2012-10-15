# include<stdio.h>
# include <string.h>
# define ORIGINAL "/usr/share/dict/words"
# define COPIE "/tmp/mondouble"
# define L 60

/*fonction est un palindrome*/
int palin(char *s)
{
int i=0, j;
j=strlen(s)-1;

	while (s[i]==s[j] && i<j) { i++ ; j-- ; }
	return s[i]==s[j] ;
}


int main()
{
FILE*in, *out;
char s[L];
int nl=0;

in= fopen(ORIGINAL,"r");
if (in==NULL) {perror(ORIGINAL); return 1;}
out= fopen(COPIE,"w");
if (out==NULL) {perror(COPIE); return 2;}
while (fgets(s,L-1,in)!=NULL)
{
	fprintf(out,"%02d: %s",nl,s);
	nl++;

}
fclose(in);
fclose(out);
return 0;
}
