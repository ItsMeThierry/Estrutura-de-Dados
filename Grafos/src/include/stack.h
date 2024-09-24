#ifndef STACK_H
#define STACK_H

#include "node.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    node* top;
    int size;
} stack;

stack* create_stack();
void insert_stack(stack* stack, int element);
int remove_stack(stack* stack);

void print_stack(stack* stack);

#endif