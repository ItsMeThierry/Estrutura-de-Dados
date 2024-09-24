#include "include/adjacent_list.h"
#include "include/adjacent_matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct data{
    int n;
    int** matrix;
} file_data;

file_data* select_and_read_file() {
    char input[256];
    printf("Digite o nome do arquivo quer usar como teste (nao digite .txt): ");
    scanf("%s", input);

    printf("Lendo arquivo...\n");
    char file_path[300];
    snprintf(file_path, sizeof(file_path), "./src/inputs/%s.txt", input);

    FILE *file = fopen(file_path, "r");

    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }
    
    fscanf(file, "%s", input); // Lê dimensão da matriz

    int n = atoi(input); // Pode gerar erro

    char c;
    while ((c = fgetc(file)) != '\n') {} // Ignora resto da primeira linha

    int** matrix = malloc(n * sizeof(int*));
    
    for(int i = 0; i < n; i++){
        matrix[i] = malloc(n * sizeof(int));
    }

    //Transforma texto do arquivo em dado
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fscanf(file, "%s", input);
            matrix[i][j] = atoi(input);
        }
    }

    fclose(file);

    file_data* data = malloc(sizeof(file_data));
    data->n = n;
    data->matrix = matrix;

    return data;
}

void load_list(file_data* data, alist* list){
    printf("Criando estruturas...\n");

    //Converte dados em lista de adjacencia
    for(int i = 0; i < data->n; i++){
        insert_vertex(list);

        for(int j = 0; j < data->n; j++){
            if(data->matrix[i][j] != 0){
                insert_adjacent(list, i+1, j+1, data->matrix[i][j]);
            }
        }
    }
}

void load_matrix(file_data* data, amatrix* matrix){
    matrix->vertexes = data->n;
    matrix->matrix = data->matrix;
}

int read_input(){
    int resp;

    while(1){
        if(scanf("%d", &resp) != 1){
            printf("Entrada invalida.\n");
            while (getchar() != '\n');
            continue;
        }

        return resp;
    }
}

int programa(alist* adjacent_list, amatrix* adjacent_matrix){
    printf(
        "==================================================================\n"
        "   Qual operacao voce quer fazer?\n"
        "   1- BFS com Lista de Adjacencia\n"
        "   2- DFS com Lista de Adjacencia\n"
        "   3- BFS com Matriz de Adjacencia\n"
        "   4- DFS com Matriz de Adjacencia\n"
        "   5- Encerrar\n"
        "==================================================================\n"
        "RESPOSTA: "
    );

    int resp = read_input();
    int start, end;

    switch(resp){
        case 1:
            printf("Qual o numero do vertice inicial? ");
            start = read_input();

            printf("Qual o numero do vertice final? ");
            end = read_input();

            BFS_adjacent_list(adjacent_list, start, end);

            Sleep(1000);
            return 1;
        case 2:
            printf("Qual o numero do vertice inicial? ");
            start = read_input();

            printf("Qual o numero do vertice final? ");
            end = read_input();

            DFS_adjacent_list(adjacent_list, start, end);

            Sleep(1000);
            return 1;
        case 3:
            printf("Qual o numero do vertice inicial? ");
            start = read_input();

            printf("Qual o numero do vertice final? ");
            end = read_input();

            BFS_adjacent_matrix(adjacent_matrix, start, end);

            Sleep(1000);
            return 1;
        case 4:
            printf("Qual o numero do vertice inicial? ");
            start = read_input();

            printf("Qual o numero do vertice final? ");
            end = read_input();

            DFS_adjacent_matrix(adjacent_matrix, start, end);

            Sleep(1000);
            return 1;
        case 5:
            printf("Encerrando o programa...\n");
            return 0;
        default:
            printf("Valor invalido\n");

            Sleep(1000);
            return 1;
    }
}

int main()
{
    alist* adjacent_list = create_adjacent_list();
    amatrix* adjacent_matrix = create_adjacent_matrix();

    file_data* data = select_and_read_file();

    load_list(data, adjacent_list);
    load_matrix(data, adjacent_matrix);

    free(data);
    //print_adjacent_list(adjacent_list);
    //print_adjacent_matrix(adjacent_matrix);

    while(programa(adjacent_list, adjacent_matrix));

    return 0;
}