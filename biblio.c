 #include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LIVRES 100
#define MAX_CHAR 100
#define MAX_EMPRUNTS 100
   
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
        system("cls");
        system("color C");
    if (bibliotheque.nombreLivres >= MAX_LIVRES) {
        printf("La bibliothèque est pleine!\n");
        return;
    }

    struct Livre nouveauLivre;

    printf("Titre du livre: ");
    fgets(nouveauLivre.titre, MAX_CHAR, stdin);
    nouveauLivre.titre[strcasecmp(nouveauLivre.titre, "\n")] = 0;

    printf("Auteur: ");
    fgets(nouveauLivre.auteur, MAX_CHAR, stdin);
    nouveauLivre.auteur[strcasecmp(nouveauLivre.auteur, "\n")] = 0;

    do {
        printf("Annee de publication: ");
        scanf("%d", &nouveauLivre.anneePublication);
    } while (nouveauLivre.anneePublication < 1000 || nouveauLivre.anneePublication > 2025);

    do {
        printf("Code ISBN (5 chiffres): ");
        scanf("%d", &nouveauLivre.ISBN);
        getchar();
    } while (nouveauLivre.ISBN < 10000 || nouveauLivre.ISBN > 99999);

    nouveauLivre.estEmprunte = false;

    bibliotheque.livres[bibliotheque.nombreLivres++] = nouveauLivre;
    printf("Livre ajoute avec succes!\n");

    system("pause");
    system("cls");
}
void rechercherLivre() {
    system("cls");
    system("color A");
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
        printf("Aucun livre disponible ne correspond a votre recherche.\n");
    }
    system("pause");
    system("cls");
}
