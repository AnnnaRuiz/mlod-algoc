#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Liste l = (Liste)malloc(sizeof(Cellule));
	l->val=v;
	l->suiv=NULL;
	return l;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	Liste new = creer(v);
	new->suiv=l;
	return new;
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	if(estVide(l)){
		printf("La liste est vide");
	}
	Liste liste = l;
	while (!estVide(liste)){
		afficheElement(liste->val);
		liste = liste->suiv;
	}
	printf("\n");
}

// version recursive
void afficheListe_r(Liste l) {
	if(l!= NULL){
		afficheElement(l->val);
		afficheListe_r(l->suiv);
	}
	else{
		printf("\n");
	}
}


// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste list=l;
	while (!estVide(list)){
		Liste suivant = list->suiv;
		detruireElement(list->val);
		free(list);
		list = suivant;
	}
}

// version récursive
void detruire_r(Liste l) {
	if(!estVide(l)){
		detruire_r(l->suiv);
		detruireElement(l->val);
		free(l);
		
	}
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	Liste liste=l;
	while(!estVide(liste->suiv)){
		liste=liste->suiv;
	}
	Liste new = creer(v);
	liste->suiv = new;
	return new;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if(estVide(l)){
		return creer(v);
	}else if (estVide(l->suiv)) {
        Liste new = creer(v);
        l->suiv = new;
        return new;
	}else {
		return ajoutFin_r(v, l->suiv);
	}
}


// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	Liste list = l;
	while (!estVide(list) && !equalsElement(list->val,v)){
		list=list->suiv;
	}
	return list;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if (!estVide(l) && !equalsElement(l->val,v)){
		return cherche_r(v, l->suiv);
	}
	return l;
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	Liste precedent = NULL;
	Liste courant = l;
	if(estVide(courant) || equalsElement(courant->val,v)){
		detruireElement(courant->val);
		free(courant);
		return l->suiv;
	}
	precedent=courant;
	courant=courant->suiv;
	while (!estVide(courant) && !equalsElement(courant->val,v)){
		precedent = courant;
		courant=courant->suiv;
	}
	precedent->suiv = courant->suiv;
	detruireElement(courant->val);
	free(courant);
	return l;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	Liste precedent = NULL;
	Liste courant = l;

	if(estVide(courant) || equalsElement(courant->val,v)){
		detruireElement(courant->val);
		free(precedent);
		return l->suiv;
	}

	if(!estVide(courant) && !equalsElement(courant->val,v)){
		courant->suiv = retirePremier_r(v, courant->suiv);
	}
	return l;
}


void afficheEnvers_r(Liste l) {
	if(!estVide(l->suiv)){
		afficheEnvers_r(l->suiv);
	}
	afficheElement(l->val);
}



