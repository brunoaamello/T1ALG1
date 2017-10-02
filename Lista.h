/*
    TRABALHO 1 -- SSC0502 -- ALGORITMOS E ESTRUTURAS DE DADOS
    PROFESSOR: Bruno Roberto Nepomuceno Matheus
    ALUNOS:
        Bruno Arantes de Achilles Mello     9866490
        Laura Pereira de Gouveia                  9880200
*/

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "AllocationsStatic.h"
//#include "AllocationsDyn.h"

//###   FUNCOES BASICAS DE FILA     ###
//  FUNCAO QUE COLOCA NO FIM DA FILA
int entraLista(Lista* lista, void* elemento);

//  FUNCAO QUE RETIRA DO INICIO DA FILA
void* saiLista(Lista* lista, int* erro);

//################################

//###   FUNCOES BASICAS DE PILHA    ###
//  FUNCAO QUE COLOCA NO TOPO DA PILHA
int pushLista(Lista* lista, void* elemento);

//  FUNCAO QUE PEGA DO TOPO DA PILHA
void* popLista(Lista* lista, int* erro);

//################################


//###  FUNCOES DE LISTA     ###

//  INICIALIZA A LISTA
void initLista(Lista* lista);

//  LIMPA A LISTA
void limpaLista(Lista* lista);

//  RETORNA O ELEMENTO NA POSICAO ESPECIFICADA NA LISTA
void* atLista(Lista* lista, uint32 posicao, int* erro);

//  RETIRA E RETORNA O ELEMENTO NA POSICAO ESPECIFICADA NA LISTA
void* getLista(Lista* lista, uint32 posicao, int* erro);

//  CHECA SE A LISTA ESTA VAZIA
int estaVazia(Lista* lista);

//  INSERE NO FIM DA LISTA
int insereFim(Lista* lista, void* elemento);

//  INSERE NO INICIO DA LISTA
int insereInicio(Lista* lista, void* elemento);

//  RETIRA DO FIM DA LISTA
void* retiraFim(Lista* lista, int* erro);

//  RETIRA DO INICIO DA LISTA
void* retiraInicio(Lista* lista, int* erro);

//################################


#endif // LISTA_H_INCLUDED
