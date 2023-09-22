#include "02-matrice-malloc.h"

int main (void){
    Matrice *A, *B;
    Matrice *AmultB;

    A=creer(1,2,3);
    B=creer(1,3,3);
    initialiserLigne(2,1,A);
    initialiserLigne(2,2,B);

    AmultB=multiplier(A,B);

    afficher(A);
    detruire(A);
    printf("\n");
    afficher(B);
    detruire(B);
    printf("\n");
    afficher(AmultB);
    detruire(AmultB);

    return 0;
}