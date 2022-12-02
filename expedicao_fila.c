#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct no_expedicao {
    int id;
    int pedido;
    struct no_expedicao *prox;
} Expedicao;

typedef struct no_fila {
    struct no_expedicao *inicio;
    struct no_expedicao *final;
} Fila;

int inicializa_fila(Fila *fila);
int inserir_fila(Fila *fila, int id, int pedido);
int remover_fila(Fila *fila);
int consultar_fila(Fila *fila, int *id, int *pedido);

int main(int argc, char const *argv[]) {
    int erro, opcao, id, pedido;
    
    Expedicao *expedicao = malloc(sizeof(Expedicao));
    Fila fila;

    do {
        system("clear");
        printf("FILA Estatica \n");
        printf("\n\nOpcoes: \n\n");
        printf("1 -> Inicializa \n");
        printf("2 -> Insere\n");
        printf("3 -> Remove\n");
        printf("4 -> Lista \n");
        printf("5 -> Sair \n:");
        scanf("%d", &opcao);
        getchar();
        
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
                scanf("%d", &id);

                printf("Digite o número do pedido: ");
                scanf("%d", &pedido);

                erro = inserir_fila(&fila, id, pedido);

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
                erro = consultar_fila(&fila, &id, &pedido);

                if (erro == 0) {
                    printf("ID: %d | Pedido: %d\n", id, pedido);
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
    } while (opcao != 5);
    
//     return 0;
// }

int inicializa_fila(Fila *fila) {
    (*fila).inicio = NULL;
    (*fila).final = NULL;
}

int inserir_fila(Fila *fila, int id, int pedido) {
    Expedicao *expedicao = malloc(sizeof(Expedicao));

    if (expedicao == NULL) {
        return 1;
    } else {
        expedicao->id = id;
        expedicao->pedido = pedido;
        expedicao->prox = NULL;
    }

    if (fila->inicio == NULL) {
        fila->inicio = expedicao;
    } else {
        fila->final->prox = expedicao;
    }

    fila->final = expedicao;

    return 0;
}

int remover_fila(Fila *fila) {
    Expedicao *expedicao = malloc(sizeof(Expedicao));

    if (fila->inicio == NULL) {
        return 1;
    }

    expedicao = fila->inicio;
    fila->inicio = expedicao->prox;

    if (fila->inicio == NULL) {
        fila->final = NULL;
    }

    free(expedicao);
    return 0;

}

int consultar_fila(Fila *fila, int *id, int *pedido) {
    if (fila->inicio == NULL) {
        return 1;
    }

    *id = (*fila).inicio->id;
    *pedido = (*fila).inicio->pedido;

    return 0;
}
