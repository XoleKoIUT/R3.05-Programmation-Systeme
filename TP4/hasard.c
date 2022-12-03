#include <stdio.h>
#include <stdlib.h>

int main() {
    int nbRdm;

    if(fork() < 3){
        nbRdm = rand() % 255 + 1;
        printf("%d\n", nbRdm);
    }
return 0;
}