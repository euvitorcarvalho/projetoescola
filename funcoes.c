#include "funcoes.h"
#include <stdio.h>

void ler_str(char str[], int tamanho){ // recebe uma string e o tamanho dela

    // ler a string com o fgets
    fgets(str, tamanho, stdin); 

    // remove o \n que o fgets considera ao apertar enter
    str[strcspn(str, "\n")] = '\0';
}


void lerData(TipoData *pData){ // recebe o endereço da variavel do tipo Data
    int num;

    // lê um numero no formato ddmmaaaa
    scanf("%d",&num);  
    getchar(); // limpar buffer 😭
    // chama função para separar em dia, mes e ano
    *pData = DiaMesAno(num);
}

TipoData DiaMesAno(int num){ // recebe um numero inteiro no formato ddmmaaaa e retorna uma data separada em dia, mes e ano
    TipoData data;

    data.dia = num / 1000000;
    data.mes = (num % 1000000) / 10000;
    data.ano = num % 10000;

    return data;
}