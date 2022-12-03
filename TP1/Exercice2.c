#include <stdio.h>
int main(){
    int a, b;
    int *p,*q;
    a=12;
    b=2+a/4 ;
    p=&a ;
    printf("*p = %d\t a = %d\n",*p,a);
    *p=*p + 5 ;
    printf("*p = %d\t a = %d\n",*p,a);
    a= a-7;
    printf("*p = %d\t a = %d\n",*p,a);
    q=p ;
    p=&b ;
    printf("*p = %d\t *q = %d\n",*p,*q);
    printf("a = %d\t b = %d\n",a,b);
    q=p ;
    a=a+a ;
    printf("*p = %d\t *q = %d\n",*p,*q);
    printf("a = %d\t b = %d\n",a,b);
    return 0;
}
