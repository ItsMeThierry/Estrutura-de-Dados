#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    node* first;
    node* last;
} queue;

queue* create_queue();
void insert_queue(queue* q, int element);
int remove_queue(queue* q);
int seek_element(queue* q, int element);

void print_queue(queue* q);

#endif