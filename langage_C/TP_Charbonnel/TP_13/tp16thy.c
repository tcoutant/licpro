# include <stdio.h>
# include <stdlib.h>

void *f1(void *arg)
{
	/*		*/
	pthread_exist(0);
}

void *f2(void *arg)
{
	/*		*/
	pthread_exist(0);
}

void *f3(void *arg)
{
	/*		*/
	pthread_exist(0);
}

int main(int nb_args, char *arg[])
{
   pthread_t t1,t2,t3;
	if (pthread_create(&t1,NULL,f1,NULL)<0) perror ("f1 fails\n);
	if (pthread_create(&t2,NULL,f1,NULL)<0) perror ("f2 fails\n);
	if (pthread_create(&t3,NULL,f1,NULL)<0) perror ("f3 fails\n);

    return 0;
}

