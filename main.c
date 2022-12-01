#include <stdlib.h>
#include <stdio.h>
#include "pilha.c"

/* Estrutura do pedido - Lista circular
Campos: id, valor total, situacao
Como é uma LISTA CIRCULAR, teremos duas structs: uma representando o nó e outra para nos movimentarmos mais facilmente entre inicio e fim
Utilizar essa mesma struct para a expedição dos pedidos (fila)
*/

typedef struct no{
    int id;
    int valorPedido;
    int situacao; //parâmetros: 0 -  aguardando pagamento   | 1 - pago e em preparacao | 2 - expedido
    struct no *prox;
} Pedido;

typedef struct {
    Pedido *inicio;
    Pedido *fim;
    int tam;
} Lista;

