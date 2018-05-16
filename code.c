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

int vazia(No* lista){
    if(lista->prox == NULL)
        return 1;
    else
        return 0;
}

void imprime_contatos(No* lista){
    if(vazia(lista)){
        printf("Lista vazia!\n\n");
    }else{
        //
    }
}

void libera_lista(No* lista){
    if(!vazia(lista)){
        No *proxNo, *atual;

        atual = lista->prox;
        while(atual != NULL){
            proxNo = atual->prox;
            free(atual);
            atual = proxNo;
        }
    }
}

int menu(void){
    int opt;

    printf("*----------------------------------*\n");
    printf("*              AGENDA              *\n");
    printf("*----------------------------------*\n");
    printf("* 1- Inserir novo contato          *\n");
    printf("* 2- Remover contato               *\n");
    printf("* 3- Visualizar um contato         *\n");
    printf("* 4- Visualizar todos os contatos  *\n");
    printf("* 5- Sair                          *\n");
    printf("*----------------------------------*\n");
    printf("Opção: ");    
    scanf("%d", &opt);

    return opt;
}

void opcao(No* lista, int op){

    switch(op){
        case 1:
            //inserir_contato();
            break;
        case 2:
            //remover_contato();
            break;
        case 3:
            //visualizar_contato();
            break;
        case 4:
            //imprime_contatos();
            break;
        case 5:
            exit(1);
        default:
            printf("Opção inválida!\n");
    }
}

int main(){

    No* lista = NULL;
    //Head* head = NULL;
    

    // int opt;
    // No* lista;

    // do {
    //     opt = menu();
    //     opcao(lista, opt);
    // } while (opt);
    
    
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
