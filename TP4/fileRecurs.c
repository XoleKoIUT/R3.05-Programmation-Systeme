#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


void creerProc(int nb, int num){
    int pfils;
    if(nb > 0){
        pfils = fork();
        if(pfils == -1){
            perror("fork a echoue");
            exit(1);
        }
        if (pfils > 0){
            wait(NULL);
        }
        else{
            printf("Je suis le processus P%d de pid = %d et mon ppid = %d \n",
                   num ,getpid(), getppid());
            creerProc(nb -1, num+1);
        }
    }
}

int main()
{
    int nbproc;
    printf("Donnez le nombre de proccessus à creer :");
    scanf("%d", &nbproc);
    printf("Je suis le processus P%d de pid = %d \n", 1, getpid());
    creerProc(nbproc, 2);
    return 0;
}