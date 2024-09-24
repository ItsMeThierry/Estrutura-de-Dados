#include "include/adjacent_matrix.h"

#define NOT_VISITED 0
#define TO_VISIT 1
#define VISITED 2

amatrix* create_adjacent_matrix(){
    amatrix* matrix = malloc(sizeof(amatrix));
    matrix->vertexes = 0;
    matrix->matrix = 0;

    return matrix;
}

void BFS_adjacent_matrix(amatrix* matrix, int start, int end){
    if((start < 1 || start > matrix->vertexes) || (end < 1 || end > matrix->vertexes)){
        fprintf(stderr, "Posicao invalida.\n");
        return;
    }

    int visited[matrix->vertexes];
    for(int i = 0; i < matrix->vertexes; i++){
        visited[i] = NOT_VISITED;
    }

    int found = 0;
    queue* q = create_queue();
    queue* path = create_queue();
    
    insert_queue(q, start);
    visited[start-1] = TO_VISIT;

    while(q->first != 0){
        int vertex_id = remove_queue(q);

        if(vertex_id == end){
            found = 1;
            insert_queue(path, vertex_id);
            break;
        }
        
        for(int i = 1; i <= matrix->vertexes; i++){
            if(matrix->matrix[vertex_id-1][i-1] == 0){
                continue;
            }

            if(visited[i-1] == NOT_VISITED){
                insert_queue(q, i);
                visited[i-1] = TO_VISIT;
            }
        }

        visited[vertex_id-1] = VISITED;
        insert_queue(path, vertex_id);
    }

    free(q);

    printf("BFS: ");
    if(found){
        while(path->first != 0){
            printf("V%d ", remove_queue(path));
        }

        printf("\n");
    } else{
        printf("Caminho nao encontrado.\n");
    }

    free(path);
}

void DFS_adjacent_matrix(amatrix* matrix, int start, int end){
    if((start < 1 || start > matrix->vertexes) || (end < 1 || end > matrix->vertexes)){
        fprintf(stderr, "Posicao invalida.\n");
        return;
    }

    int visited[matrix->vertexes];
    for(int i = 0; i < matrix->vertexes; i++){
        visited[i] = NOT_VISITED;
    }

    int found = 0;
    stack* visit = create_stack();
    insert_stack(visit, start);

    while(visit->top != 0){
        // Seleciona o vertice
        int vertex_id = visit->top->element;
        visited[vertex_id-1] = TO_VISIT;

        // Verifica se tem adjacencia para olhar
        int i;
        for(i = 0; i < matrix->vertexes; i++){
            if(matrix->matrix[vertex_id-1][i] == 0){
                continue;
            }

            if(visited[i] == NOT_VISITED){
                insert_stack(visit, i+1);
                visited[i] = TO_VISIT;
                break;
            }
        }

        // Finaliza se achou
        if(visited[end-1] == TO_VISIT){
            found = 1;
            break;
        }

        // Se não tem mais adjacencias, já olhou
        if(i == matrix->vertexes){
            remove_stack(visit);
            visited[vertex_id-1] = VISITED;
        }
    }

    // Imprime caminho
    printf("DFS: ");
    
    if(found){
        int size = visit->size;
        int path[size];
        int i;

        for(i = size-1; i >= 0; i--){
            path[i] = remove_stack(visit);
        }

        for(i = 0; i < size; i++){
            printf("V%d ", path[i]);
        }
        
        printf("\n");
    } else{
        printf("Caminho nao encontrado\n");
    }
}

void print_adjacent_matrix(amatrix* matrix){
    for(int i = 0; i < matrix->vertexes; i++){
        for(int j = 0; j < matrix->vertexes; j++){
            printf("%d ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
}