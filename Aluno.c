#include "Aluno.h"

int novoAluno(Aluno* aluno, char* nome, char* telefone, char* email, unsigned int numusp){  //  DINAMICO
    Aluno* nAl = getAluno();
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
