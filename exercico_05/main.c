//5. Fila de atendimento em uma clínica médica

#include <stdio.h>
#include <string.h>

#define MAX 70
#define NOME_MAX 20




void inserirLista(char lista[][NOME_MAX],int *tamanho, char nome[]){
    if(*tamanho < MAX){
        strcpy(lista[*tamanho],nome);
        (*tamanho)++;
    }

}

void exibirPacientes(char lista[][NOME_MAX],int tamanho){
    printf("\nFila dos Pacientes aguardando o atendimento: \n");
    for(int i = 0; i < tamanho; i++){
        printf("%s",lista[i]);
    }
}

int excluirPaciente(char lista[][NOME_MAX],int *tamanho){
    if(*tamanho > 0){
        printf("Paciente %s foi atendido(a) e sera removido da lista",lista[0]);
        for (int i = 1; i < *tamanho; i++){
            strcpy(lista[i - 1],lista[i]);
        }
        (*tamanho)--;
    }
}


int main(){
    
    int opcao,tamanho = 0;
    char lista[MAX][NOME_MAX];
    char nome[NOME_MAX];


    do{
        printf("\nDigite sua escolha: \n1 - Adicionar um paciente\n2 - Remover um paciente\n3 - Exibir a lista de pacientes aguardando atendimento\n0 - Sair do programa");
        printf("\nSua escolha: ");
        scanf("%d",&opcao);
        getchar();
        switch (opcao){
            case 1:
                printf("Digita o nome do paciente: ");
                fgets(nome,sizeof(nome),stdin);
                inserirLista(lista,&tamanho,nome);
                break;
            case 2:
                printf("Removendo Paciente atendido...\n");
                excluirPaciente(lista,&tamanho);
                break;
            case 3:
                exibirPacientes(lista,tamanho);
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