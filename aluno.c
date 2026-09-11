#include "aluno.h"
#include "validacao.h"
#include "funcoes.h"
#include <stdio.h>
#include <string.h>

void imprimirDadosAluno(Aluno a){
    printf("\n-----Dados do Aluno-----\n");
    printf("Nome: %s\n",a.nome);

    if (a.sexo == 'M' || a.sexo == 'm')
        printf("Sexo: Masculino\n");
    else if(a.sexo == 'F' || a.sexo == 'f')
        printf("Sexo: Feminino\n");
    else if(a.sexo == 'O' || a.sexo == 'o')
        printf("Sexo: Outro\n");
    
    printf("Data de nascimento: %02d/%02d/%04d\n",
        a.dataNascimento.dia,
        a.dataNascimento.mes,
        a.dataNascimento.ano);

    printf("CPF: %s\n",a.CPF); //exibir cpf formatado em breve

    printf("Matricula: %d\n",a.matricula);

}

int cadastrarAluno(Aluno *pAluno){ // recebe o endereço do aluno para alterar

    // cópia das variaveis do aluno, para leiura e validação antes de atribuir ao aluno
    //int matricula;
    char nome[100];
    char sexo[10];
    char cpf[15];
    TipoData data;

    int invalido; // verificador de validade

    //LER NOME
    printf("Digite seu nome: ");
    ler_str(nome, sizeof(nome)); // nome precisa de validação?

    // LER SEXO
    do{
        printf("\n-----Sexo-------\n");
        printf(" M - Masculino\n");
        printf(" F - Feminino\n");
        printf(" O - Outro\n");

        printf("\nSelecione seu sexo: ");
        ler_str(sexo, sizeof(sexo));  //ler a opção selecionada + \n + \0 , uma forma de evitar problemas de buffer de teclado
        invalido = validar_sexo(sexo); // validação ainda em desenvolvimento. verificar se uma das opções foi selecionada, case insensitive

        switch(invalido){
            case 1 : printf("Selecione uma opção valida."); break;
            default : break;
        }

    }while(invalido);

    //LER CPF
    do{
        printf("Digite seu CPF:");
        ler_str(cpf, sizeof(cpf));
        invalido = validar_cpf(cpf);

        switch(invalido){
            case 0 : break;
            case 1 : printf("\n/// Erro 1 - Cpf digitado não contem 11 dígitos. ///\n\n"); break;
            case 2 : printf("\n/// Erro 2 - Digite apenas numeros, sem pontos ou traços. ///\n\n"); break;
            case 3 : printf("\n/// Erro 3 - Cpf digitado possui todos os caracteres iguais. ///\n\n"); break;
            case 4 : printf("\n/// Erro 4 - Erro no 1º dígito verificador. ///\n\n"); break;
            case 5 : printf("\n/// Erro 5 - Erro no 2º dígito verificador. ///\n\n"); break;
            default: printf("\n/// Erro desconhecido - falha na leitura. ///\n\n"); break;
        }

    }while (invalido);

    // LER DATA DE NASCIMENTO
    do{
        printf("Digite sua data de nascimento (ddmmaaaa):");
        lerData(&data);

        invalido = validar_data(data); // validação ainda em desenvolvimento. Verificar se dia está entre 1 e 31, se mês está entre 1 e 12. e caso seja mes fevereiro, verificar se dia está entre 1 e 28 ou 29 caso seja ano bissexto.

        switch (invalido){
            case 1 : printf("Digite uma data valida."); break;
            default : break;
        }
    }while(invalido); // repete a leitura enquanto for invalido

    char salvar[10];
    do{
        printf("Salvar cadastro? (s/n): ");
        ler_str(salvar, sizeof(salvar));

        if(salvar[0] == 's' || salvar[0] == 'S'){
            break;
        }
        else if(salvar[0] == 'n' || salvar[0] == 'N'){
            printf("\n/// Cadastro cancelado. voltando... ///\n");
            return 0;
        }
        else   
            printf("Digite uma opção valida.\n");
    }while(1);
       
    //ATRIBUIÇÃO - se os dados forem validos, atribuir ao aluno
    
    strcpy(pAluno->nome, nome);
    strcpy(pAluno->CPF, cpf);//                                                   0    1    2    
    pAluno->sexo = sexo[0]; // passa primeira letra lida da string de sexo. ex: | M | \n | \0 |
    pAluno->dataNascimento = data;
    // falta gerar matricula;
    printf("\n/// Cadastro Salvo! ///\n\n");
    
    return 1; //sucesso
    
}
