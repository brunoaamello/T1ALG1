#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED
#include "BaseHeader.h"

typedef struct {
    char nome[50], telefone[16], email[30];
    uint32 numusp;
}Aluno;

int novoAluno(Aluno* aluno, char* nome, char* telefone, char* email, uint32 numusp);
int alunoGet(Aluno* aluno, Lista* alunos, uint32 posicao);
int alunoAt(Aluno* aluno, Lista* alunos, uint32 posicao);
int alunoAppend(Lista* alunos, Aluno* aluno);


#endif // ALUNO_H_INCLUDED
