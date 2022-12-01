#include <stdlib.h>
#include <stdio.h>

/*2- Pilha: Análise dos pagamentos
Lista dos pagamentos a serem confirmados, que vai definir se o pagamento foi aprovado,
recusado ou se está aguardando. Uma estrutura composta por id, valor total e situação.
*/

/* Estrutura do pagamento - Pilha
Campos: id, valor total, situacao
*/

typedef struct no
{
  int id;
  int valorPedido;
  // int idPedido
  int situacao; // parâmetros: 0 -  aguardando pagamento   | 1 - pago
  Pagamento *prox;
} Pagamento;

/* -----------------------------------------------------------------------------
Prototipos das funcoes
------------------------------------------------------------------------------*/
int P_Inserir_topo(Pagamento **inicio, int idPagamento, int valorPedidoPagamento, int situacaoPagamento);
int P_Remover_topo(Pagamento **inicio);
int P_Atualizar(Pagamento **inicio);
int P_Consultar(Pagamento *inicio, int *idPagamento, int *valorPedidoPagamento, int *situacaoPagamento);

/* -------------------------------------------------------------------------------------
INSERÇÃO PILHA
---------------------------------------------------------------------------------------*/
int IP_Inserir_topo(Pagamento **inicio, int idPagamento, int valorPedidoPagamento, int situacaoPagamento)
{
  Pagamento *no_novo;

  /* Criacao do novo nó */
  no_novo = (Pagamento *)malloc(sizeof(Pagamento));
  // no_novo -> id = idPagamento;
  no_novo->valorPedido = valorPedidoPagamento;
  no_novo->situacao = situacaoPagamento;

  if (*inicio == NULL) { // insercao em pilha vazia
    no_novo->prox = NULL;
    *inicio = no_novo;
  } else { // insercao em pilha nao vazia
    no_novo->prox = *inicio;
    *inicio = no_novo;
  }
  return 0;
}

/* -------------------------------------------------------------------------
REMOCAO PILHA
-------------------------------------------------------------------------*/
int P_Remover_topo(Pagamento **inicio) {
  Pagamento *aux;
  if (*inicio == NULL) {
    return 1; /* pilha vazia, impossivel remover topo */
  } else {
    aux = *inicio;
    *inicio = (*inicio)->prox;
    free(aux);
    return 0;
  }
}

/* -------------------------------------------------------------------------
ATUALIZAÇÃO PILHA
-------------------------------------------------------------------------*/
int P_Atualizar(Pagamento **inicio) {
}

/* -------------------------------------------------------------------------
CONSULTAR PILHA
-------------------------------------------------------------------------*/
int P_Consultar(Pagamento *inicio, int *idPagamento, int *valorPedidoPagamento, int *situacaoPagamento) {
  if (inicio != NULL) {
    *idPagamento = inicio->id;
    *valorPedidoPagamento = inicio->valorPedido;
    *situacaoPagamento = inicio->situacao;
    return 0;
  } else
    return 1; // Pilha Vazia
}

int main(void) {
  // Pagamento
  int idPagamento, valorPedidoPagamento, situacaoPagamento;
  Pagamento *ini;
}