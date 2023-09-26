#include "03-prixTuring.h"
#define maxSize 1000
char buffer[maxSize];

int numberOfWinners (FILE *f){
    int count = 0;
    int c;
    while ((c = fgetc(f)) != EOF) {
        if (c == '\n') {
            count++; 
        }
    }
    rewind(f);
    return count;
}

char* readStringFromFileUntil(FILE* f, char caract){
    char* cp;
    char c;
    int i=0;
    memset(buffer, 0, maxSize);
    while((c = (char) fgetc(f))!=caract){
        buffer[i]=c;
        i++;
    }
    buffer[i+1] = '\0';
    cp = (char*)calloc(i+2, sizeof(char));
    for(int b=0; buffer[b]!='\0'; b++){
        cp[b]=buffer[b];
    }
    cp[i+2]='\0';
    return cp;

}

void readWinner(TuringWinner* winner, FILE *f){
    fscanf(f, "%u;", &winner->annee);
    printf("%u \n", winner->annee);
    winner->noms=readStringFromFileUntil(f,';');
    printf("%s \n", winner->noms);
    winner->description=readStringFromFileUntil(f,'\n');
    printf("%s \n", winner->description);
}
/*
TuringWinner* readWinners(int numberOfTuringWInner, FILE* f){

}



void printWinners(TuringWinner* s){

}
*/