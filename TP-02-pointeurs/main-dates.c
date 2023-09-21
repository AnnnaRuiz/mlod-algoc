#include "02-dates.h"

int main(void){
    Date d;

    initialiseDate(&d); // on a ajouté & pour modifier le d et non sa copie.
    afficheDate(&d);

/*
    d=creerDateParCopie();
    afficheDate(&d);
*/
/*
    Date *date;
    date = newDate();
    afficheDate(date); //...
    free(date);
*/
/*
vérifier si le code dateValide(d) fonctionne :

    Date d = {30, 4, 2024};
    if (dateValide(d)) {
        printf("La date est valide.\n");
    } else {
        printf("La date n'est pas valide.\n");
    }
    return 0;
*/
/*
    unsigned int j;
    j= jourDansAnnee(d);
    printf("c'est le jour numéro : %u\n", j);
*/
}