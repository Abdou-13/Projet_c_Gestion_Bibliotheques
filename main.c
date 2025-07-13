#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblio.h"

int main()
{
     int choix;

    do {
        afficherMenu();
        printf("=== Menu de la Bibliotheque ===\n");
        scanf("%d", &choix);
        getchar();

        switch(choix) {
            case 1: enregistrerLivre();
                 printf ("\n");
               break;
            case 2: afficherLivres();
                 printf ("\n");
               break;
            case 3: rechercherLivre();
                  printf ("\n");
               break;
            case 4: supprimerLivre();
                  printf ("\n");
               break;
           case 5: gererEmprunt();
                 printf ("\n");
               break;
           case 6: afficherStatistiques();
                 printf ("\n");
               break;
            case 0: printf("Merci d'avoir utilise notre bibliotheque!!\n"); break;
            default: printf("Choix invalide.\n");
        }
    } while(choix != 0);

    return 0;


}

