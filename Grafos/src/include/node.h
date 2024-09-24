#ifndef NODE_H
#define NODE_H

typedef struct node{
    int element;
    struct node* next;
    struct node* before;
} node;

#endif