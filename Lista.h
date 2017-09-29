#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "AllocationsStatic.h"
#include "AllocationsDyn.h"

//  FILA
int entraLista(Lista* lista, void* elemento);
int saiLista(Lista* lista, void* saida);

//  PILHA
int pushLista(Lista* lista, void* elemento);
int popLista(Lista* lista, void* saida);

//  LISTA
int atLista(void* saida, Lista* lista, uint32 posicao);
int getLista(void* saida, Lista* lista, uint32 posicao);
int estaVazia(Lista* lista);
int insereFim(Lista* lista, void* elemento);
int insereInicio(Lista* lista, void* elemento);
int retiraFim(Lista* lista, void* saida);
int retiraInicio(Lista* lista, void* saida);

#endif // LISTA_H_INCLUDED
