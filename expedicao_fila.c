#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct no_expedicao {
    int id;
    int pedido;
    struct no_expedicao *prox;
} Expedicao;

typedef struct no_fila {
    int tamanho;
    struct no_expedicao *inicio;
    struct no_expedicao *final;
} Fila;

int inicializa_fila(Fila *fila);
int inserir_fila(Fila *fila, Expedicao expedicao);
int remover_fila(Fila *fila);
int consultar_fila(Fila *fila, Expedicao expedicao);

int main(int argc, char const *argv[]) {
    int erro, opcao;

    Expedicao expedicao;
    Fila fila;

    do {
        system("cls");
        printf("FILA Estatica \n");
        printf("\n\nOpcoes: \n\n");
        printf("1 -> Inicializa \n");
        printf("2 -> Insere\n");
        printf("3 -> Remove\n");
        printf("4 -> Lista \n");
        printf("5 -> Sair \n:");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                erro = inicializa_fila(&fila);
                printf("\nInicializacao realizada com sucesso !\n");
                printf("\nFila VAZIA \n");
                system("pause");
                break;
            case 2:
                printf("Dado para insercao: \n\n");

                printf("Digite o número da expedição: ");

                int temp_id = 0, temp_pedido = 0;
                
                scanf("%d", &temp_id);

                expedicao.id = temp_id;

                printf("Digite o número do pedido: ");
                scanf("%d", &temp_pedido);

                expedicao.pedido = temp_pedido;

                erro = inserir_fila(&fila, expedicao);

                if (erro == 1) {
                    printf("\nFila cheia. Overflow\n");
                }

                system("pause");
                break;
            case 3:
                erro = remover_fila(&fila);

                if (erro == 1) {
                    printf("\nFila Vazia. Underflow\n");
                }

                system("pause");
                break;
            case 4:
                erro = consultar_fila(&fila, expedicao);

                if (erro == 0) {
                    printf("ID: %d | Pedido: %d\n", expedicao.id, expedicao.pedido);
                } else {
                    printf("fila vazia. Sem primeiro\n");
                }

                system("pause");
                break;
            case 5:
                break;
            default:
                printf("\n\n Opcao nao valida");
        }
        getchar();
    } while (opcao != 5);

    remover_fila(&fila);
    
    return 0;
}

int inicializa_fila(Fila *fila) {
    (*fila).tamanho = 0;
    (*fila).inicio = NULL;
    (*fila).final = NULL;
}

int inserir_fila(Fila *fila, Expedicao expedicao) {
    Expedicao novo;
    novo.id = expedicao.id;
    novo.pedido = expedicao.pedido;

    if ((*fila).tamanho == 0) {
        (*fila).inicio = &novo;
        (*fila).final = &novo;
        novo.prox = NULL;
    } else {
        (*fila).final = &novo;
        novo.prox = NULL;
    }

    (*fila).tamanho = (*fila).tamanho++;

    return 0;
}

int remover_fila(Fila *fila) {
    Expedicao *final = fila->final;
    
    if (final != NULL) {
        return 1;
    }

    return 0;
}

int consultar_fila(Fila *fila, Expedicao expedicao) {
    if (fila != NULL) {
        (*expedicao) = fila->inicio;
        return 0;
    }

    return 1;
}
