#include <stdio.h>
#include "02-echangeContenu.h"

void echangeContenu(int *a, int *b);

int main(void){
    int a=10, b=20;
    printf("avant échange : a=%d\tb=%d\n", a, b);
    echangeContenu(&a,&b);
    printf("après échange : a=%d\tb=%d\n", a, b);
    return 0;
}