//10. Sistema de entrega de encomendas

#include <stdio.h>
#include <string.h>

#define MAX 100
#define NOME_MAX  50

typedef struct{
    char nome[NOME_MAX];
    float distancia;
} Encomenda;

typedef struct{
    Encomenda encomenda[MAX];
    int quantidade;
} ListaEncomendas;

void inicializarListaEncomendas(ListaEncomendas *lista){
    lista->quantidade = 0;
}

void adicionarEncomenda(ListaEncomendas *lista, char nome[],float distancia){
    if(lista->quantidade < MAX){
        int i;
        for(i = lista->quantidade; i > 0 && lista->encomenda[i-1].distancia > distancia;i--){
            lista->encomenda[i] = lista->encomenda[i-1];
        }
        strncpy(lista->encomenda[i].nome,nome,NOME_MAX);
        lista->encomenda[i].distancia = distancia;
        lista->quantidade++;
        printf("Encomenda %s adicionada \n",nome);
    }
}

void removerEncomenda(ListaEncomendas *lista,char nome[]){
    for(int i = 0; i < lista->quantidade; i++){
        if(strcmp(lista->encomenda[i].nome,nome) == 0){
            for( int j = i; j < lista->quantidade -1; j++){
                lista->encomenda[j] = lista->encomenda[j+1];
            }
            lista->quantidade--;
            printf("Encomenda %s removida",nome);
        }

    }
}

void exibirEncomenda(ListaEncomendas *lista){  
    printf("Encomenda ...................... Distancia\n"); 
    for(int i = 0; i < lista->quantidade; i++){
        printf("%s ...................... %.2f\n",lista->encomenda[i].nome,lista->encomenda[i].distancia);
    }
}

int main(){
    int opcao;
    float distancia;
    char nome[NOME_MAX];

    ListaEncomendas lista;

    inicializarListaEncomendas(&lista);

    do{
        printf("\n ------- Sistema de Entregas ------- \n");
        printf("\nDigite sua escolha: \n1 - Adicionar Encomenda\n2 - Remover Encomenda\n3 - Listar Encomendas\n0 - Sair do programa");
        printf("\nSua escolha: ");
        scanf("%d",&opcao);
        getchar();
        switch (opcao){
        case 1:
            printf("Digita o nome da encomenda: ");
            fgets(nome,sizeof(nome),stdin);
            nome[strcspn(nome,"\n")] = 0;
            printf("Digite Digite a distancia para o destinatario (km): ");
            scanf("%f", &distancia);
            adicionarEncomenda(&lista,nome,distancia);
            break;
        case 2:
            printf("Digite o nome da encomenda a ser removida: ");
            fgets(nome,sizeof(nome),stdin);
            nome[strcspn(nome,"\n")] = 0;
            removerEncomenda(&lista,nome);
            break;
        case 3:
            exibirEncomenda(&lista);
            break;
        case 0:
            printf("SAIU ...\n");
            break;
        default:
            printf("Opcao Invalida");
            break;
        }

    }while(opcao != 0);

    

    return 0;
}