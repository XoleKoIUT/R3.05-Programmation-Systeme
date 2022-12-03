#include<stdio.h>

#define ROUGE(c) printf("\033[31m%c\033[0m",c)
int main()
{
    char ligne[50];
    char c, *s;
    puts("Saisir la date du jour : ");
    if( fgets(ligne, 50, stdin) == NULL ){
        printf("Erreur de lecturre \n");
        return 1;
    }
    
    s=ligne;
    while ( *s != '\0') {
        if(*s >= '0' && *s<='9')
            ROUGE(*s);
        else
            putchar(*s);
        s++;
    }
    return 0;
}
