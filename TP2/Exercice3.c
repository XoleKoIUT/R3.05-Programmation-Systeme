#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * construireChaineInverse(char * str);
int main()
{
   char chaine[20];
   printf("Donnez une chaine de caractères : ");
   scanf("%s", chaine);
   printf("L'inverse de la chaine : %s\n", construireChaineInverse(chaine));
   return 0;
}

char * construireChaineInverse(char * str){
    int l = strlen(str);
    char * res = (char *) malloc ((l+1)*sizeof(char));
    
    int i, j;
    for(i = l-1, j = 0; i >= 0; i--, j++){
        res[j] = str[i];
    }
    res[j] = '\0';
    return res;
}
