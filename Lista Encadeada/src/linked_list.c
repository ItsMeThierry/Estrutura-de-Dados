#include "include/linked_list.h"

void create_list(llist* list){
    list->head = 0;
    list->size = 0;
}

int is_empty(llist* list){
    return list->size == 0;
}

int size(llist* list){
    return list->size;
}

int get_element(llist* list, int pos){
    if(is_empty(list) || pos < 1 || pos > list->size){
        fprintf(stderr, "Posicao invalida ou a lista esta vazia.\n");
        return INT_MIN;
    }
    
    node* aux = list->head;

    for(int i = 1; i < pos; i++){
        aux = aux->next;
    }

    return aux->element;
}

int change_element(llist* list, int element, int pos){
    if(is_empty(list) || pos < 1 || pos > list->size){
        fprintf(stderr, "Posicao invalida ou a lista esta vazia.\n");

        return INT_MIN;
    }
    
    node* aux = list->head;

    for(int i = 1; i < pos; i++){
        aux = aux->next;
    }

    aux->element = element;

    return 1;
}

int insert_element(llist* list, int element, int pos){
    if(is_empty(list) && pos != 1 || pos < 1 || pos > list->size+1){
        fprintf(stderr, "Posicao invalida.\n");
        return INT_MIN;
    } 

    node* new = malloc(sizeof(node));

    new->element = element;

    if(pos == 1){ /* Insert at begging */
        new->next = list->head;
        list->head = new;
        list->size++;
        return 1;
    }

    node* aux = 0;
    aux = list->head;

    for(int i = 1; i < pos-1; i++){
        aux = aux->next;
    }

    if(pos == list->size+1){ /* Insert at end */
        new->next = 0;
        aux->next = new;
        list->size++;
        return 1;
    }

    new->next = aux->next; /* Insert at middle */
    aux->next = new;
    list->size++;  
    return 1;
}

int remove_element(llist* list, int pos){
    if(is_empty(list) || pos < 1 || pos > list->size){
        fprintf(stderr, "Posicao invalida ou a lista esta vazia.\n");

        return INT_MIN;
    }

    node* aux = list->head;
    int element;

    if(pos == 1){ /* Remove at begging */
        list->head = aux->next;
        element = aux->element;

        free(aux);
        list->size--;
        return element;
    }

    node* removed = 0; /* Remove in list */

    for(int i = 1; i < pos-1; i++){
        aux = aux->next;
    }

    removed = aux->next;
    aux->next = removed->next;
    element = removed->element;

    free(removed);
    list->size--;
    return element;
}

void print_list(llist* list){
    printf("[");

    if(!is_empty(list)){
        node* aux = list->head;

        for(int i = 1; i <= list->size; i++){
            printf(" \"%d\" ", aux->element);
            aux = aux->next;
        }
    }

    printf("]\n");
}