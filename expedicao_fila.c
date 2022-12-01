/*---------------------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
/*---------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
Estrutura LISTA ENCADEADA SIMPLES
------------------------------------------------------------------------------*/

struct no_ls
{
    int dado;
    struct no_ls *prox;
};
typedef struct no_ls Tno_ls;

typedef struct no_pedido {
    int id;
    int valorPedido;
    int id_produto; //Cadastrar alguns produtos e, na main, deixar a pessoa decidir qual produto vai inserir
    int situacao; //parâmetros: 0 -  aguardando pagamento   | 1 - pago e em preparacao | 2 - expedido
    struct no *prox;
} Pedido;

typedef struct no_expedicao {
    int id;
    Pedido pedido;
    int situacao; //parâmetros: 0 -  aguardando pagamento   | 1 - pago e em preparacao | 2 - expedido
    struct no_expedicao *prox;
} Expedicao;

/* Tabela de codigo de erros
// 0 - sem erro
// 1 - ...
// 2 - ...
*/

/* -----------------------------------------------------------------------------
Prototipos das funcoes
------------------------------------------------------------------------------*/
int Inicializar_LS                  (Tno_ls **P_inicio);
int Inicializar2_LS               (Tno_ls **P_inicio);
int Inserir_inicio_LS           (Tno_ls **P_inicio, int info);
int Inserir_fim_LS                (Tno_ls **P_inicio, int info);
int Inserir_meio_LS             (Tno_ls **P_inicio, int info, int pos);
int Remover_inicio_LS       (Tno_ls **P_inicio);
int Listar_LS                         (Tno_ls *CP_inicio);
int Obter_pos_LS                (Tno_ls *CP_inicio, int dado, int *pos);
int Obter_Tamanho_LS      (Tno_ls *CP_inicio, int *tam);
int Inverte_LS                       (Tno_ls **P_inicio);
int Inserir_fim_varios          (Tno_ls **P_inicio, int dados[], int n);

// ------------ FAZER
int Obter_dado_LS             (Tno_ls *inicio, int pos, int *dado);
int Remover_meio_LS        (Tno_ls **P_inicio, int pos);
int Remover_fim_LS           (Tno_ls **P_inicio);
int Inserir_ordenado_LS       (Tno_ls **P_inicio, int info);
int Inverte_LS_2                   (Tno_ls **P_inicio);
/* inverter a lista encadeada usando as rotinas prontas */


int Repete_Dado_LS         (Tno_ls *inicio, int info, int *resp);
/* verifica se o dado esta repetido na estrutura */
/* resp = 1 - sim */
/* resp = 0 - nao */

int Maiorque_Dado_LS        (Tno_ls *inicio, int info, int *quant);
/* obtem a quantidade de dados maior que info */



/* Variaveis global */
// NENHUMA

int BaixaPagamento (Tno_ls *inicio,)

