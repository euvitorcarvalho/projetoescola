#ifndef ALUNO_H
#define ALUNO_H
#include "funcoes.h"

#define QNT_ALUNOS 10

typedef struct ALUNO
{
    int matricula; // número de matrícula do aluno
    char nome[100]; 
    char sexo; // 
    char CPF[12]; // formato: XXXXXXXXXXX\0
    DATA dataNascimento; // data com dia, mês e ano separados
    int preenchido;
} ALUNO;

void imprimirDadosAluno(ALUNO a); // exibe informações do aluno

void listarAlunos(ALUNO lista_alunos[], int qnt_alunos_cadastrados);

int cadastrarAluno(ALUNO *aluno); // cadastra o aluno

void ExecutarCadastroAlunos(ALUNO lista_alunos[], int *qnt_alunos_cadastrados, int *matriculaAluno);

int ExecutarAtualizarAluno(ALUNO lista_alunos[], int qnt_alunos_cadastrados);

int ExecutarExcluirAluno(ALUNO lista_alunos[], int *qnt_alunos_cadastrados);

void RelatorioAlunos(ALUNO lista_alunos[], int qnt_alunos_cadastrados);

void CRUD_Alunos(ALUNO lista_alunos[], int *qnt_alunos_cadastrados, int *matriculaAluno);

int buscar_matricula(int matricula, ALUNO lista_alunos[], int qnt_alunos_cadastrados);

void ordenar_por_matricula(ALUNO lista_alunos[], int qnt_alunos_cadastrados);

void ordenar_por_nome(ALUNO lista_alunos[], int qnt_alunos_cadastrados);

void ordenar_por_data(ALUNO lista_alunos[], int qnt_alunos_cadastrados);

void ordenar_preenchidos(ALUNO lista_alunos[], int qnt_alunos_cadastrados);

void ordenar_por_sexo(ALUNO lista_alunos[], int qnt_alunos_cadastrados);


#endif