#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "obras_arvore.h"
#include "pagamento_pilha.h"
#include "pedido_lista.h"
#include "expedicao_fila.h"

int main()
{
	int q, erro, idObra, erroArvore, idExpedicao, idPagamento, valorPedidoPagamento, situacaoPagamento, idPedido, valorPedido;

    Pedido *ini;
    Pagamento *iniciar;
	tipoNoListaDupla *raizArvore, *buscaArvore;
	Fila filaExpedicao;

	erroArvore = inicializarArvore(&raizArvore);

	if (erroArvore > 0) {
		printf("Ocorreu um erro ao inicializar o banco de obras");
	}

	erro = inicializarLista(&ini);

	do {
		printf("\nGERENCIAMENTO - ACERVO OBRAS DE ARTE\n");
		printf("\nOpcoes:\n");
		printf("1 - Cadastrar novas obras\n");
		printf("2 - Consultar acervo\n");
		printf("3 - Buscar obra especifica\n");
		printf("4 - Obra vendida? Gere um pedido aqui\n");
		printf("5 - Consultar lista de pedidos\n");
		printf("6 - Atualize o status do pagamento de um pedido\n");
		printf("7 - Verificar Pagamentos\n");
		printf("8 - Expedir pedido com pagamento realizado\n");
		printf("9 - Excluir obra do acervo\n");
		printf("10 - Excluir pedido\n");
		printf("11 - Lista de pedidos expedidos\n");
		printf("12 - Sair\n");
		scanf("%d", &q);

		switch (q) {
		case 1:
			printf("\nInforme os dados da obra para inseri-la no acervo:\n");
			erroArvore = inserirObraNaArvore(&raizArvore, criarObra());
			if (erro == 0) {
				printf("\nObra cadastrada no acervo com sucesso!\n");
				printf("Pressione ENTER para retornar ao menu principal\n");
			}
			break;

		case 2:
			mostrarTodasObras(raizArvore, 0);
			break;

		case 3:
			printf("\nDigite o identificador da obra a ser buscada: \n");
			scanf("%d", &q);
			buscaArvore = buscarObra(raizArvore, q);
			if (!buscaArvore) {
				printf("Obra nao encontrada!\n");
			}
			break;

		case 4:
			printf("\nInsira os dados do seu pedido para cria-lo:\n");
			printf("\nIdentificador do pedido: ");
			scanf("%d", &idPedido);
			printf("\nValor do pedido: ");
			scanf("%d", &valorPedido);
			printf("\n* -----------------------------------------------------------------------------\n");
			printf("\nEssas são as obras em estoque. Escolha a que vai para o pedido e digite seu ID:\n");
			mostrarTodasObras(raizArvore, 0);
			printf("* -----------------------------------------------------------------------------\n");
			printf("\nIdentificador da obra vendida: ");
			scanf("%d", &idObra);

			erro = inserirNovoPedido(&ini, idPedido, valorPedido, idObra);
			if (erro == 0) {
				printf("\nSeu pedido foi criado. Acesse a opcao 5 para verificar todos os seus pedidos\n");
			}
			break;

		case 5:
			erro = listarPedidos(ini, raizArvore);
			if (erro == 1) {
				printf("\nNao ha nenhum pedido cadastrado\n");
			}
			break;

		case 6:
			printf("\nInsira o ID do pedido que foi pago:\n");
			scanf("%d", &idPedido);
			atualizarSituacaoPedido(ini, idPedido);

			if (&filaExpedicao == NULL) {
				inicializaFila(&filaExpedicao);
			}

			time_t seconds;
			seconds = time(NULL);

			erro = inserirFila(&filaExpedicao, seconds, idPedido);

			if (erro == 1) {
				printf("\nFila cheia.\n");
			}

			break;
		case 7:
			printf("\nLista de Pagamentos a serem confirmados:\n");
			ConsultarPag0(ini, raizArvore);
			
			printf("\nLista de Pedidos já pagos:\n");
			ConsultarPag1(ini, raizArvore);

			getchar();

			break;
		case 8:
			erro = consultarFila(&filaExpedicao, &idExpedicao, &idPedido);

			if (erro == 0) {
                if (removerFila(&filaExpedicao) == 1) {
                    printf("\nFila Vazia.\n");
                } else {
					expedirPedido(ini, idPedido);
					printf("A ordem %d do pedido %d foi expedida com sucesso!\n", idExpedicao, idPedido);
				}
			} else {
				printf("fila vazia.\n");
			}

			break;

		case 9:
			printf("\nInsira o ID da obra a ser excluida:\n");
			scanf("%d", &q);
			raizArvore = excluirObra(raizArvore, q);
			break;

		case 10:
			printf("\nDigite o ID do pedido que deseja excluir: ");
			scanf("%d", &idPedido);
			erro = excluirPedido(&ini, idPedido);
			if (erro == 0) {
				printf("\nPedido removido.\n");
			}
			break;

		case 11:
			printf("\n* -----------------------------------------------------------------------------\n");
			printf("\nEsses são os pedidos que foram pagos e enviados para o comprador: \n");
			listarPedidosExpedidos(ini);
			printf("* -----------------------------------------------------------------------------\n");
			break;

		case 12:
		//return 1;
			break;

		default:
			printf("\n\n Opcao invalida");
		}
		getchar();
	} while (q != 11);
}
