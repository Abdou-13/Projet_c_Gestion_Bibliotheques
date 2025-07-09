
void afficherStatistiques() {
    system("cls");
    system("color 6");
    int totalLivres = bibliotheque.nombreLivres;
    int livresEmpruntes = 0;

    for (int i = 0; i < bibliotheque.nombreLivres; i++) {
        if (bibliotheque.livres[i].estEmprunte) {
            livresEmpruntes++;
        }
    }

    printf("\n=== Statistiques de la Bibliotheque ===\n");
    printf("Total de livres: %d\n", totalLivres);
    printf("Livres empruntes: %d\n", livresEmpruntes);
    printf("Livres disponibles: %d\n", totalLivres - livresEmpruntes);
    printf("Nombre total d'emprunts enregistres: %d\n", bibliotheque.nombreEmprunts);

     system("pause");
    system("cls");
}
=======
 