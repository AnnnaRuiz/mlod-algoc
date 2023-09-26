#include "03-prixTuring.h"
 
int main(/*int argc, char** argv*/void){
	char filename[] = "turingWinners.csv";
	//char outputFilename[] = "out.csv";
	//char ligne[300];

	FILE* f = fopen(filename, "r");
	printf("nbr lignes : %d\n", numberOfWinners(f));
	/*FILE* of = fopen(outputFilename, "w");

    while (fgets(ligne, sizeof(ligne), f) != NULL) {
        fputs(ligne, of);
    }
	fclose(of);*/
	
	// TuringWinner* winner = (TuringWinner*)malloc (sizeof(TuringWinner));
	// winner->annee=1978;
	// winner->noms='Bertrand Bertrand';
	// winner->description='faire la sieste';

	fclose(f);


	return EXIT_SUCCESS;
}