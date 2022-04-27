#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//TAD
//dir, esq
//chave
//int altura

//NoAVL* PtrNoAVL
typedef struct NoAVL* PtrNoAVL;

typedef struct NoAVL{
    PtrNoAVL dir, esq;
    int chave;
    int altura;
}NoAVL;

void iniciaAVL(PtrNoAVL *no){
    (*no) = NULL;
}//iniciaArvoreAVL

bool estaVaziaAVL(PtrNoAVL *no){
    return ((*no) == NULL);
}//estaVaziaAVL

void preOrdemAVL(PtrNoAVL *no){
    if((*no) == NULL) return;
    printf("%d\n", (*no)->chave);
    preOrdemAVL(&(*no)->esq);
    preOrdemAVL(&(*no)->dir);
}//preOrdemAVL

int main(){
    PtrNoAVL raiz;
    if(estaVaziaAVL(&raiz)){
        printf("Esta Vazia\n");
    }//if
    return 0;
}//main