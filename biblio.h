#define _CRT_SECURE_NO_WARNINGS
#ifndef BIBLIO_H
#define BIBLIO_H

#include <stdio.h>
#include <stdlib.h>

/* --- Structure de base pour les éléments --- */
typedef struct Element {
    int info;
    struct Element* suivant;
} Element;

/* --- Structure pour la Liste Simple --- */
typedef struct {
    Element* premier;
    int nb_elements;
} MaListe;

MaListe* initialiserListe();
void insererDebut(MaListe* L, int val);
void insererFin(MaListe* L, int val);
void insererA(MaListe* L, int val, int pos);
int supprimerValeur(MaListe* L, int val);
void viderMaListe(MaListe* L);
int positionDe(MaListe* L, int val);
void afficherMaListe(MaListe* L);
void supprimerMaListe(MaListe** L);

/* --- Structure pour la File (FIFO) --- */
typedef struct {
    Element* debut;
    Element* fin;
    int taille;
} MaFile;

MaFile* initialiserFile();
void ajouterFile(MaFile* F, int val);
int retirerFile(MaFile* F, int* res);
int estVideFile(MaFile* F);
void viderMaFile(MaFile* F);
void afficherMaFile(MaFile* F);
void supprimerMaFile(MaFile** F);

/* --- Structure pour la Pile (LIFO) --- */
typedef struct {
    Element* haut;
    int taille;
} MaPile;

MaPile* initialiserPile();
void pousserPile(MaPile* P, int val);
int tirerPile(MaPile* P, int* res);
int estVidePile(MaPile* P);
void viderMaPile(MaPile* P);
void afficherMaPile(MaPile* P);
void supprimerMaPile(MaPile** P);

#endif