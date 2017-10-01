#ifndef ALLOCATIONSDYN_H_INCLUDED
#define ALLOCATIONSDYN_H_INCLUDED

#include "Types.h"
#include <stdlib.h>

//  FUNCAO DE INICIO DO PROGRAMA, NA VERSAO DINAMICA EFETIVAMENTE NAO FAZ NADA
void init();

//  FUNCOES DE ALOCACAO, NA VERSAO DINAMICA E EFETIVAMENTE UM MALLOC
Node*        getNode();
Aluno*       getAluno();
Livro*         getLivro();
char*          getMensagem();

//  FUNCOES DE DESALOCACCAO, NA VERSAO DINAMICA E EFETIVAMENTE UM FREE
int                 freeNode(Node*);
int                 freeAluno(Aluno*);
int                 freeLivro(Livro*);
int                 freeMensagem(char*);

#endif // ALLOCATIONSDYN_H_INCLUDED
