#include "queue.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct adjacent{
    int index;
    int weight;
    struct adjacent* next;
} adj;

typedef struct vertex{
    int index;
    adj* adjacent;
} vrtx;

typedef struct adjacent_list{
    int vertexes;
    vrtx** array;
} alist;

alist* create_adjacent_list();
vrtx* create_vertex(alist* list);
void insert_vertex(alist* list);
void insert_adjacent(alist* list, int iu, int iv, int weight);

void BFS_adjacent_list(alist* list, int start, int end);
void DFS_adjacent_list(alist* list, int start, int end);

void print_adjacent_list(alist* list);