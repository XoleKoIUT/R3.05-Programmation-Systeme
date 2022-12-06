/* Demander à l'utilisateur deux nombres, les mémoriser dans deux variables, multiplier leurs valeurs en affectant
 * le résultat à) une troisième variable, puis l'afficher
 */

#include <stdio.h>  // Inclure la bibliothèque STanDard Input Output
// permet d'utiliser, entre autre, printf et scanf
int main() {
    int nb1, nb2, resultat; // Entiers : nb1, nb2, resultat

    printf("Produit de deux entiers\n"); // Afficher : "Produit de deux entiers"

    printf("Entrez un nombre entier : "); // Afficher : "Entrez un nombre entier : "
    scanf("%d", &nb1);    // Entrer : nb1

    printf("Entrez un deuxieme nombre entier : "); // Afficher : "Entrez un deuxieme nombre entier : "
    scanf("%d", &nb2);    // Entrer : nb2

    resultat = nb1 * nb2; // resultat <-- nb1 * nb2;

    printf("\n%d x %d = %d\n", nb1, nb2, resultat); // Afficher : "nb1 x nb2 = resultat"

    return 0;
}