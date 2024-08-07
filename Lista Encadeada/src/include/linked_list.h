#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct list_node{
    int element;
    struct list_node* next;
} node;

typedef struct linked_list{
    node* head;
    int size;
} llist;

void create_list(llist* list);
int is_empty(llist* list);
int size(llist* list);
int get_element(llist* list, int pos);
int change_element(llist* list, int element, int pos);
int insert_element(llist* list, int element, int pos);
int remove_element(llist* list, int pos);
void print_list(llist* list);