#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int **matriz;
    int vertices;
    int arestas;
    bool dirigido;
}GrafoMatriz;

void iniciaGrafoMatriz(GrafoMatriz *g, int v, bool dir){
    g->vertices = v;
    g->arestas = 0;
    g->dirigido = dir;
    g->matriz = malloc(v * (sizeof(int*)));
    int i, j;
    for(i = 0; i < v; i++){
        g->matriz[i] = malloc(v * (sizeof(int)));
    }//for
    for(i = 0; i < v; i++){
        for(j = 0; j < v; j++){
            g->matriz[i][j] = 0;
        }//for
    }//for
    return;
}//void

void impressao(GrafoMatriz *g){
    int i, j, v;
    v = g->vertices;
    for(i = 0; i < v; i++){
        for(j = 0; j < v; j++){
            printf("%d ", g->matriz[i][j]);
        }//for
        printf("\n");
    }//for
}//impressao

void inserir(GrafoMatriz *g, int v1, int v2){
    g->matriz[v1][v2] = 1;
    if(!g->dirigido){
        g->matriz[v2][v1] = 1;
    }//if
    g->arestas++;
}//insercao

void remover(GrafoMatriz *g, int v1, int v2){
    g->matriz[v1][v2] = 0;
    if(!g->dirigido){
        g->matriz[v2][v1] = 0;
    }//if
    g->arestas--;
}//insercao

void destruir(GrafoMatriz *g){
    for(int i = 0; i < g->vertices; i++){
        free(g->matriz[i]);
    }//for
    free(g->matriz);
}//destruir

int main(){
    GrafoMatriz g;
    iniciaGrafoMatriz(&g, 6, true);
    inserir(&g, 0, 1);
    inserir(&g, 0, 4);
    inserir(&g, 1, 3);
    inserir(&g, 2, 3);
    inserir(&g, 2, 5);
    inserir(&g, 3, 4);
    inserir(&g, 4, 1);
    inserir(&g, 5, 5);
    impressao(&g);
    destruir(&g);
    return 0;
}//main