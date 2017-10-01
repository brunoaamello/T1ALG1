#ifndef ALLOCATIONSSTATIC_H_INCLUDED
#define ALLOCATIONSSTATIC_H_INCLUDED

#include "Banco.h"

//  FUNCAO DE INICIALIZACAO INICIALIZA O BANCO DE MEMORIA
void init();

//################ALOCACAO################################

//  RETORNA O ENDERECO PARA UM NO VAZIO NO BANCO DE MEMORIA
Node*         getNode();

//  RETORNA O ENDERECO PARA UM ALUNO VAZIO NO BANCO DE MEMORIA
Aluno*        getAluno();

//  RETORNA O ENDERECO PARA UM LIVRO VAZIO NO BANCO DE MEMORIA
Livro*          getLivro();

//  RETORNA O ENDERECO PARA UMA MENSAGEM VAZIO NO BANCO DE MEMORIA
char*           getMensagem();

//#########################################################


//#############DESALOCACAO################################

//  FUNCAO QUE LIVRA O NO NO BANCO DE MEMORIA
int                 freeNode(Node*);

//  FUNCAO QUE LIVRA O ALUNO NO BANCO DE MEMORIA
int                 freeAluno(Aluno*);

//  FUNCAO QUE LIVRA O LIVRO NO BANCO DE MEMORIA
int                 freeLivro(Livro*);

//  FUNCAO QUE LIVRA A MENSAGEM NO BANCO DE MEMORIA
int                 freeMensagem(char*);

//########################################################

#endif // ALLOCATIONSSTATIC_H_INCLUDED
