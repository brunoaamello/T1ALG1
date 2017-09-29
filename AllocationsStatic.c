#include "AllocationsStatic.h"

void init(){
    printf("Mode set to Static\n");
    getBanco();
    printf("Banco de memoria inicializado com %d elementos.\nBanco de %.2lf kB\n", getBanco()->alunos.elems, sizeof(Banco)/((double) 1024.0));
}
Node* getNode(){
    Node* intermediate;
    if(getBanco()->nodes.elems == T_NODES){
        return NULL;
    }
    int indice = getBanco()->nodes.prim_vazio;
    intermediate = &(getBanco()->nodes.nodes[indice]);
    getBanco()->nodes.elems++;
    int i=indice+1;
    while(1){
            if(getBanco()->nodes.nodes[i].valor == NULL){
                    getBanco()->nodes.prim_vazio = i;
                    break;
            }
            i++;
    }
    return intermediate;
}
Aluno* getAluno(){
    Aluno* intermediate;
    if(getBanco()->alunos.elems == T_ALUNOS){
        return NULL;
    }
    int indice = getBanco()->alunos.prim_vazio;
    intermediate = &(getBanco()->alunos.alunos[indice]);
    getBanco()->alunos.elems++;
    int i=indice+1;
    while(1){
            if(getBanco()->alunos.alunos[i].numusp == 0){
                    getBanco()->alunos.prim_vazio = i;
                    break;
            }
            i++;
    }
    return intermediate;
}
Livro* getLivro(){
    Livro* intermediate;
    if(getBanco()->livros.elems == T_LIVROS){
        return NULL;
    }
    int indice = getBanco()->livros.prim_vazio;
    intermediate = &(getBanco()->livros.livros[indice]);
    getBanco()->livros.elems++;
    int i=indice+1;
    while(1){
            if(getBanco()->livros.livros[i].isbn == 0){
                    getBanco()->livros.prim_vazio = i;
                    break;
            }
            i++;
    }
    return intermediate;
}

char* getMensagem(){
    char* intermediate;
    if(getBanco()->mensagens.elems == 30*T_ALUNOS){
        return NULL;
    }
    int indice = getBanco()->mensagens.prim_vazio;
    intermediate = (getBanco()->mensagens.mensagens[indice]);
    getBanco()->mensagens.elems++;
    int i=indice+1;
    while(1){
            if(getBanco()->mensagens.mensagens[i][0] == '\0'){
                    getBanco()->mensagens.prim_vazio = i;
                    break;
            }
            i++;
    }
    return intermediate;
}
