#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

#define SIZE 5

void matrix_mult(int64_t matR[][SIZE], int64_t mat1[][SIZE],int64_t mat2[][SIZE]){
    for (int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE;j++){
            int64_t somme = 0;
            for(int k=0; k<SIZE; k++){
                somme+=mat1[i][k]*mat2[k][j];
            }
            matR[i][j]=somme;
        }
    }
}

void matrix_print (int64_t matR[SIZE][SIZE]){
    for (int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE;j++){
            printf("%" PRId64" \t",matR[i][j]);
        }
        printf(" \n");
    }
}

int main(void){
    // en C on ne peut omettre qu'une seule dimension. 
    //On n'aurait pas pu faire l'inverse. 
    //Il faut mettre la dimension la plus interne
    int64_t matrice1[][SIZE]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    int64_t matrice2[][SIZE]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
    int64_t matriceResultat [SIZE][SIZE]; // c'est un tableau donc c'est l'adresse de la première case

    matrix_mult(matriceResultat,matrice1,matrice2);
    matrix_print(matriceResultat);

    return EXIT_SUCCESS;
}

/*
pb : taille ? 
*/
