#include <stdio.h>
#include <string.h>

#define MAX 30

typedef struct{
    char compromisso[30];
    int horario;
} Compromisso;

typedef struct{
    Compromisso Compromisso[MAX];
    int quantidade;
}ListaCompromisso;

void iniciarLista(ListaCompromisso *lista){
    lista->quantidade = 0;
}

int incluirCompromisso(ListaCompromisso *lista, char compromisso[],int horario){
    if(lista->quantidade < MAX){
        int i;
        for( i = lista->quantidade -1;(i >= 0 && lista->Compromisso[i].horario> horario); i--){
            lista->Compromisso[i+1] = lista->Compromisso[i];
        }
        strcpy(lista->Compromisso[i + 1].compromisso,compromisso);
        lista->Compromisso[i +1].horario = horario;
        lista->quantidade++;
        return 1;
    }
    return 0;
}

void exibirListaCompromisso(ListaCompromisso *lista){
    printf("Lista de todos os compromissos:\n");
    for(int i = 0; i < lista->quantidade;i++){
        printf("Nome: %sHorario %d\n--------------\n",lista->Compromisso[i].compromisso,lista->Compromisso[i].horario);
    }
}

int excluirCompromisso(ListaCompromisso *lista,char nome[]){
    for (int i = 0; i < lista->quantidade; i++){
        if(strcmp(lista->Compromisso[i].compromisso,nome) == 0){
            for(int j = i; j < lista->quantidade -1; j++){
                lista->Compromisso[j] = lista->Compromisso[j+1];
            }
            lista->quantidade--;
            return 1;
        }
    }
    return 0;
}




int main(){
    int opcao;
    char nome[30];
    int horario;

    ListaCompromisso lista;

    iniciarLista(&lista);
    do{
        printf("------------ LISTA Compromisso ------------");
        printf("\n1 - Incluir Compromisso\n2 - Listar compromisso\n3 - Excluir compromisso\n4 - Encerrar programa");
        printf("\nDigite a opcao: ");
        scanf("%d",&opcao);
        getchar();
        switch (opcao){
        case 1:
            printf("\n1 - Incluir compromisso na lista\n");
            printf("Digite o compromisso: ");
            fgets(nome,sizeof(nome),stdin);
            printf("Digite a hora do do compromisso: ");
            scanf("%d",&horario);
            incluirCompromisso(&lista,nome,horario);            
        break;
        case 2:
            printf("\n2 - Listar todos Compromissos\n");
            exibirListaCompromisso(&lista);
        break;
        case 3:
            printf("Digita o compromisso ja realizado para excluir da lista:");
            fgets(nome,sizeof(nome),stdin);
            excluirCompromisso(&lista,nome);

            
            break;
        case 4:
            printf("SAIU...");
            break;
        default:
            printf("\nEscolha uma das opcoes validas");
        }

    }while(opcao != 4);



    return 0;
}