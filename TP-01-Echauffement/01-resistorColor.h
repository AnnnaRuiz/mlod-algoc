#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

typedef enum{BLACK, BROWN, RED, ORANGE, YELLOW, 
    GREEN, BLUE, VIOLET, GREY, WHITE} resistor_band_t;

uint16_t color_code(resistor_band_t color); //on retourne l'adresse de la première case du tableau
resistor_band_t *colors(void);


/* 
on déclare dans le .h les typedef, les fonctions qu'on va réutiliser après
le fichier .c peut dépendre de la machine sur laquelle on exécute
*/