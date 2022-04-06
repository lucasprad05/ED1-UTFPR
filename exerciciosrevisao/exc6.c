/*
 * @file: exc6.c
 * @date: 09 mar 2022
 * @brief: Aula 00 exercicio 6
 * --- Baralho ---
 */

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

typedef struct{
    char valor;
    char naipe;
    bool jogada;
} Carta;

typedef struct{
    Carta array[54];
} Baralho;

char naipes[4] = {'P', 'O', 'E', 'C'};
char valores[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'D', 'J', 'Q', 'k'};

void imprimeCarta(Carta c);
void imprimeBaralho(Baralho deck);
void criaBaralho(Baralho *deck);
Carta *topo(Baralho *deck);
Carta *fundo(Baralho *deck);
Carta *carteado(Baralho *deck);

int main(int argc, const char *argv[]){

    Baralho baralho;

    printf("Antes:\n");
    imprimeCarta(baralho.array[0]);
    criaBaralho(&baralho);

    printf("\n\nDepois: \n");
    //    imprimeBaralho(baralho);

    Carta *top = topo(&baralho);
    imprimeCarta(*top);

    Carta *fund = fundo(&baralho);

    Carta *cartead = carteado(&baralho);
    return 0;
}

void imprimeCarta(Carta c){
    printf("Valor = %c ", c.valor);
    printf("Naipe = %c ", c.naipe);
    printf("Jogada? = %d\n", c.jogada);
}//imprimeCarta(Carta)

void imprimeBaralho(Baralho deck){
    for (int i = 0; i < 54; i++){
        imprimeCarta(deck.array[i]);
    }
}//imprimeBaralho

void criaBaralho(Baralho *deck){

    int i;
    for (i = 0; i < 52; i++){

        int valorId = i % 13;
        deck->array[i].valor = valores[valorId];

        int naipeId = i % 4;
        deck->array[i].naipe = naipes[naipeId];

        deck->array[i].jogada = false;
    }

    // inicializar coringas
    deck->array[52].valor = 'C';
    deck->array[52].naipe = ' ';
    deck->array[52].jogada = false;

    deck->array[53].valor = 'C';
    deck->array[53].naipe = ' ';
    deck->array[53].jogada = false;
}//criaBaralho

Carta *topo(Baralho *deck){

    for (int i = 53; i >= 0; i--){
        if (!deck->array[i].jogada){
            return (&deck->array[i]);
        }
    }
    printf("Não existe carta para ser consultada!");
    return (NULL);
}//topo

Carta *fundo(Baralho *deck){
    for (int i = 0; i <= 53; i++){
        if (!deck->array[i].jogada){
            return (&deck->array[i]);
        }
    }
    printf("Não existe carta para ser consultada!");
    return (NULL);
}//fundo

Carta *carteado(Baralho *deck){
    int vet[3];
    vet[0] = rand() % 52;
    vet[1] = rand() % 52;
    vet[2] = rand() % 52;
    
    if(vet[0] == vet[1]){
        do{
            vet[1] = rand() % 52;
        }while(vet[0] == vet[1] || vet[1] == vet[3]);
    }//if

    if(vet[1] == vet[2]){
        do{
            vet[2] = rand() % 52;
        }while(vet[1] == vet[2] || vet[2] == vet[3]);
    }//if

    if(vet[2] == vet[3]){
        do{
            vet[3] = rand() % 52;
        }while(vet[2] == vet[3] || vet[3] == vet[1]);
    }//if

    for(int i = 0; i < 3; i++){
        printf("Carta %d: %c %c\n", i + 1, deck->array[i].valor, deck->array[i].naipe);
    }//for
}//carteado