#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {
janvier=1, fevrier, mars, avril, mai, juin, juillet, aout, 
septembre, octobre, novembre, decembre
} Mois; 

typedef struct {
    int jour;
    Mois mois; 
    int annee;
}Date;

void initialiseDate( Date *d);

void afficheDate( Date *d);

Date creerDateParCopie(void);

Date* newDate(void);

bool estAnneeBissextile(int annee);

unsigned int nbreJours(Mois mois, unsigned int annee);

bool dateValide(Date uneDate);

unsigned int jourDansAnnee(Date uneDate);