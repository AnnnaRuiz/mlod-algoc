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

void readWinner(TuringWinner* winners, FILE *f){
    fscanf(f, "%u;", &winners->annee);
    winners->noms=readStringFromFileUntil(f,';');
    winners->description=readStringFromFileUntil(f,'\n');
}

TuringWinner* readWinners(FILE* file, int numberOfWinners, TuringWinner* winners) {;
    int i;

    for (i = 0; i < numberOfWinners; i++) {
        readWinner(&winners[i], file);
    }

    return winners;
}
void printWinners(TuringWinner* winners, int numberOfWinners, FILE* outFile) {
    if (outFile == NULL) {
        perror("Erreur lors de l'ouverture du fichier out.csv");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numberOfWinners; i++) {
        fprintf(outFile, "%u;%s;%s\n", winners[i].annee, winners[i].noms, winners[i].description);
    }
}

void infosAnnee(unsigned int year, TuringWinner *winners, int numberOfWinners) {
    for (int i = 0; i < numberOfWinners; i++) {
        if (winners[i].annee == year) {
            printf("L'année %d, le(s) gagnant(s) ont été : %s\n", winners[i].annee, winners[i].noms);
            printf("Nature des travaux : %s\n", winners[i].description);
            return;
        }
    }
    printf("Aucune information disponible pour l'année %d\n", year);
}

// tri par selection : permet d'éviter d'avoir à faire une copie et d'allour de la mémoire 
void sortTuringWinnersByYear(TuringWinner *winners, int numberOfWinners) {
    int i, j, minIndex;
    TuringWinner tempo;

    for (i = 0; i < numberOfWinners - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < numberOfWinners; j++) {
            if (winners[j].annee < winners[minIndex].annee) {
                minIndex = j;
            }
        }

        // Échange des éléments
        tempo = winners[i];
        winners[i] = winners[minIndex];
        winners[minIndex] = tempo;
    }
}

