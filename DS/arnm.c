#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "vaccins_covid.h"

// =========
// = Types =
// =========

const char NUCLEOTIDES[] = "ATCG";

typedef struct {
	int index;
	int distance;
} Difference;

typedef Difference* listeDifferences;

// =============
// = Fonctions =
// =============

int* statistics (const char seqNucleotides[]){
	int* tab = (int*)calloc(4,sizeof(int));
	int taille=0;

	for(int i=0; seqNucleotides[i]!='\0';i++){
		taille++;
		if(seqNucleotides[i]=='A'){
			tab[0]+=1;
		}
		if(seqNucleotides[i]=='T'){
			tab[1]+=1;
		}
		if(seqNucleotides[i]=='C'){
			tab[2]+=1;
		}
		if(seqNucleotides[i]=='G'){
			tab[3]+=1;
		}
	}

	tab[0] = tab[0]*100/taille;
	tab[1] = tab[1]*100/taille;
	tab[2] = tab[2]*100/taille;
	tab[3] = tab[3]*100/taille;

	return tab;
}


bool isNucleotide(char c) {
    return (c==NUCLEOTIDES[0] || c==NUCLEOTIDES[1] || c==NUCLEOTIDES[2] || c==NUCLEOTIDES[3]);
}

int indexOf(char nucleotide) {
	switch(nucleotide) {
		case 'A': return 0;
		case 'T': return 1;
		case 'C': return 2;
		case 'G': return 3;
		default:
			return -1;
	}
}

int distanceBetweenNucleotides(char n1, char n2) {
    return indexOf(n1)-indexOf(n2);
}

	
int nbDifferences(const char seq1[], const char seq2[]){
	int nb=0;
	for (int i=0; seq1[i]!='\0'; i++ ){
		if(seq1[i]!=seq2[i]){
			nb++;
		}
	}
	return nb;
}


listeDifferences computeDifferencesBetween(const char seq1[], const char seq2[]) {
    // Vérifier si les séquences ont la même taille
    if (strlen(seq1) != strlen(seq2)) {
        return NULL; 
    }

    int nb = nbDifferences(seq1, seq2);
    listeDifferences l = malloc(nb * sizeof(Difference));
    int ind = 0;

    for (int i = 0; seq1[i] != '\0'; i++) {
        if (seq1[i] != seq2[i]) {
            l[ind].index = i;
            l[ind].distance = distanceBetweenNucleotides(seq1[i], seq2[i]);
            ind++;
        }
    }

    return l;
}


void printDifferences(const char seq1[], const char seq2[]){
	int n= nbDifferences(seq1, seq2);
	listeDifferences l = computeDifferencesBetween(seq1, seq2);
	if (l==NULL){
		printf("Erreur : chaînes de tailles différentes");
	}
	else{
		for (int i=0; i<n; i++){
			printf("<%i,%i> ", l[i].index, l[i].distance);
		}	
	}
	printf("\n");
	
}


// ========
// = Main =
// ========

int main(void){

	char sequenceDeNucleotides[]="ATGCATCCATCATGCATGTA";
	char seq[]="AAGCTTTACA";

	int* tab = statistics(seq);
	printf("Nombre de A : %i\n", tab[0]);
	printf("Nombre de T : %i\n", tab[1]);
	printf("Nombre de C : %i\n", tab[2]);
	printf("Nombre de G : %i\n", tab[3]);

	listeDifferences l = computeDifferencesBetween("ATGC", "ATCG");
	printf("index: %i distance: %i \n", l[0].index, l[0].distance);
	printf("index: %i distance: %i \n", l[1].index, l[1].distance);

	printDifferences("ATGC", "ATCG");
	printDifferences(seq, sequenceDeNucleotides);

	printf("Nombre de différences : %i\n", nbDifferences(code_proteine_spike_pfizer, code_proteine_spike_moderna));
	printDifferences(code_proteine_spike_pfizer, code_proteine_spike_moderna);
	
    //printf("%s\n",code_proteine_spike_moderna);

	return EXIT_SUCCESS;
}

