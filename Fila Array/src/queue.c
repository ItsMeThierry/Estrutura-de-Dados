#include "include/queue.h"

void create_queue(queue* q, int max_size){
    q->data = (int*) calloc(max_size, sizeof(int) * max_size);
    q->first = 0;
    q->last = -1;
    q->size = 0;
    q->max_size = max_size;
}

int is_empty(queue* q){
    return q->size == 0;
}

int is_full(queue* q){
    return q->size == q->max_size;
}

int insert_queue(queue* q, int element){
    if(is_full(q)){
        printf("A fila esta cheia\n");
        return 0;
    }

    q->last = (q->last + 1) % q->max_size;
    q->data[q->last] = element;

    q->size++;

    return 1;
}

int remove_queue(queue* q){
    if(is_empty(q)){
        printf("A fila esta vazia\n");
        return INT_MIN;
    }

    int removed = q->data[q->first];
    q->data[q->first] = 0;
    q->first = (q->first + 1) % q->max_size;
    q->size--;

    return removed;
}

int get_first(queue* q){
    return q->data[q->first];
}