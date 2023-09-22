#pragma once
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct {
    uint16_t nbLignes;
    uint16_t nbColonnes;
    int** valeurs;
}Matrice;

Matrice* creer(int valeurInitiale , uint16_t nbrLignes, uint16_t nbColonnes);

void afficher(Matrice* m);

void initialiserLigne(int valeur, uint16_t indiceLigne, Matrice* m);

Matrice* multiplier(Matrice* m1, Matrice* m2);

void detruire(Matrice* m);