#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 100;

typedef struct no No;
struct no{
    char nome[101];
    char tel[11];
    char endereco[101];
    char cpf[12];
    char dataNascimento[11];
    No* prox;
    No* ante;
};

char* le_string(int n){
    int qtd = n;
    char* string = (char*)malloc(sizeof(char)*qtd);
    scanf("%[^\n]s", string);
    return string;
}

void* inserir_contato(No* lista){
    No* aux = lista;
    No* novo = (No*)malloc(sizeof(No));
    char* teste;
    strcpy(novo->nome,teste);
    strcpy(novo->tel,le_string(11));
    strcpy(novo->endereco,le_string(101));
    strcpy(novo->cpf,le_string(12));
    strcpy(novo->dataNascimento,le_string(11));
    novo->ante = NULL;
    novo->prox = NULL;

    if(lista == NULL){
        lista = novo;
        return;
    }

    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
    novo->ante = aux;
}

int main(){

    No* lista;

    inserir_contato(lista);

    return 0;
}
