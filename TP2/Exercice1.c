#include<string.h>
#include <stdlib.h>

#define TAILLECHAINE 12 // Constante déclarée à 12

char  s0[10] = "numero 1"; // Tableau de char déclaré à 10 char
char* s1     = "numero 2"; // Pointeur qui pointe sur une constante

// s0 & s1 sont des variables globales

char* cree_copie_chaine(char*src)
{
    char* copie; //Copie est de type pointeur en char
    copie = (char*) malloc (strlen(src)+1); //+1 Pour prévoir une place pour le \o
    strcpy (copie , src); /* copie=destination, src=source*/
    return copie; //On retourne le pointeur sur la chaîne copiée
}
int main()
{
    char s2[TAILLECHAINE];
    char s3[]="numero 3";
    char *pa, *pb, *pc, *pe;
    pa = s1;
    pb = s0;
    strcpy (s2, "A + tard");
    pc = cree_copie_chaine(s0);
    pe = "numero 4";
    free(pc);
    return 0;
}
