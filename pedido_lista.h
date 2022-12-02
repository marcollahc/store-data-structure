#include <stdlib.h>
#include <stdio.h>

/* Estrutura do pedido - Lista circular
Campos: id, valor total, situacao
*/

typedef struct no {
  int id;
  int valorPedido;
  int idProduto;
  int situacao; // parâmetros: 0 -  aguardando pagamento   | 1 - pago e em preparacao | 2 - expedido
  struct no *prox;
} Pedido;

int inicializarLista(Pedido **inicio) {
  *inicio = NULL;
  return 0;
}

int inserirNovoPedido(Pedido **inicio, int id, int valor, int idObra) {
  Pedido *no_novo, *percorre;

  no_novo = (Pedido *)malloc(sizeof(Pedido));
  no_novo->id = id;
  no_novo->valorPedido = valor;
  no_novo->idProduto = idObra;
  no_novo->situacao = 0;
  no_novo->prox = NULL;

  if (*inicio == NULL) {
    *inicio = no_novo;
  } else {
    percorre = *inicio;

    while (percorre->prox != NULL) {
      percorre = percorre->prox;
    }
    percorre->prox = no_novo;
  }
  return 0;
}

int listarPedidos(Pedido *inicio, tipoNoListaDupla *raizArvore) {
  if (!inicio) {
    printf("\nNão existem pedidos cadastros!\n");
    return 1;
  }
  printf("\nLISTA DE PEDIDOS ::\n\n");
  do {
    printf("ID DO PEDIDO: %d\n", inicio->id);
    printf("VALOR DO PEDIDO: %d\n", inicio->valorPedido);
    printf("ID DA OBRA:%d\n", inicio->idProduto);
    printf("SITUAÇÃO: %d\n", inicio->situacao);

    inicio = inicio->prox;
  } while (inicio != NULL);

  printf("\n");
  return 0;
}

void atualizarSituacaoPedido(Pedido *inicio, int id) {
  if (id == inicio->id) {
    inicio->situacao = 1;
    printf("\nO status do seu pedido foi atualizado! Acesse a opcao 5 e verifique.\n");
  }
}

void expedirPedido(Pedido *inicio, int id) {
  if (id == inicio->id) {
    inicio->situacao = 2;
    printf("\nO seu pedido foi liberado para expedição! Acesse a opcao 10 e verifique.\n");
  }
}

void listarPedidosExpedidos(Pedido *inicio) {
  int index;
  Pedido *auxiliar;

  if (!inicio) {
    printf("Nenhum pedido expedido encontrado!");
  }

  auxiliar = inicio;

  do {
    if (inicio->situacao == 2) {
      printf("Idenfiticador do pedido: %d\n", inicio->id);
    }
    inicio = inicio->prox;
  } while (inicio);
}

int excluirPedido(Pedido **inicio, int num) {
  Pedido *aux, *remover = NULL;

  if (*inicio) {
    if ((*inicio)->id == num) {
      remover = *inicio;
      *inicio = remover->prox;
    } else {
      aux = *inicio;

      while (aux->prox && aux->prox->id != num) {
        aux = aux->prox;
      }

      if (aux->prox) {
        remover = aux->prox;
        aux->prox = remover->prox;
      }
    }
  }
  return 0;
}
