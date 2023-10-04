#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a) {
	return a==NULL;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a) {
	*a=NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) {
	ArbreBinaire a = malloc(sizeof(Noeud));
	a->val=e;
	a->filsDroit=NULL; //initialiser(&res->filsDroit) => ça fonctionne
	a->filsGauche=NULL;
	return a;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) {
	ArbreBinaire res = creer(e), courant = a, parent = NULL;
    if (estVide(a)) {
        return res;
    }
    while (!estVide(courant)) {
		if (e == courant->val) {
            return a;
		}
        parent = courant;
        if (e < courant->val) {
            courant = courant->filsGauche;
        } else {
            courant = courant->filsDroit;
        }
    }
    if (e < parent->val) {
        parent->filsGauche = res;
    } else {
        parent->filsDroit = res;
    }
    return a;
}


// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e){
	if (estVide(a)) {
        return creer(e);
    }
    if (e < a->val) {
        a->filsGauche = insere_r(a->filsGauche, e);
    } else if (e > a->val) {
        a->filsDroit = insere_r(a->filsDroit, e);
    }
    return a;
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a){
	if (estVide(a)) {
        return 0;
    }
    return 1 + nombreDeNoeud(a->filsGauche)+ nombreDeNoeud(a->filsDroit);
}


// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e){
	if(estVide(a)) {
		return -1;
	}

	ArbreBinaire noeud = a;
	int profondeur = 0;

	while(!estVide(noeud)){
		if(e == noeud->val){
			return profondeur;
		} else if(e < noeud->val){
			noeud = noeud->filsGauche;
		} else {
			noeud = noeud->filsDroit;
		}
		profondeur++;
	}

	return -1;
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a){
	if (estVide(a)) {
        return 0;
    } else {
        int hauteurGauche = hauteur(a->filsGauche);
        int hauteurDroite = hauteur(a->filsDroit);

        // La hauteur de l'arbre est le maximum entre la hauteur du sous-arbre gauche et droite + 1
        return 1 + (hauteurGauche > hauteurDroite ? hauteurGauche : hauteurDroite);
    }
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem){
	ArbreBinaire pere = NULL, courant = a;

    while (!estVide(courant) && elem != courant->val) {
        pere = courant;

        if (elem < courant->val) {
            courant = courant->filsGauche;
        } else if (elem > courant->val) {
            courant = courant->filsDroit;
        }
    }

    if (estVide(courant)) {
        return NULL; // L'élément n'a pas été trouvé dans l'arbre
    }

    return pere;
}

// RGD = racine, gauche, droite
void afficheRGD_r(ArbreBinaire a){
	if (a != NULL) {
        printf("%d ", a->val);
		afficheRGD_r(a->filsGauche);
        afficheRGD_r(a->filsDroit);
    }
}

void afficheGRD_r(ArbreBinaire a){
	if (a != NULL) {
        afficheGRD_r(a->filsGauche);
        printf("%d ", a->val);
        afficheGRD_r(a->filsDroit);
    }
}

void afficheGDR_r(ArbreBinaire a){
	if (a != NULL) {
        afficheGRD_r(a->filsGauche);
		afficheGRD_r(a->filsDroit);
        printf("%d ", a->val);
    }
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a){
	ArbreBinaire res=a;
	if(estVide(a)){
		return a;
	}
	while(!estVide(res->filsGauche)){
		res = res->filsGauche;
	}
	return res;
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a){
	ArbreBinaire res=a;
	if(estVide(a)){
		return a;
	}
	while(!estVide(res->filsDroit)){
		res = res->filsDroit;
	}
	return res;
}


// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem){
	if(estVide(a)) {
		return NULL;
	}
	if(elem == a->val) {
		return a;
	}
	if(elem < a->val) {
		return recherche_r(a->filsGauche, elem);
	} else {
		return recherche_r(a->filsDroit, elem);
	}
}


// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a,Element x){
	if (estVide(a)) {
        return a;
    }

    if (x < a->val) {
        a->filsGauche = supprimer_r(a->filsGauche, x);
    } else if (x > a->val) {
        a->filsDroit = supprimer_r(a->filsDroit, x);
    } else {
        if (estVide(a->filsGauche)) {
            ArbreBinaire temp = a->filsDroit;
            free(a);
            return temp;
        } else if (estVide(a->filsDroit)) {
            ArbreBinaire temp = a->filsGauche;
            free(a);
            return temp;
        } else {
            ArbreBinaire minDroit = min(a->filsDroit);
            a->val = minDroit->val;
            a->filsDroit = supprimer_r(a->filsDroit, minDroit->val);
        }
    }

    return a;
}

void detruire_r(ArbreBinaire a){
	 if (estVide(a)) {
        return;
    }

    detruire_r(a->filsGauche);
    detruire_r(a->filsDroit);

    free(a);
}

