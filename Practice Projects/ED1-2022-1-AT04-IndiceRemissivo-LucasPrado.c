#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define TAMANHO 1000

FILE *in, *out;

//Ptr NoFila
typedef struct NoFila* PtrNoFila;

//No Fila
typedef struct NoFila{
    int x;
    PtrNoFila proximo;
}NoFila;

//PilhaDinamica
typedef struct{
    PtrNoFila inicio;
    PtrNoFila fim;
    int qtde;
}FilaDinamica;

typedef struct NoArvore* PtrNoArvore;

typedef struct NoArvore{
    char palavra[21];
    FilaDinamica f;
    PtrNoArvore direita;
    PtrNoArvore esquerda;
}NoArvore;

//########################################################
//########################################################
void converteMinusculo(char *busca);
void iniciaFilaDinamica(FilaDinamica* fila);
bool estaVaziaFilaDinamica(FilaDinamica* fila);
int tamanhoFilaDinamica(FilaDinamica* fila);
void imprimirFilaDinamica(FilaDinamica* fila);
bool buscarFilaDinamica(FilaDinamica* fila, int valor);
void enfileirarFilaDinamica(FilaDinamica* fila, int valor);
void iniciaArvore(PtrNoArvore *no);
bool vaziaArvore(PtrNoArvore *no);
bool inserirArvore(PtrNoArvore *no, char *busca);
void emOrdemArvore(PtrNoArvore *no);
bool pesquisaArvore(PtrNoArvore *no, char *busca, int pagina);
//########################################################
//########################################################

int main(int argc, char *argv[]){
    /*
    //controle entrada
    if(argc != 3){
        printf("ERROR!\n");
        return 0;
    }//if
    */

    PtrNoArvore raiz;
    iniciaArvore(&raiz);
    char frase[TAMANHO];
    char *busca;
    int pagina = 0;

    in = fopen("entrada2.txt", "r");
    out = fopen("saida2.txt", "w");
    if(in == NULL || out == NULL){
        printf("Erro ao abrir os arquivos\n");
        return 0;
    }//if

    //Pegar termos
    fgets(frase, TAMANHO, in);
    busca = strtok(frase, "<:,>\n");
    while(busca != NULL){
        busca = strtok(NULL, "<:,>\n");
        if(busca != NULL){
            inserirArvore(&raiz, busca);
        }//if
    }//while

    //Pegar primeira pagina
    while(!feof(in)){
        fgets(frase, TAMANHO, in);
        busca = strtok(frase, "<:> ,.\n");
        printf("%s\n", busca);
        if(strcmp(busca, "page") == 0){
            pagina++;
        }//if
        while(busca != NULL){
            converteMinusculo(busca);
            pesquisaArvore(&raiz, busca, pagina);
            busca = strtok(NULL, "<:> ,.\n");   
        }//while
    }//while

    emOrdemArvore(&raiz);

    fclose(in);
    fclose(out);
    return 0;
}//main

void converteMinusculo(char *busca){
    int t = strlen(busca);
    for(int i = 0; i < t; i++){
        busca[i] = tolower(busca[i]);
    }//for
    return;
}//converteMinusculo

//########################################################
//                       LISTA
//########################################################

void iniciaFilaDinamica(FilaDinamica* fila){
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->qtde = 0;
    return;
}//iniciaFilaDinamica

bool estaVaziaFilaDinamica(FilaDinamica* fila){
    return (fila->qtde == 0);
}//estaVaziaFilaDinamica

int tamanhoFilaDinamica(FilaDinamica* fila){
    return (fila->qtde);
}//tamanhoFilaDinamica

void imprimirFilaDinamica(FilaDinamica* fila){
    PtrNoFila aux;
    for(aux = fila->inicio; aux != NULL; aux = aux->proximo){
        if(aux->proximo == NULL){
            fprintf(out, "%d", aux->x);
        }else{
            fprintf(out, "%d,", aux->x);
        }
    }//for
    return;
}//imprimirFilaDinamica

bool buscarFilaDinamica(FilaDinamica* fila, int valor){
    PtrNoFila aux;
    for(aux = fila->inicio; aux != NULL; aux = aux->proximo){
        if(aux->x == valor){
            return true;
        }//if
    }//for
    return false;
}//buscarFilaDinamica

void enfileirarFilaDinamica(FilaDinamica* fila, int valor){
    if(buscarFilaDinamica(fila, valor)){
        return;
    }else{
        PtrNoFila aux = (PtrNoFila)malloc(sizeof(NoFila));
        aux->x = valor;
        if(estaVaziaFilaDinamica(fila)) {
            fila->inicio = fila->fim = aux;
            aux->proximo = NULL;
        }else{
            aux->proximo = fila->fim->proximo;
            fila->fim->proximo = aux;
            fila->fim = fila->fim->proximo;
        }//else
    }//else
    fila->qtde++;
    return;
}//enfileirarFilaDinamica

//########################################################
//                       ARVORE
//########################################################

void iniciaArvore(PtrNoArvore *no){
    (*no) = NULL;
    return;
}//void

bool vaziaArvore(PtrNoArvore *no){
    return ((*no) == NULL);
}//vaziaArvore

bool inserirArvore(PtrNoArvore *no, char *busca){
    //condicoes de parada recursao
    //1 - achei ponto inserçao
    if((*no) == NULL){
        (*no) = malloc(sizeof(NoArvore));
        converteMinusculo(busca);//converter minusculo
        strcpy((*no)->palavra, busca);
        (*no)->direita = NULL;
        (*no)->esquerda = NULL;
        iniciaFilaDinamica(&((*no)->f));
        return (true);
    }//if

    //2 - nao quero repetido
    if(strcmp((*no)->palavra, busca) == 0) return false;

    //percorrer arvore
    //valor > no.chave
    if(strcmp((*no)->palavra, busca) < 0){//---------------
        return (inserirArvore(&(*no)->direita, busca));
    }else{
        return (inserirArvore(&(*no)->esquerda, busca));
    }//else
}//inserirArvore

void emOrdemArvore(PtrNoArvore *no){
    if((*no) == NULL) return;
    emOrdemArvore(&(*no)->esquerda);
    fprintf(out, "%s,", (*no)->palavra);
    imprimirFilaDinamica(&((*no)->f));
    fprintf(out, "\n");
    emOrdemArvore(&(*no)->direita);
}//preOrdemArvore

bool pesquisaArvore(PtrNoArvore *no, char *busca, int pagina){
    //nao achei
    if((*no) == NULL) return false;

    //achei elemento
    if(strcmp((*no)->palavra, busca) == 0){
        enfileirarFilaDinamica(&((*no)->f), pagina);
        return true;
    }//if

    //recursao
    if(strcmp((*no)->palavra, busca) < 0){
        return (pesquisaArvore(&(*no)->direita, busca, pagina));
    }else{
        return (pesquisaArvore(&(*no)->esquerda, busca, pagina));
    }//else
}//pesquisaArvore

//printf("%s", busca);
//pesquisaArvore(&raiz, busca, pagina);