/* -----------------------------------------------------------------------------
PRINCIPAL
------------------------------------------------------------------------------*/
int main(void)
{

    int info;
    int resp, pos;
    int erro; /* valor de erro retornado pelas funcoes */


    Tno_ls *ini; // a lista est� aqui


    int q;  /* receber a opcao do usuario */
    erro=Inicializar_LS (&ini);

    do
    {
        system("cls");
        printf("LISTA ENCADEADA SIMPLES - LES");
        printf("\n\nOpcoes: \n\n");
        printf("1 -> Inserir no inicio \n");
        printf("2 -> Inserir no final\n");
        printf("3 -> Remover no inicio\n");
        printf("4 -> Mostrar toda a lista \n");
        printf("5 -> Inicializar a lista (versao 2)\n");
        printf("6 -> Inverter a lista\n");
        printf("7 -> Verifica a repeticao de um dado\n");
        printf("8 -> Remover no meio\n");
        printf("9 -> Remover no fim\n");
        printf("10 -> Inserir varios\n");
        printf("11 -> Sair \n:");
        scanf("%d", &q);     /* Ler a opcao do usuario */
        switch(q)
        {
        case 1:
            printf("Dado para insercao na lista: ");
            scanf("%d",&info);
            erro=Inserir_inicio_LS (&ini, info);
            if (erro == 0) printf("Insercao realizada com sucesso\n");
            system("pause");
            break;
        case 10:
            int dados[5];
            printf("5 dados para insercao na lista: ");
            scanf("%d%d%d%d%d",&dados[0],&dados[1],&dados[2],&dados[3],&dados[4]);
            erro=Inserir_fim_varios (&ini, dados, 5);
            if (erro == 0) printf("Insercao realizada com sucesso\n");
            system("pause");
            break;
        case 2:
            printf("Dado para insercao na lista: ");
            scanf("%d",&info);
            Inserir_fim_LS (&ini, info);
            break;
        case 3:
            erro = Remover_inicio_LS (&ini);
            if (erro==1)
            {
                printf("\nLista vazia. Impossivel remover");
            }
            system("pause");
            break;
        case 4:
            erro=Listar_LS (ini);
            if (erro==1)
            {
                printf("\nLista vazia. Impossivel listar");
            }
            system("pause");
            break;
        case 5:
            erro=Inicializar2_LS (&ini);
            printf("\nInicializacao realizada com sucesso !\n");
            printf("\nLISTA VAZIA !\n");
            system("pause");
            break;
        case 6:
            erro=Inverte_LS (&ini);
            if (erro == 1)
                printf("\nLista vazia. Inversao nao realizada !\n");
            else
                printf("\nInversao realizada !\n");
            system("pause");
            break;
        case 7:
            printf("Dado para pesquisa na lista: ");
            scanf("%d",&info);
            erro = Repete_Dado_LS (ini, info, &resp);
            if (erro!=0)
                printf("\nErro na opera��o");
            else
                printf("\nResposta (1:sim, 0:Nao) : %d \n",resp);
            system("pause");
            break;
        case 8:
            printf("Posi��o para remover da lista: ");
            scanf("%d",&info);
            erro=Remover_meio_LS (&ini, info);
            system("pause");
            break;
        case 9:
            erro = Remover_fim_LS (&ini);
            if (erro==1)
            {
                printf("\nLista vazia. Impossivel remover");
            }
            system("pause");
            break;
        case 11:
            break;
        default:
            printf("\n\n Opcao nao valida");
        }
        getchar();    /* Limpa o buffer de entrada */
    }
    while ((q != 11) );

}

int Inserir_fim_varios (Tno_ls **inicio, int dados[], int n)
{
    for (int i=0; i < n; i++)
    {
        Inserir_fim_LS(inicio, dados[i]);
    }
    return 0;
}

/* ------------------------------------------------------------------------------------
LISTAR todos os elementos presentes na lista encadeada
--------------------------------------------------------------------------------------*/
int Listar_LS (Tno_ls *inicio)
{
    int i;
    Tno_ls *aux;

    if (inicio == NULL)
    {
        return 1;  /* lista vazia */
    }
    printf("LISTA ::  ");
    aux = inicio;
    do
    {
        printf(" %d",inicio -> dado);
        inicio = inicio->prox;
    }
    while (inicio != NULL);

    printf("\n");
    return 0; /* sem erro */
} /* Fim da fun��o de MOSTRAR */



/* ------------------------------------------------------------------------------------
INICIALIZAR
--------------------------------------------------------------------------------------*/
int Inicializar_LS (Tno_ls **inicio)
{
    *inicio= NULL;


    return 0; /* sem erro */
} /* Fim da fun��o de INICIALIZAR */
/* ================================================= */

int Inicializar2_LS(Tno_ls **inicio)
{
    Tno_ls *percorre, *aux;
    if(*inicio != NULL)
    {
        percorre = *inicio;
        do
        {
            aux = percorre;
            percorre = percorre->prox;
            free(aux);
        }
        while (percorre != *inicio);
        *inicio = NULL;
        return 1; /* inicializa apagando tudo da listsa */
    }
    else
    {
        return 0;
    }
}


