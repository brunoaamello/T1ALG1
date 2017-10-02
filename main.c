/*
    TRABALHO 1 -- SSC0502 -- ALGORITMOS E ESTRUTURAS DE DADOS
    PROFESSOR: Bruno Roberto Nepomuceno Matheus
    ALUNOS:
        Bruno Arantes de Achilles Mello     9866490
        Laura Pereira de Gouveia                  9880200
*/

#include "Livro.h"

int main(){
    init();
    Lista alunos, livros;
    initLista(&alunos);
    initLista(&livros);
    Livro* livro;
    Aluno* aluno;
    int erro;
    uint64 isbn;
    uint32 nusp;
    char texto[100];
    int escolha_0, escolha_1;
    do{
        printf("1) Cadastrar um Livro.\n2) Cadastrar um Aluno.\n3) Gerenciar Livros.\n4) Gerenciar Alunos.\n5) Sair.\n");
        do{
            scanf("%d", &escolha_0);
            if(escolha_0 < 1 || escolha_0 > 5){
                printf("Favor escolher uma das opcoes demarcadas.\n");
            }
        }while(escolha_0 < 1 || escolha_0 > 5);
        switch(escolha_0){
        case 1:
            cadastrarLivro(&livros);
            break;
        case 2:
            cadastrarAluno(&alunos);
            break;
        case 3:
            printf("1) Procurar por ISBN.\n2) Procurar por titulo.\n3) Procurar por autor.\n4) Sair.\n");
            do{
                scanf("%d", &escolha_1);
                if(escolha_1 < 1 || escolha_1 > 4){
                    printf("Favor escolher uma das opcoes demarcadas.\n");
                }
            }while(escolha_1 < 1 || escolha_1 > 4);
            switch(escolha_1){
            case 1:
                printf("Digite o ISBN: ");
                scanf("%llu", &isbn);
                livro = findLivro_N(&livros, isbn, &erro);
                if(erro == 1){
                    printf("ISBN nao encontrado.\n");
                    break;
                }else{
                    printLivroInfo(livro);
                    operarLivro(&livros, livro, &alunos);
                    break;
                }
            case 2:
                printf("Digite o titulo: ");
                scanf("%s", texto);
                findLivro_ST(&livros, texto, &alunos);
                break;
            case 3:
                printf("Digite o autor: ");
                scanf("%s", texto);
                findLivro_SA(&livros, texto, &alunos);
                break;
            case 4:
                break;
            default:
                break;
            }
            break;
        case 4:
            printf("1) Procurar por numero USP.\n2) Procurar por nome.\n3) Voltar.\n");
            do{
                scanf("%d", &escolha_1);
                if(escolha_1 < 1 || escolha_1 > 3){
                    printf("Favor escolher uma das opcoes demarcadas.\n");
                }
            }while(escolha_1 < 1 || escolha_1 > 3);
            switch(escolha_1){
            case 1:
                printf("Digite o nusp: ");
                scanf("%u", &nusp);
                aluno = findAluno_N(&alunos, nusp, &erro);
                if(erro == 1){
                    printf("Numero USP nao encontrado.\n");
                    break;
                }else{
                    operarAluno(&alunos, aluno);
                    break;
                }
            case 2:
                printf("Digite o nome: ");
                scanf("%s", texto);
                findAluno_S(&alunos, texto);
                break;
            case 3:
                break;
            default:
                break;
            }
            break;
        case 5:
            break;
        default:
            break;
        }
    }while(escolha_0 != 5);
    limpaLista(&alunos);
    limpaLista(&livros);

    return 0;
}
