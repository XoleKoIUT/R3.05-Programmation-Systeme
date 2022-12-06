/*Ecrire une commande lspathi qui comme lspath2 liste chacun des répertoires de la variable PATH après avoir affiché le nom du répertoire ; mais demande pour chaque répertoire l'option à appliquer à la commande ls.
L'utilisateur a les réponses possibles suivantes :

    "réponse vide" ----> pas d'option
    code de l'option (sans tiret)
    quit ---> arrêt du programme
    next ---> pas de listage et passage au répertoire suivant
    prec ---> pas de listage et retour au répertoire précedent.

La saisie des réponses sera réalisée par le processus fils.
Les 3 derniers cas seront traités par : exit(code_retour), la valeur du code_retour permet de spécifier le cas. Elle est récupérée par le processus père afin de contrôler les itérations sur les différents répertoires.
Dans les 2 premiers cas la commande ls est exécutée, le code de retour récupéré par le processus père est donc celui rendu par ls.
Dans le cas d'une erreur du ls, par exemple pour option non valide, la liste des options sera affichée par :
ls --help*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char  *s = getenv("PATH"); //on récupère la variable PATH du shell
    char  *tpath[60];
    int   i, status, ret;
    char  *chemin;
    pid_t pid;
    char  opt[20], tiretopt[50];

    if (s == NULL)
    {
        fprintf(stderr, "%s Impossible de trouver la variable PATH \n", argv[0]);
        exit(1);
    }

    chemin = strdup(s); //réserve de la mémoire pour la copie de la variable PATH

    //décomposition des différents chemins
    tpath[0] = strtok(chemin, ":"); //on traite le 1er cas séparément
    for (int i = 1; (tpath[i]=strtok(NULL, ":")) != NULL; i++);
    //on traite les autres cas; LE POINT VIRGULE EST IMPORTANT (instruction vide))

    //affichage des différents chemins

    i = 0;
    while (tpath[i] != NULL)
    {
        pid = fork();

        if (pid == -1)
        {
            perror("fork a échoué");
            exit(33);

        }

        if (pid == 0)
        {
            printf(" %s\n", tpath[i]);

            printf("Entrez une option pour ls : ");

            fgets(opt, 20, stdin);
            opt[strlen(opt)-1] = '\0'; //on enlève le retour chariot


            if (strcmp(opt, "quit") == 0) exit(1);
            if (strcmp(opt, "prec") == 0) exit(3);
            if (strcmp(opt, "next") == 0) exit(4);

            if (strlen(opt) == 0) //si l'utilisateur n'a pas entré d'option
            {
                execlp("ls", "ls", tpath[i], NULL);
                perror("execl(ls)");
                exit(1);
            }
            else
            {
                /*strcpy(tiretopt, "-");
                strcat(tiretopt, opt);*/

                sprintf(tiretopt, "-%s", opt); //on concatène les 2 chaines

                //on exécute la commande ls avec l'option entrée par l'utilisateur
                execlp("ls", "ls", tiretopt, tpath[i], NULL);

                perror("execl(ls)");
                exit(1);
            }
        }
        else
        {
            wait(&status);

            if (WIFEXITED(status)) //si le fils s'est terminé normalement
                ret = WEXITSTATUS(status); //on récupère le code de retour
            else ret = 1;

            if ( ret == 1) exit(1); //si le fils a renvoyé 1, on quitte le programme
            if ((ret == 3) && (i> 0)) { i--; continue; } //si le fils a renvoyé 3, on revient au répertoire précédent
            if ((ret == 3) && (i == 0)) { continue;} //si on est au 1er répertoire, on ne fait rien
            if ( ret == 2)
            {
                if((pid=fork())< 0) //on crée un processus fils car on ne peut pas faire 2 execl dans le même processus
                {
                    perror("fork a échoué)");
                    exit(3);
                }
                else if (pid == 0)
                {
                    execlp("ls", "ls", "--help", NULL); //on affiche la liste des options car l'utilisateur a entré une option non valide
                    perror("execl(ls)");
                    exit(1);
                }
                else
                {
                    i--;
                    wait(NULL);
                }
            }

            i++;

        }
    }

    return 0;


}
