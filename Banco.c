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
    for(i=0; i<T_TXT; i++){
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

int getIndex(uint32 address){
    uint32 info = 2*sizeof(uint32);
    uint32 nodes = sizeof(Node)*T_NODES;
    uint32 alunos = sizeof(Aluno)*T_ALUNOS;
    uint32 mensagens = sizeof(char)*T_MSG*T_TXT;
    uint32 livros = sizeof(Livro)*T_LIVROS;
    if(address < global_mainBank+info){
        return -1;
    }else if(address < global_mainBank+info+nodes){
        address-=info;
        return address%sizeof(Node);
    }else if(address < global_mainBank+(2*info)+nodes){
        return -1;
    }else if(address < global_mainBank+(2*info)+nodes+alunos){
        address-=2*info;
        address-=nodes;
        return address%sizeof(Aluno);
    }else if(address < global_mainBank+(3*info)+nodes+alunos){
        return -1;
    }else if(address < global_mainBank+(3*info)+nodes+alunos+mensagens){
        address-=3*info;
        address-=nodes;
        address-=alunos;
        return address%(sizeof(char)*T_MSG);
    }else if(address < global_mainBank+(4*info)+nodes+alunos+mensagens){
        return -1;
    }else if(address < global_mainBank+(4*info)+nodes+alunos+mensagens+livros){
        address-=4*info;
        address-=nodes;
        address-=alunos;
        address-=mensagens;
        return address%sizeof(Livro);
    }else{
        return -1;
    }
}
