/*
 * @file: exc2.c
 * @date: 09 mar 2022
 * @author: Lucas Prado
 * @brief: Aula 00 exercicio 2
 * Fa�a um programa que receba do usu�rio um arquivo texto. 
 * Crie outro arquivo texto de sa�da contendo o texto do arquivo de entrada original, por�m substituindo todas as vogais pelo caractere ?*?. 
 * Al�m disso, mostre na tela quantas linhas esse arquivo possui. 
 * Dentro do programa fa�a o controle de erros, isto �, insira comandos que mostre se os arquivos foram abertos com sucesso, e caso contr�rio, imprima uma mensagem de erro encerrando o programa.
 */

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<ctype.h>

bool verificaVogal(char c);

int main(){
    char c;
    int contador = 1; //1 - contar �ltima linha
    FILE *arq1, *arq2;
    arq1 = fopen("arq1.txt", "r");
    arq2 = fopen("arq2.txt", "w");
    if(arq1 == NULL || arq2 == NULL) {
        printf("Erro ao abrir os arquivos\n");
        return 0;
    }//if

    //ler arquivos
    while(!feof(arq1)){
        c = fgetc(arq1);
        printf("%c", c);
        if(verificaVogal(c)){
            fprintf(arq2, "%c", '*');
        }else{
            fprintf(arq2, "%c", c);
            if(c == '\n') {
                contador++;
            }//if
        }//else
    }//while
    fclose(arq1);
    fclose(arq2);
    printf("A quantidade de linhas �: %d\n", contador);
    return 0;
}//main

bool verificaVogal(char c){
    bool ret;
    c = tolower(c);
    ret = (c == 'a' || c == 'e' || c == 'o'
    || c == 'i'|| c == 'u');
    return(ret);
}//verificaVogal