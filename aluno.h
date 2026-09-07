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
    TipoData dataNascimento; // data com dia, mês e ano separados
    char CPF[12]; // formato: XXXXXXXXXXX\0
} Aluno;

void cadastrarAluno(Aluno *aluno); // cadastra o aluno

TipoData DiaMesAno(int num); // ler um inteiro no formato ddmmaaaa e separa os numeros em dia, mes, ano

void lerNome(char nome[], int tamanho); // ler o nome do aluno

void lerData(TipoData *pData); // recebe o ponteiro da data e lê a data de nascimento

void lerSexo(char *pSexo); // recebe o ponteiro do char do sexo e lê. considerar 'M' para masculino, 'F' para feminino; case insensitive

void lerCPF(char cpf[], int tamanho); // ler char de cpf no formato: xxxxxxxxxxx

#endif