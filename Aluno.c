#include "Aluno.h"

int novoAluno(Aluno* aluno, char* nome, char* telefone, char* email, unsigned int numusp){  //  DINAMICO
    Aluno* nAl = malloc(sizeof(Aluno));
    if(nAl == NULL){
        return 0;
    }
    strcpy(nAl->nome, nome);
    strcpy(nAl->telefone, telefone);
    strcpy(nAl->email, email);
    nAl->numusp=numusp;
    aluno = nAl;
    return 1;
}

int alunoGet(Aluno* aluno, Lista* alunos, unsigned int posicao){
    int i;
}
int alunoAt(Aluno* aluno, Lista* alunos, unsigned int posicao);

int alunoAppend(Lista* alunos, Aluno* aluno){
    No* no = malloc(sizeof(no));
    if(no == NULL){
        return 0;
    }
    no->valor = aluno;
    no->prox = NULL;
    if(alunos->tamanho ==0){
        alunos->fim = no;
        alunos->inicio = no;
    }else{
        alunos->fim->prox = no;
        alunos->fim = no;
    }
    return 1;
}
