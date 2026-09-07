#include "aluno.h"
#include <stdio.h>
#include <string.h>

int main(){
    Aluno aluno;
    cadastrarAluno(&aluno);
    printf("Cadastro concluido!");
}

void cadastrarAluno(Aluno *aluno){ // recebe o endereço do aluno para alterar
    
    printf("Digite seu nome: ");
    lerNome(aluno->nome, sizeof(aluno->nome));
    
    printf("Digite sua data de nascimento (ddmmaaaa):");
    lerData(&aluno->dataNascimento);
    // validar data depois

    printf("Selecione seu sexo:\n ");
    printf("M - Masculino\n ");
    printf("F - Feminino\n ");

    lerSexo(&aluno->sexo);

    printf("Digite seu CPF:");
    lerCPF(aluno->CPF, sizeof(aluno->CPF));
    // validar cpf depois
    
}

//DEFINIÇÃO DAS FUNÇÕES DE LEIURA

void lerNome(char nome[], int tamanho){ // recebe a string e o tamanho dela

    // ler o nome com o fgets
    fgets(nome, tamanho, stdin); 

    // remove o \n que o fgets considera ao apertar enter
    nome[strcspn(nome, "\n")] = '\0';
}


void lerData(TipoData *pData){ // recebe o endereço da variavel do tipo Data
    int num;

    // lê um numero no formato ddmmaaaa
    scanf("%d",&num);  

    // chama função para separar em dia, mes e ano
    *pData = DiaMesAno(num);
}

void lerSexo(char *pSexo){ // recebe o endereço de onde salvar o char
   
    // ler o sexo com o scanf
   scanf(" %c",pSexo);

   // corrige erro de pular a leitura do CPF, algum problema de buffer, eu acho
   getchar(); 
}

void lerCPF(char CPF[], int tamanho){ // recebe a string e o tamanho dela
    
    // ler o array com o fgets
    fgets(CPF, tamanho, stdin);

    // remove o \n que o fgets considera ao apertar enter
    CPF[strcspn(CPF, "\n")] = '\0';

}

TipoData DiaMesAno(int num){ // recebe um numero inteiro no formato ddmmaaaa e retorna uma data separada em dia, mes e ano
    TipoData data;

    data.dia = num / 1000000;
    data.mes = (num % 1000000) / 10000;
    data.ano = num % 10000;

    return data;
}


