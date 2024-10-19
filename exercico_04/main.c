// 4.Biblioteca de uma universidade

#include <stdio.h>
#include <string.h>

#define MAX_Livros 550

typedef struct{
    char nome[50];
    int codigo;
    char status;
}Livro;

typedef struct{
    Livro livro[MAX_Livros];
    int n;
}ListaLivros;

void inicializarLista(ListaLivros *lista){
    lista->n = 0;
}

int incluirLivro(ListaLivros *lista,char nome[],int codigo,char status){
    if(lista->n < MAX_Livros){
        strcpy(lista->livro[lista->n].nome,nome);
        lista->livro[lista->n].codigo = codigo;
        lista->livro[lista->n].status = status;
        lista->n++;
        return 1;
    }
    return 0;
}

void exibirLivros(ListaLivros *lista){
    printf("Listar todos os Livros:\n");
    for(int i = 0; i < lista->n;i++){
        printf("Nome %sCodigo %d\nStatus %c\n---------------\n",lista->livro[i].nome,lista->livro[i].codigo,lista->livro[i].status);
    }
}

int excluirLivros(ListaLivros *lista,char nome[]){
    for(int i = 0; i < lista->n; i++){
        if(strcmp(lista->livro[i].nome,nome) == 0 && lista->livro[i].status == 'D'){
            for(int j = i; j < lista->n -1; j++){
                lista->livro[j] = lista->livro[j+1];
            }
            lista->n--;
            return 1;
        }
    }
    return 0;
}


int main(){
    int opcao;
    char nome[50],status;
    int codigo;

    ListaLivros lista;

    inicializarLista(&lista);

    do{
        printf("------------ LISTA Livros ------------");
        printf("\n1 - Incluir Livro\n2 - Listar Livros\n3 - Excluir Livro\n4 - Encerrar programa");
        printf("\nDigite a opcao: ");
        scanf("%d",&opcao);
        getchar();
        switch (opcao){
        case 1:
            printf("\n1 - Incluir novo Livro\n");
            printf("Digite o nome do Livro: ");
            fgets(nome,sizeof(nome),stdin);
            printf("Digite o codigo do livro: ");
            scanf("%d",&codigo);
            getchar();
            printf("Digite o estado do Livro (D - Danificado, N - Normal): ");
            scanf("%c",&status);
            incluirLivro(&lista,nome,codigo,status);            
        break;
        case 2:
            printf("\n2 - Listar todos Livros\n");
            exibirLivros(&lista);
        break;
        case 3:
            printf("Digita o Livro danificado para excluir da lista:");
            fgets(nome,sizeof(nome),stdin);
            excluirLivros(&lista,nome);
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