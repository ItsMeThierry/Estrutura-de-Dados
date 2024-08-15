#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef struct queue{
    int *data;
    int first, last;
    int max_size;
    int size;
} queue;

void create_queue(queue* q, int max_size);
int is_empty(queue* q);
int is_full(queue* q);
int insert_queue(queue* q, int element);
int remove_queue(queue* q);
int get_first(queue* q);