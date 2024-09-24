#include "include/stack.h"

stack* create_stack(){
    stack* stack = malloc(sizeof(stack));
    stack->top = 0;
    stack->size = 0;
}

void insert_stack(stack* stack, int element){
    node* new = malloc(sizeof(node));
    new->element = element;
    new->next = stack->top;

    stack->top = new;
    stack->size++;
}

int remove_stack(stack* stack){
    node* aux = stack->top;
    stack->top = aux->next;

    int returned = aux->element;

    free(aux);

    stack->size--;
    return returned;
}

void print_stack(stack* stack){
    node* aux = stack->top;

    printf("STACK = ");
    while(aux != 0){
        printf("%d ", aux->element);
        aux = aux->next;
    }
    printf("\n");
}