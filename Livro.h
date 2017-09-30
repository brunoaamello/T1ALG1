#ifndef LIVRO_H_INCLUDED
#define LIVRO_H_INCLUDED
#include "Aluno.h"

Livro* findLivro_N(Lista* livros, uint64 isbn, int* erro);
Livro* novoLivro(char* titulo, char* autor, char* editora, uint64 isbn, int ano, int edicao, int copias,  int* erro);
void printLivroInfo(Livro* livro);
int getAlunoPosition(Livro* livro, Aluno* aluno, int* erro);
#endif // LIVRO_H_INCLUDED
