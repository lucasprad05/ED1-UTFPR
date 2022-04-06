/*
 * @file: exc1.c
 * @date: 09 mar 2022
 * @author: Lucas Prado
 * @brief: Aula 00 exercicio 1
 * Um ponteiro pode ser usado para dizer a uma funçãoo onde ela deve depositar o resultado de seus cálculos. 
 * Escreva uma função que converta uma quantidade de minutos na notação horas/minutos. 
 * A função recebe como parâmetro: um número inteiro (totalMinutos); e os endereços de duas variáveis inteiras, horas e minutos.
 * 
 * A função deve então atribuir valores às variáveis passadas por referência, de modo que os valores atribuídos respeitem as seguintes condições:
 *                                      minutos < 60
 *                          60 ? horas + minutos = totalMinutos
 * Escreva também a função principal (main) que use a função desenvolvida.
 */

#include <stdio.h>
#include <stdlib.h>

void calculaMinutos(int *totalMinutos, int *horas, int *minutos);

int main(){
    int totalMinutos, horas, minutos;
    do{
        printf("Digite o total de minutos: ");
        scanf("%d", &totalMinutos);
    }while(totalMinutos < 0);

    //chamar função
    calculaMinutos(&totalMinutos, &horas, &minutos);
    printf("Horas: %d Minutos: %d\n", horas, minutos);
    return 0;
}//main

void calculaMinutos(int *totalMinutos, int *horas, int *minutos){
    *horas = *totalMinutos / 60;
    *minutos = *totalMinutos % 60;
    return;
}//calculaMinutos