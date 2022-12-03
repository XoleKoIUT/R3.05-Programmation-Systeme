/*
Ecrire un programme  qui affiche les caractéristiques suivantes du processus :

    pid
    uid et nom de l'utilisateur correspondant (utiliser les fonctions getuid et getpwuid)

et demande à l'utilisateur  un programme exécutable(avec ou sans paramètres) à exécuter par recouvrement. Dans le cas d'une erreur, le programme affiche le numéro de l'erreur système ( avec la variable extern int errno)et le message d'erreur correspond (avec la fonction strerror(errno))  et demande de nouveau le nom de l'exécutable avec ses paramètres.
Tester différents exécutables. Faites  le test avec le programme affichant les caractéristiques du processus indiquées ci-dessus.

Indication : le programme exécutable et ses paramètres sont séparés par un nombre d'espaces quelconque. Pour récupérer ces différents éléments (tokens) on utilise la fonction strtok.
*/
#define Length 100;
extern int errno;

int main() {
    char *s
    char *args[Length];
    char com[Length];
    char rep;
    int j,i;
    printf("Processus = %d\n", getpid());
    printf("Utilisateur = %d\n", getuid());
    printf("Nom d'utilisateur : %s\n", getpwuid(getuid()) -> pw_name);

    while(1){
        prinf("Programme executable(e)/commande shell(s) ? :");
        rep = getchar();
        /* pour vider le tampon */
        if ( rep != '\n')
            while(getchar() != '\n') {};

        switch(rep){
            case'e' : printf("Executable avec les params");


                        if(fgets(com, Length, stdin) != NULL){
                            com[strlen(com)-1] ='\0'; /* pour supprimer le caractere '\n' */
                            for(j=0, s=com; (s=strtoks(s,"")) != NULL; j++, s=NULL)
                                args[j] = s;

                            args[j] = NULL;
                            execvp(args[0], args);

                        }
                        break;

            case's' : printf("Commande à executer :");

                        if(fgets(com, Length, stdin) != NULL){
                            com[strlen(com)-1] ='\0';
                            execlp("sh", "sh","-c", com, NULL);
                        }

            }
            break;
    }
}