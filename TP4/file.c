#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t pid = getpid();
    printf("P1 PID %d\n", pid);

    for (int cpt = 1; cpt < 8; cpt++) {
        pid = fork();

        switch (pid) {
            case -1:
                printf("ERREUR DE FORK\n");
                exit(EXIT_FAILURE);
            case 0:
                printf("P%d PID %d PPID %d\n", cpt+1, getpid(), getppid());
                break;
            default:
                wait(NULL);
                return 0;
        }
    }
    return 0;
}