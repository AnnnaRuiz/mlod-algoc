#include "01-resistorColor.h"

uint16_t color_code(resistor_band_t color){ //on retourne l'adresse de la première case du tableau
    return color;
}

resistor_band_t colors_array[] = {
    BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE
};

resistor_band_t *colors(){
    return colors_array;
}