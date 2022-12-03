#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    unsigned char jour;
    char mois[10];
    unsigned short annee;
} date;

int numeroMois(char *nomMois)
{
    char *tabMois[] = {"janvier", "fevrier", "mars", "avril", "mail", "juin", "juillet", "aout", "septembre", "octobre", "novembre", "décembre"};

    int i;
    for (i = 0; i < 12; i++)
        if (strcmp(tabMois[i], nomMois) == 0)
            return i + 1;
    return -1;
}

void afficherDate(date d)
{
    printf("%2hu    %s    %4hu\n", d.jour, d.mois, d.annee);
}

void demandeDate(date *dp)
{
    do
    {
        printf("Jour ?");
        scanf("%hu", &(dp->jour));
    } while ((dp->jour < 1) || (dp->jour > 31)); // dp->jour === (*dp).jour

    do
    {
        printf("Mois ?");
        scanf("%s", &(dp->mois));
    } while (numeroMois(dp->mois) == -1); // dp->mois === (*dp).mois

    printf("Année ?");
    scanf("%hu", &(dp->annee));
}

int main()
{

    date date1 = {13, "Octobre", 2022}, date2, date3;
      demandeDate(&date2);
  
      printf("La date: ");
      afficherDate(date1);
      demandeDate(&date3);
      
      printf("La date : ");
      afficherDate(date2);
      
      printf("La date : ");
      afficherDate(date3);
  
      return EXIT_SUCCESS;
}
