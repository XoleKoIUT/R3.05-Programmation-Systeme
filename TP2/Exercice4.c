#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char date[11];
char * chaineDate(char * str);
int main()
{
   printf("Donnez une cdate sous forme jj/mm/aaaa : ");
   scanf("%s", date);
}

char * chaineDate(char * str){
    
    char * tabMois[] = {"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin",
                        "Juillet", "Aout", "Septembre", "Octobre", "Novembre",
                        "Decembre"};
    
    char * jour  = strtok(date, "/");
    char * mois  = strtok(NULL, "/");
    char * annee = strtok(NULL, "/");
    int numJour = atoi(jour);
   
    if(numJour < 1 || numJour > 31 ) {
        printf("Jour invalide \n");
        return 1;
    }
    
    int numMois = atoi(mois);
    if(numMois < 1 || numJour > 12 ) {
        printf("Mois invalide \n");
        return 2;
    }
    
    printf("Date est : %d %s %s\n", numJour, numMois, tabMois[numMois-1], annee);
    return 0;
}
