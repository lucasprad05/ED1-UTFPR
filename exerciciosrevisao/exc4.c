/*
 * @file: exc4.c
 * @date: 09 mar 2022
 * @author: Lucas Prado
 * @brief: Aula 00 exercicio 4
 * Faça um programa que leia um valor N e crie dinamicamente um vetor com essa quantidade de elementos.
 * Em seguida, passe esse vetor para uma função que vai ler os elementos desse vetor.
 * Depois, no programa principal, imprima os valores do vetor preenchido. 
 * Além disso, antes de finalizar o programa, lembre-se de liberar a área de memória alocada para armazenar os valores do vetor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheVetor(int *vet, int tamanho);
void imprimeVetor(int *vet, int tamanho);

int main(){
    srand(time(NULL));
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    int *vet;
    vet = malloc(tamanho * sizeof(int));

    //preencher vetor
    preencheVetor(vet, tamanho);
    imprimeVetor(vet, tamanho);
    free(vet);
    return 0;
}//main

void preencheVetor(int *vet, int tamanho){
  for(int i = 0; i < tamanho; i++){
    // gerar numeros aleatorios
    vet[i] = rand() % 10;
  }//for
}//preencheVetor

void imprimeVetor(int *vet, int tamanho){
  int i;
  printf("Vetor = [");
  for(i = 0; i < tamanho; i++){
    printf("%d ", vet[i]);
  }//for
  printf("]\n");
}//imprimeVetor