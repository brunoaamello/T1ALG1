/*
    TRABALHO 1 -- SSC0502 -- ALGORITMOS E ESTRUTURAS DE DADOS
    PROFESSOR: Bruno Roberto Nepomuceno Matheus
    ALUNOS:
        Bruno Arantes de Achilles Mello     9866490
        Laura Pereira de Gouveia                  9880200
*/

#ifndef  TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

typedef unsigned int uint32;                        //  INTEIRO DE 32 BITS
typedef unsigned long long int uint64;      // INTEIRO DE 64 BITS

//##############LISTA###################

//  NO DUPLAMENTE ENCADEADO, RECEBENDO UM PONTEIRO PARA O CONTEUDO, NAO CONTENDO O PRORPIO TIPO ARMAZENADO
typedef struct Node{
    struct Node*   anterior;
    void*   valor;
    struct Node*   prox;
}Node;

//  LISTA DE NOS
typedef struct {
    Node* inicio;
    Node* fim;
    uint32 tamanho;
}Lista;
//######################################

//##############ALUNO##################
typedef struct Aluno{
    char nome[100], telefone[25], email[100];
    uint32 numusp;
    Lista livros;
    Lista mensagensPilha;
}Aluno;
//######################################

//##############LIVRO###################
typedef struct {
    char titulo[100], autor[100], editora[100];
    uint64 isbn;
    int ano, edicao, copias, disponiveis;
    Lista fila;
}Livro;
//######################################



#endif // TYPES_H_INCLUDED
