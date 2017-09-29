#include "Lista.h"

//  FILA
int entraLista(Lista* lista, void* elemento);
int saiLista(Lista* lista, void* saida);

//  PILHA
int pushLista(Lista* lista, void* elemento);
int popLista(Lista* lista, void* saida);

//  LISTA
int atLista(void* saida, Lista* lista, uint32 posicao);
int getLista(void* saida, Lista* lista, uint32 posicao);


int estaVazia(Lista* lista){
    if(lista->tamanho == 0)
        return 1;
    else
        return 0;
}

int insereFim(Lista* lista, void* elemento){
    Node* no = getNode();
    if(no == NULL){
        return 0;
    }
    lista->tamanho++;
    no->valor = elemento;
    no->prox = NULL;
    if(lista->tamanho == 0){
        no->anterior = NULL;
        lista->fim = no;
        lista->inicio = no;
    }else{
        no->anterior = lista->fim;
        lista->fim->prox = no;
        lista->fim = no;
    }
    return 1;
}

int insereInicio(Lista* lista, void* elemento){
    Node* no = getNode();
    if(no == NULL){
        return 0;
    }
    lista->tamanho++;
    no->anterior = NULL;
    no->valor = elemento;
    if(lista->tamanho == 0){
        no->prox = NULL;
        lista->fim = no;
        lista->inicio = no;
    }else{
        no->prox = lista->inicio;
        lista->inicio->anterior = no;
        lista->inicio = no;
    }
    return 1;
}

int retiraFim(Lista* lista, void* saida){
    if(lista->tamanho == 0){
        return 0;
    }
    lista->tamanho--;
    saida = lista->fim;
    if(lista->inicio == lista->fim){
        lista->inicio = NULL;
    }
    lista->fim = lista->fim->anterior;
}
int retiraInicio(Lista* lista, void* saida);
