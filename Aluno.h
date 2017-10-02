/*
    TRABALHO 1 -- SSC0502 -- ALGORITMOS E ESTRUTURAS DE DADOS
    PROFESSOR: Bruno Roberto Nepomuceno Matheus
    ALUNOS:
        Bruno Arantes de Achilles Mello     9866490
        Laura Pereira de Gouveia                  9880200
*/

#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED
#include "Lista.h"
#include "Livro.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>


//   CRIA UM NOVO ALUNO
Aluno* novoAluno(char* nome, char* telefone, char* email, uint32 numusp, int* erro);

//  ACHA UM ALUNO DE ACORDO COM O NUMERO USP
Aluno* findAluno_N(Lista* alunos, uint32 numusp, int* erro);

//  PROCURA UM ALUNO PELO NOME E INICIA A ROTINA DE OPERACAO
void findAluno_S(Lista* alunos, char* nome);

//  OPERA ALUNO, PERMITE ALTERACAO DE DADOS, LEITURA DE MENSAGENS E REMOCAO DE RESERVAS
void operarAluno(Lista* alunos, Aluno* aluno);

//  REMOVE ALUNO DO SISTEMA
int removerAluno(Lista* alunos, Aluno* aluno);

//  REMOVE O ALUNO DA FILA DE ESPERA DE UM LIVRO
int removerLivroAluno(Livro* livro, Aluno* aluno);

//  IMPRIME AS INFORMACOES BASICAS DO ALUNO
void printAlunoBaseInfo(Aluno* aluno);

//  IMPRIME AS INFORMACOES BASICAS DO ALUNO E AS FILAS DE ESPERA QUE ESTA
void printAlunoInfo(Aluno* aluno);

//  IMPRIME AS MENSAGENS DA PILHA DO ALUNO
void printAlunoMensagens(Aluno* aluno);

//  CADASTRA UM NOVO ALUNO
int cadastrarAluno(Lista* alunos);

#endif // ALUNO_H_INCLUDED
