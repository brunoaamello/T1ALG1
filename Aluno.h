#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED
#include "Lista.h"
#include "Livro.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>


Aluno* novoAluno(char* nome, char* telefone, char* email, uint32 numusp, int* erro);
Aluno* findAluno_N(Lista* alunos, uint32 numusp, int* erro);
void findAluno_S(Lista* alunos, char* nome);
void operarAluno(Lista* alunos, Aluno* aluno);
int removerAluno(Lista* alunos, Aluno* aluno);
int removerLivroAluno(Livro* livro, Aluno* aluno);
void printAlunoBaseInfo(Aluno* aluno);
void printAlunoInfo(Aluno* aluno);
void printAlunoMensagens(Aluno* aluno);
int cadastrarAluno(Lista* alunos);

#endif // ALUNO_H_INCLUDED
