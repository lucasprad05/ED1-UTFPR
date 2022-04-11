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

PtrNoArvore procuraMaior(PtrNoArvore *no){
    while((*no)->direita!= NULL){
        (*no) = (*no)->direita;
    }//while
    PtrNoArvore ret = (*no);
    (*no) = (*no)->esquerda;
    return (ret);
}//procuraMaior

//--------------------------------------------------------
//REMOCAO
//--------------------------------------------------------
bool removeArvore(PtrNoArvore *no, int valor){
//pode nao encontrar o valor(NULL)-> return false
    if((*no) == NULL) return false;

//se encontrar
    if((*no)->chave == valor){
        PtrNoArvore tmp = (*no);

        //caso 1 folha: no = NULL
        if((*no)->direita == NULL && (*no)->esquerda == NULL){
            (*no) = NULL;
        }
        //caso 2 subarvore esq existe: no-esq
        else if((*no)->direita == NULL && (*no)->esquerda != NULL){
            (*no) = (*no)->esquerda;
        }
        //caso 3 subarvore dir existe: no-dir
        else if((*no)->direita != NULL && (*no)->esquerda == NULL){
            (*no) = (*no)->direita;
        }else{
        //caso 4 tem duas subarvores:
            //A: maior elemento subarvore esq
            //B: menor elemento subarvore dir
            tmp = procuraMaior(&(*no)->esquerda);
            (*no)->chave = tmp->chave;
        }//else
    free(tmp);
    return true;
    }//if

//se nao
//recursiva
    if(valor > (*no)->chave){
        return(removeArvore(&(*no)->direita, valor));
    }else{
        return (removeArvore(&(*no)->esquerda, valor));
    }//else
}//removeArvore

//funcao auxiliar (procura maximo na subarvore esquerda)



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

    int consulta[] = {17, 13, -11, 12};
    for(int i = 0; i < 4; i++){
        if(pesquisaArvore(&raiz, consulta[i])){
            printf("achou!\n");
        }else{
            printf("nao achou!\n");
        }//else
    }//for

    removeArvore(&raiz, -10);
    preOrdemArvore(&raiz);
    return 0;
}//main
