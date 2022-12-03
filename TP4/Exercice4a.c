#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    fork();
    fork();

    for ( int cpt = 1; cpt <= 3; cpt++ ){
        printf ("%d\n",cpt);
    }

    return 0;
}
