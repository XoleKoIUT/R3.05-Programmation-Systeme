/*---------------------------------------------------------------------------*
*                       Occupation mémoire                                   *
* Place occupée par les différentes variables d'un programme selon leur type *
*----------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
int main(){
    char chaine[]="abcd";
    char c='a';
    printf("Taille de \"a\"  :\t%lu\n",sizeof("a"));
    printf("Taille de char  :\t%lu\n",sizeof(char));
    printf("Taille de int   :\t%lu\n",sizeof(int));
    printf("Taille de short :\t%lu\n",sizeof(short));
    printf("Taille de long  :\t%lu\n",sizeof(long));
    printf("Taille de float :\t%lu\n",sizeof(float));
    printf("Taille de double:\t%lu\n",sizeof(double));
    printf("Taille de 1 :\t%lu\n",sizeof(1));
    printf("Taille de 'a':\t%lu\n",sizeof('a'));
    printf("Taille de c :\t%lu\n",sizeof(c));
    printf("Taille de '\\n':\t%lu\n",sizeof('\n'));
    printf("Taille de chaine:\t%lu\n",sizeof(chaine));
    printf("Longueur de la chaine:\t%lu\n",strlen(chaine));
    return 0;
}
