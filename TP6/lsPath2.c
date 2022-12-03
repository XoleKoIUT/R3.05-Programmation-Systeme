#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
Ecrire une commande  lspath2 qui liste chacun des répertoires de la variable PATH après avoir affiché
le nom du répertoire. On utilisera la forme à un seul répertoire : ls rep
*/

int main(int argc, char *argv[])
{
    char  *path  = getenv("PATH");
    char  *token = strtok(path, ":");
    int   i;
    pid_t pid;

    for(i = 3; (token = strtok(NULL, ":")) != NULL; i++) {
        pid = fork();

        if(pid == 0){
            execl("/bin/ls", "ls", "-al", "/", NULL);
            perror("execl");
        }else{
            wait(NULL);
            token = strtok(NULL, ":");
            exit(1);
        }
    }
}