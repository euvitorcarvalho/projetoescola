#ifndef ALUNO_H
#define ALUNO_H
#include "funcoes.h"

typedef struct 
{
    int matricula; // número de matrícula do aluno
    char nome[100]; 
    char sexo; // 
    char CPF[12]; // formato: XXXXXXXXXXX\0
    TipoData dataNascimento; // data com dia, mês e ano separados

} ALUNO;

void imprimirDadosAluno(ALUNO a); // exibe informações do aluno

void listarAlunos(ALUNO lista[], int qnt);

int cadastrarAluno(ALUNO *aluno); // cadastra o aluno

#endif