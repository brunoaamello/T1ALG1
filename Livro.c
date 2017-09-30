#include "Livro.h"

Livro* novoLivro(char* titulo, char* autor, char* editora, uint64 isbn, int ano, int edicao, int copias,  int* erro){
    Livro* nLi = getLivro();
    if(nLi == NULL){
        *erro = 1;
        return NULL;
    }
    strcpy(nLi->titulo, titulo);
    strcpy(nLi->autor, autor);
    strcpy(nLi->editora, editora);
    nLi->isbn=isbn;
    nLi->edicao=edicao;
    nLi->ano=ano;
    nLi->copias=copias;
    nLi->disponiveis=copias;
    initLista(&(nLi->fila));
    *erro=0;
    return nLi;
}

Livro* findLivro_N(Lista* livros, uint64 isbn, int* erro){
    Livro* saida;
    if(livros->tamanho == 0){
        *erro = 1;
        return NULL;
    }
    Node* no = getNode();
    no->valor = livros->inicio->valor;
    no->prox = livros->inicio->prox;
    uint32 i;
    for(i=0;i<livros->tamanho;i++){
        if(((Livro*)no->valor)->isbn == isbn){
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

void printLivroInfo(Livro* livro){
    if(livro == NULL){
        printf("Erro na impressao do livro.\n");
        return;
    }
    printf("Titulo: %s\n %da edicao, %d\n", livro->titulo, livro->edicao, livro->ano);
    printf("Autor: %s\n", livro->autor);
    printf("ISBN: %llu\n", livro->isbn);
}

int getAlunoPosition(Livro* livro, Aluno* aluno, int* erro){
    if(livro->fila.tamanho == 0){
        *erro=1;
        return 0;
    }
    int i;
    for(i=0;i<livro->fila.tamanho;i++){
        if((Aluno*)atLista(&(livro->fila), i, erro) == aluno){
            *erro=0;
            return i+1;
        }
    }
    *erro=1;
    return 0;
}
