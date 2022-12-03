#include <stdio.h>
int val1, val2;
int temp;

void permut(int val1, int val2, int temp){
    val1=5;
    val2=10;
    
    printf("Avant Permutation : \n",val1);
    printf("Valeur1 : %d\n",val1);
    printf("Valeur2 : %d\n",val2);
    
    temp = val1;
    val1 = val2;
    val2 = temp;
    
    printf("Après Permutation : \n",val1);
    printf("Valeur1 : %d\n",val1);
    printf("Valeur2 : %d\n",val2);
}
int main(){
    permut(val1, val2, temp);
    return 0;
}
