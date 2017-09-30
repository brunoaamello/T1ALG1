#ifndef ALLOCATIONSDYN_H_INCLUDED
#define ALLOCATIONSDYN_H_INCLUDED

#include "Types.h"
#include <stdlib.h>

void init();
Node*        getNode();
Aluno*       getAluno();
Livro*         getLivro();
char*          getMensagem();
int                 freeNode(Node*);
int                 freeAluno(Aluno*);
int                 freeLivro(Livro*);
int                 freeMensagem(char*);

#endif // ALLOCATIONSDYN_H_INCLUDED
