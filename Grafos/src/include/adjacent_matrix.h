#include "queue.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct adjacent_matrix{
    int vertexes;
    int** matrix;
} amatrix;

amatrix* create_adjacent_matrix();
void BFS_adjacent_matrix(amatrix* matrix, int start, int end);
void DFS_adjacent_matrix(amatrix* matrix, int start, int end);

void print_adjacent_matrix(amatrix* matrix);