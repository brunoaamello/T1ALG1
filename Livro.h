#ifndef LIVRO_H_INCLUDED
#define LIVRO_H_INCLUDED
#include "BaseHeader.h"

typedef struct {
    char titulo[50], autor[50], editora[30];
    uint64 isbn;
    int ano, edicao, copias, disponiveis;
    Lista* fila;
}Livro;


#endif // LIVRO_H_INCLUDED
