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

int inicializaFila(Fila *fila) {
    (*fila).inicio = NULL;
    (*fila).final = NULL;
}

int inserirFila(Fila *fila, int id, int pedido) {
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

int removerFila(Fila *fila) {
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

int consultarFila(Fila *fila, int *id, int *pedido) {
    if (fila->inicio == NULL) {
        return 1;
    }

    *id = (*fila).inicio->id;
    *pedido = (*fila).inicio->pedido;

    return 0;
}
