#include <stdlib.h>
#include <stdio.h>

/* Estrutura do pedido - Lista circular
Campos: id, valor total, situacao
Utilizar essa mesma struct para a expedição dos pedidos (fila)
*/

typedef struct no {
  int id;
  int valorPedido;
  int id_produto; // Cadastrar alguns produtos e, na main, deixar a pessoa decidir qual produto vai inserir
  int situacao;   // parâmetros: 0 -  aguardando pagamento   | 1 - pago e em preparacao | 2 - expedido
  struct no *prox;
} Pedido;

/* CRUD
Criar 3 - Obra vendida? Gere um pedido aqui OK
Remover 9 - Excluir pedido OK
Atualizar - nAO VAI SER POSSIVEL, PRECISA CANCELAR O PEDIDO (REMOVER) E CRIAR OUTRO
Consultar 4 - Consultar lista de pedidos +obter tamanho da lista OK
*/

int Inicializar_LS(Pedido **inicio) {
  *inicio = NULL;
  return 0;
}

int Inserir_Novo_Pedido(Pedido **inicio, int id, int valor, int *idObra) {
  Pedido *no_novo, *percorre;

  /* Criacao do novo no - Aloca��o de memoria */
  no_novo = (Pedido *)malloc(sizeof(Pedido));
  no_novo->id = id;
  no_novo->valorPedido = valor;
  no_novo->id_produto = *idObra;
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

int Listar_Pedidos(Pedido *inicio) {
  int i, tam, *idObra;
  Pedido *aux;

  if (inicio == NULL) {
    return 1; /* lista vazia */
  }
  printf("\nLISTA DE PEDIDOS ::  ");
  printf("\nAtualmente, existem %d pedidos na sua lista.", Obter_Tamanho_Lista(inicio, &tam));
  aux = inicio;
  do {
    printf("ID DO PEDIDO: %d", inicio->id);
    printf("VALOR DO PEDIDO: %d", inicio->valorPedido);
    printf("DADOS DA OBRA:\n", buscarObra(inicio, *idObra, i)); // remover o nivel
    printf("SITUAÇÃO: %d", inicio->situacao);                   // eu tenho que pegar essa situacao do pagamento. como?

    inicio = inicio->prox;
  } while (inicio != NULL);

  printf("\n");
  return 0;
}

int Obter_Tamanho_Lista(Pedido *inicio, int *tam) {
  Pedido *percorre;
  *tam = 0;
  if (inicio != NULL) {
    percorre = inicio;
    while (percorre != NULL) {
      (*tam)++;
      percorre = percorre->prox;
    }
  } else {
    *tam = 0;
  }
}

int Remover_Pedido(Pedido **inicio, int num) {
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
