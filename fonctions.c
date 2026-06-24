#define _CRT_SECURE_NO_WARNINGS
#include "biblio.h"

/* --- Implémentation LISTE --- */
MaListe* initialiserListe() {
    MaListe* L = (MaListe*)malloc(sizeof(MaListe));
    if (L) { L->premier = NULL; L->nb_elements = 0; }
    return L;
}

void insererDebut(MaListe* L, int val) {
    Element* nouveau = (Element*)malloc(sizeof(Element));
    nouveau->info = val;
    nouveau->suivant = L->premier;
    L->premier = nouveau;
    L->nb_elements++;
}

void insererFin(MaListe* L, int val) {
    Element* nouveau = (Element*)malloc(sizeof(Element));
    nouveau->info = val;
    nouveau->suivant = NULL;
    if (!L->premier) L->premier = nouveau;
    else {
        Element* temp = L->premier;
        while (temp->suivant) temp = temp->suivant;
        temp->suivant = nouveau;
    }
    L->nb_elements++;
}

void insererA(MaListe* L, int val, int pos) {
    if (pos <= 0) { insererDebut(L, val); return; }
    if (pos >= L->nb_elements) { insererFin(L, val); return; }

    Element* nouveau = (Element*)malloc(sizeof(Element));
    nouveau->info = val;
    Element* p = L->premier;
    for (int i = 0; i < pos - 1; i++) p = p->suivant;
    nouveau->suivant = p->suivant;
    p->suivant = nouveau;
    L->nb_elements++;
}

int supprimerValeur(MaListe* L, int val) {
    if (!L->premier) return 0;
    Element* p = L->premier, * prec = NULL;
    while (p && p->info != val) {
        prec = p;
        p = p->suivant;
    }
    if (!p) return 0;
    if (!prec) L->premier = p->suivant;
    else prec->suivant = p->suivant;
    free(p);
    L->nb_elements--;
    return 1;
}

void viderMaListe(MaListe* L) {
    Element* p = L->premier;
    while (p) {
        Element* tmp = p;
        p = p->suivant;
        free(tmp);
    }
    L->premier = NULL;
    L->nb_elements = 0;
}

void afficherMaListe(MaListe* L) {
    Element* p = L->premier;
    printf(" [ ");
    while (p) {
        printf("%d ", p->info);
        p = p->suivant;
    }
    printf("]\n");
}

void supprimerMaListe(MaListe** L) {
    if (*L) { viderMaListe(*L); free(*L); *L = NULL; }
}

/* --- Implémentation FILE --- */
MaFile* initialiserFile() {
    MaFile* F = (MaFile*)malloc(sizeof(MaFile));
    F->debut = F->fin = NULL;
    F->taille = 0;
    return F;
}

void ajouterFile(MaFile* F, int val) {
    Element* nouveau = (Element*)malloc(sizeof(Element));
    nouveau->info = val;
    nouveau->suivant = NULL;
    if (!F->fin) F->debut = F->fin = nouveau;
    else { F->fin->suivant = nouveau; F->fin = nouveau; }
    F->taille++;
}

int retirerFile(MaFile* F, int* res) {
    if (!F->debut) return 0;
    Element* tmp = F->debut;
    *res = tmp->info;
    F->debut = F->debut->suivant;
    if (!F->debut) F->fin = NULL;
    free(tmp);
    F->taille--;
    return 1;
}

void afficherMaFile(MaFile* F) {
    Element* p = F->debut;
    while (p) { printf("[%d]->", p->info); p = p->suivant; }
    printf("SORTIE\n");
}

void supprimerMaFile(MaFile** F) {
    int v; while (retirerFile(*F, &v));
    free(*F); *F = NULL;
}

/* --- Implémentation PILE --- */
MaPile* initialiserPile() {
    MaPile* P = (MaPile*)malloc(sizeof(MaPile));
    P->haut = NULL; P->taille = 0;
    return P;
}

void pousserPile(MaPile* P, int val) {
    Element* nouveau = (Element*)malloc(sizeof(Element));
    nouveau->info = val;
    nouveau->suivant = P->haut;
    P->haut = nouveau;
    P->taille++;
}

int tirerPile(MaPile* P, int* res) {
    if (!P->haut) return 0;
    Element* tmp = P->haut;
    *res = tmp->info;
    P->haut = tmp->suivant;
    free(tmp);
    P->taille--;
    return 1;
}

void afficherMaPile(MaPile* P) {
    Element* p = P->haut;
    while (p) { printf("| %d |\n", p->info); p = p->suivant; }
    printf(" ----\n");
}

void supprimerMaPile(MaPile** P) {
    int v; while (tirerPile(*P, &v));
    free(*P); *P = NULL;
}