#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 100;

typedef struct no No;
struct no{
    char nome[101];
    char tel[11];
    char endereco[101];
    int cep;
    char dataNascimento[11];
    No* prox;
    No* ante;
};

typedef struct head Head;
struct head{
    No* inicio;
    No* fim;
};

char* le_string(int n){
    int qtd = n;
    char* string = (char*)malloc(sizeof(char)*qtd);
    __fpurge(stdin);
    scanf("%[^\n]s", string);
    __fpurge(stdin);
    return string;
}

int le_inteiro(){
    int var;
    __fpurge(stdin);
    scanf("%d", &var);
    __fpurge(stdin);
    return var;
}

void imprime_lista(No* lista){
  if(lista != NULL){
      printf("%s\n", lista->nome);
      printf("%s\n", lista->tel);
      printf("%s\n", lista->endereco);
      printf("%d\n", lista->cep);
      printf("%s\n", lista->dataNascimento);
      printf("\n");
      imprime_lista(lista->prox);
  }
}

void inserir_contato(No** lista){
    No* aux = *lista;
    No* novo = (No*)malloc(sizeof(No));

    strcpy(novo->nome,le_string(101));
    strcpy(novo->tel,le_string(11));
    strcpy(novo->endereco,le_string(101));
    novo->cep = le_inteiro();
    strcpy(novo->dataNascimento,le_string(11));
    novo->ante = NULL;
    novo->prox = NULL;

    if(*lista == NULL){
        *lista = novo;
        return;
    }

    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
    novo->ante = aux;
    return;
}

int main(){

    No* lista = NULL;
    Head* head = NULL;
    inserir_contato(&lista);
    inserir_contato(&lista);
    imprime_lista(lista);

    // printf("%s\n", lista->nome);
    // printf("%s\n", lista->tel);
    // printf("%s\n", lista->endereco);
    // printf("%d\n", lista->cep);
    // printf("%s\n", lista->dataNascimento);
    return 0;
}
