#include "02-dates.h"

void initialiseDate( Date *d){
    printf("Entrer jour :");
    scanf("%d",&d->jour);
    printf(" mois :");
    scanf("%d",(int*)&d->mois);
    printf(" annee :");
    scanf("%d",&d->annee);
}

void afficheDate( Date *d){
    printf("La date est : %d/%d/%d \n", d->jour, d->mois,d->annee);
}

Date creerDateParCopie(void){ //ne devrait pas être utilisée car dès qu'on crée une nouvelle date on occupe un nouvel espace de la mémoire => surcout en mémoire
    Date d;
    printf("Entrer jour :");
    scanf("%d",&d.jour);
    printf(" mois :");
    scanf("%d",(int*)&d.mois);
    printf(" annee :");
    scanf("%d",&d.annee);
    return d;
}

Date* newDate(void){
    Date* date = (Date*)malloc(sizeof(Date)); // Allouer de la mémoire
    printf("Entrer jour :");
    scanf("%d",&date->jour);
    printf(" mois :");
    scanf("%d",(int*)&date->mois);
    printf(" annee :");
    scanf("%d",&date->annee);
    return date;
}

bool estAnneeBissextile(int annee) {
    return (annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0);
}

unsigned int nbreJours(Mois mois, unsigned int annee) {
    switch (mois) {
        case janvier:
        case mars:
        case mai:
        case juillet:
        case aout:
        case octobre:
        case decembre:
            return 31;
        case avril:
        case juin:
        case septembre:
        case novembre:
            return 30;
        case fevrier:
            if (estAnneeBissextile(annee)) {
                return 29; // Si c'est une année bissextile
            } else {
                return 28; // Si ce n'est pas une année bissextile
            }
        default:
            return 0; // Valeur par défaut si le mois est invalide
    }
}

bool dateValide(Date date) {
    if (date.annee < 0) {
        return false; // Année invalide
    }

    if (date.mois < 1 || date.mois > 12) {
        return false; // Mois invalide
    }
    if (date.jour<1 || date.jour>nbreJours(date.mois, date.annee)){
        return false;
    }
    return true; // La date est valide
}

unsigned int jourDansAnnee(Date date) {
    int totalJours = 0;

    // Ajouter les jours des mois précédents
    for (int i = 1; i < date.mois; i++) {
        totalJours += nbreJours((Mois)(i), date.annee); 
    }

    // Ajouter les jours du mois actuel
    totalJours += date.jour;

    return totalJours;
}


