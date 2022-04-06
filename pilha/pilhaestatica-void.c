#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAMANHO 10

// Definição abstrato de pilha
typedef struct{
    //int vetor
    int vetor[TAMANHO];

    //topo
    int topo;
}PilhaEstatica;

void iniciaPilhaEstatica(PilhaEstatica *pilha);
bool estaVaziaPilhaEstatica(PilhaEstatica *pilha);
bool estaCheiaPilhaEstatica(PilhaEstatica *pilha);
void imprimePilhaEstatica(PilhaEstatica *pilha);
void empilharPilhaEstatica(PilhaEstatica *pilha, int x);
void desempilharPilhaEstatica(PilhaEstatica *pilha);

int main(){
    PilhaEstatica p;

    //iniciar pilha
    iniciaPilhaEstatica(&p);

    //verificar pilha
    if(estaVaziaPilhaEstatica(&p)){
        printf("Pilha está vazia!\n");
    }else{
        printf("Pilha não está vazia!\n");
    }//if
    if(estaCheiaPilhaEstatica(&p)){
        printf("Pilha está cheia!\n");
    }else{
        printf("Pilha não está cheia!\n");
    }//if

    //empilhar elemento
    empilharPilhaEstatica(&p, 7);
    empilharPilhaEstatica(&p, 3);
    empilharPilhaEstatica(&p, 12);
    empilharPilhaEstatica(&p, 23);
    empilharPilhaEstatica(&p, 10);
    empilharPilhaEstatica(&p, 32);
    empilharPilhaEstatica(&p, 69);
    empilharPilhaEstatica(&p, 85);
    empilharPilhaEstatica(&p, 100);
    empilharPilhaEstatica(&p, 101);

    //imprimir pilha
    imprimePilhaEstatica(&p);

    //imprimir tamanho da pilha
    printf("Tamanho da pilha: %d\n", tamanhoPilhaEstatica(&p));

    //remover pilha
    desempilharPilhaEstatica(&p);

    //imprimir pilha
    imprimePilhaEstatica(&p);
    return 0;
}//main

// inicialização pilha
void iniciaPilhaEstatica(PilhaEstatica *pilha){
    pilha->topo = -1;
    return;
}//iniciaPilhaEstatica

bool estaVaziaPilhaEstatica(PilhaEstatica *pilha){
    return(pilha->topo == -1);
}//estaVaziaPilhaEstatica

bool estaCheiaPilhaEstatica(PilhaEstatica *pilha){
    return(pilha->topo == (TAMANHO - 1));
}//estaVaziaPilhaEstatica

void imprimePilhaEstatica(PilhaEstatica *pilha){
    printf("Pilha = [");
    for(int i = 0; i <= pilha->topo; i++){
        printf("%d ", pilha->vetor[i]);
    }//for
    printf("]\n");
    return;
}//imprimePilhaEstatica

int tamanhoPilhaEstatica(PilhaEstatica *pilha){
    return(pilha->topo + 1);
}//tamanhoPilhaEstatica

//inserção empilhar-push
void empilharPilhaEstatica(PilhaEstatica *pilha, int x){
    if(estaCheiaPilhaEstatica(pilha)){
        printf("Erro! Pilha Cheia!\n");
    }else{
        pilha->topo++;
        pilha->vetor[pilha->topo] = x;
    }//else
    return;
}//empilharPilhaEstatica

//desempilhar-pop
void desempilharPilhaEstatica(PilhaEstatica *pilha){
    int aux;
    if(estaVaziaPilhaEstatica(pilha)){
        printf("Erro! Pilha Vazia!\n");
    }else{
        aux = pilha->vetor[pilha->topo];
        pilha->topo--;
    }//else

    printf("Elemento removido: %d\n", aux);
    return;
}//dempilharPilhaEstatica