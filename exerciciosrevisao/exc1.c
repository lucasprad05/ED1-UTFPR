/*
 * @file: exc1.c
 * @date: 09 mar 2022
 * @author: Lucas Prado
 * @brief: Aula 00 exercicio 1
 * Um ponteiro pode ser usado para dizer a uma fun��oo onde ela deve depositar o resultado de seus c�lculos. 
 * Escreva uma fun��o que converta uma quantidade de minutos na nota��o horas/minutos. 
 * A fun��o recebe como par�metro: um n�mero inteiro (totalMinutos); e os endere�os de duas vari�veis inteiras, horas e minutos.
 * 
 * A fun��o deve ent�o atribuir valores �s vari�veis passadas por refer�ncia, de modo que os valores atribu�dos respeitem as seguintes condi��es:
 *                                      minutos < 60
 *                          60 ? horas + minutos = totalMinutos
 * Escreva tamb�m a fun��o principal (main) que use a fun��o desenvolvida.
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

    //chamar fun��o
    calculaMinutos(&totalMinutos, &horas, &minutos);
    printf("Horas: %d Minutos: %d\n", horas, minutos);
    return 0;
}//main

void calculaMinutos(int *totalMinutos, int *horas, int *minutos){
    *horas = *totalMinutos / 60;
    *minutos = *totalMinutos % 60;
    return;
}//calculaMinutos