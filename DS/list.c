#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>


// constructs a new (empty) list
List *list_create(void) {
    List *l = malloc(sizeof(List));
    l->first = l->last = NULL;
    return l;
}

// counts the items on a list
size_t list_count(const List *list) {
    size_t count = 0;

    ListNode *p=list->first;
    while(p!=NULL) {
        count++;
        p=p->next;
    }

    return count;
}

ListNode* listNode_create(data_t val){
    ListNode *l = malloc(sizeof(ListNode));

    l->prev = l->next = NULL; // a affecter par la suite lors de l'intégration dans une liste
    l->data=val;

    return l;
}

bool estVideList(List* l){
    return (l->first==NULL && l->last==NULL) ;
}

// inserts item_data at *end* of a list
void list_addlast(List *list, data_t item_data) {
    ListNode* l = listNode_create(item_data);
    ListNode* courant = list->first ;

    if(estVideList(list)){
        list->first = l;
        list->last =l; 
    }
    else {
        while(courant->next!=NULL){
            courant = courant->next;    
        }
        courant->next=l;
        l->prev=courant;
        list->last =l;
    }
}

// removes the item from *end* of the list and returns its value

data_t list_rmlast(List *list) { // A corriger, ne fonctionne pas d'après les tests
    data_t val;

    if(estVideList(list)){
        return -1;
    }

    ListNode* precedent = list->first;
    ListNode* courant = list->first;
    
    if(!estVideList(list)){
        while(courant->next!=NULL){
            precedent = courant;
            courant = courant->next;    
        }
        val=courant->data;
        courant->prev=NULL;
        list->last = precedent;

        free(courant);

        return val;
    }

    return -1;
}

void list_print(List *l){
    ListNode* courant = l->first;

    if(estVideList(l)){
        printf("La liste est vide");
    }
    else {
        while(courant!=NULL){
            printf("%i ", courant->data);
            courant = courant->next;    
        }
        printf("\n");
    }

}

void detruire_list(List *l){
    //TODO
}


int main(void) {

    List *l = list_create();

    assert(list_count(l)==0);

    list_addlast(l,10);
    list_addlast(l,20);
    list_addlast(l,30);
    list_addlast(l,40);

    assert(list_count(l)==4);

    list_print(l);

    data_t t =  list_rmlast(l);

    assert(t==40);

    list_print(l);



    return 0;
}