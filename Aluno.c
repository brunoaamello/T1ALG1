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

void printAlunoBaseInfo(Aluno* aluno){
    if(aluno == NULL){
        printf("\nErro na impressao de aluno.\n");
        return;
    }
    printf("\nNome:      %s\n", aluno->nome);
    printf("NUSP:      %u\n", aluno->numusp);
    printf("Email:     %s\n", aluno->email);
    printf("Telefone:  %s\n", aluno->telefone);
}

void printAlunoInfo(Aluno* aluno){
    char teste;
    printAlunoBaseInfo(aluno);
    printf("\n");
    printf("Deseja ver a lista de Livros que o aluno esta esperando?(s/n)\n");
    do{
        fflush(stdin);
        scanf("%c", &teste);
        if(teste != 's' && teste != 'n'){
            printf("Por favor digite 's' para sim ou 'n' para nao.\n");
        }
    }while(teste != 's' && teste != 'n');
    if(teste == 'n'){
        return;
    }
    if(aluno->livros.tamanho == 0){
        printf("O Aluno nao esta em nenhuma lista de espera.\n");
        return;
    }
    int i, erro;
    Livro* livro;
    for(i=0;i<aluno->livros.tamanho;i++){
        livro = atLista((&aluno->livros), i, &erro);
        printf("%d)\n", i);
        printLivroInfo(livro);
        printf("Posicao do Aluno: %d\n", getAlunoPosition(livro, aluno, erro));
    }
}
void findAluno_S(Lista* alunos, char* nome){
    Lista matches;
    initLista(&matches);
    int i, j, erro, checker;
    for(i=0;i<alunos->tamanho;i++){
        checker=1;
        for(j=0; (j<strlen(nome) && j<strlen(((Aluno*)atLista(alunos, i, erro))->nome)); j++){
            if(tolower(nome[j]) != ((Aluno*)atLista(alunos, i, erro))->nome[j] && toupper(nome[j]) != ((Aluno*)atLista(alunos, i, erro))->nome[j]){
                checker=0;
            }
        }
        if(checker){
            insereInicio(&matches, atLista(alunos, i, erro));
        }
    }
    for(i=0;i<matches.tamanho;i++){
        printf("Escolha entre as opcoes encontradas: \n\n%d)\n", i+1);
        printAlunoBaseInfo(atLista(&matches, i, erro));
    }
    do{
        fflush(stdin);
        scanf("%d", &i);
        if(i<1 || i>matches.tamanho){
            printf("Por favor digite um valor entre os mostrados\n");
        }
    }while(i<1 || i>matches.tamanho);
    operarAluno(alunos, atLista(&matches, i, erro));
    limpaLista(&matches);
}

void operarAluno(Lista* alunos, Aluno* aluno){
    int escolha, index, erro;
    int i=0;
    while(i<alunos->tamanho){
        if(((Aluno*)atLista(alunos, i, erro))->numusp == aluno->numusp){
            index = i;
            break;
        }
        i++;
    }
    printAlunoInfo(aluno);
    printf("Escolha a operacao que deseja realizar:\n");
    printf("1) Alterar nome.\n2) Alterar email.\n3) Alterar numero USP.\n4) Alterar telefone.\n5)Remover aluno.\n6) Remover de uma lista de espera.\n7)Nada.\n");
    do{
        fflush(stdin);
        scanf("%d", &escolha);
        if(escolha<1 || escolha>7){
            printf("Por favor digite um valor entre os mostrados\n");
        }
    }while(escolha<1 || escolha>7);
    switch(escolha){
    case 1:
        printf("Digite o novo nome: ");
        scanf("%s", aluno->nome);
        break;
    case 2:
        printf("Digite o novo email: ");
        scanf("%s", aluno->email);
        break;
    case 3:
        printf("Digite o novo numero USP: ");
        scanf("%u", aluno->numusp);
        break;
    case 4:
        printf("Digite o novo telefone: ");
        scanf("%s", aluno->telefone);
        break;
    case 5:
        removerAluno(alunos, index, aluno);
        break;
    case 6:
        printf("Digite o numero do livro: ");
        do{
            fflush(stdin);
            scanf("%d", &escolha);
            if(escolha<1 || escolha>aluno->livros.tamanho){
                printf("Escolha um valor entre os mostrados.\n");
            }
        }while(escolha<1 || escolha>aluno->livros.tamanho);
        removerLivroAluno(atLista(&aluno->livros, escolha-1, erro), aluno);
        break;
    default:
    case 7:
        return;
    }
}

int removerAluno(Lista* alunos, int index, Aluno* aluno){
    int i, erro;
    Aluno* removed = getLista(alunos, index, &erro);
    for(i=0; i<aluno->livros.tamanho;i++){
        removerLivroAluno(getLista(&aluno->livros, i, erro), aluno);
    }
    freeAluno(removed);
    return erro;
}

int removerLivroAluno(Livro* livro, Aluno* aluno){
    int i, erro;
    for(i=0; i<livro->fila.tamanho;i++){
        if(((Aluno*)atLista(&livro->fila, i, erro))->numusp == aluno->numusp){
            getLista(&livro->fila, i, erro);
        }
    }
    for(i=0; i<aluno->livros.tamanho;i++){
        if(((Livro*)atLista(&livro->fila, i, erro))->isbn == livro->isbn){
            getLista(&aluno->livros, i, erro);
        }
    }
    return erro;
}

void printAlunoMensagens(Aluno* aluno){
    int erro;
    int i = 1;
    char* mensagem;
    while(aluno->mensagensPilha.tamanho != 0){
        mensagem = popLista(&aluno->mensagensPilha, &erro);
        printf("%d) %s\n", i, mensagem);
        i++;
        freeMensagem(mensagem);
    }
    printf("Fim da impressao de mensagens.\n");
}

