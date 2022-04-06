//Lista Dinâmica
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Single-linkage

//-------------------------------------------------
//NoLista
//  int
//  proximo (PtrNoLista)

//Lista
//  inicio (PtrNoLista)
//  qtde

typedef struct NoLista *PtrNoLista;

typedef struct NoLista{
    int elemento;
    PtrNoLista proximo;
}NoLista;

typedef struct{
    PtrNoLista inicio;
    int qtde;
}ListaOrdenada;

void iniciaListaOrdenada(ListaOrdenada* l);
bool estaVaziaListaOrdenada(ListaOrdenada* l);
int tamanhoListaOrdenada(ListaOrdenada* l);
void inserirListaOrdenada(ListaOrdenada* l, int x);
void imprimirListaOrdenada(ListaOrdenada* l);
bool pesquisaListaOrdenada(ListaOrdenada* l, int valor, int* contador);
bool removerListaOrdenada(ListaOrdenada* l, int valor);
void destruirListaOrdenada(ListaOrdenada* l);
void destruirListaOrdenadaNovo(ListaOrdenada* l);
int primeiroListaOrdenada(ListaOrdenada* l);

int main(int argc, char* argv[]){
    ListaOrdenada lista;
    iniciaListaOrdenada(&lista);
    
    if(estaVaziaListaOrdenada(&lista)){
        printf("Está vazia!\n");
    }//if

    printf("Tamanho: %d\n", tamanhoListaOrdenada(&lista));

    imprimirListaOrdenada(&lista);
    inserirListaOrdenada(&lista, 10);
    inserirListaOrdenada(&lista, 1);
    inserirListaOrdenada(&lista, 0);
    inserirListaOrdenada(&lista, 67);
    inserirListaOrdenada(&lista, 12);
    inserirListaOrdenada(&lista, 43);
    imprimirListaOrdenada(&lista);

    int con1 = 0;
    int busca[] = {0, -16, 2000, 42, 10};
    for(int i = 0; i < 5; i++){
        if(pesquisaListaOrdenada(&lista, busca[i], &con1)){
            printf("Encontrou!\n");
        }else{
            printf("Não Encontrou!\n");
        }//else
        printf("Contador: %d\n", con1);
    }//for

    removerListaOrdenada(&lista, 67);
    imprimirListaOrdenada(&lista);

    destruirListaOrdenada(&lista);
    imprimirListaOrdenada(&lista);
    
    return;
}//main

//iniciar lista
void iniciaListaOrdenada(ListaOrdenada* l){
    l->inicio = NULL;
    l->qtde = 0;
    return;
}//iniciaListaOrdenada

//esta vazia
bool estaVaziaListaOrdenada(ListaOrdenada* l){
    return (l->inicio == NULL);
}//estaVaziaListaOrdenada

//tamanho lista
int tamanhoListaOrdenada(ListaOrdenada* l){
    return (l->qtde);
}//tamanhoListaOrdenada

//inserir elemento
void inserirListaOrdenada(ListaOrdenada* l, int x){
    PtrNoLista novo;
    novo = malloc(sizeof(NoLista));
    novo->elemento = x;

    if(estaVaziaListaOrdenada(l) || novo->elemento < l->inicio){
        novo->proximo = l->inicio;
        l->inicio = novo;
    }else{
        PtrNoLista aux = l->inicio;
        while(aux->proximo != NULL && aux->proximo->elemento <= x){
            aux = aux->proximo;
        }//while
        novo->proximo = aux->proximo;
        aux->proximo = novo;
    }//else
    l->qtde++;
}//inserirListaOrdenada

//imprimir lista
void imprimirListaOrdenada(ListaOrdenada* l){
    printf("Lista = [");
    PtrNoLista temp;
    for(temp = l->inicio; temp != NULL; temp = temp->proximo){
        printf("%d ", temp->elemento);
    }//for
    printf("]\n");
    return;
}//imprimirListaOrdenada

//pesquisa
bool pesquisaListaOrdenada(ListaOrdenada* l, int valor, int* contador){
    //percorrerlista
    PtrNoLista aux;
    for(aux = l->inicio; aux != NULL; aux = aux->proximo){
        (*contador)++;
        if(aux->elemento == valor){
            return true;
        }//for
        if(aux->elemento > valor){
            return false;
        }//if
    }//for
    return false;
}//pesquisaListaOrdenada

//remover elemento
bool removerListaOrdenada(ListaOrdenada* l, int valor){
    PtrNoLista aux;
    if(estaVaziaListaOrdenada(l) || valor < l->inicio->elemento){
        printf("Não da pra remover!\n\n");
        return false;
    }//if

    if(valor == l->inicio->elemento){
        aux = l->inicio;
        l->inicio = l->inicio->proximo;
        free(aux);
        l->qtde--;
        return true;
    }//if

    aux = l->inicio;
    while(aux->proximo != NULL && aux->proximo->elemento < valor){
        aux = aux->proximo;
    }//while

    if(aux->proximo == NULL || aux->proximo->elemento != valor){
        printf("Não da pra remover!\n");
        return false;
    }//if

    PtrNoLista remove = aux->proximo;
    aux->proximo = aux->proximo->proximo;
    free(remove);
    l->qtde--;
    return true;
}//removerListaOrdenada

//destruir lista
void destruirListaOrdenada(ListaOrdenada* l){
    PtrNoLista aux;
    while(l->qtde != 0){
        aux = l->inicio;
        l->inicio = l->inicio->proximo;
        free(aux);
        l->qtde--;
    }//while
}//destruirListaOrdenada

int primeiroListaOrdenada(ListaOrdenada* l){
    if(!estaVaziaListaOrdenada){
        return l->inicio->elemento;
    }else{
        return -999;
    }//else
}//primeiroListaOrdenada

void destruirListaOrdenadaNovo(ListaOrdenada* l){
    int remover;
    while(!estaVaziaListaOrdenada){
        remover = primeiroListaOrdenada(l);

        removerListaOrdenada(l, remover);
    }//while
}//destruirListaOrdenada