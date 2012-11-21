# include <stdio.h>
# include <signal.h>

int main()
{
	pid_dt pid;
	int ret;

	pid = fork(); /* dédoublement: pid reçoit le PID du fils dans le père
									pid reçoit 0 dabs le fils */

	switch(pid)
	{
		case -1 :
			puts("erreur");
			return 1;
			break;

		case 0 :
			puts("je suis le fils");
			return 3;

		default :
			printf("je suis le pere, le PID de mon fils est %d\n",pid);
			puts("j'attends que mon fils se termine");
			wait(&ret);
			printf("mon fils a renvoyé %d\n" WEXITSTATUT(ret));
			return 0;
	}
}
