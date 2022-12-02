#include <stdlib.h>
#include <stdio.h>
#include "obras_arvore.c"
#include "pagamento_pilha.c"
#include "pedido_lista.c"

int main() {
  Pedido *ini;                      // a lista dos pe� aqui
  int q, erro, *idObra, erroArvore; // usar o idobra como ponteiro pq ele vai ser importante em varios os cases???
  int idPedido, valorPedido;
  tipoNoListaDupla *raizArvore, *buscaArvore;

  erroArvore = inicializarArvore(&raizArvore);
  
  if (erroArvore > 0) {
    printf("Ocorreu um erro ao inicializar o banco de obras");
  }

  erro = Inicializar_LS(&ini);

  do {
    printf("\nGERENCIAMENTO - ACERVO OBRAS DE ARTE\n");
    printf("\nOpções:\n");
    printf("1 - Cadastrar novas obras\n");
    printf("2 - Consultar acervo\n");
    printf("3 - Buscar obra específica\n");
    printf("4 - Obra vendida? Gere um pedido aqui\n");
    printf("5 - Consultar lista de pedidos\n");
    printf("6 - Atualize o status do pagamento de um pedido \n");
    printf("7 - Expedir pedido com pagamento realizado \n");

    printf("\nTarefas de gerenciamento :\n");
    printf("8 - Excluir obra do acervo \n");
    printf("9 - Excluir pedido\n");
    printf("10 - \n");
    printf("11 - \n");
    printf("12 -  \n");
    printf("13 -  \n");
    printf("14 -  \n");
    printf("15 -  \n");
    printf("16 -  \n");
    scanf("%d", &q);

    switch (q) {
    case 1:
      printf("\nInforme os dados da obra para inseri-la no acervo:\n");
      erroArvore = inserirObraNaArvore(&raizArvore, criarObra());
      if (erro == 0) {
        printf("\nObra cadastrada no acervo com sucesso!\n");
      }
      break;

    case 2:
      mostrarTodasObras(raizArvore, 0);
      break;

    case 3:
      printf("\nDigite o identificador da obra a ser buscada: \n");
      scanf("%d", &q);
      buscaArvore = buscarObra(raizArvore, q, 0);
      if (!buscaArvore) {
        printf("Obra não encontrada!\n");
      }

      break;

    case 4:
      printf("\nInsira os dados do seu pedido para criá-lo:\n");
      printf("\nId do pedido: ");
      scanf("%d", &idPedido);
      printf("\nValor do pedido: ");
      scanf("%d", &valorPedido);
      printf("\nId da obra vendida: ");
      scanf("%d", &idObra);

      erro = Inserir_Novo_Pedido(&ini, idPedido, valorPedido, &idObra);
      if (erro == 0) {
        printf("\nSeu pedido foi criado. Acesse a opção 4 para verificar todos os seus pedidos\n");
      }
      break;

    case 5:
      erro = Listar_Pedidos(&ini);
      if (erro == 1) {
        printf("\nNão há nenhum pedido cadastrado\n");
      }
      break;

    case 6:
      break;

    case 7:
      break;

    case 8:
      printf("\nInsira o ID da obra a ser excluida:\n");
      scanf("%d", &q);
      raizArvore = excluirObra(raizArvore, q);
      break;

    case 9:
      printf("\nDigite o ID do pedido que deseja excluir: ");
      scanf("%d", &idPedido);
      erro = Remover_Pedido(&ini, idPedido);
      if (erro == 0) {
        printf("\nPedido removido.\n");
      }
      break;

    case 10:

      break;

    case 11:
      break;

    case 12:
      break;

    case 13:
      break;

    case 14:
      break;

    case 15:
      break;

    default:
      printf("\n\n Opção inválida");
    }
    getchar();
  } while (q != 15);
}
