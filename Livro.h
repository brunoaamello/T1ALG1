#ifndef LIVRO_H_INCLUDED
#define LIVRO_H_INCLUDED
#include "Aluno.h"

Livro* findLivro_N(Lista* livros, uint64 isbn, int* erro);
void findLivro_ST(Lista* livros, char* titulo, Lista* alunos);
void findLivro_SA(Lista* livros, char* autor, Lista* alunos);
void operarLivro(Lista* livros, Livro* livro, Lista* alunos);
void removerLivro(Lista* livros, Livro* livro);
Livro* novoLivro(char* titulo, char* autor, char* editora, uint64 isbn, int ano, int edicao, int copias,  int* erro);
void printLivroInfo(Livro* livro);
int getAlunoPosition(Livro* livro, Aluno* aluno, int* erro);
int cadastrarLivro(Lista* livros);
#endif // LIVRO_H_INCLUDED
