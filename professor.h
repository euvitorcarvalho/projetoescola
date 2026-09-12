// estruturas
// prototipos de funções

#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "funcoes.h"

// Declarações de funções, structs e constantes

typedef struct {
    char nome[100];
    char sexo;
    int matricula;
    char CPF[12];
    TipoData dataNascimento;

}PROFESSOR;

int cadastrarProfessor(PROFESSOR *professor); // Recebe um endereço de um struct PROFESSOR para preencher os dados do professor
void listarProfessores(PROFESSOR lista[],int qnt);
void imprimirDadosProfessor(PROFESSOR p);
#endif