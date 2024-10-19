#include <stdio.h>
#include <string.h>

#define MAX 200


void inserirLista(int lista[],int * tamanho, int visitante){
    if(*tamanho < MAX){
        lista[*tamanho] = visitante;
        (*tamanho)++;
    }
}

int excluirVisitante(int lista[],int *tamanho){
    if(*tamanho > 0){
        printf("Visitante %d ja usou o brinquedo\n",lista[0]);
        for (int i = 1; i < *tamanho; i++){
            lista[i-1] = lista[i];
        }
        (*tamanho)--;
    }
}


void exibirVisitantes(int lista[],int tamanho){
    printf("\nFila dos visitantes: \n");
    for(int i = 0; i < tamanho; i++){
        printf("%d - ",lista[i]);
    }
    printf("\n");
}


int main(){

 int lista[MAX],opcao,tamanho = 0,visitante;

    do{
        printf("\nDigite sua escolha: \n1 - Adicionar visitante ao final da fila\n2 - Remover visitante\n3 - Exibir visitantes na fila\n0 - Sair do programa\n");
        printf("\nSua escolha: ");
        scanf("%d",&opcao);
        getchar();
        switch (opcao){
            case 1:
                printf("Digita o numero do visitante: ");
                scanf("%d",&visitante);
                inserirLista(lista,&tamanho,visitante);
                break;
            case 2:
                printf("Removendo visitante da fila...\n");
                excluirVisitante(lista,&tamanho);
                break;
            case 3:
                exibirVisitantes(lista,tamanho);
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