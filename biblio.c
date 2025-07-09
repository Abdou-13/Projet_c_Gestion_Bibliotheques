int gererEmprunt() {
    int choix;
    printf("\nGestion des emprunts:\n");
    printf("1. Emprunter un livre\n");
    printf("2. Retourner un livre\n");
    printf("Choix: ");
    scanf("%d", &choix);
    getchar();

    if (choix == 1) {
        int isbn;
        printf("Entrez l'ISBN du livre à emprunter: ");
        scanf("%d", &isbn);
        getchar();

        int livreIndex = -1;
        for (int i = 0; i < bibliotheque.nombreLivres; i++) {
            if (bibliotheque.livres[i].ISBN == isbn) {
                livreIndex = i;
                break;
            }
        }

        if (livreIndex == -1) {
            printf("Livre non trouvé.\n");
            return 0;
        }

        if (bibliotheque.livres[livreIndex].estEmprunte) {
            printf("Ce livre est déjà emprunté.\n");
            return 0;
        }

        char eleve[MAX_CHAR];
        char date[11];

        printf("Nom de l'élève: ");
        fgets(eleve, MAX_CHAR, stdin);
        eleve[strcspn(eleve, "\n")] = 0;

        printf("Date d'emprunt (jj/mm/aaaa): ");
        fgets(date, 11, stdin);
        date[strcspn(date, "\n")] = 0;

        bibliotheque.livres[livreIndex].estEmprunte = true;

        struct Emprunt nouvelEmprunt = { .ISBN = isbn };
        strcpy(nouvelEmprunt.eleve, eleve);
        strcpy(nouvelEmprunt.date, date);
        bibliotheque.emprunts[bibliotheque.nombreEmprunts++] = nouvelEmprunt;

        printf("Livre emprunté avec succès.\n");
        return 1;

    } else if (choix == 2) {
        int isbn;
        printf("Entrez l'ISBN du livre à retourner: ");
        scanf("%d", &isbn);
        getchar();

        int livreIndex = -1;
        for (int i = 0; i < bibliotheque.nombreLivres; i++) {
            if (bibliotheque.livres[i].ISBN == isbn) {
                livreIndex = i;
                break;
            }
        }

        if (livreIndex == -1) {
            printf("Livre non trouvé.\n");
            return 0;
        }

        if (!bibliotheque.livres[livreIndex].estEmprunte) {
            printf("Ce livre n'est pas emprunté.\n");
            return 0;
        }

        bibliotheque.livres[livreIndex].estEmprunte = false;
        printf("Livre retourné avec succès.\n");
        return 1;

    } else {
        printf("Choix invalide.\n");
        return 0;
    }
}

