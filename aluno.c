#include "aluno.h"
#include <stdio.h>
#include <string.h>

void cadastrarAluno(Aluno *novoAluno){
    
    printf("Digite seu nome: ");
    lerNome(novoAluno->nome, sizeof(novoAluno->nome));
    
    printf("Digite sua data de nascimento (ddmmaaaa):");
    lerData(&novoAluno->dataNascimento);
    //validar data depois

    printf("Selecione seu sexo:\n ");
    printf("M - Masculino\n ");
    printf("F - Feminino\n ");

    lerSexo(&novoAluno->sexo);

    printf("Digite seu CPF:");
    lerCPF(novoAluno->CPF, sizeof(novoAluno->CPF));
    //validar cpf depois
    
}

//DEFINIÇÃO DAS FUNÇÕES DE LEIURA

void lerNome(char nome[], int tamanho){
    fgets(nome, tamanho, stdin); // ler o nome com o fgets

    nome[strcspn(nome, "\n")] = '\0';// remove o \n que o fgets considera ao apertar enter
}


void lerData(TipoData *pData){ // recebe o endereço da variavel do tipo Data do aluno
    int num;
    scanf("%d",&num); // lê um numero no formato ddmmaaaa 

    // chama função para separar em dia, mes e ano
    *pData = DiaMesAno(num);
}

void lerSexo(char *pSexo){ // recebe o endereço de onde salvar
    scanf(" %c",pSexo);  //ler o sexo com o scanf
}

void lerCPF(char CPF[], int tamanho){ // recebe o array e o tamanho dele
    
    fgets(CPF, tamanho, stdin); // ler o array com o fgets
    CPF[strcspn(CPF, "\n")] = '\0';// remove o \n que o fgets considera ao apertar enter

}

TipoData DiaMesAno(int num){ // recebe um numero inteiro no formato ddmmaaaa e separa em formato de data em dia, mes e ano
    TipoData data;

    data.dia = num / 1000000;
    data.mes = (num % 1000000) / 10000;
    data.ano = num % 10000;

    return data;
}


