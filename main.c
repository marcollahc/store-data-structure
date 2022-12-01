#include <stdlib.h>
#include <stdio.h>
#include "pagamento_pilha.c"
#include  "pedido_lista.c"

int main (){
    //declarar variaveis aqui
    int q;

    do {
        printf("\nGERENCIAMENTO - ACERVO OBRAS DE ARTE\n");
        printf("\nOpções:\n");
        printf("1 - Cadastrar novas obras\n");
        printf("2 - Consultar acervo\n");
        printf("3 - Obra vendida? Gere um pedido aqui\n");
        printf("4 - Consultar lista de pedidos\n");
        printf("5 - Atualize o status do pagamento de um pedido \n");
        printf("6 - Expedir pedido com pagamento realizado \n");

        printf("\nTarefas de gerenciamento :\n");
        printf("7 - Excluir obra do acervo \n");
        printf("8 - Atualizar localização da obra no estoque \n");
        printf("9 - Excluir pedido\n");
        printf("10 - Atualizar dados do pedido \n");
        printf("11 -  \n");
        printf("12 -  \n");
        printf("13 -  \n");
        printf("14 -  \n");
        printf("15 -  \n");
        scanf("%d", &q);

        switch(q) {
            case 1:
            break;

            case 2:
            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
            break;

            case 6:
            break;

            case 7:
            break;

            case 8:
            break;

            case 9:
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

            default: printf("\n\n Opção inválida");

        }
        getchar();

    } while (q != 15);


}
