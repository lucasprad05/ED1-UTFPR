/*
 * @file: exc3.c
 * @date: 09 mar 2022
 * @author: Lucas Prado
 * @brief: Aula 00 exercicio 3
 * Escreva uma função recursiva para calcular o valor de um número inteiro de base x elevada a um expoente inteiro y.
 */

#include <stdio.h>
#include <stdlib.h>

int calculaPotencia(int x, int y);

int main(){
    int x, y, resultado;
    printf("Digite o valor da base: ");
    scanf("%d", &x);
    printf("Digite o valor do expoente: ");
    scanf("%d", &y);
    resultado = calculaPotencia(x, y);
    printf("Resultado: %d\n", resultado);
    return 0;
}//main

int calculaPotencia(int x, int y){
    if(y == 0){
        return 1;
    }else{
        return x * calculaPotencia(x, y - 1);
    }//else
}//calculaPotencia