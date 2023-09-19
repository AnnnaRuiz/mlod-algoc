
#include <stdio.h> //printf
#include <stdlib.h> //EXIT_SUCCESS
#include <stdbool.h> //bool
#include <stdint.h> //uint8_t, uint64_t,...

typedef short TypeEntier;
TypeEntier factorielle(TypeEntier);

TypeEntier factorielle(TypeEntier n){
    TypeEntier facto = 1;
    for (int i=1; i<n ; i++){
        facto*=i;
    }
    return facto;
}


int main (void){
    TypeEntier nombre = 6;

    printf("Le factoriel de %u est : %u \n", nombre, factorielle(nombre));

}