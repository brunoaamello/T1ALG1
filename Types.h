#ifndef  TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

typedef unsigned int uint32;
typedef unsigned long long int uint64;





//##############LISTA###################
typedef struct Node{
    struct Node*   anterior;
    void*   valor;
    struct Node*   prox;
}Node;

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
    char titulo[50], autor[50], editora[30];
    uint64 isbn;
    int ano, edicao, copias, disponiveis;
    Lista fila;
}Livro;
//######################################



#endif // TYPES_H_INCLUDED
