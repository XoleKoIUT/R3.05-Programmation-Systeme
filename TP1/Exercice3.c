/*--------------------------------------------------------*
*                    Allocation mémoire                   *
*  Disposition des différentes variables d'un programme   *
*---------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

 int a,b ;

 void fonc(int c , int *d){

        int e,f;
        int *p,*q;
        p=&e ;
        q =(int*) malloc(sizeof(int));
        printf("L'adresse de a :\t%p\n",&a);
        printf("L'adresse de b :\t%p\n",&b);
        printf("L'adresse de c :\t%p\n",&c);
        printf("L'adresse de d :\t%p\n",&d);
        printf("L'adresse de e :\t%p\n",&e);
        printf("L'adresse de p :\t%p\n",&p);
        printf("L'adresse de q :\t%p\n",&q);
        printf("La valeur de p :\t%p\n",p);
        printf("La valeur de q :\t%p\n",q);
        printf("L'adresse de fonc :\t%p\n",&fonc);
}
int main(){

        fonc(a,&b);
        return 0 ;
}
