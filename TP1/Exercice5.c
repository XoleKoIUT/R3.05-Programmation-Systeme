#include <stdio.h>
#include <stdlib.h>             /* à compléter pour malloc() et free */
#include <assert.hq>             /* à compléter pour assert() */
int main(){
         int x=1; //Simple variable en entier
         int * y; // Pointeur en int
         int ** z; // Tableau de pointeur sur des entiers
         y = &x ;   /* initialisation du pointeur y */
         z = (int**) malloc(2*sizeof(int*));
         assert(z != NULL); // Vérifie si le malloc a bien alloué de la mémoire à z
         z[0] = y; // y contient l'adresse de x
         x = 2; 
         z[1] = y; // y contient l'adresse de x
         printf("*z[0]=%d\t\t*z[1]=%d\n", *z[0], *z[1]);
         free (z);
         return 0;
}
