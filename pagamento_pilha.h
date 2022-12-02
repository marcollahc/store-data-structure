 #include <stdlib.h>
 #include <stdio.h>

 typedef struct No_pilha
 {
    int id;
    int valorPedido;
    // int idPedido
    int situacao; // parâmetros: 0 -  aguardando pagamento   | 1 - pago e em preparacao | 2 - expedido
    struct No_pilha *prox;
 }  Pagamento;
 
 

 /* Inserir */

 int Inserir_topo (Pagamento **iniciar, int idPagamento, int valorPedidoPagamento, int situacaoPagamento)
{
    Pagamento *no_novo;

    /* Criacao do novo nó */
    no_novo = (Pagamento*) malloc(sizeof(Pagamento));
    no_novo -> id = idPagamento;
    no_novo -> valorPedido = valorPedidoPagamento;
    no_novo -> situacao = situacaoPagamento;


	if (*iniciar==NULL)
	{    // insercao em pilha vazia
	    no_novo -> prox = NULL;
	    *iniciar = no_novo;
	}
	else { // insercao em pilha nao vazia
	     no_novo -> prox = *iniciar;
	    *iniciar = no_novo;
	}
    return 0;
}

 /* Remover */
 
int Remover_topo (Pagamento **iniciar)
{
    Pagamento *aux;
    if (*iniciar == NULL)
    {
         return 1;  /* pilha vazia, impossivel remover topo */
    }
    else {
        aux = *iniciar;
        *iniciar = (*iniciar)->prox;
        free(aux);
        return 0;
    }
}

 /* Consultar - Lista de Todos os Pagamentos*/
 
 int P_Consultar(Pagamento *inicio, int *idPagamento, int *valorPedidoPagamento, int *situacaoPagamento) {
   if (inicio != NULL) {
     *idPagamento = inicio->id;
     *valorPedidoPagamento = inicio->valorPedido;
     *situacaoPagamento = inicio->situacao;
     return 0;
   } else
     return 1; // Pilha Vazia
 }
 

 
 
 
 
