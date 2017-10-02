/*
    TRABALHO 1 -- SSC0502 -- ALGORITMOS E ESTRUTURAS DE DADOS
    PROFESSOR: Bruno Roberto Nepomuceno Matheus
    ALUNOS:
        Bruno Arantes de Achilles Mello     9866490
        Laura Pereira de Gouveia                  9880200
*/

#include "AllocationsDyn.h"

void init(){
    printf("Mode set to Dynamic\n");
}
Node*        getNode(){
    Node* no = malloc(sizeof(Node));
    no->anterior=NULL;
    no->prox = NULL;
    no->valor = NULL;
    return no;
}
Aluno*       getAluno(){
    return (Aluno*) malloc(sizeof(Aluno));
}
Livro*         getLivro(){
    return malloc(sizeof(Livro));
}
char* getMensagem(){
    return malloc(sizeof(char)*200);
}
int freeNode(Node* no){
    free(no);
    return 0;
}
int freeAluno(Aluno* aluno){
    free(aluno);
    return 0;
}
int freeLivro(Livro* livro){
    free(livro);
    return 0;
}
int freeMensagem(char* msg){
    free(msg);
    return 0;
}
