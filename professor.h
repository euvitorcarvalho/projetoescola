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
    TipoData dataNascimento;

}PROFESSOR;

void RelatorioProfessores(PROFESSOR lista_professores[], int qnt_professores_cadastrados);

int cadastrarProfessor(PROFESSOR *professor); // Recebe um endereço de um struct PROFESSOR para preencher os dados do professor

void imprimirDadosProfessor(PROFESSOR p);

void listarProfessoresMatricula(PROFESSOR lista[], int qnt);

void ExecutarCadastroProfessores(PROFESSOR lista_professores[], int *qnt_professores_cadastrados, int *matriculaProfessor);

void CRUD_Professores(PROFESSOR lista_professores[], int *qnt_professores_cadastrados, int *matriculaProfessor);

#endif