/* ================================================= */
int Obter_Tamanho_LS(Tno_ls *inicio, int *tam)
{
    Tno_ls *percorre;
    *tam = 0;
    if(inicio != NULL)
    {
        percorre = inicio;
        while (percorre != NULL)
        {
            (*tam)++;
            percorre = percorre -> prox;
        }
    }
    else
    {
        *tam = 0;
    }
}

/* -------------------------------------------------------------------------------------
INSER��O
---------------------------------------------------------------------------------------*/
int Inserir_inicio_LS (Tno_ls **inicio, int info)
{
    Tno_ls *no_novo;

    /* Criacao do novo no - Aloca��o de memoria */
    no_novo = (Tno_ls *) malloc(sizeof(Tno_ls));
    no_novo -> dado = info;

    if (*inicio==NULL)
    {
        /* insercao em lista vazia */
        no_novo -> prox = NULL;
        *inicio = no_novo;
    }
    else   /* insercao em lista nao vazia */
    {
        no_novo -> prox = *inicio;
        *inicio = no_novo;
    }
    return 0;
}

/* ================================================= */
int Inserir_meio_LS (Tno_ls **inicio, int info, int pos)
{
    int tam;
    Tno_ls *no_novo, *percorre;

    /* Tratamento de erros ======================================= */
    if (pos<= 0)
        return 1;  /*) posicao invalida para insercao */

    Obter_Tamanho_LS(*inicio, &tam);
    if (pos > tam+1)
        return 2;   /* posicao invalida. Acima do tamanho da lista */
    /* ================================================= */

    /* Alocacao do novo no */
    no_novo = (Tno_ls *)malloc(sizeof(Tno_ls));
    no_novo -> dado = info;

    /* procura pela posicao de insercao */
    if (pos==1)
    {
        /* insercao no inicio */
        Inserir_inicio_LS (inicio, info);
    }
    else
    {
        if (pos == tam+1)
        {
            Inserir_fim_LS (inicio, info);
        }
        else
        {
            int pos_aux=1;
            percorre = *inicio;
            while (pos_aux!=pos-1) /* parar uma posicao antes */
            {
                percorre = percorre -> prox;
                pos_aux++;
            }
            no_novo -> prox = percorre -> prox;
            percorre -> prox = no_novo;
        }
    }
    return 0;
}

/* ---------------------------------------------------------------------------------------

------------------------------------------------------------------------------------------*/
int Inserir_fim_LS (Tno_ls **inicio, int info)
{
    Tno_ls *no_novo, *percorre;

    /* Criacao do novo no - Aloca��o de memoria */
    no_novo = (Tno_ls *) malloc(sizeof(Tno_ls));
    no_novo -> dado = info;
    no_novo -> prox = NULL;

    if (*inicio==NULL)
    {
        /* lista vazia. */
        *inicio = no_novo;
    }
    else   /* lista nao vazia */
    {
        percorre = *inicio;
        while (percorre->prox != NULL)
        {
            percorre = percorre -> prox;
        }
        percorre->prox = no_novo;
    }
    return 0;
}

/* ================================================= */
int Obter_Pos_LS (Tno_ls *inicio, int valor, int *pos)
{
    *pos = 0;
    while (inicio != NULL)
    {
        (*pos)++;
        if (valor == inicio->dado)
            return 0;     /* dado encontrado */
        inicio = inicio -> prox;
    }
    if (inicio == NULL)
        *pos = 0;
    return 1;  /* dado nao encontrado */
}


