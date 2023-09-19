#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

uint16_t squareOfSum(uint16_t n){
    uint16_t sum = 0;
    for (int i=1; i<=n; i++){
        sum += i;
    }
    return pow(sum,2);
}

uint16_t sumOfSquares(uint16_t n){
    uint16_t sum = 0;
    for (int i=1; i<=n; i++){
        sum += pow(i,2);
    }
    return sum;
}

uint16_t difference(uint16_t n){
    return (squareOfSum(n) - sumOfSquares(n));
}

int main (void){
    uint16_t number= 10;
    printf("Difference between squareOfSum of first %"PRIu16, number);
    printf(" natural numbers and its sumOfSquares : %"PRIu16"\n", difference(number));
    return 0;
}
