#include "Lista.h"

//  FILA
int entraLista(Lista* lista, void* elemento){
    return insereInicio(lista, elemento);
}
void* saiLista(Lista* lista, int* erro){
    return retiraFim(lista, erro);
}

//  PILHA
int pushLista(Lista* lista, void* elemento){
    return insereInicio(lista, elemento);
}
void* popLista(Lista* lista, int* erro){
    return retiraInicio(lista, erro);
}

//  LISTA

void initLista(Lista* lista){
    lista->fim=NULL;
    lista->inicio=NULL;
    lista->tamanho=0;
}

void limpaLista(Lista* lista){
    int erro;
    while(lista->tamanho != 0){
        retiraInicio(lista, erro);
    }
}

void* atLista(Lista* lista, uint32 posicao, int* erro){
    void* saida;
    if(posicao >= lista->tamanho){
        *erro = 1;
        return NULL;
    }
    Node* no = getNode();
    no->valor = lista->inicio->valor;
    no->prox = lista->inicio->prox;
    uint32 i;
    for(i=0;i<lista->tamanho;i++){
        if(i == posicao){
            *erro  = 0;
            saida = no->valor;
            freeNode(no);
            return saida;
        }
        no->valor=no->prox->valor;
        no->prox=no->prox->prox;
    }
    freeNode(no);
    *erro = 1;
    return NULL;
}
void* getLista(Lista* lista, uint32 posicao, int* erro){
    void* saida;
    if(posicao >= lista->tamanho){
        *erro = 1;
        return NULL;
    }
    Node* no = lista->inicio;
    uint32 i;
    for(i=0;i<lista->tamanho;i++){
        if(i == posicao){
            saida = no->valor;
            no->anterior->prox = no->prox;
            no->prox->anterior = no->anterior;
            *erro = freeNode(no);
            return saida;
        }
        no=no->prox;
    }
    *erro = 1;
    return NULL;
}


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
    lista->tamanho++;
    return 1;
}

void* retiraFim(Lista* lista, int* erro){
    Node* no;
    void* saida;
    if(lista->tamanho == 0){
        *erro = 1;
        return NULL;
    }
    lista->tamanho--;
    no = lista->fim;
    if(lista->inicio == lista->fim){
        lista->inicio = NULL;
    }
    lista->fim = lista->fim->anterior;
    saida = no->valor;
    *erro = freeNode(no);
    return saida;
}

void* retiraInicio(Lista* lista, int* erro){
    Node* no;
    void* saida;
    if(lista->tamanho == 0){
        *erro = 1;
        return NULL;
    }
    lista->tamanho--;
    no = lista->inicio;
    if(lista->inicio == lista->fim){
        lista->fim = NULL;
    }
    lista->inicio = lista->inicio->prox;
    saida = no->valor;
    *erro = freeNode(no);
    return saida;
}
