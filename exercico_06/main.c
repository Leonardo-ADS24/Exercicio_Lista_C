//6. Sistema de compras online com produtos ordenados por preço

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME_MAX 50


typedef struct Produto{
    char nome[NOME_MAX];
    float preco;
    struct Produto* proximo;
}Produto;

void inserirProduto(Produto** lista,char nome[],float preco){
    Produto* novoProduto = (Produto*)malloc(sizeof(Produto));
    strcpy(novoProduto->nome,nome);
    novoProduto->preco = preco;
    novoProduto->proximo = NULL;

    if(*lista == NULL || (*lista)->preco >= preco){
        novoProduto->proximo = *lista;
        *lista = novoProduto;
    }else{ 
        Produto* atual = *lista;
        while(atual->proximo != NULL && atual->proximo->preco < preco){
            atual = atual->proximo;
        }
        novoProduto->proximo = atual->proximo;
        atual->proximo = novoProduto;
        
    };

}


void removerProduto(Produto ** lista,char nome[],float preco){
    Produto* atual = *lista;
    Produto* anterior = NULL;

    while(atual != NULL && strcmp(atual->nome,nome) != 0){
        anterior = atual;
        atual = atual->proximo;
    }

    if(anterior == NULL){
        *lista = atual->proximo;
    }else{
        anterior->proximo = atual->proximo;
    }

    printf("O produto %s com o preco %.2f foi removido\n",nome,preco);
}

void exibirProdutos(Produto* lista){
    printf("Os produtos disponiveis sao: \n");
    Produto* atual = lista;
    while(atual != NULL){
        printf("Produto: %sPreco: %.2f\n---------------\n",atual->nome,atual->preco);
        atual = atual->proximo;
    }
}


int main(){
    Produto* lista = NULL;
    int opcao;
    char nome[NOME_MAX];
    float preco;

    do{
        printf("\nDigite sua escolha: \n1 - Adicionar um produto\n2 - Remover um produto\n3 - Exibir produtos disponiveis\n0 - Sair do programa");
        printf("\nSua escolha: ");
        scanf("%d",&opcao);
        getchar();
        switch (opcao){
        case 1:
            printf("Digita o nome do produto: ");
            fgets(nome,sizeof(nome),stdin);
            printf("Digite o preco do produto: ");
            scanf("%f", &preco);
            inserirProduto(&lista,nome,preco);
            break;
        case 2:
            printf("Digite o produto que esta indisponivel para remove-lo da lista: ");
            fgets(nome,sizeof(nome),stdin);
            removerProduto(&lista,nome,preco);
            break;
        case 3:
            exibirProdutos(lista);
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