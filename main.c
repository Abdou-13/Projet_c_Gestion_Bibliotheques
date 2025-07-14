#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblio.h"

int main()
{
     int choix;

    do {
        afficherMenu();
        scanf("%d", &choix);
        getchar();

        switch(choix) {
            case 1: enregistrerLivre();
               break;
            case 2: afficherLivres();
               break;
            case 3: rechercherLivre();
               break;
            case 4: supprimerLivre();
               break;
           case 5: gererEmprunt();
               break;
           case 6: afficherStatistiques();
               break;
           case 0: printf("Merci d'avoir utilise notre bibliotheque!!\n"); 
               break;
            default: printf("Choix invalide.\n");
        }
    } while(choix != 0);

    return 0;


}