/* -------------------------------------------------------------------------
REMOCAO
-------------------------------------------------------------------------*/
int Remover_inicio_LS (Tno_ls **inicio)
{
    Tno_ls *aux;
    if (*inicio == NULL)
    {
        printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover primeiro */
    }
    else
    {
        aux = *inicio;
        *inicio = (*inicio)->prox;
        free(aux);
        return 0;
    }
}
/*=====================================================================*/
int Remover_fim_LS (Tno_ls **inicio)
{
    Tno_ls *aux, *percorre;
    int tamanho=0;
    if (*inicio == NULL)
    {
        printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover ultimo */
    }
    else
    {
        Obter_Tamanho_LS(*inicio, &tamanho);
        if (tamanho == 1)
        {
            Remover_inicio_LS(inicio);
        }
        else
        {
            percorre = *inicio;
            while (percorre->prox != NULL)
            {
                aux = percorre;
                percorre = percorre -> prox;
            }
            aux->prox = NULL;
            free(percorre);
            return 0;
        }
    }
}
/*=========================================================================*/
int Remover_meio_LS (Tno_ls **inicio, int pos)
{
    int tam;
    Tno_ls *aux, *percorre;

    /* Tratamento de erros ======================================= */
    if (pos<= 0)
        return 1;  /*) posicao invalida para remocao */

    Obter_Tamanho_LS(*inicio, &tam);
    if (pos > tam)
        return 2;   /* posicao invalida. Acima do tamanho da lista */
    /* ================================================= */
    /* procura pela posicao de remocao */
    if (pos==1)
    {
        /* remocao no fim */
        Remover_inicio_LS(inicio);
    }
    else
    {
        if (pos == tam)
        {
            Remover_fim_LS(inicio);
        }
        else
        {
            int pos_aux=1;
            percorre = *inicio;
            while (pos_aux!=pos) /* parar uma posicao antes */
            {
                aux = percorre;
                percorre = percorre -> prox;
                pos_aux++;
            }
            aux -> prox = percorre -> prox;
            free(percorre);
        }
    }
    return 0;
}
/* -------------------------------------------------------------------------
INVERTER LISTA
-------------------------------------------------------------------------*/
int Inverte_LS (Tno_ls **inicio)
{
    Tno_ls *percorre,*aux_1,*aux_2,*aux_3;
    percorre=*inicio;
    if(percorre==NULL)
    {
        return 1;/*Caso a lista esteja vazia. */
    }
    else if(percorre->prox==NULL)
    {
        return 0;/*Caso a lista tenha apenas um n�. */
    }
    else
    {
        aux_1       = *inicio;        /*O ponteiro aux_a aponta para o primeiro n�, uma vez que o ponteiro "ini" passar� a apontar para o �ltimo. */
        aux_2       = aux_1->prox;    /*O ponteiro aux_p passa a apontar para o segundo n� da lista.*/
        aux_3       = aux_2->prox;    /*O ponteiro aux_v passa a apontar para o terceiro n� da lista.*/
        aux_1->prox = NULL;           /*O primeiro n� da lista passa a ser o �ltimo, apontando para NULL.*/
        aux_2->prox = aux_1;          /*O segundo n� da lista passa a apontar para o primeiro, come�ando a invers�o da lista.*/
        /*In�cio - Processo de invers�o.*/
        while(aux_3!=NULL)
        {
            aux_1 = aux_2;             /*O ponteiro aux_a pega o valor do n� a sua frente na lista.*/
            aux_2 = aux_3;             /*O ponteiro aux_p pega o valor do n� a sua frente na lista.*/
            aux_3 = aux_3->prox;       /*O ponteiro aux_v pega o valor do n� a sua frente na lista.*/
            aux_2->prox=aux_1;         /*O n� para o qual aux_p est� apontado passa a apontar para o n� anterior a ele na lista.*/
        }
        /*Fim - Processo de invers�o. */
        *inicio = aux_2;               /* atualiza��o do ponteiro de inicio */
    }

    return 0;

}


int Repete_Dado_LS   (Tno_ls *inicio, int info, int *resp)
{
    int cont=0;  /* contagem de repeticoes*/
    if (inicio == NULL)
    {
        *resp = 0;  /* Dados nao repete */
        return 1;  /* lista vazia*/
    }
    while (inicio != NULL)
    {
        if (inicio->dado == info)
            cont++;
        inicio = inicio->prox;
    }
    if (cont > 1)
        *resp = 1;
    else
        *resp = 0;
    return 0; /* sem erro */
}
