#include "include/adjacent_list.h"

#define NOT_VISITED 0
#define TO_VISIT 1
#define VISITED 2

alist* create_adjacent_list(){
    alist* list = malloc(sizeof(alist));
    list->array = malloc(sizeof(vrtx*));;
    list->vertexes = 0;

    return list;
}

vrtx* create_vertex(alist* list){
    vrtx* vertex = malloc(sizeof(vrtx));

    list->vertexes++;

    vertex->index = list->vertexes;
    vertex->adjacent = 0;

    return vertex;
}

void insert_vertex(alist* list){
    vrtx* vertex = create_vertex(list);

    if(list->vertexes > 1){
        list->array = realloc(list->array, list->vertexes * sizeof(vrtx*));
    }

    list->array[list->vertexes-1] = vertex;
}

void insert_adjacent(alist* list, int iu, int iv, int weight){
    if(iu > list->vertexes){
        fprintf(stderr, "Posicao invalida.\n");
        return;
    }
    
    adj* adjacent = malloc(sizeof(adj));
    adjacent->index = iv;
    adjacent->next = 0;
    adjacent->weight = weight;

    adj* aux_adj = list->array[list->vertexes-1]->adjacent;

    if(aux_adj == 0){
        list->array[list->vertexes-1]->adjacent = adjacent;
        return;
    }

    while(aux_adj->next != 0){
        aux_adj = aux_adj->next;
    }

    aux_adj->next = adjacent;
}

void BFS_adjacent_list(alist* list, int start, int end){
    if((start < 1 || start > list->vertexes) || (end < 1 || end > list->vertexes)){
        fprintf(stderr, "Posicao invalida.\n");
        return;
    }

    int visited[list->vertexes];
    for(int i = 0; i < list->vertexes; i++){
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
            insert_queue(path, end);
            break;
        }

        vrtx* aux_vrtx = list->array[vertex_id-1];

        if(aux_vrtx->adjacent == 0){
            continue;
        }

        adj* aux_adj = aux_vrtx->adjacent;

        while(aux_adj != 0){
            if(visited[aux_adj->index-1] == NOT_VISITED){
                insert_queue(q, aux_adj->index);
                visited[aux_adj->index-1] = TO_VISIT;
            }
            aux_adj = aux_adj->next;
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

void DFS_adjacent_list(alist* list, int start, int end){
    if((start < 1 || start > list->vertexes) || (end < 1 || end > list->vertexes)){
        fprintf(stderr, "Posicao invalida.\n");
        return;
    }

    int visited[list->vertexes];
    for(int i = 0; i < list->vertexes; i++){
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
        adj* aux_adj = list->array[vertex_id-1]->adjacent;

        while(aux_adj != 0){
            if(visited[aux_adj->index-1] == NOT_VISITED){
                insert_stack(visit, aux_adj->index);
                visited[aux_adj->index-1] = TO_VISIT;
                break;
            }

            aux_adj = aux_adj->next;
        }

        // Finaliza se achou
        if(visited[end-1] == TO_VISIT){
            found = 1;
            break;
        }

        // Se não tem mais adjacencias, já olhou
        if(aux_adj == 0){
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

    free(visit);
}

void print_adjacent_list(alist* list){
    for(int i = 0; i < list->vertexes; i++){
        vrtx* aux_vrtx = list->array[i];
        printf("[V%d] = ", aux_vrtx->index);

        adj* aux_adj = aux_vrtx->adjacent;

        while(aux_adj != 0){
            printf("V%d ", aux_adj->index);
            aux_adj = aux_adj->next;
        }

        printf("\n");
    }
}