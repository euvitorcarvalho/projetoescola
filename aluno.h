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
    int contDisciplinas; // contador de disciplinas matriculadas
} ALUNO;

void imprimirDadosAluno(ALUNO a); // exibe informações do aluno

void listarAlunos(ALUNO lista_alunos[], int qnt_alunos_cadastrados);

ALUNO LerDadosAluno(); // Lê e valida os dados do aluno. Retorna o struct aluno com os dados lidos.

void ExecutarCadastroAlunos(ALUNO lista_alunos[], int *qnt_alunos_cadastrados, int *matriculaAluno);

void ExecutarAtualizarAluno(ALUNO lista_alunos[], int qnt_alunos_cadastrados);

void ExecutarExcluirAluno(ALUNO lista_alunos[], int *qnt_alunos_cadastrados);

void RelatorioAlunos(ALUNO lista_alunos[], int qnt_alunos_cadastrados);

void CRUD_Alunos(ALUNO lista_alunos[], int *qnt_alunos_cadastrados, int *matriculaAluno);

int buscar_matricula_aluno(int matricula, ALUNO lista_alunos[], int qnt_alunos_cadastrados);

void ordenar_por_matricula_alunos(ALUNO lista_alunos[], int qnt_alunos_cadastrados);

void ordenar_por_nome_alunos(ALUNO lista_alunos[], int qnt_alunos_cadastrados);

void ordenar_por_data_alunos(ALUNO lista_alunos[], int qnt_alunos_cadastrados);

void ordenar_preenchidos_alunos(ALUNO lista_alunos[], int qnt_alunos_cadastrados);

void listar_por_sexo_alunos(ALUNO lista_alunos[], int qnt_alunos_cadastrados);


#endif