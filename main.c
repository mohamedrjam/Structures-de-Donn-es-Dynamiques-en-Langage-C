#define _CRT_SECURE_NO_WARNINGS
#include "biblio.h"

void clearMsg() { printf("\nAppuyez sur Entrer..."); getchar(); getchar(); }

int main() {
    int main_choice, sub_choice, val, pos;

    do {
        printf("\n--- GESTION DE STRUCTURES ---\n");
        printf("1. Tester Liste\n2. Tester File\n3. Tester Pile\n0. Quitter\nChoix: ");
        scanf("%d", &main_choice);

        if (main_choice == 1) {
            MaListe* L = initialiserListe();
            do {
                printf("\n--- MENU LISTE ---\n");
                afficherMaListe(L);
                printf("1. Ajouter Fin\n2. Ajouter Debut\n3. Supprimer valeur\n0. Retour\nChoix: ");
                scanf("%d", &sub_choice);
                if (sub_choice == 1) { printf("Valeur: "); scanf("%d", &val); insererFin(L, val); }
                if (sub_choice == 2) { printf("Valeur: "); scanf("%d", &val); insererDebut(L, val); }
                if (sub_choice == 3) { printf("Valeur: "); scanf("%d", &val); supprimerValeur(L, val); }
            } while (sub_choice != 0);
            supprimerMaListe(&L);
        }
        else if (main_choice == 2) {
            MaFile* F = initialiserFile();
            do {
                printf("\n--- MENU FILE (FIFO) ---\n");
                afficherMaFile(F);
                printf("1. Enfiler\n2. Defiler\n0. Retour\nChoix: ");
                scanf("%d", &sub_choice);
                if (sub_choice == 1) { printf("Valeur: "); scanf("%d", &val); ajouterFile(F, val); }
                if (sub_choice == 2) { if (retirerFile(F, &val)) printf("Sortie: %d\n", val); }
            } while (sub_choice != 0);
            supprimerMaFile(&F);
        }
        else if (main_choice == 3) {
            MaPile* P = initialiserPile();
            do {
                printf("\n--- MENU PILE (LIFO) ---\n");
                afficherMaPile(P);
                printf("1. Empiler\n2. Depiler\n0. Retour\nChoix: ");
                scanf("%d", &sub_choice);
                if (sub_choice == 1) { printf("Valeur: "); scanf("%d", &val); pousserPile(P, val); }
                if (sub_choice == 2) { if (tirerPile(P, &val)) printf("Sortie: %d\n", val); }
            } while (sub_choice != 0);
            supprimerMaPile(&P);
        }

    } while (main_choice != 0);

    return 0;
}