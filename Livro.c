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
    printf("\nTitulo: %s%da edicao, %d\n", livro->titulo, livro->edicao, livro->ano);
    printf("Autor: %s", livro->autor);
    printf("ISBN: %llu\n\n", livro->isbn);
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

int cadastrarLivro(Lista* livros){
    int erro, edicao, ano, copias;
    Livro* nLi;
    uint64 isbn;
    char titulo[100], autor[100], editora[100];
    printf("Digite o titulo do livro: ");
    fflush(stdin);
    fgets(titulo, 100, stdin);
    printf("Digite o nome do autor: ");
    fflush(stdin);
    fgets(autor, 100, stdin);
    printf("Digite o nome da editora: ");
    fflush(stdin);
    fgets(editora, 100, stdin);
    printf("Digite o ISBN do livro: ");
    fflush(stdin);
    scanf("%llu", &isbn);
    printf("Digite o ano do livro: ");
    fflush(stdin);
    scanf("%d", &ano);
    printf("Digite a edicao do livro: ");
    fflush(stdin);
    scanf("%d", &edicao);
    printf("Digite o numero de copias do livro: ");
    fflush(stdin);
    scanf("%d", &copias);
    nLi = novoLivro(titulo, autor, editora, isbn, ano, edicao, copias, &erro);
    if(livros == NULL || erro){
        return 1;
    }
    printLivroInfo(nLi);
    return insereInicio(livros, nLi);
}

void findLivro_ST(Lista* livros, char* titulo, Lista* alunos){
    Lista matches;
    Livro* livro;
    initLista(&matches);
    int i, j, erro, checker;
    for(i=0;i<(livros->tamanho);i++){
        livro = atLista(livros, i, &erro);
        checker=1;
        for(j=0; (j<strlen(titulo) && j<strlen(livro->titulo)); j++){
            if(tolower(titulo[j]) != livro->titulo[j] && toupper(titulo[j]) != livro->titulo[j]){
                checker=0;
            }
        }
        if(checker){
            insereInicio(&matches, atLista(livros, i, &erro));
        }
    }

    for(i=0;i<matches.tamanho;i++){
        printf("\n%d)\n", i+1);
        printLivroInfo(atLista(&matches, i, &erro));
    }
    do{
        fflush(stdin);
        scanf("%d", &i);
        if(i<1 || i>matches.tamanho){
            printf("Por favor digite um valor entre os mostrados\n");
        }
    }while(i<1 || i>matches.tamanho);
    operarLivro(livros, atLista(&matches, i-1, &erro), alunos);
    limpaLista(&matches);
}

void findLivro_SA(Lista* livros, char* autor, Lista* alunos){
    Lista matches;
    Livro* livro;
    initLista(&matches);
    int i, j, erro, checker, escolha;
    for(i=0;i<(livros->tamanho);i++){
        livro = atLista(livros, i, &erro);
        checker=1;
        for(j=0; (j<strlen(autor) && j<strlen(livro->autor)); j++){
            if(tolower(autor[j]) != livro->autor[j] && toupper(autor[j]) != livro->autor[j]){
                checker=0;
            }
        }
        if(checker){
            insereInicio(&matches, atLista(livros, i, &erro));
        }
    }
    printf("Escolha entre as opcoes encontradas: \n");
    for(i=0;i<matches.tamanho;i++){
        printf("\n%d)\n", i+1);
        printLivroInfo(atLista(&matches, i, &erro));
    }
    do{
        fflush(stdin);
        scanf("%d", &escolha);
        if(escolha<1 || escolha>matches.tamanho){
            printf("Por favor digite um valor entre os mostrados\n");
        }
    }while(escolha<1 || escolha>matches.tamanho);
    operarLivro(livros, atLista(&matches, escolha-1, &erro), alunos);
    limpaLista(&matches);
}

