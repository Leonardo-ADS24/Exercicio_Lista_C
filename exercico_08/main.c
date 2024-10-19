#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAX_NOME 30

typedef struct{
    char jogador[MAX_NOME];
    int pontuacao;
}Jogador;

typedef struct{
    Jogador Jogador[MAX];
    int quantidade;
}ListaJogadores;

void inicializarListaJogador(ListaJogadores *lista){
    lista->quantidade = 0;
}


int incluirPontuacaoJogador(ListaJogadores *lista,char nome[],int pontuacao){
    if(lista->quantidade < MAX){
        int i;
        for(i = lista->quantidade -1;(i >= 0 && lista->Jogador[i].pontuacao > pontuacao); i--){
            lista->Jogador[i+1] = lista->Jogador[i];
        }
        strcpy(lista->Jogador[i+1].jogador,nome);
        lista->Jogador[i+1].pontuacao = pontuacao;
        lista->quantidade++;
        printf("\n");
        return 1;
    }
    return 0;
}

void exibirPontuacaoJogadores(ListaJogadores *lista){
    printf("Lista das pontuacoes dos Jogadores:\n");
    for(int i = 0; i < lista->quantidade; i++){
        printf("Jogador: %s .................... Pontuacao %d \n",lista->Jogador[i].jogador,lista->Jogador[i].pontuacao);
    }
}


int excluirJogador(ListaJogadores *lista,char nome[]){
    for(int i = 0; i < lista->quantidade; i++){
        if(strcmp(lista->Jogador[i].jogador,nome) == 0){
            for(int j = i; j < lista->quantidade -1; j++){
                lista->Jogador[j] = lista->Jogador[j+1];
            }
            lista->quantidade--;
            return 1;
        }
    }
    return 0;
}



int main(){
    
    int opcao,pontuacao;
    char nome[MAX_NOME];

    ListaJogadores lista;

    inicializarListaJogador(&lista);
        do{
        printf("------------ Pontuacoes JOgadores ------------");
        printf("\n1 - Incluir Jogador\n2 - Listar pontuacoes dos jogadores\n3 - Excluir jogador\n0 - Encerrar programa");
        printf("\nDigite a opcao: ");
        scanf("%d",&opcao);
        getchar();
        switch (opcao){
        case 1:
            printf("\n1 - Incluir Jogador na lista\n");
            printf("Digite o nome do jogador: ");
            fgets(nome,sizeof(nome),stdin);
            nome[strcspn(nome,"\n")] = 0;
            printf("Digite a pontuacao do jogador: ");
            scanf("%d",&pontuacao);
            incluirPontuacaoJogador(&lista,nome,pontuacao);            
        break;
        case 2:
            printf("\n2 - Listar todos os Jogadores\n");
            exibirPontuacaoJogadores(&lista);
        break;
        case 3:
            printf("Digita o jogador desqualificado: ");
            fgets(nome,sizeof(nome),stdin);
            nome[strcspn(nome,"\n")] = 0;
            excluirJogador(&lista,nome);
            break;
        case 0:
            printf("SAIU...");
            break;
        default:
            printf("\nEscolha uma das opcoes validas");
        }

    }while(opcao != 0);

    return 0;
}