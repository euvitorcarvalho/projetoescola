#ifndef ALUNO_H
#define ALUNO_H

typedef struct
{
   int dia;
   int mes;
   int ano;
}TipoData; // representa uma data com dia, mês e ano

typedef struct 
{
    int matricula; // número de matrícula do aluno
    char nome[100]; 
    char sexo; // 
    char CPF[12]; // formato: XXXXXXXXXXX\0
    TipoData dataNascimento; // data com dia, mês e ano separados

} Aluno;

void imprimirDadosAluno(Aluno a); // exibe informações do aluno

int cadastrarAluno(Aluno *aluno); // cadastra o aluno

TipoData DiaMesAno(int num); // ler um inteiro no formato ddmmaaaa e separa os numeros em dia, mes, ano

void ler_str(char nome[], int tamanho); // ler uma string com o fgets e tira o \n que ele considera

void lerData(TipoData *pData); // recebe o ponteiro da data e lê a data 

#endif