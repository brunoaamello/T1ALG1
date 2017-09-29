#include "Banco.h"

int initBanco(Banco* meuBanco){
    int i;
    for(i=0; i<T_NODES; i++){
        meuBanco->nodes.nodes[i].valor = NULL;
    }
    for(i=0; i<T_LIVROS; i++){
        meuBanco->livros.livros[i].isbn = 0;
    }
    for(i=0; i<T_ALUNOS; i++){
        meuBanco->alunos.alunos[i].numusp = 0;
    }
    for(i=0; i<30*T_ALUNOS; i++){
        meuBanco->mensagens.mensagens[i][0] = '\0';
    }
    meuBanco->nodes.prim_vazio = 0;
    meuBanco->alunos.prim_vazio = 0;
    meuBanco->livros.prim_vazio = 0;
    meuBanco->mensagens.prim_vazio = 0;
    meuBanco->nodes.elems = 0;
    meuBanco->alunos.elems = 0;
    meuBanco->livros.elems = 0;
    meuBanco->mensagens.elems = 0;
}

Banco* getBanco(){
    if(global_mainBank == NULL){
        Banco newBank;
        initBanco(&newBank);
        global_mainBank = &newBank;
    }
    return global_mainBank;
}
