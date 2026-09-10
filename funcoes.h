//DEFINIÇÃO DAS FUNÇÕES DE LEIURA
#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct TipoData
{
   int dia;
   int mes;
   int ano;
} TipoData; // representa uma data com dia, mês e ano

void ler_str(char str[], int tamanho);

void lerData(TipoData *pData);

TipoData DiaMesAno(int num);

#endif