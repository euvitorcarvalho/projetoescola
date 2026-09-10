//int main pra rodar e testar.
// definições de funções.
#include <stdio.h>
#include <string.h>
#include "professor.h"

int cadastrarProfessor(PROFESSOR *professor){
    char nome[100];
    char sexo[10];
    int matricula;
    char CPF[12];
    TipoData dataNascimento;

    printf("digite seu nome: ");
    ler_str(nome,sizeof(nome));// recebe o nome.

    printf("informe seu sexo:\n");
    printf("F - feminino\n");
    printf("M - masculino\n");
    ler_str(sexo, sizeof(sexo)); //recebe o sexo

    printf("digite seu cpf: ");
    ler_str(CPF,sizeof(CPF));// recebe cpf.

    printf("digite sua data de nascimento (ddmmaaaa):  ");
    lerData(dataNascimento);// recebe data de nascimento.

    //ATRIBUIÇÃO
    strcpy(professor->nome,nome);
    strcpy(professor->CPF,CPF);//  0    1    2
    professor->sexo = sexo[0];// |'M'|'\n'|'\0'|
    professor.dataNascimento = data;
    //gerar matricula

    return 1; //sucesso

}   //função cadastrar


    //função atualizar

    // função excluir

    // gerar matricula

