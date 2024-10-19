//9. Estoque de um supermercado

#include <stdio.h>
#include <string.h>

#define MAX_PRODUTO 100
#define NOME_MAX 50

typedef struct{
    char produto[NOME_MAX];
} Produto;

typedef struct{
    Produto Produto[MAX_PRODUTO];
    int quantidade;
} ListaProduto;


void iniciarListaProduto(ListaProduto *lista){
    lista->quantidade = 0;
}


int adicionarProduto(ListaProduto *lista,char produto[]){
    if(lista->quantidade < MAX_PRODUTO){
        int i;
        for(i = lista->quantidade; i > 0; i--){
            lista->Produto[i] = lista->Produto[i -1];
        }
        strcpy(lista->Produto[0].produto,produto);
        lista->quantidade++;
        printf("Produto %s adicionado no estoque\n",produto);
        
        return 1;
    }
    return 0;
}

int removerProduto(ListaProduto *lista,char produto[]){
    for(int i = 0; i < lista->quantidade;i++){
        if(strcmp(lista->Produto[i].produto,produto) == 0){
            for(int j = i; j <lista->quantidade -1; j++){
                lista->Produto[j] = lista->Produto[j+1];
            }
            lista->quantidade--;
            printf("Produto %s removido do estoque\n",produto);
            return 1;
        }
    }
    return 0;

}


void exibirProdutos(ListaProduto *lista){
    printf("Lista dos produtos em estoques: \n");
    for(int i = 0; i < lista->quantidade; i++){
        printf("- %s\n",lista->Produto[i].produto);
    }
}


int main(){
    int opcao;
    char produto[NOME_MAX];

    ListaProduto lista;

    iniciarListaProduto(&lista);

        do{
        printf("\n----------- Estoque de Produtos ------------");
        printf("\n1 - Incluir Produto no estoque\n2 - Remover produto\n3 - Listar produtos em estoque\n0 - Encerrar programa");
        printf("\nDigite a opcao: ");
        scanf("%d",&opcao);
        getchar();
        switch (opcao){
        case 1:
            printf("\n1 - Adicionar Produto no estoque\n");
            printf("Digite o nome do Produto: ");
            fgets(produto,sizeof(produto),stdin);
            produto[strcspn(produto,"\n")] = 0;
            adicionarProduto(&lista,produto);
        break;
        case 2:
            printf("Digita o produto indisponivel: ");
            fgets(produto,sizeof(produto),stdin);
            produto[strcspn(produto,"\n")] = 0;
            removerProduto(&lista,produto);
        break;
        case 3:
            printf("\n2 - Listar produtos em estoque\n");
            exibirProdutos(&lista);
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