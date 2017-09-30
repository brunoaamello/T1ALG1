#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED
#include "Lista.h"
#include <string.h>
extern void printf(char*, ...);

Aluno* novoAluno(char* nome, char* telefone, char* email, uint32 numusp, int* erro);
Aluno* findAluno_N(Lista* alunos, uint32 numusp, int* erro);
void printAlunoInfo(Aluno* aluno);

#endif // ALUNO_H_INCLUDED
