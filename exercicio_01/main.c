#include <stdio.h>
#define MAX 1000

void inserir(int lista[],int *tamanho, int valor){
    if(*tamanho < MAX){
        lista[*tamanho] = valor;
        (*tamanho)++;
    }
}

void exibir(int lista[],int tamanho){
    printf("\nElemento da lista: ");
    for(int i = 0; i < tamanho; i++){
        printf("%d - ",lista[i]);
    }
    printf("\n");
}

void remover(int lista[],int tamanho, int valor){

}


int main(){
    int lista[MAX];
    int tamanho = 0;
    int escolha,pedido;

    printf("Lanchonete: ");
    do{
        printf("\nDigite sua escolha: \n 1 - Adicionar Pedido\n2 - Exibir todos os pedidos\n 3 - Remover um pedido que ja foi atendido");
        printf("\nSua escolha: ");
        scanf("%d",&escolha);
        switch (escolha){
            case 1:
                printf("Digita  o numero do pedido: ");
                scanf("%d",&pedido);
                inserir(lista,&tamanho,pedido);
                break;
            case 2:
                printf("Exibir Todos os pedidos");
                exibir(lista,tamanho);
                break;
            case 3:
                
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