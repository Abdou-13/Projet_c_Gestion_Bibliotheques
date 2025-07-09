int supprimerLivre() {
    system("cls");
    system("color 5");
    int isbn;
    printf("Entrez le code ISBN du livre à supprimer: ");
    scanf("%d", &isbn);
    getchar();

    int index = -1;

    for (int i = 0; i < bibliotheque.nombreLivres; i++) {
        if (bibliotheque.livres[i].ISBN == isbn) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Aucun livre trouve.\n");
        return 0;
    }

    for (int i = index; i < bibliotheque.nombreLivres - 1; i++) {
        bibliotheque.livres[i] = bibliotheque.livres[i + 1];
    }

    bibliotheque.nombreLivres--;
    printf("Livre supprime.\n");
    return 1;

    system("pause");
    system("cls");
}
