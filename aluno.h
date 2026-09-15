#ifndef ALUNO_H
#define ALUNO_H
#include "funcoes.h"

#define QNT_ALUNOS 3

typedef struct ALUNO
{
    int matricula; // número de matrícula do aluno
    char nome[100]; 
    char sexo; // 
    char CPF[12]; // formato: XXXXXXXXXXX\0
    TipoData dataNascimento; // data com dia, mês e ano separados

} ALUNO;

void imprimirDadosAluno(ALUNO a); // exibe informações do aluno

void listarAlunosMatricula(ALUNO lista[], int qnt);

int cadastrarAluno(ALUNO *aluno); // cadastra o aluno

void ExecutarCadastroAlunos(ALUNO lista_alunos[], int *qnt_alunos_cadastrados, int *matriculaAluno);

int ExecutarAtualizarAluno(ALUNO lista[], int qnt);

int ExecutarExcluirAluno();

void RelatorioAlunos(ALUNO lista_alunos[], int qnt_alunos_cadastrados);

void CRUD_Alunos(ALUNO lista_alunos[], int *qnt_alunos_cadastrados, int *matriculaAluno);

#endif