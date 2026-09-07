//int main pra rodar e testar.
// definições de funções.
#include <stdio.h>
#include "professor.h"

int main() {
    //ainda não gera a matricula.
    PROFESSOR meuProfessor;
    cadastrarProfessor(&meuProfessor);
    printf("Cadastro concluido!\n");
    printf("nome do professor: %s", meuProfessor.nome);
    printf("sexo do professor: %c\n", meuProfessor.sexo);
    printf("cpf do professor: %s\n", meuProfessor.CPF);
    printf("data de nascimento do professor: %02d/%02d/%04d\n",
        meuProfessor.dataNascimento.dia,
        meuProfessor.dataNascimento.mes,
        meuProfessor.dataNascimento.ano);
  //printf("matricula do professor: %d", matricula);  
    return 0;
}

void cadastrarProfessor(PROFESSOR *professor){
    printf("digite seu nome: ");
    fgets(professor->nome, sizeof(professor->nome), stdin);// recebe o nome.

    printf("informe seu sexo:\n");
    printf("F - feminino\n");
    printf("M - masculino\n");
    scanf(" %c", &professor->sexo);// recebe o sexo.
    getchar();// ???
    printf("digite seu cpf:");
    fgets(professor->CPF,sizeof(professor->CPF),stdin);// recebe cpf.

    printf("digite sua data de nascimento (ddmmaaaa):  ");
    int data;
    scanf("%d",&data);// recebe data de nascimento.

    professor->dataNascimento.dia = data / 1000000;// divide pela quantidade de caracteres para separar dia, mês e ano.
    professor->dataNascimento.mes = (data % 1000000) / 10000;
    professor->dataNascimento.ano = data % 10000;
}   //função cadastrar


    //função atualizar

    // função excluir

    // gerar matricula

