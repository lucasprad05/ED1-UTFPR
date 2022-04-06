#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NoPilha* PtrNoPilha;
typedef struct NoPilha{
    int x;
    PtrNoPilha proximo;
}NoPilha;

typedef struct{
    PtrNoPilha topo;
    int qtde;
}PilhaDinamica;

void inicializarPilha(PilhaDinamica *pilha);
bool estaVaziaPilha(PilhaDinamica *pilha);
int tamanhoPiha(PilhaDinamica *pilha);
void imprimirPilha(PilhaDinamica *pilha);
void desempilhaPilha(PilhaDinamica *pilha);
void destruirPilha(PilhaDinamica *pilha);

int main(){
    PilhaDinamica p;
    inicializarPilha(&p);
    if(estaVaziaPilha(&p)){
        printf("Pilha está vazia!\n");
    }else{
        printf("Pilha não está vazia\n");
    }//else
    empilharPilha(&p, 7);
    empilharPilha(&p, 8);
    empilharPilha(&p, 12);

    imprimirPilha(&p);

    int tam = tamanhoPilha(&p);
    for(int i = 0; i < tam; i++){
        desempilhaPilha(&p);
        imprimirPilha(&p);
    }//for
    return 0;
}//main

//iniciar
void inicializarPilha(PilhaDinamica *pilha){
    //topo
    pilha->topo = NULL;
    //contador
    pilha->qtde = 0;
}//inicializarPilha

//verificar se esta vazia
bool estaVaziaPilha(PilhaDinamica *pilha){
    //topo == null
    return(pilha->topo = NULL);
}//estaVaziaPilha

//tamanho
int tamanhoPilha(PilhaDinamica *pilha){
    return(pilha->qtde);
}//tamanhoPiha

//imprimir
void imprimirPilha(PilhaDinamica *pilha){
    PtrNoPilha aux = pilha->topo;
    printf("Pilha = [");
    //codigo impressao
    while(aux != NULL){
        printf("%d ", aux->x);
        aux = aux->proximo;
    }//while
    printf("]\n");
}//imprimirPilha

//inserir
void empilharPilha(PilhaDinamica *pilha, int aux){
    //criar novo no
    PtrNoPilha novo = malloc(sizeof(NoPilha));
    //copiar valor no novo no
    novo->x = aux;

    novo->proximo = pilha->topo;

    pilha->topo = novo;

    pilha->qtde++;
}//empilharPilha

//remover
void desempilhaPilha(PilhaDinamica *pilha){
    if(!estaVaziaPilha(pilha)){
    //criar aux
    PtrNoPilha aux;
    //aux = no removido
    aux = pilha->topo;
    //att topo
    pilha->topo = pilha->topo->proximo;
    //liberar memoria
    free(aux);
    //qtde--
    pilha->qtde--;
    }//if
}//desempilhaPilha

//destruir
void destruirPilha(PilhaDinamica *pilha){
    while(pilha->qtde != 0){
        desempilhaPilha(pilha);
    }//while
}//void

//consultar topo