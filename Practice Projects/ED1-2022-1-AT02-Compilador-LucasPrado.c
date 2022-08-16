/*
 * @file: ED1-2022-1-AT02-Compilador-LucasPrado.c
 * @date: 04 apr 2022
 * @author: Lucas Prado
 * @brief: Atividade Prática 02
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NoPilha* PtrNoPilha;

typedef struct NoPilha{
    char x;
    PtrNoPilha proximo;
}NoPilha;

typedef struct{
    PtrNoPilha topo;
    int qtde;
}PilhaDinamica;

void inicializarPilha(PilhaDinamica *pilha);
void imprimirPilha(PilhaDinamica *pilha);
void empilharPilha(PilhaDinamica *pilha, char aux);
char desempilhaPilhaDinamica(PilhaDinamica *pilha);
void compilador(PilhaDinamica *pilha, FILE* arq1, FILE* arq2);

int main(){
    //controle entrada
    /*
    if(argc != 3){
        printf("ERROR!\n");
        return 0;
    }//if
    */
   
    PilhaDinamica p;

    //abrir arquivos
    FILE *in, *out;
    in = fopen("entrada.txt","r");
    out = fopen("saida.txt", "w");
    if(in == NULL || out == NULL){
        printf("Erro ao abrir os arquivos\n");
        return 0;
    }//if

    //iniciar Pilha
    inicializarPilha(&p);
    compilador(&p, in, out);

    fclose(in);
    fclose(out);
    return 0;
}//main

void inicializarPilha(PilhaDinamica *pilha){
    //topo
    pilha->topo = NULL;
    //contador
    pilha->qtde = 0;
}//inicializarPilha

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

void empilharPilha(PilhaDinamica *pilha, char aux){
    //criar novo no
    PtrNoPilha novo = malloc(sizeof(NoPilha));
    //copiar valor no novo no
    novo->x = aux;

    novo->proximo = pilha->topo;

    pilha->topo = novo;

    pilha->qtde++;
}//empilharPilha

char desempilhaPilhaDinamica(PilhaDinamica *pilha){
    char c;
    PtrNoPilha aux;
    aux = pilha->topo;
    c = aux->x;
    pilha->topo = aux->proximo; 
    free(aux);
    pilha->qtde--;
    return(c);
}//desempilhaPilhaDinamica

void compilador(PilhaDinamica *pilha, FILE* arq1, FILE* arq2){
    char c, valor1, valor2;
    char temp1 = 'T';
    int contador = 0;
    while(!feof(arq1)){
        c = fgetc(arq1);

        if(c == 43|| c == 45 || c == 42 || c == 47){
            valor1 = desempilhaPilhaDinamica(pilha);
            if(valor1 != 84){ //pra printar TEMP(contador) certo na linha 139
                fprintf(arq2, "LDR %c\n", valor1);
            }//if

            valor2 = desempilhaPilhaDinamica(pilha);
            fprintf(arq2, "LDR %c\n", valor2);
            switch(c){
                case 43:// +
                    fprintf(arq2, "ADD %c %c", valor1, valor2);
                    break;

                case 45:// -
                    fprintf(arq2, "SUB %c %c", valor1, valor2);
                    break;
                    
                case 42:// *
                    fprintf(arq2, "MUL %c %c", valor1, valor2);
                    break;
                    
                case 47:// /
                    fprintf(arq2, "DIV %c %c", valor1, valor2);
                    break;
                    
                default:
                    printf("Error!\n");
            }//switch

            if(pilha->qtde != 0){
                fprintf(arq2, "\n");//coloquei aqui só pra não dar \n na ultima linha no arquivo

                contador++;
                fprintf(arq2, "STR TEMP%d\n", contador);
                fprintf(arq2, "LDR TEMP%d\n", contador);
                empilharPilha(pilha, temp1);
            }//if
        }else if(65 <= c <= 90 ||  97 <= c <= 122){//controle alfabeto tabela ASCII
            empilharPilha(pilha, c);
        }//else
    }//while
    return;
}//void

//controle dos argumentos
//linha 110