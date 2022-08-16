/*
 * @file: ED1-2022-1-AT01-ConversorD2B-LucasPrado.c
 * @date: 21 mar 2022
 * @author: Lucas Prado
 * @brief: Atividade Prática 01
 */

#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 50

typedef struct{
    int valor[TAMANHO];
    int topo;
}PilhaEstatica;

void iniciaPilhaEstatica(PilhaEstatica *pilha);
void empilharPilhaEstatica(PilhaEstatica *pilha, FILE* arq1);
void imprimePilhaEstatica(PilhaEstatica *pilha);
int desempilharPilhaEstatica(PilhaEstatica *pilha);
void converteBinario(PilhaEstatica *pilha, PilhaEstatica *bin, FILE* arq2);

int main(int argc, char *argv[]){
    //controle entrada
    if(argc != 3){
        printf("ERROR!\n");
        return 0;
    }//if

    PilhaEstatica p, b;

    //abrir arquivos
    FILE *arq1, *arq2;
    arq1 = fopen(argv[1],"r");
    arq2 = fopen(argv[2], "w");
    if(arq1 == NULL || arq2 == NULL){
        printf("Erro ao abrir os arquivos\n");
        return 0;
    }//if

    //iniciar Pilhas
    iniciaPilhaEstatica(&p);
    iniciaPilhaEstatica(&b);

    //empilhar
    empilharPilhaEstatica(&p, arq1);

    //imprimir Pilha
    imprimePilhaEstatica(&p);

    //converteBinario
    converteBinario(&p, &b, arq2);

    fclose(arq1);
    fclose(arq2);
    return 0;
}//main

void iniciaPilhaEstatica(PilhaEstatica *pilha){
    pilha->topo = -1;
    return;
}//iniciaPilhaEstatica

void empilharPilhaEstatica(PilhaEstatica *pilha, FILE* arq1){
    while(!feof(arq1)){
        pilha->topo++;
        fscanf(arq1,"%d",&pilha->valor[pilha->topo]);
    }//while
    return;
}//empilharPilhaEstatica

void imprimePilhaEstatica(PilhaEstatica *pilha){
    printf("Pilha = [");
    for(int i = 0; i <= pilha->topo; i++){
        printf("%d ", pilha->valor[i]);
    }//for
    printf("]\n");
    return;
}//imprimePilhaEstatica

void converteBinario(PilhaEstatica *pilha, PilhaEstatica *bin, FILE* arq2){
    while(pilha->topo >= 0){
        int num = desempilharPilhaEstatica(pilha);
        do{
            if(num % 2 == 0){
                bin->topo++;
                bin->valor[bin->topo] = 0;
                num /= 2;
            }else{
                bin->topo++;
                bin->valor[bin->topo] = 1;
                num /= 2;
            }//else
        }while(num > 0);

        //exibir na tela e salvar no arquivo
        while(bin->topo >= 0){
            int aux = desempilharPilhaEstatica(bin);
            printf("%d", aux);
            fprintf(arq2, "%d", aux);
        }//while
        printf("\n");
        fprintf(arq2, "\n"); 
    }//while
    return;
}//converteBinario