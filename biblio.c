 #include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LIVRES 100
#define MAX_CHAR 100
#define MAX_EMPRUNTS 100

struct Livre {
    char titre[MAX_CHAR];
    char auteur[MAX_CHAR];
    int anneePublication;
   int ISBN ;
    bool estEmprunte;
};

struct Emprunt {
    int ISBN;
    char eleve[MAX_CHAR];
    char date[11];
};

struct Bibliotheque {
    struct Livre livres[MAX_LIVRES];
    struct Emprunt emprunts[MAX_EMPRUNTS];
    int nombreLivres;
    int nombreEmprunts;
};


struct Bibliotheque bibliotheque = { .nombreLivres = 0, .nombreEmprunts = 0 };
void afficherMenu() {
    printf("\n");
    printf("\033[1;34m.-----------------------------------------.\033[0m\n");
    printf("\033[1;34m|\033[1;35m     GESTION DE BIBLIOTHEQUE SCOLAIRE   \033[1;34m|\033[0m\n");
    printf("\033[1;34m|-----------------------------------------|\033[0m\n");
    printf("\033[1;34m|                                         |\033[0m\n");
    printf("\033[1;34m|\033[0m  \033[1;33m1.\033[0m [\033[1;32mAjout\033[0m] Enregistrer un nouveau livre\033[1;34m|\033[0m\n");
    printf("\033[1;34m|\033[0m  \033[1;33m2.\033[0m [\033[1;32mListe\033[0m] Consulter tous les livres\033[1;34m   |\033[0m\n");
    printf("\033[1;34m|\033[0m  \033[1;33m3.\033[0m [\033[1;32mRecherche\033[0m] Trouver un ouvrage\033[1;34m      |\033[0m\n");
    printf("\033[1;34m|\033[0m  \033[1;33m4.\033[0m [\033[1;31mSuppression\033[0m] Retirer un livre\033[1;34m      |\033[0m\n");
    printf("\033[1;34m|\033[0m  \033[1;33m5.\033[0m [\033[1;36mEmprunts\033[0m] Gestion des prets\033[1;34m        |\033[0m\n");
    printf("\033[1;34m|\033[0m  \033[1;33m6.\033[0m [\033[1;35mStats\033[0m] Afficher les statistiques\033[1;34m   |\033[0m\n");
    printf("\033[1;34m|                                         |\033[0m\n");
    printf("\033[1;34m|\033[0m  \033[1;33m0.\033[0m Quitter le programme\033[1;34m                |\033[0m\n");
    printf("\033[1;34m|                                         |\033[0m\n");
    printf("\033[1;34m'-----------------------------------------'\033[0m\n");
    printf("\n");
    printf("Votre choix : ");
}
void enregistrerLivre() {
    if (bibliotheque.nombreLivres >= MAX_LIVRES) {
        printf("La bibliotheque est pleine!\n");
        return;
    }

    struct Livre nouveauLivre;

    printf("Titre du livre: ");
    fgets(nouveauLivre.titre, MAX_CHAR, stdin);
    nouveauLivre.titre[strcspn(nouveauLivre.titre, "\n")] = 0;

    printf("Auteur:");
    fgets(nouveauLivre.auteur, MAX_CHAR, stdin);
    nouveauLivre.auteur[strcspn(nouveauLivre.auteur, "\n")] = 0;

    do {
        printf("Annee de publication:");
        scanf("%d", &nouveauLivre.anneePublication);
    } while (nouveauLivre.anneePublication < 1000 || nouveauLivre.anneePublication > 2025);

    do {
        printf("Code ISBN (5 chiffres): ");
        scanf("%d", &nouveauLivre.ISBN);
        getchar();
    } while (nouveauLivre.ISBN < 10000 || nouveauLivre.ISBN > 99999);

    nouveauLivre.estEmprunte = false;

    bibliotheque.livres[bibliotheque.nombreLivres++] = nouveauLivre;
    printf("Livre ajoute avec succès!\n");
}

void afficherLivres() {
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
}

void rechercherLivre() {
    char terme[MAX_CHAR];
    int choix;

    printf("\nRechercher par:\n1. Titre\n2. Auteur\n");
    printf("Choix: ");
    scanf("%d", &choix);
    getchar();

    printf("Recherche: ");
    fgets(terme, MAX_CHAR, stdin);
    terme[strcspn(terme, "\n")] = 0;

    printf("\n=== Resultats de recherche ===\n");
    int trouve = 0;

    for (int i = 0; i < bibliotheque.nombreLivres; i++) {
        if (!bibliotheque.livres[i].estEmprunte &&
           ((choix == 1 && strstr(bibliotheque.livres[i].titre, terme)) ||
            (choix == 2 && strstr(bibliotheque.livres[i].auteur, terme)))) {
            printf(" %s - %s (%d) [ISBN: %d]\n",
                   bibliotheque.livres[i].titre,
                   bibliotheque.livres[i].auteur,
                   bibliotheque.livres[i].anneePublication,
                   bibliotheque.livres[i].ISBN);
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucun livre disponible ne correspond à votre recherche.\n");
    }
}

int supprimerLivre() {
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
        printf("Aucun livre trouvé.\n");
        return 0;
    }

    for (int i = index; i < bibliotheque.nombreLivres - 1; i++) {
        bibliotheque.livres[i] = bibliotheque.livres[i + 1];
    }

    bibliotheque.nombreLivres--;
    printf("Livre supprime.\n");
    return 1;
}

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
            printf("Ce livre est déjà emprunte.\n");
            return 0;
        }

        char eleve[MAX_CHAR];
        char date[11];

        printf("Nom de l'eleve: ");
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

        printf("Livre emprunte avec succes.\n");
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
            printf("Livre non trouve.\n");
            return 0;
        }

        if (!bibliotheque.livres[livreIndex].estEmprunte) {
            printf("Ce livre n'est pas emprunte.\n");
            return 0;
        }

        bibliotheque.livres[livreIndex].estEmprunte = false;
        printf("Livre retourne avec succes.\n");
        return 1;

    } else {
        printf("Choix invalide.\n");
        return 0;
    }
}

void afficherStatistiques() {
    int totalLivres = bibliotheque.nombreLivres;
    int livresEmpruntes = 0;

    for (int i = 0; i < bibliotheque.nombreLivres; i++) {
        if (bibliotheque.livres[i].estEmprunte) {
            livresEmpruntes++;
        }
    }
 
    printf("\n=== Statistiques de la Bibliotheque ===\n");
    printf("Total de livres: %d\n", totalLivres);
    printf("Livres empruntés: %d\n", livresEmpruntes);
    printf("Livres disponibles: %d\n", totalLivres - livresEmpruntes);
    printf("Nombre total d'emprunts enregistres: %d\n", bibliotheque.nombreEmprunts);
}
