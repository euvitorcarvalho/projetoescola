//int main pra rodar e testar.
// definições de funções.
#include <stdio.h>
#include <string.h>
#include "professor.h"
#include "funcoes.h"
#include "validacao.h"

int cadastrarProfessor(PROFESSOR *professor){
    char nome[100];
    char sexo[10];
    char CPF[15];
    TipoData dataNascimento;
    int invalido = 0;

    printf("digite seu nome: ");
    ler_str(nome,sizeof(nome));// recebe o nome.
    do{
         printf("\n----- Sexo -----\n");
        printf("F - Feminino\n");
        printf("M - Masculino\n");
        printf("O - Outro\n");
        printf("Informe seu sexo:\n");
        ler_str(sexo, sizeof(sexo)); //recebe o sexo
        invalido = validar_sexo(sexo);
        if(invalido){
            printf("\nSexo inválido, digite novamente.\n");
        }
    }while(invalido);

    do{
        printf("Digite seu cpf: ");
        ler_str(CPF,sizeof(CPF));// recebe cpf.
        invalido = validar_cpf(CPF);
        switch(invalido){
            case 0 : break;
            case 1 : printf("\n/// Erro 1 - Cpf digitado não contem 11 dígitos. ///\n\n"); break;
            case 2 : printf("\n/// Erro 2 - Digite apenas numeros, sem pontos ou traços. ///\n\n"); break;
            case 3 : printf("\n/// Erro 3 - Cpf digitado possui todos os caracteres iguais. ///\n\n"); break;
            case 4 : printf("\n/// Erro 4 - Erro no 1º dígito verificador. ///\n\n"); break;
            case 5 : printf("\n/// Erro 5 - Erro no 2º dígito verificador. ///\n\n"); break;
            default: printf("\n/// Erro desconhecido - falha na leitura. ///\n\n"); break;
        }
    }while(invalido);

    do{
        printf("Digite sua data de nascimento (ddmmaaaa):  ");
        lerData(&dataNascimento);// recebe data de nascimento.
        invalido = validar_data(dataNascimento);// função vazia
    }while(invalido);

    char salvar[10];
    do{
        printf("\nDeseja salvar o cadastro? (s/n): ");
        ler_str(salvar, sizeof(salvar));

        if(salvar[0] == 'S' || salvar[0] == 's'){
            //ATRIBUIÇÃO
            strcpy(professor->nome,nome);
            strcpy(professor->CPF,CPF);//  0    1    2
            professor->sexo = sexo[0];// |'M'|'\n'|'\0'|
            professor->dataNascimento = dataNascimento;

            printf("\n/// Cadastro concluido com sucesso! ///\n");
            return 1; // sucesso
        }
        else if( salvar[0] == 'N' || salvar[0] == 'n'){
            printf("\n/// Cadastro cancelado. Voltando... ///\n");
            return 0; // cadastro cancelado;
        }
        else{
            printf("\n/// Digite uma opção valida. ///\n");
        }
    }while(1);

}   

void listarProfessores(PROFESSOR lista[], int qnt){// função listar
    printf("\n\n///          LISTAR PROFESSORES         ///\n\n");

    for(int i = 0; i < qnt; i++){
        imprimirDadosProfessor(lista[i]);
    }
}
void imprimirDadosProfessor(PROFESSOR p){
     printf("\n--------Dados do Professor--------\n");

    printf("Nome: %s\n",p.nome);

    printf("Matricula: %06d\n",p.matricula);

    if (p.sexo == 'M')
        printf("Sexo: Masculino\n");
    else if(p.sexo == 'F')
        printf("Sexo: Feminino\n");
    else if(p.sexo == 'O')
        printf("Sexo: Outro\n");
    
    printf("Data de nascimento: %02d/%02d/%04d\n",
        p.dataNascimento.dia,
        p.dataNascimento.mes,
        p.dataNascimento.ano);

    printf("CPF: %s\n",p.CPF); //exibir cpf formatado em breve
}


    //função atualizar

    // função excluir