#include "Aluno.h"

Aluno* novoAluno(char* nome, char* telefone, char* email, uint32 numusp, int* erro){  //  DINAMICO
    Aluno* nAl = getAluno();
    if(nAl == NULL){
        *erro = 1;
        return NULL;
    }
    strcpy(nAl->nome, nome);
    strcpy(nAl->telefone, telefone);
    strcpy(nAl->email, email);
    nAl->numusp=numusp;
    initLista(&(nAl->livros));
    initLista(&(nAl->mensagensPilha));
    return nAl;
}

Aluno* findAluno_N(Lista* alunos, uint32 numusp, int* erro){
    Aluno* saida;
    if(alunos->tamanho == 0){
        *erro = 1;
        return NULL;
    }
    Node* no = getNode();
    no->valor = alunos->inicio->valor;
    no->prox = alunos->inicio->prox;
    uint32 i;
    for(i=0;i<alunos->tamanho;i++){
        if(((Aluno*)no->valor)->numusp == numusp){
            *erro  = 0;
            saida = no->valor;
            freeNode(no);
            return saida;
        }
        no->valor=no->prox->valor;
        no->prox=no->prox->prox;
    }
    freeNode(no);
    *erro = 1;
    return NULL;
}

void printAlunoInfo(Aluno* aluno){
    if(aluno == NULL){
        printf("\nErro na impressao de aluno.\n");
        return;
    }
    printf("\nNome:      %s\n", aluno->nome);
    printf("NUSP:      %u\n", aluno->numusp);
    printf("Email:     %s\n", aluno->email);
    printf("Telefone:  %s\n", aluno->telefone);
}
