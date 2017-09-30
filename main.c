#include "Livro.h"

int main(){
    init();
    Lista alunos;
    initLista(&alunos);
    Aluno* alunoTeste;
    int erro;
    alunoTeste = novoAluno("Bruno Arantes", "+5512997013033", "brunoaamello@gmail.com", 9866490, &erro);
    pushLista(&alunos, alunoTeste);
    alunoTeste = novoAluno("Pessoa2", "+55163928482", "pessoa@gmail.com", 8393412, &erro);
    pushLista(&alunos, alunoTeste);
    alunoTeste = novoAluno("PersonaZ", "+55123241512", "z@gmail.com", 3373238, &erro);
    pushLista(&alunos, alunoTeste);
    findAluno_S(&alunos, "Bruno");

    return 0;
}
