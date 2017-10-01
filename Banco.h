#ifndef BANCO_H_INCLUDED
#define BANCO_H_INCLUDED

#define T_ALUNOS 150    // QUANTIDADE DE ALUNOS A SEREM GUARDADOS NO SISTEMA
#define T_TXT 3000          // QUANTIDADE DE MENSAGENS A SER GUARDADA NO BANCO DE MEMORIA
#define T_LIVROS 1500    // QUANTIDADE DE LIVROS A SEREM GUARDADOS NO BANCO DE MEMORA
#define T_NODES 5000    //  QUANTIDADE DE NOS DUPLAMENTE ENCADEADOS A SER GUARDADO NO BANCO DE MEMORIA
#define T_MSG 200           //  TAMANHO DAS MENSAGENS A SEREM GUARDADAS

#include <stdlib.h>
#include "Types.h"

struct NodeBank{
    uint32 elems, prim_vazio;
    Node nodes[T_NODES];
};
struct AlunoBanco{
    uint32 elems, prim_vazio;
    Aluno alunos[T_ALUNOS];
};
struct MensagensBanco{
    uint32 elems, prim_vazio;
    char mensagens[T_TXT][T_MSG];
};
struct LivroBanco{
    uint32 elems, prim_vazio;
    Livro livros[T_LIVROS];
};
typedef struct {
    struct NodeBank nodes;
    struct AlunoBanco alunos;
    struct MensagensBanco mensagens;
    struct LivroBanco livros;
}Banco;

//  PONTEIRO GLOBAL PARA O BANCO DE MEMORIA
Banco* global_mainBank;

//  INICIALIZA O BANCO DE MEMORIA
int initBanco(Banco*);

//  RETORNA O ENDERECO DO BANCO DE MEMORIA E O INSTANCIA CASO NAO ESTEJA INSTANCIADO
Banco* getBanco();

//  FUNCAO PARA LOCALIZAR ENDERECO DENTRO DO BANCO DE MEMORIA
int getIndex(uint32);



#endif // BANCO_H_INCLUDED
