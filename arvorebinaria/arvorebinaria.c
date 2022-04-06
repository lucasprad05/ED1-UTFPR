#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NoArvore* PtrNoArvore;

typedef struct NoArvore {
    int chave;
    PtrNoArvore direita;
    PtrNoArvore esquerda;
}NoArvore;

void iniciaArvore(PtrNoArvore *no){
    (*no) = NULL;
    return;
}//void

bool vaziaArvore(PtrNoArvore *no){
    return ((*no) == NULL);
}//vaziaArvore

bool inserirArvore(PtrNoArvore *no, int valor){
    //condicoes de parada recursao
    //1 - achei ponto inserçao
    if((*no) == NULL){
        (*no) = malloc(sizeof(NoArvore));
        (*no)->direita = NULL;
        (*no)->esquerda = NULL;
        (*no)->chave = valor;
        return (true);
    }//if

    //2 - nao quero repetido
    if((*no)->chave == valor) return false;

    //percorrer arvore
    //valor > no.chave
    if(valor > (*no)->chave){
        return (inserirArvore(&(*no)->direita, valor));
    }else{
        return (inserirArvore(&(*no)->esquerda, valor));
    }//else
    return;
}//inserirArvore

void preOrdemArvore(PtrNoArvore *no){
    if((*no) == NULL) return;
    printf("%d ", (*no)->chave);
    preOrdemArvore(&(*no)->esquerda);
    preOrdemArvore(&(*no)->direita);
}//preOrdemArvore

void emOrdemArvore(PtrNoArvore *no){
    if((*no) == NULL) return;
    emOrdemArvore(&(*no)->esquerda);
    printf("%d ", (*no)->chave);
    emOrdemArvore(&(*no)->direita);
}//preOrdemArvore

void posOrdemArvore(PtrNoArvore *no){
    if((*no) == NULL) return;
    preOrdemArvore(&(*no)->esquerda);
    preOrdemArvore(&(*no)->direita);
    printf("%d ", (*no)->chave);
}//preOrdemArvore

bool pesquisaArvore(PtrNoArvore *no, int valor){
    //nao achei
    if((*no) == NULL) return false;

    //achei elemento
    if((*no)->chave == valor) return true;

    //recursao
    if(valor > (*no)->chave){
        return (pesquisaArvore(&(*no)->direita, valor));
    }else{
        return (pesquisaArvore(&(*no)->esquerda, valor));
    }//else
}//pesquisaArvore

int main(){
    PtrNoArvore raiz;
    iniciaArvore(&raiz);
    if(vaziaArvore(&raiz)){
        printf("Está Vazia!\n");
    }else{
        printf("Arvore contem elementos\n");
    }//else

    int inserir[] = {10, 5, 17, 13, 48, 10, 10, -10};
    for(int i = 0; i < 8; i++){
        inserirArvore(&raiz, inserir[i]);
    }//for

    printf("Pre Ordem: ");
    preOrdemArvore(&raiz);
    printf("\n");

    printf("Em Ordem: ");
    emOrdemArvore(&raiz);
    printf("\n");

    printf("Pos Ordem: ");
    posOrdemArvore(&raiz);
    printf("\n");

    int consula[] = {17, 13, -11, 12};
    for(int i = 0; i < 4; i++){
        if(pesquisaArvore(&raiz, consula[i])){
            printf("achou!\n");
        }else{
            printf("nao achou!\n");
        }//else
    }//for
    return 0;
}//main