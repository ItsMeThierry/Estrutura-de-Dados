#include "include/sequencial_list.h"

void create_array(slist *list, int max_size){
    list->data = (int*) calloc(max_size, sizeof(int) * max_size);
    list->max_size = max_size;
    list->size = 0;
}

int is_empty(slist *list){
    return list->size == 0;
}

int is_full(slist *list){
    return list->size == list->max_size;
}

int size(slist *list){
    return list->size;
}

int get_element(slist *list, int pos){
    if(pos <= 0 || pos > list->size || is_empty(list)){
        fprintf(stderr, "Posicao invalida ou array vazio\n");

        return INT_MIN;
    }

    return list->data[pos-1];
}

int change_element(slist *list, int pos, int data){
    if(pos <= 0 || pos > list->size || is_empty(list)){
        fprintf(stderr, "Posicao invalida ou array vazio\n");

        return INT_MIN;
    }

    list->data[pos-1] = data;

    return 1;
}

int insert_element(slist *list, int pos, int data){
    if(pos > list->size+1 || pos <= 0 || is_full(list)){
        fprintf(stderr, "Posicao invalida ou array cheio\n");

        return INT_MIN;
    }

    for(int i = list->size; i >= pos; i--){
        list->data[i] = list->data[i-1];
    }

    list->data[pos-1] = data;
    list->size++;

    return 1;
}

int remove_element(slist *list, int pos){
    if(pos <= 0 || pos > list->size || is_empty(list)){
        fprintf(stderr, "Posicao invalida ou array vazio\n");

        return INT_MIN;
    }

    int data;
    data = list->data[pos-1];

    for(int i = pos-1; i < list->size-1; i++){
        list->data[i] = list->data[i+1];
    }

    list->data[list->size-1] = 0;
    list->size--;
    return data;
}