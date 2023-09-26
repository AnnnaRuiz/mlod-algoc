#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

typedef struct {
    unsigned int annee;
    char* noms;
    char* description;
} TuringWinner ;

char* readStringFromFileUntil(FILE* f, char caract);

int numberOfWinners (FILE *f);

void readWinner(TuringWinner* winner, FILE *f);

TuringWinner* readWinners(int numberOfTuringWInner, FILE* f);

void printWinners(TuringWinner* s);