void operarLivro(Lista* livros, Livro* livro, Lista* alunos){
    uint32 nusp;
    char* msg;
    Aluno* emprestador;
    int escolha, erro;
    char texto[100];
    printLivroInfo(livro);
    printf("Escolha a operacao que deseja realizar:\n");
    printf("1) Alterar titulo.\n2) Alterar autor.\n3) Alterar editora.\n4) Alterar isbn.\n5) Alterar edicao.\n6) Alterar ano.\n7) Alterar copias.\n8) Emprestar para aluno.\n9) Devolver livro.\n10) Remover livro.\n11) Nada\n");
    do{
        fflush(stdin);
        scanf("%d", &escolha);
        if(escolha<1 || escolha>11){
            printf("Por favor digite um valor entre os mostrados\n");
        }
    }while(escolha<1 || escolha>11);
    switch(escolha){
    case 1:
        printf("Digite o novo titulo: ");
        fflush(stdin);
        fgets(texto, 100, stdin);
        strcpy(livro->titulo, texto);
        break;
    case 2:
        printf("Digite o novo autor: ");
        fflush(stdin);
        fgets(texto, 100, stdin);
        strcpy(livro->autor, texto);
        break;
    case 3:
        printf("Digite a nova editora: ");
        fflush(stdin);
        fgets(texto, 100, stdin);
        strcpy(livro->editora, texto);
        break;
    case 4:
        printf("Digite o novo ISBN: ");
        fflush(stdin);
        scanf("%llu", &livro->isbn);
        break;
    case 5:
        printf("Digite a nova edicao: ");
        fflush(stdin);
        scanf("%d", &livro->edicao);
        break;
    case 6:
       printf("Digite o novo ano: ");
       fflush(stdin);
        scanf("%d", &livro->ano);
        break;
    case 7:
        fflush(stdin);
        printf("Digite a diferenca no numero de copias: ");
        scanf("%d", &escolha);
        if(escolha+livro->disponiveis < 0){
            printf("Nao ha essa quantidade de livros disponiveis para ser removida.\n");
        }else{
            livro->copias+=escolha;
            livro->disponiveis+=escolha;
        }
        break;
    case 8:
        printf("Digite o numero USP do aluno: ");
        scanf("%u", &nusp);
        emprestador = findAluno_N(alunos, nusp, &erro);
        if(erro){
            printf("Aluno nao encontrado.\n");
        }else{
            msg = getMensagem();
            if(livro->disponiveis == 0){
                printf("Nao ha livros disponiveis, aluno colocado na fila de espera.\n");
                entraLista(&livro->fila, emprestador);
                insereInicio(&emprestador->livros, livro);
                strcpy(msg, "Colocado na fila para o livro ");
                strcat(msg, livro->titulo);
                pushLista(&emprestador->mensagensPilha, msg);
            } else{
                livro->disponiveis--;
                strcpy(msg, "Livro retirado: ");
                strcat(msg, livro->titulo);
                pushLista(&emprestador->mensagensPilha, msg);
                printf("Livro retirado.\n");
            }
        }
        break;
    case 9:
        if(livro->disponiveis == livro->copias){
            printf("Nao ha livros para se devolver.\n");
            break;
        }else{
            if(livro->fila.tamanho != 0){
                msg = getMensagem();
                emprestador = saiLista(&livro->fila, &erro);
                strcpy(msg, "Livro disponivel para retirada: ");
                strcat(msg, livro->titulo);
                pushLista(&emprestador->mensagensPilha, msg);
                printf("Livro encaminhado para proximo aluno.\n");
            }else{
                livro->disponiveis++;
            }
        }
        break;
    case 10:
        removerLivro(livros, livro);
        printf("Livro removido.\n");
        break;
    case 11:
        break;
    default:
        break;
    }
}

void removerLivro(Lista* livros, Livro* livro){
    int i, erro;
    for(i=0; i<livro->fila.tamanho; i++){
        removerLivroAluno(livro, atLista(&livro->fila, i, &erro));
    }
    for(i=0; i<livros->tamanho; i++){
        if(atLista(livros, i, &erro) == livro){
            getLista(livros, i, &erro);
        }
    }
    freeLivro(livro);
}
