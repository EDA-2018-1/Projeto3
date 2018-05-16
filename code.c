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

void remove_elemento(No** lista, char* nome){
    No* aux = *lista;

    if(strcmp(nome,aux->nome) == 0 && aux->ante == NULL){
        *lista = aux->prox;
        aux->prox->ante = NULL;
        free(aux);
        return;
    }
    while(aux->prox != NULL){
        if(strcmp(nome,aux->prox->nome) == 0){
            No* aux2 = aux->prox;
            if(aux2->prox != NULL){
                aux->prox = aux2->prox;
                aux2->prox->ante = aux;
            }else aux->prox = NULL;
            free(aux2);
        }else {
            aux = aux->prox;
        }
    }
}

void imprime_elemento(No** lista, char* nome){
    No* aux = *lista;

    while(aux != NULL){
        if(strcmp(aux->nome,nome) == 0){
            printf("%s\n", aux->nome);
            printf("%s\n", aux->tel);
            printf("%s\n", aux->endereco);
            printf("%d\n", aux->cep);
            printf("%s\n", aux->dataNascimento);
            printf("\n");
        }
        aux = aux->prox;
    }
}

int main(){

    No* lista = NULL;
    //Head* head = NULL;
    inserir_contato(&lista);
    inserir_contato(&lista);
    inserir_contato(&lista);
    imprime_lista(lista);
    char* nome = (char*)malloc(sizeof(char));
    __fpurge(stdin);
    scanf("%s", nome);
    __fpurge(stdin);
    // remove_elemento(&lista,nome);
    // imprime_lista(lista);
    imprime_elemento(&lista,nome);
    // printf("%s\n", lista->nome);
    // printf("%s\n", lista->tel);
    // printf("%s\n", lista->endereco);
    // printf("%d\n", lista->cep);
    // printf("%s\n", lista->dataNascimento);
    return 0;
}
