#include <stdlib.h>
#include <stdio.h>

/* Estrutura dos produtos - Árvore Binária de Busca
Campos: id, largura, altura, comprimento e local */
typedef struct {
  int id;
  int largura;
  int altura;
  int profundidade;
  char localizacao[100];
  char nome[50];
} Obra;

typedef struct noListaDupla {
	Obra obra;
	struct noListaDupla *esquerda, *direita;
} tipoNoListaDupla;

Obra criarObra(){ // Cadastro de produtos a serem inseridos na árvore
  Obra novoProduto;
  printf("Digite o nome da obra: ");
  getchar();
  fgets(novoProduto.nome, 49, stdin);

  printf("Digite o identificador da obra: ");
  scanf("%d", &novoProduto.id);

  return novoProduto;
}

void criarNovoNo(tipoNoListaDupla **inicio, Obra obra){ // Alocação de memória para um novo nó
  tipoNoListaDupla *novoNo;

  novoNo = (tipoNoListaDupla *) malloc(sizeof(tipoNoListaDupla));
  novoNo->obra = obra; // Campo obra da struct do nó recebe de fato a obra
  novoNo->esquerda = NULL;
  novoNo->direita = NULL;

  *inicio = novoNo;
}

void inserirObraNaArvore(tipoNoListaDupla **raiz, Obra produtoParaInserir){
  if (!*raiz){
    criarNovoNo(raiz, produtoParaInserir);
  } else{
    if (produtoParaInserir.id < (*raiz)->obra.id){
      inserirObraNaArvore(&((*raiz)->esquerda), produtoParaInserir);
    } else{
      inserirObraNaArvore(&((*raiz)->direita), produtoParaInserir);
    }
  }
}

tipoNoListaDupla* buscarObra(tipoNoListaDupla *raiz, int id, int nivel) {
  if (raiz){
    if (id == raiz->obra.id){
      printf("A obra %d foi encontrado na profundidade: %d\n", raiz->obra.nome, nivel);
      return raiz;
    } else if (id < raiz->obra.id){
      return buscarObra(raiz->esquerda, id, nivel + 1);
    } else {
      return buscarObra(raiz->direita, id, nivel + 1);
    }
  }
  return NULL;
}

int buscarTotalProdutos(tipoNoListaDupla *raiz){
  if (!raiz) {
    return 0;
  } else {
    return 1 + buscarTotalProdutos(raiz->esquerda) + buscarTotalProdutos(raiz->direita);
  }
}

int salvarAlturaObra(tipoNoListaDupla *raiz){
  if (!raiz){
    return -1;
  } else {
    int esquerdaDoNo = salvarAlturaObra(raiz->esquerda);
    int direitaDoNo = salvarAlturaObra(raiz->direita);

    if(esquerdaDoNo > direitaDoNo){
      raiz->obra.altura = esquerdaDoNo + 1;
    } else {
      raiz->obra.altura = direitaDoNo + 1;
    }
  }
}

tipoNoListaDupla* excluirObra(tipoNoListaDupla *raiz, int identificador) { // O identificador é o id da obra
  if (!raiz){
    printf("Obra não encontrada!\n");
    return NULL;
  } else { 
    if(raiz->obra.id == identificador) { 
      if(!raiz->esquerda && !raiz->direita) {
        free(raiz);
        printf("A obra de identificador %d foi removida!\n", identificador);
        return NULL;
      } else { 
        if(raiz->esquerda && raiz->direita) { 
          Obra produtoParaRemover;
          tipoNoListaDupla *noAuxiliar = raiz->direita; 

          while(noAuxiliar->esquerda) { 
            noAuxiliar = noAuxiliar->esquerda;
          }

          produtoParaRemover = raiz->obra;
          raiz->obra = noAuxiliar->obra;
          noAuxiliar->obra = produtoParaRemover; 
          raiz->direita = excluirObra(raiz->direita, identificador);
          return raiz;
        } else { 
          tipoNoListaDupla *noAuxiliar;
          if(raiz->direita) {
            noAuxiliar = raiz->direita;
          } else {
            noAuxiliar = raiz->esquerda;
          }
          free(raiz);
          printf("A obra de identificador %d foi removida!\n", identificador);
          return noAuxiliar;
        }
      }
    } else { 
      if(identificador < raiz->obra.id){
        raiz->esquerda = excluirObra(raiz->esquerda, identificador);
      } else {
        raiz->direita = excluirObra(raiz->direita, identificador);
      }
      return raiz;
    }
  }
}
