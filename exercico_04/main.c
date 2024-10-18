#include <stdio.h>
#include <string.h>

#define MAX_Livros 550

typedef struct{
    char nome[50];
    char status;
}Livro;

typedef struct{
    Livro livro[MAX_Livros];
    int n;
}ListaLivros;

void inicializarLista(ListaLivros *lista){
    lista->n = 0;
}

int incluirLivro(ListaLivros *lista,char nome[],char status){
    if(lista->n < MAX_Livros){
        strcpy(lista->livro[lista->n].nome,nome);
        lista->livro[lista->n].status = status;
        lista->n++;
        return 1;
    }
    return 0;
}



int main(){
    

    return 0;
}