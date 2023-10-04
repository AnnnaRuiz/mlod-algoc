#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void afficheElement(Element e){
    printf("%s ",(char*)e);
}

void detruireElement(Element e){}

bool equalsElement(Element e1, Element e2){
	return strcmp((char*)e1,e2)==0;
}

int main(void){
	Liste l, p;

	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");
	
	l = ajoutTete("It",l);
	l = ajoutTete("is",l);
	l = ajoutTete("not",l);
	l = ajoutTete("raining",l);
	l = ajoutTete("today",l);
	l = ajoutTete("I",l);
	l = ajoutTete("am",l);
    l = ajoutTete("happy",l);
	l = ajoutTete("!",l);    

	afficheListe_i(l);
	afficheEnvers_r(l);
	printf("\n");
	
	ajoutFin_i("sleep",l);
	afficheListe_i(l);

	ajoutFin_r("food",l);
	afficheListe_i(l);

	p = cherche_i("po",l);
	printf("cherche_i(po) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_i("happy",l);
	if(estVide(p))
		printf("cherche_i(happy) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_i(happy) : trouve ");
		afficheElement(p->val);
		printf("\n");
	}

	p = cherche_r("po",l);
	printf("cherche_r(po) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_r("happy",l);
	if(estVide(p))
		printf("cherche_r(happy) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_r(happy) : trouve ");
		afficheElement(p->val);
		printf("\n");
	}

	printf("retirePremier_i(food) : ");
	l = retirePremier_i("food",l);
	afficheListe_r(l);

	printf("retirePremier_i(sleep) : ");
	l = retirePremier_i("sleep",l);
	afficheListe_r(l);

	printf("retirePremier_i(!) : ");
	l = retirePremier_i("!",l);
	afficheListe_r(l);

	printf("retirePremier_r(I)   : ");
	l = retirePremier_r("I",l);
	afficheListe_r(l);

	printf("retirePremier_r(am)   : ");
	l = retirePremier_r("am",l);
	afficheListe_r(l);

	printf("retirePremier_r(today)  : ");
	l = retirePremier_r("today",l);
	afficheListe_r(l);

	detruire_r(l);

	return EXIT_SUCCESS;
}