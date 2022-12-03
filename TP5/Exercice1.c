#include <unistd.h>
/*
Ecrire un programme qui affiche le contenu du rÃ©pertoire racine, donner :

*/

//Une version avec la fonction execl,
int main(int argc, char *argv[])
{
    execl("/bin/ls", "ls", "-al", "/", NULL);
    perror("execl");
}

//Une version avec la fonction execlp,
int main(int argc, char *argv[])
{
    execlp("ls", "ls", "-al", "/", NULL);
    perror("execlp");
}

//Une version avec la fonction execv.
int main(int argc, char *argv[])
{
    char *args[] = {"ls", "-l", "/", NULL};
    execv("/bin/ls", args);
    return 1;
}