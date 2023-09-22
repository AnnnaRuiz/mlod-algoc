#include "02-matrice-malloc.h"

Matrice* creer(int valeurInitiale , uint16_t nbrLignes, uint16_t nbrColonnes){
    Matrice* m = (Matrice*)malloc(sizeof(Matrice));;
    
    m->nbLignes=nbrLignes;
    m->nbColonnes=nbrColonnes;
    m->valeurs=(int**)calloc(nbrLignes,sizeof(int*));
    for (int i=0; i<nbrLignes; i++){
        m->valeurs[i]=(int*)calloc(nbrColonnes,sizeof(int));
        for(int j=0;j<nbrColonnes;j++){
            m->valeurs[i][j]=valeurInitiale;
        }
    }
    return m;
}

void afficher(Matrice* m){
        for (int i=0; i<m->nbLignes; i++){
        for(int j=0; j<m->nbColonnes;j++){
            printf("%d\t",m->valeurs[i][j]);
        }
        printf(" \n");
    }
}

void initialiserLigne(int valeur, uint16_t indiceLigne, Matrice* m){
    for(int j=0; j<m->nbColonnes; j++){
        m->valeurs[indiceLigne-1][j]=valeur;
    }
}

Matrice* multiplier(Matrice* m1, Matrice* m2){
    Matrice* res;
    res=creer(0,m1->nbLignes,m2->nbColonnes);
    for (int i=0; i<m1->nbLignes; i++){
        for(int j=0; j<m2->nbColonnes;j++){
            int64_t somme = 0;
            for(int k=0; k<m1->nbColonnes; k++){
                somme+=m1->valeurs[i][k]*m2->valeurs[k][j];
            }
            res->valeurs[i][j]=somme;
        }
    }
    return res;
}

void detruire(Matrice* m){
    for (int i=0; i<m->nbLignes; i++){
        free(m->valeurs[i]);
    }
    free(m->valeurs);
    free(m);
}