// estruturas
// prototipos de funções

#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "funcoes.h"

// Declarações de funções, structs e constantes
#define QNT_PROFESSORES 3

typedef struct PROFESSOR{
    char nome[100];
    char sexo;
    int matricula;
    char CPF[12];
    DATA dataNascimento;
    int preenchido;

}PROFESSOR;

void RelatorioProfessores(PROFESSOR lista_professores[], int qnt_professores_cadastrados);

int LerDadosProfessor(PROFESSOR *professor); // Recebe um endereço de um struct PROFESSOR para preencher os dados do professor

void imprimirDadosProfessor(PROFESSOR p);

void listarProfessores(PROFESSOR lista_professores[], int qnt_professores_cadastrados);

void ExecutarCadastroProfessores(PROFESSOR lista_professores[], int *qnt_professores_cadastrados, int *matriculaProfessor);

void ExecutarAtualizarProfessor(PROFESSOR lista_professores[], int qnt_professores_cadastrados);

void ExecutarExcluirProfessor(PROFESSOR lista_professores[], int *qnt_professores_cadastrados);

void CRUD_Professores(PROFESSOR lista_professores[], int *qnt_professores_cadastrados, int *matriculaProfessor);

void listar_por_sexo_professores(PROFESSOR lista_professores[], int qnt_professores_cadastrados);

int buscar_matricula_professor(int matricula, PROFESSOR lista_professores[], int qnt_professores_cadastrados);

void ordenar_preenchidos_professores(PROFESSOR lista[], int qnt);

void ordenar_por_matricula_professores(PROFESSOR lista_professores[], int qnt_professores_cadastrados);

void ordenar_por_data_professores(PROFESSOR lista_professores[], int qnt_professores_cadastrados);

void ordenar_por_nome_professores(PROFESSOR lista_professores[], int qnt_professores_cadastrados);



#endif