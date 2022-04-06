/*
 * @file: exc5.c
 * @date: 09 mar 2022
 * @author: Lucas Prado
 * @brief: Aula 00 exercicio 5
 * Defina um tipo abstrato de dados que ir� representar bandas de m�sica.
 * Essa estrutura deve ter o nome da banda, que tipo de m�sica ela toca, o n�mero de integrantes, e em que posi��o do ranking essa banda est� dentre as suas 5 bandas favoritas.
 * a) Crie uma fun��o para preencher as 5 estruturas de bandas criadas no exemplo passado;
 * b) Ap�s criar e preencher, exiba todas as informa��es das bandas/estruturas;
 * c) Crie uma fun��o que pe�a ao usu�rio um n�mero de 1 at� 5.
 * Em seguida, seu programa deve exibir informa��es da banda cuja posi��o no seu ranking � a que foi solicitada pelo usu�rio.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[21];
    char tipoMusica[11];
    int integrantes;
    int ranking;
}Banda;

void preencheBandas(Banda *bandas);
void exibeBandas(Banda *bandas);
void pesquisa(Banda *bandas);

int main(){
    int valor;
    Banda bandas[5];
    preencheBandas(&bandas);
    exibeBandas(&bandas);
    pesquisa(&bandas);
    return 0;
}//main

void preencheBandas(Banda *bandas){
    for(int i = 0; i < 5; i++){
        fflush(stdin);
        printf("Digite o nome da banda: ");
        fgets(bandas[i].nome, 21, stdin);
        bandas[i].nome[strcspn(bandas[i].nome, "\n")] = '\0';
        fflush(stdin);

        printf("Digite o tipo de musica: ");
        fgets(bandas[i].tipoMusica, 21, stdin);
        bandas[i].tipoMusica[strcspn(bandas[i].tipoMusica, "\n")] = '\0';
        fflush(stdin);

        printf("Digite a quantidade de integrantes: ");
        scanf("%d", &bandas[i].integrantes);

        printf("Digite o ranking: ");
        scanf("%d", &bandas[i].ranking);
    for(int j = 0; j < 5; j++){
        if(bandas[i].ranking == bandas[j].ranking && i != j){
            printf("Digite o ranking novamente, pois essa posi��o est� ocupada: ");
            scanf("%d", &bandas[i].ranking);
        }//if
    }//for     
        system("cls");
    }//for
    return;
}//preencheBandas

void exibeBandas(Banda *bandas){
    for(int i = 0; i < 5; i++){
        printf("Nome: %s\nTipo: %s\nIntegrantes: %d\nRanking: %d\n", bandas[i].nome, bandas[i].tipoMusica, bandas[i].integrantes, bandas[i].ranking);
    }//for
    return;
}//exibeBandas

void pesquisa(Banda *bandas){
    int valor;
    printf("Digite o ranking a ser buscado: ");
    scanf("%d", &valor);
    for(int i = 0; i < 5; i++){
        if(valor == bandas[i].ranking){
        printf("Nome: %s\nTipo: %s\nIntegrantes: %d\nRanking: %d\n", bandas[i].nome, bandas[i].tipoMusica, bandas[i].integrantes, bandas[i].ranking);
        }//if
    }//for
    return;
}//pesquisa