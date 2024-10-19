//3. Cadastro de alunos em uma escola

#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct{
    char nome[20];
    int matricula;
}Aluno;

typedef struct{
    Aluno dado[MAX];
    int n;
}ListaAlunos;

void iniciarLista(ListaAlunos *lista){
    lista->n = 0;
}

int acrescentar(ListaAlunos *lista,char nome[],int matricula){
    if(lista->n < MAX){
        strcpy(lista->dado[lista->n].nome,nome);
        lista->dado[lista->n].matricula = matricula;
        lista->n++;
        return 1;
    }
    return 0;
}

void exibirAlunos(ListaAlunos *lista){
    printf("Lista todos os alunos:\n");
    for(int i = 0; i < lista->n;i++){
        printf("Nome: %sMatricula %d\n----------------\n",lista->dado[i].nome,lista->dado[i].matricula);
    }
}

void buscarMatricula(ListaAlunos *lista,int matricula){
    printf("Buscando aluno...\nSe nao for encontrado nada sera exibido...\n");
    //int achou = 0;
    for(int i = 0; i < lista->n; i++){
        if(lista->dado[i].matricula == matricula){
            printf("Aluno encontrado:\nNome %sMatricula %d",lista->dado[i].nome,lista->dado[i].matricula);
            //achou = 1;
            //break;
        }
       // if(!achou){
       //     printf("Matricula nao foi encontrada");
       //     break;
//}
    }
}




int main(){
    int opcao,matricula;
    char nome[20];

    ListaAlunos lista;

    iniciarLista(&lista);

    do{
        printf("\n------------ LISTA ALUNOS ------------");
        printf("\n1 - Incluir Aluno na lista\n2 - Listar todos Alunos\n3 - Buscar Matricula\n4 - Encerrar programa");
        printf("\nDigite a opcao: ");
        scanf("%d",&opcao);
        getchar();
        switch(opcao){
            case 1:
                printf("\n1 - Incluir Aluno na lista\n");
                printf("Digite o nome do aluno: ");
                fgets(nome,sizeof(nome),stdin);
                printf("Digite a matricula do aluno: ");
                scanf("%d",&matricula);
                acrescentar(&lista,nome,matricula);
            break;
            case 2:
                printf("\n2 - Listar todos Alunos\n");
                exibirAlunos(&lista);
            break;
            case 3:
                printf("\n3 - Buscar Matricula\n");
                printf("Digite a matricula do aluno: ");
                scanf("%d",&matricula);
                buscarMatricula(&lista,matricula);
            break;
            case 4:
                printf("\nSAIU...");
            break;
            default:
                printf("\nEscolha uma das opcoes validas");
        }
    }while(opcao != 4);


    return 0;
}