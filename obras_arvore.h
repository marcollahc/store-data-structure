#include <stdlib.h>
#include <stdio.h>

/* Estrutura dos produtos - Árvore Binária de Busca
Campos: id, largura, altura, comprimento e local */
typedef struct {
  int id;
  float largura;
  float altura;
  float peso;
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

  printf("Digite a altura da obra em mm: ");
  scanf("%f", &novoProduto.altura);

  printf("Digite a largura da obra em mm: ");
  scanf("%f", &novoProduto.largura);

  printf("Digite o peso da obra em gramas: ");
  scanf("%f", &novoProduto.peso);

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

int inicializarArvore(tipoNoListaDupla **inicio) {
	*inicio = NULL;
	return 0;
}

int inserirObraNaArvore(tipoNoListaDupla **raiz, Obra produtoParaInserir) {
  if (!*raiz){
    criarNovoNo(raiz, produtoParaInserir);
  } else {
    if (produtoParaInserir.id < (*raiz)->obra.id) {
      inserirObraNaArvore(&((*raiz)->esquerda), produtoParaInserir);
    } else{
      inserirObraNaArvore(&((*raiz)->direita), produtoParaInserir);
    }
  }

  return 0;
}

tipoNoListaDupla* buscarObra(tipoNoListaDupla *raiz, int id) {
  if (raiz) {
    if (id == raiz->obra.id){
      printf("Obra encontrada!\n");
      printf("Nome: %s\n", raiz->obra.nome);
      printf("Identificador: %d\n", raiz->obra.id);
      printf("Altura: %f\n", raiz->obra.altura);
      printf("Largura: %f\n", raiz->obra.largura);
      printf("Peso: %f\n", raiz->obra.peso);
      return raiz;
    } else if (id < raiz->obra.id){
      return buscarObra(raiz->esquerda, id);
    } else {
      return buscarObra(raiz->direita, id);
    }
  }
  return NULL;
}

void mostrarTodasObras(tipoNoListaDupla *raiz, int nivel){
  if (raiz) {
    mostrarTodasObras(raiz->esquerda, nivel + 1);
    printf("Nome da obra: %s | Id: %d | Nível na árvore binária(%d)\n\n", raiz->obra.nome, raiz->obra.id, nivel);
    mostrarTodasObras(raiz->direita, nivel + 1);
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
