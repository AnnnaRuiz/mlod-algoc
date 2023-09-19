#include <stdio.h> //printf
#include <stdlib.h> //EXIT_SUCCESS
#include <stdbool.h> //bool
#include <stdint.h> //uint8_t, uint64_t,...

int sommeDiviseurs(uint64_t nombre){
    long somme=0;
    for (int i=0; i<=nombre/2;i++){
        if(nombre%i==0){
            somme+=i;
        }
    }
    return somme;
}

bool estUnNombreParfait(int n){
    return sommeDiviseurs(n)==n;
}

int main (void){
    uint32_t nbParfaitATrouver = 3;
    printf("%u premiers nombres parfaits: \n ", nbParfaitATrouver);

    uint8_t nbParfaitTrouve=0;
    uint64_t nombre = 20;
    while (nbParfaitTrouve<nbParfaitATrouver){
        if(estUnNombreParfait(nombre)){
            printf("%llu", nombre);
            nbParfaitATrouver+=1;
        }
    }
}