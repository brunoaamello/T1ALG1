#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "AllocationsStatic.h"
#include "AllocationsDyn.h"

//  FILA
int entraLista(Lista* lista, void* elemento);
void* saiLista(Lista* lista, int* erro);

//  PILHA
int pushLista(Lista* lista, void* elemento);
void* popLista(Lista* lista, int* erro);

//  LISTA
void initLista(Lista* lista);
void* atLista(Lista* lista, uint32 posicao, int* erro);
void* getLista(Lista* lista, uint32 posicao, int* erro);
int estaVazia(Lista* lista);
int insereFim(Lista* lista, void* elemento);
int insereInicio(Lista* lista, void* elemento);
void* retiraFim(Lista* lista, int* erro);
void* retiraInicio(Lista* lista, int* erro);

#endif // LISTA_H_INCLUDED
