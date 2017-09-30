#ifndef ALLOCATIONSSTATIC_H_INCLUDED
#define ALLOCATIONSSTATIC_H_INCLUDED

#include "Banco.h"

void init();
Node*         getNode();
Aluno*        getAluno();
Livro*          getLivro();
char*           getMensagem();
int                 freeNode(Node*);
int                 freeAluno(Aluno*);
int                 freeLivro(Livro*);
int                 freeMensagem(char*);

#endif // ALLOCATIONSSTATIC_H_INCLUDED
