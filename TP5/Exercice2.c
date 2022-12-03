//   Ecrire un programme execmde.c qui lit et exÃ©cute une ligne de commande shell avec ou sans arguments.
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(){
    char com[BUFSIZ];
    printf("Commande shell à executer : ");
    if(fgets(com, BUFSIZ, stdin) != NULL){
        com[strlen(com)-1] ='\0';
        execlp("sh", "sh", "-c", com, NULL);
        /* Oubien l'interpreteur bash
        execlp("bash", "bash", "-c", com, NULL);
        */
        perror("exec");
    }
}