#include "include/queue.h"

queue* create_queue(){
    queue* q = malloc(sizeof(queue));
    q->first = 0;   
    q->last = 0;
}

void insert_queue(queue* q, int element){
    node* new = malloc(sizeof(node));
    new->element = element;
    new->next = 0;

    if(q->first == 0){
        q->first = new;
    } else{
        q->last->next = new;
    }

    q->last = new;
}

int remove_queue(queue* q){
    if(q->first == 0){
        fprintf(stderr, "Fila vazia.\n");
        return -1;
    }
    
    if(q->first == q->last){
        q->last = 0;
    }

    node* aux = q->first;
    
    int result = aux->element;
    q->first = aux->next;

    free(aux);
    return result;
}

int seek_element(queue* q, int element){
    node* aux = q->first;

    while(aux != 0){
        if(aux->element == element){
            return 1;
        }
        
        aux = aux->next;
    }

    return 0;
}

void print_queue(queue* q){
    node* aux = q->first;

    while(aux != 0){
        printf("%d ", aux->element);
        aux = aux->next;
    }

    printf("\n");
}