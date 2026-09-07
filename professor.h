// estruturas
// prototipos de funções

#ifndef PROFESSOR_H
#define PROFESSOR_H

// Declarações de funções, structs e constantes
typedef struct {
    int dia;
    int mes;
    int ano;
}Data;

typedef struct {
    char nome[100];
    char sexo;
    int matricula;
    char CPF[12];
    Data dataNascimento;

}PROFESSOR;

void cadastrarProfessor(PROFESSOR *professor); // Recebe um endereço de um struct PROFESSOR para preencher os dados do professor

#endif