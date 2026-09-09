#include "aluno.h"
#include "validacoes.h"
#include <stdio.h>
#include <string.h>

int main(){
    Aluno aluno;
    cadastrarAluno(&aluno);
    printf("\nCadastro concluido!\n");
    imprimirDadosAluno(aluno);
}

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

void cadastrarAluno(Aluno *pAluno){ // recebe o endereço do aluno para alterar

    // cópia das variaveis do aluno, para leiura e validação antes de atribuir ao aluno
    //int matricula;
    char nome[100];
    char sexo[3];
    char cpf[12];
    TipoData data;

    int invalido; // verificador de validade

    //LER NOME
    printf("Digite seu nome: ");
    ler_str(nome, sizeof(nome)); // nome precisa de validação?

    // LER SEXO
    do{
        printf("\n--------Sexo-------\n");
        printf("M - Masculino\n ");
        printf("F - Feminino\n ");
        printf("O - Outro\n ");

        printf("\nSelecione seu sexo: ");

        ler_str(sexo, sizeof(sexo));  //ler a opção selecionada + \n + \0
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
            case 1 : printf("Erro 1 - Cpf digitado não contem 11 dígitos.\n"); break;
            case 2 : printf("Erro 2 - Digite apenas numeros, sem pontos ou traços.\n"); break;
            case 3 : printf("Erro 3 - Cpf digitado possui todos os caracteres iguais.\n"); break;
            case 4 : printf("Erro 4 - Erro no 1º dígito verificador.\n"); break;
            case 5 : printf("Erro 5 - Erro no 2º dígito verificador\n."); break;
            default: printf("Erro desconhecido - falha na leitura.\n"); break;
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

    //ATRIBUIÇÃO - se os dados forem validos, atribuir ao aluno
    
    strcpy(pAluno->nome, nome);
    strcpy(pAluno->CPF, cpf);//                                                   0    1    2    
    pAluno->sexo = sexo[0]; // passa primeira letra lida da string de sexo. ex: | M | \n | \0 |
    pAluno->dataNascimento = data;
    // falta gerar matricula;
    
}

//DEFINIÇÃO DAS FUNÇÕES DE LEIURA

void ler_str(char str[], int tamanho){ // recebe uma string e o tamanho dela

    // ler a string com o fgets
    fgets(str, tamanho, stdin); 

    // remove o \n que o fgets considera ao apertar enter
    str[strcspn(str, "\n")] = '\0';
}


void lerData(TipoData *pData){ // recebe o endereço da variavel do tipo Data
    int num;

    // lê um numero no formato ddmmaaaa
    scanf("%d",&num);  

    // chama função para separar em dia, mes e ano
    *pData = DiaMesAno(num);
}

TipoData DiaMesAno(int num){ // recebe um numero inteiro no formato ddmmaaaa e retorna uma data separada em dia, mes e ano
    TipoData data;

    data.dia = num / 1000000;
    data.mes = (num % 1000000) / 10000;
    data.ano = num % 10000;

    return data;
}


