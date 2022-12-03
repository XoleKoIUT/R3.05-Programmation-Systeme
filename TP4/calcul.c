#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int a, b;
    int etat;

    printf("Veuillez saisir le quotient  : ");
    scanf("%d", &a);

    do {
        printf("Veuillez saisir le dividende : ");
        scanf("%d", &b);
        while(getchar() != '\n'); // Vider le tampon
        int pfils = fork();
        if(pfils == -1){
            perror("Fork a échoué");
            exit(2);
        }
        if(pfils == 0){
            if( b != 0){
                printf("%d / %d = %d \n", a ,b, (a / b));
                exit(0);
            }else {
                exit(1);
            }
        }else {
            wait(&etat);
        }
    } while(b <= 0);

    printf("Au revoir \n");
}