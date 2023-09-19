
#include <stdio.h> //printf
#include <stdlib.h> //EXIT_SUCCESS
#include <stdbool.h> //bool
#include <stdint.h> //uint8_t, uint64_t,...

typedef unsigned long long TypeEntier;
TypeEntier factorielle(TypeEntier);

TypeEntier factorielle(TypeEntier n){
    TypeEntier facto = 1;
    for (int i=1; i<=n ; i++){
        facto*=i;
    }
    return facto;
}


int main (void){
    TypeEntier nombre = 15;
    for (int i=1; i <= nombre; i++){
        printf("Le factoriel de %u est : %llu \n",i, factorielle(i));
    }
}

/*
On remarque qu'avec le type "short" on n'obtient pas les bons résultats pour factorielle à partir de 8.
Cela est du à un problème de mémoire ? La mémoire allouée à ce type est trop petite.
Avec le type "unsigned long long" on obtient le bon résultat
 */