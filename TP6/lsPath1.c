                           #include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
Ecrire une commande  lspath1 qui liste tous les répertoires de la variable PATH .
On utilisera la forme à plusieurs répertoires : ls rep1  rep2  rep3 ...
*/

int main(int argc, char *argv[])
{
    char *tpath[60];
    char *s, *chemin;
    int  i;

    /* Récuperation de la variale d'environnement PATH avec la fonction getenv("PATH") */
    if((s = getenv("PATH")) == NULL){
        fprintf(stderr, "%s variable PATH inaccessible\n", argv[0]);
        perror("stderr");
    }

    chemin = strdup(s);
    /* La fonction strdup réserve la place mémoire et copie la chaine s dans la chaine chemin */
    /* Décomposition des différents chemins */
    tpath[0]= "ls";
    tpath[1]= "-al";
    tpath[2]= strtok(chemin, ":");

    for(i = 3; (tpath[i] = strtok(NULL, ":")) != NULL; i++){
        /* Affichage des différents chemins */
        execvp("ls", tpath); // Ou execv("/bin/ls", tpath); si on ne fait pas de copie de chemins

        perror("execvp(ls)");
    }
}