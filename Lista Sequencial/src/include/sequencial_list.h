#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef struct sequencial_list{
    int *data;
    int max_size;
    int size;
} slist;

void create_array(slist *list, int max_size);
int is_empty(slist *list);
int is_full(slist *list);
int size(slist *list);
int get_element(slist *list, int pos);
int change_element(slist *list, int pos, int data);
int insert_element(slist *list, int pos, int data);
int remove_element(slist *list, int pos);