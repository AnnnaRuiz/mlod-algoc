#include "03-prixTuring.h"

int main(int argc, char **argv) {

	char* filename = argv[argc-1];


	if (argc != 4 && argc != 5) {
        printf("Usages:\n %s -o <nom_fichier_output> <nom_fichier_input>\n", argv[0]);
        printf("%s --info <annee > <nom_fichier_input>\n", argv[0]);
		printf("valeur de argc: %d \n", argc);
		return 0;
    }
	
	// Ouvrir le fichier donné en entrer et copier les données dans la structure de données.
    FILE* inFile = fopen(filename, "r");
    if (inFile == NULL) {
        perror("Erreur lors de l'ouverture du fichier d'entrée");
        return EXIT_FAILURE;
    }

    int n = numberOfWinners(inFile);
    TuringWinner* winners = readWinners(inFile);
    fclose(inFile);

	// Recopier les données de la structure de données dans le fichier de sortie
	// seulement si le deuxième argument est '-o'
	if (argc == 4 && strcmp(argv[1], "-o") == 0) {
		FILE* outFile = fopen(argv[2], "w");
        printWinners(winners, n, outFile);
		fclose(outFile);
    }
	
	//si le deuxième argument est '--info' on affiche les infos de l'année demandée
	if (argc == 4 && strcmp(argv[1], "--info") == 0) {
        int annee = atoi(argv[2]);
        infosAnnee(annee, winners, n);
    }

	if (argc == 5 && strcmp(argv[1], "--sort") == 0 && strcmp(argv[2], "-o") == 0) {
        sortTuringWinnersByYear(winners, n);
        FILE *sortedFile = fopen(argv[3], "w");
        printWinners(winners, n, sortedFile);
        fclose(sortedFile);
    }

    // Libération de la mémoire allouée pour les noms et descriptions
    int i;
    for (i = 0; i < n; i++) {
        free(winners[i].noms);
        free(winners[i].description);
    }
    free(winners);

    return EXIT_SUCCESS;
}
