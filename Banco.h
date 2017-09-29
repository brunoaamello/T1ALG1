#ifndef BANCO_H_INCLUDED
#define BANCO_H_INCLUDED

#define T_ALUNOS 150
#define T_LIVROS 1000
#define T_NODES 5000
#define T_MSG 200

#include <stdlib.h>
#include "Types.h"

typedef struct NodeBank{
    uint32 elems, prim_vazio;
    Node nodes[T_NODES];
};
typedef struct AlunoBanco{
    uint32 elems, prim_vazio;
    Aluno alunos[T_ALUNOS];
};
typedef struct MensagensBanco{
    uint32 elems, prim_vazio;
    char mensagens[30*T_ALUNOS][T_MSG];
};
typedef struct LivroBanco{
    uint32 elems, prim_vazio;
    Livro livros[T_LIVROS];
};
typedef struct {
    struct NodeBank nodes;
    struct AlunoBanco alunos;
    struct MensagensBanco mensagens;
    struct LivroBanco livros;
}Banco;

Banco* global_mainBank;

int initBanco(Banco*);
Banco* getBanco();



#endif // BANCO_H_INCLUDED
