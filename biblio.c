void afficherLivres() {
    system("cls");
    system("color B");
   int trouves = 0;
    printf("\n=== Livres disponibles ===\n");
    for (int i = 0; i < bibliotheque.nombreLivres; i++) {
        if (!bibliotheque.livres[i].estEmprunte) {
            printf("%d. %s - %s (%d) [ISBN: %d]\n",
                   i + 1,
                   bibliotheque.livres[i].titre,
                   bibliotheque.livres[i].auteur,
                   bibliotheque.livres[i].anneePublication,
                   bibliotheque.livres[i].ISBN);
            trouves++;
        }
    }
    if (trouves == 0)
        printf("Aucun livre disponible.\n");

  
