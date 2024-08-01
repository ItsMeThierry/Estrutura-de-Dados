#include <stdio.h>
#include <windows.h>
#include "include/sequencial_list.h"

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

int programa(slist *list){
    printf(
        "==================================================================\n"
        "   Qual operacao voce quer fazer com o Array?\n"
        "   1- Verificar se esta vazia\n"
        "   2- Verificar se esta cheia\n"
        "   3- Obter o tamanho atual\n"
        "   4- Obter o valor do elemento em uma determinada posicao\n"
        "   5- Modificar o valor do elemento em uma determinada posicao\n"
        "   6- Inserir um elemento em uma determinada posicao\n"
        "   7- Remover um valor do elemento em uma determinada posicao\n"
        "   8- Exibir conteudo\n"
        "   9- Encerrar\n"
        "==================================================================\n"
        "RESPOSTA: "
    );

    int resp = read_input();
    int aux, returned;

    switch(resp){
        case 1:
            if(is_empty(list)){
                printf("Esta vazio\n");
            }else{
                printf("Nao esta vazio\n");
            }

            Sleep(1000);
            return 1;
        case 2:
            if(is_full(list)){
                printf("Esta cheio\n");
            }else{
                printf("Nao esta cheio\n");
            }

            Sleep(1000);
            return 1;
        case 3:
            printf("Tamanho atual: %d\n", list->size);

            Sleep(1000);
            return 1;
        case 4:
            printf("Digite a posicao: ");
            
            resp = read_input();
                
            returned = get_element(list, resp); 

            if(returned != INT_MIN){
                printf("Array[%d]: %d\n", resp-1, returned);
            }

            Sleep(1000);
            return 1;
        case 5:
            printf("Digite a posicao: ");
            aux = read_input();

            printf("Digite a informacao a ser armazenada: ");
            resp = read_input();

            returned = change_element(list, aux, resp);

            if(returned != INT_MIN){
                printf("Valor %d armazenado em Array[%d]\n", resp, aux-1);
            }

            Sleep(1000);
            return 1;
        case 6:
            printf("Digite a posicao: ");
            aux = read_input();

            printf("Digite a informacao a ser inserida: ");
            resp = read_input();

            returned = insert_element(list, aux, resp);

            if(returned != INT_MIN){
                printf("Valor Array[%d] modificado para %d\n", aux-1, resp);
            }

            Sleep(1000);
            return 1;
        case 7:
            printf("Digite a posicao: ");
            resp = read_input();

            returned = remove_element(list, resp);

            if(returned != INT_MIN){
                printf("Valor Array[%d] = %d removido\n", resp-1, returned);
            }

            Sleep(1000);
            return 1;
        case 8:
            printf("[");

            for(int i = 0; i < list->max_size; i++){
                printf(" \"%d\" ", list->data[i]);
            }

            printf("]\n");
            Sleep(1000);
            return 1;
        case 9:
            printf("Encerrando o programa...\n");
            return 0;
        default:
            printf("Valor invalido\n");

            Sleep(1000);
            return 1;
    }
}

int main(){
    slist list;
    int size;

    printf("Digite o tamanho do Array: ");
    
    while(1){
        size = read_input();

        if(size > 0){
            break;
        }

        printf("Entrada invalida, digite novamente\n");
    }

    create_array(&list, size);
    
    while(programa(&list));

    return 0;
}