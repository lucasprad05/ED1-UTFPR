#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Ptr NoFila
typedef struct NoFila* PtrNofila;

//No Fila
typedef struct NoFila{
    int x;
    PtrNofila proximo;
}NoFila;

//PilhaDinamica
typedef struct{
    PtrNofila inicio;
    PtrNofila fim;
    int qtde;
}FilaDinamica;

//Funções
void iniciaFilaDinamica(FilaDinamica* fila);
bool estaVaziaFilaDinamica(FilaDinamica* fila);
int tamanhoFilaDinamica(FilaDinamica* fila);
void imprimirFilaDinamica(FilaDinamica* fila);
void enfileirarFilaDinamica(FilaDinamica* fila, int valor);
void desenfileirarFilaDinamica(FilaDinamica* fila);
void destruir(FilaDinamica* fila);

int main(){
    FilaDinamica f;
    iniciaFilaDinamica(&f);

    if(estaVaziaFilaDinamica(&f)){
        printf("Fila está vazia!\n");
    }//if

    int tam=tamanhoFilaDinamica(&f);
    printf("Tamanho da fila: %d\n", tam);

    imprimirFilaDinamica(&f);

    int inserir[] = {12, 7, 23, 10, 11, 27};
    for(int i = 0; i < 6; i++){
        enfileirarFilaDinamica(&f, inserir[i]);
        imprimirFilaDinamica(&f);
    }//for

    /*
    for(int i = 0; i < 7; i++){
        desenfileirarFilaDinamica(&f);
        imprimirFilaDinamica(&f);
    }//for
    */

    destruir(&f);
    return 0;
}//main

void iniciaFilaDinamica(FilaDinamica* fila){
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->qtde = 0;
    return;
}//iniciaFilaDinamica

bool estaVaziaFilaDinamica(FilaDinamica* fila){
    return (fila->qtde==0);
}//estaVaziaFilaDinamica

int tamanhoFilaDinamica(FilaDinamica* fila){
    return (fila->qtde);
}//tamanhoFilaDinamica

void imprimirFilaDinamica(FilaDinamica* fila){
    printf("Fila = [");
    PtrNofila aux;
    for(aux = fila->inicio; aux != NULL; aux = aux->proximo){
        printf("%d ", aux->x);
    }//for
    printf("]\n");
    return;
}//imprimirFilaDinamica

void enfileirarFilaDinamica(FilaDinamica* fila, int valor){
    PtrNofila novo = malloc(sizeof(NoFila));

    //copiar valor no novo no
    novo->x = valor;

    //proximo novo recebe nulo
    novo->proximo = NULL;
    
    //1 inserção
    if(estaVaziaFilaDinamica(fila)){
        fila->inicio = novo;
    }else{ //2 ou +
        fila->fim->proximo = novo;
    }//else
    fila->fim = novo;
    fila->qtde++;
    return;
}//enfileirarFilaDinamica

void desenfileirarFilaDinamica(FilaDinamica* fila){
    if(!estaVaziaFilaDinamica(fila)){
        PtrNofila aux = fila->inicio;
        if(tamanhoFilaDinamica == 1){
            fila->inicio = NULL;
            fila->fim = NULL;
        }else{
            fila->inicio = fila->inicio->proximo;
        }//else
        fila->qtde--;
        free(aux);
    }else{
        printf("Warning: Fila vazia!\n");
    }//else
    return;
}//desenfileirarFilaDinamica

void destruir(FilaDinamica* fila){
    while(!estaVaziaFilaDinamica(fila)){
        desenfileirarFilaDinamica(fila);
        imprimirFilaDinamica(fila);
        int tam = tamanhoFilaDinamica(fila);
        printf("Tamanho: %d\n", tam);
    }//while
    return;
}//destruir