#include <stdio.h>
#include <stdlib.h>

int main(int nbarg, char *arg[])
{
    int i;

    for (i=0; i < nbarg; i++)
    {
        printf("Argument %d : %s \n", i+1, arg[i]);
    }

   
    return 0;
}
