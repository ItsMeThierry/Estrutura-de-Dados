#include <stdio.h>
#include <windows.h>
#include "include/queue.h"

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

int programa(queue *q){
    printf(
        "==================================================================\n"
        "   Qual operacao voce quer fazer com a fila?\n"
        "   1- Verificar se esta vazia\n"
        "   2- Verificar se esta cheia\n"
        "   3- Obter o tamanho atual\n"
        "   4- Inserir um elemento\n"
        "   5- Remover um valor\n"
        "   6- Exibir conteudo\n"
        "   7- Encerrar\n"
        "==================================================================\n"
        "RESPOSTA: "
    );

    int resp = read_input();
    int aux, returned;

    switch(resp){
        case 1:
            if(is_empty(q)){
                printf("Esta vazio\n");
            }else{
                printf("Nao esta vazio\n");
            }

            Sleep(1000);
            return 1;
        case 2:
            if(is_full(q)){
                printf("Esta cheio\n");
            }else{
                printf("Nao esta cheio\n");
            }

            Sleep(1000);
            return 1;
        case 3:
            printf("Tamanho atual: %d\n", q->size);

            Sleep(1000);
            return 1;
        case 4:
            printf("Digite o elemento a ser inserido: ");
            
            resp = read_input();
                
            returned = insert_queue(q, resp); 

            if(returned != 0){
                printf("%d inserido\n", resp);
            }

            Sleep(1000);
            return 1;
        case 5:
            returned = remove_queue(q);

            if(returned != INT_MIN){
                printf("Valor %d removido\n", returned);
            }

            Sleep(1000);
            return 1;
        case 6:
            printf("[");

            if(!is_empty(q)){
                int i = q->first;
                for(int c = 0; c < q->size; c++){
                    printf(" \"%d\" ", q->data[i]);
                    i = (i+1) % q->max_size;
                }
            }

            printf("]\n");

            Sleep(1000);
            return 1;
        case 7:
            printf("Encerrando o programa...\n");
            return 0;
        default:
            printf("Valor invalido\n");

            Sleep(1000);
            return 1;
    }
}

int main(){
    queue q;
    int size;

    printf("Digite o tamanho da fila: ");
    
    while(1){
        size = read_input();

        if(size > 0){
            break;
        }

        printf("Entrada invalida, digite novamente\n");
    }

    create_queue(&q, size);
    
    while(programa(&q));

    return 0;
}