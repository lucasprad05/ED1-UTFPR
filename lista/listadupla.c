#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// PrtNoLista
typedef struct NoLista* PtrNoLista;

// NoLista (alterado)
typedef struct NoLista{
  int elemento;
  PtrNoLista proximo;
  PtrNoLista anterior;
}NoLista;

// ListaDuplamente
typedef struct {
  int qtde;
  PtrNoLista inicio;
}ListaDupla;

void iniciaListaDupla(ListaDupla* l){
    l->inicio = NULL;
    l->qtde = 0;
    return;
}//iniciaListaDupla

bool vaziaLista(ListaDupla* l){
    return (l->qtde == 0);
}//vaziaLista

int tamanhoLista(ListaDupla* l){
    return (l->qtde);
}//tamanhoLista

void imprimirLista(ListaDupla* l){
    printf("Lista = [");
    for(PtrNoLista aux = l->inicio; aux!=NULL; aux = aux->proximo){
        printf("%d ", aux->elemento);
    }
    printf("]\n");
    return;
}//imprimirLista

void inserirLista(ListaDupla* l, int x){
    PtrNoLista novo;
    novo = malloc(sizeof(NoLista));
    novo->elemento = x;

    //casos
    if(vaziaLista(l)){//Lista Vazia
        novo->proximo = NULL;
        novo->anterior = NULL;
        l->inicio = novo;
    }else if(novo->elemento < l->inicio){//Menor que inicio
        novo->proximo = l->inicio;
        l->inicio->anterior = novo;
        novo->anterior = NULL;
        l->inicio = novo;
    }else{//percorrer lista - meio, fim
        PtrNoLista aux = l->inicio;
        while(aux->proximo != NULL && aux->proximo->elemento <= x){
            aux = aux->proximo;
        }//while
        novo->proximo = aux->proximo;
        if(aux->proximo != NULL){
            aux->proximo->anterior = novo;
        }//if
        novo->anterior = aux;
        aux->proximo = novo;
    }//else
    l->qtde++;
    return;
}//inserirLista

bool removeLista(ListaDupla* l, int x){
    PtrNoLista aux;
    if(vaziaLista(l) || x < l->inicio->elemento){
        printf("Não da pra remover!\n");
        return false;
    }//if

    if(x == l->inicio->elemento){
        aux = l->inicio;
        l->inicio = l->inicio->proximo;
        l->inicio->anterior = NULL;
        free(aux);
        l->qtde--;
        return true;
    }//if primeiro elemento

    aux = l->inicio;
    while(aux->proximo != NULL && aux->proximo->elemento < x){
        aux = aux->proximo;
    }//while

    if(aux->proximo == NULL || aux->proximo->elemento != x){
        printf("Não da pra remover!\n");
        return false;
    }//if

    PtrNoLista remove = aux->proximo;
    aux->proximo = aux->proximo->proximo;
    if(aux->proximo->proximo != NULL){
        aux->proximo->anterior = aux;
    }//if
    free(remove);
    l->qtde--;
    return true;
}//void

void imprimirReversoLista(ListaDupla* l){
    printf("Lista = [");
    PtrNoLista aux;
    aux = l->inicio;
    while(aux->proximo != NULL){
        aux = aux->proximo;
    }//while
    for(aux; aux != NULL; aux = aux->anterior){
        printf("%d ", aux->elemento);
    }//for
    printf("]\n");
    return;
}//imprimirLista

int main(){
    ListaDupla lista;
    iniciaListaDupla(&lista);

    //verificar se ta vazia
    if(vaziaLista(&lista)){
        printf("Está vazia!\n");
    }//if

    inserirLista(&lista, 10);
    inserirLista(&lista, 1);
    inserirLista(&lista, 0);
    inserirLista(&lista, 67);
    inserirLista(&lista, 12);
    inserirLista(&lista, 43);
    imprimirLista(&lista);
    printf("Tamanho: %d\n", tamanhoLista(&lista));
    removeLista(&lista, 67);
    imprimirReversoLista(&lista);

    //printar tamanho
    printf("Tamanho: %d\n", tamanhoLista(&lista));

    return 0;
}//main