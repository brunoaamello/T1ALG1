/*
    TRABALHO 1 -- SSC0502 -- ALGORITMOS E ESTRUTURAS DE DADOS
    PROFESSOR: Bruno Roberto Nepomuceno Matheus
    ALUNOS:
        Bruno Arantes de Achilles Mello     9866490
        Laura Pereira de Gouveia                  9880200
*/

#ifndef LIVRO_H_INCLUDED
#define LIVRO_H_INCLUDED
#include "Aluno.h"

//  PROCURA LIVRO PELO NUMERO ISBN
Livro* findLivro_N(Lista* livros, uint64 isbn, int* erro);

//  PROCURA LIVRO PELO TITULO, INICIANDO DIALOGO DE OPERACAO DO LIVRO
void findLivro_ST(Lista* livros, char* titulo, Lista* alunos);

//  PROCURA LIVRO PELO NOME DO AUTOR, INICIANDO DIALOGO DE OPERACAO DO LIVRO
void findLivro_SA(Lista* livros, char* autor, Lista* alunos);

//  OPERA LIVRO, PERMITINDO ALTERAR INFORMACOES, EMPRESTAR/RESERVAR LIVRO, DEVOLVER E REMOVER LIVRO
void operarLivro(Lista* livros, Livro* livro, Lista* alunos);

//  REMOVE O LIVRO DA LISTA
void removerLivro(Lista* livros, Livro* livro);

//  CRIA UM NOVO LIVRO
Livro* novoLivro(char* titulo, char* autor, char* editora, uint64 isbn, int ano, int edicao, int copias,  int* erro);

//  IMPRIME TODAS AS INFORMACOES DO LIVRO, INCLUSIVE RESERVAS
void printLivroInfo(Livro* livro);

//  GERA A POSICAO DO ALUNO NA FILA DE ESPERA DO LIVRO
int getAlunoPosition(Livro* livro, Aluno* aluno, int* erro);

//  CADASTRA UM NOVO LIVRO
int cadastrarLivro(Lista* livros);

#endif // LIVRO_H_INCLUDED
