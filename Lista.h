#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef unsigned int uint32;
typedef unsigned long long int uint64;

typedef struct{
    void*   valor;
    void*   prox;
}No;

typedef struct {
    No* inicio;
    No* fim;
    uint32 tamanho;
}Lista;

int estaVazia(Lista* lista);

#endif // LISTA_H_INCLUDED
