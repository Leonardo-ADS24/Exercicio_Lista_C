//1 . Gerenciamento de pedidos de uma lanchonete

#include <stdio.h>
#define MAX 1000

void inserir(int lista[],int *tamanho, int valor){
    if(*tamanho < MAX){
        lista[*tamanho] = valor;
        (*tamanho)++;
    }
}

void exibir(int lista[],int tamanho){
    printf("\nLista dos pedidos: ");
    for(int i = 0; i < tamanho; i++){
        printf("%d - ",lista[i]);
    }
    printf("\n");
}

int remover(int lista[],int *tamanho, int valor){
    for(int i = 0; i < *tamanho; i++){
        if(lista[i] == valor){
            for(int j = i; j < *tamanho -1; j++){
                lista[j] = lista[j + 1];
            }
            (*tamanho)--;
            return 1;
        }
    }
    return 0;

}


int main(){
    int lista[MAX];
    int tamanho = 0;
    int escolha,pedido;

    printf("Lanchonete: ");
    do{
        printf("\nDigite sua escolha: \n1 - Adicionar Pedido\n2 - Exibir todos os pedidos\n3 - Remover um pedido que ja foi atendido\n0 - Sair do programa");
        printf("\nSua escolha: ");
        scanf("%d",&escolha);
        switch (escolha){
            case 1:
                printf("Digita o numero do pedido: ");
                scanf("%d",&pedido);
                inserir(lista,&tamanho,pedido);
                break;
            case 2:
                printf("Exibir Todos os pedidos");
                exibir(lista,tamanho);
                break;
            case 3:
                printf("Digita o numero do pedido que ja foi atendido: ");
                scanf("%d",&pedido);
                remover(lista,&tamanho,pedido);
                break;
            case 0:
                printf("SAIU ...\n");
                break;
            
            default:
                printf("Opcao Invalida");
                break;
        }

    }while( escolha != 0);

}